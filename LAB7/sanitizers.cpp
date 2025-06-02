#include <iostream>

void funcion1() {
    int* p = new int[10];
    p[10] = 5; // Acceso fuera de los límites del array
    delete[] p;

    int* q = new int[10];
    delete[] q;
    std::cout << q[0] << std::endl; // Uso después de liberar memoria
}

int main() {
    funcion1();
    return 0;
}
