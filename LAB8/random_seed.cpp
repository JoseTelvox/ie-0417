#include <iostream>
#include <random>

int main() {
    // Establecer una semilla específica
    unsigned int seed = 12345;
    std::mt19937 generator(seed);

    // Generar algunos números aleatorios
    for (int i = 0; i < 5; ++i) {
        std::cout << generator() << std::endl;
    }

    return 0;
}
