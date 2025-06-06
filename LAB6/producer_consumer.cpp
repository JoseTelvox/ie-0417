#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <semaphore>
#include <chrono>
#include <random>

constexpr int BUFFER_SIZE = 5;          // tamaño del búfer compartido
constexpr int NUM_PRODUCERS = 5;        // hilos productores
constexpr int NUM_CONSUMERS = 10;        // hilos consumidores
constexpr int TASKS_PER_PRODUCER = 10;  // tareas que crea cada productor

std::queue<int> buffer;                 // búfer compartido
std::mutex mtx;                         // protege el búfer
std::condition_variable cv_producer;    // notifica a productores
std::condition_variable cv_consumer;    // notifica a consumidores

// Semáforos (C++20)
std::counting_semaphore<BUFFER_SIZE> empty_slots(BUFFER_SIZE);
std::counting_semaphore<BUFFER_SIZE> full_slots{0};

// Generador de números aleatorios para simular tiempo de trabajo
std::mt19937 rng{std::random_device{}()};
std::uniform_int_distribution<> work{80, 180};

void producer(int id) {
    for (int i = 0; i < TASKS_PER_PRODUCER; ++i) {
        empty_slots.acquire();                       // espera espacio libre
        {
            std::unique_lock<std::mutex> lock(mtx);  // sección crítica
            int item = id * 100 + i;                 // item "único"
            buffer.push(item);
            std::cout << "[P" << id << "] produjo " << item
                      << " — tamaño buffer: " << buffer.size() << '\n';
        } // desbloquea mutex al salir del alcance
        full_slots.release();                        // hay un ítem nuevo
        cv_consumer.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(work(rng)));
    }
}

void consumer(int id) {
    while (true) {
        full_slots.acquire();                        // espera ítem disponible
        int item;
        {
            std::unique_lock<std::mutex> lock(mtx);  // sección crítica
            if (buffer.empty()) {
                // todos los productores terminaron
                full_slots.release();
                break;
            }
            item = buffer.front();
            buffer.pop();
            std::cout << "      [C" << id << "] consumió " << item
                      << " — tamaño buffer: " << buffer.size() << '\n';
        }
        empty_slots.release();                       // se liberó un espacio
        cv_producer.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(work(rng)));
    }
}

int main() {
    std::vector<std::thread> producers, consumers;

    // lanza productores
    for (int i = 0; i < NUM_PRODUCERS; ++i)
        producers.emplace_back(producer, i + 1);

    // lanza consumidores
    for (int i = 0; i < NUM_CONSUMERS; ++i)
        consumers.emplace_back(consumer, i + 1);

    // espera a productores
    for (auto &p : producers) p.join();

    // da tiempo a que consumidores vacíen el búfer y acaben
    std::this_thread::sleep_for(std::chrono::seconds(1));
    // libera consumidores bloqueados (en caso de que queden)
    full_slots.release(NUM_CONSUMERS);

    for (auto &c : consumers) c.join();
    std::cout << "Fin de la simulación.\n";
    return 0;
} 