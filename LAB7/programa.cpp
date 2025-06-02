#include <iostream>

void funcion1() {
    int a = 5;
    int b = 0;
    int c = a / b; // Error: División por cero
    std::cout << "Resultado: " << c << std::endl;
}

int main() {
    std::cout << "Iniciando el programa" << std::endl;
    funcion1();
    std::cout << "Finalizando el programa" << std::endl;
    return 0;
}
