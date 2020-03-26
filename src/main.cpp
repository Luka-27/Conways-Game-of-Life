#include "Tablero.cpp"
#include "celula.cpp"
#include "celula1.cpp"
#include "celula2.cpp"
#include "celula3.cpp"

int main(){

    int turnos, m, n;
    std::cout << "Introduce el numero de turnos a realizar: ";
    std::cin >> turnos;
    std::cout << std::endl << std::endl;
    std::cout << "Introduce el numero de filas del tablero: ";
    std::cin >> m;
    std::cout << std::endl;
    std::cout << "Introduce el numero de columas del tablero: ";
    std::cin >> n;
    std::cout << std::endl;

    Tablero tabla(m,n);

    std::cout << "Numero de celulas a ser marcadas como vivas: ";
    int ncel;
    std::cin >> ncel;
    int i,j,tipo;
    std::cout << std::endl << std::endl;

    for (int k = 1; k <= ncel; k++){
        std::cout << "Tipo de celula: ";
        std::cin >> tipo;
        std::cout << std::endl;
        std::cout << "Componente i de la celula " << k << " : ";
        std::cin >> i;
        std::cout << std::endl;
        std::cout << "Componenete j de la celula " << k << " : ";
        std::cin >> j;
        std::cout << std::endl << std::endl;
        tabla.setAlive(i,j,tipo);
    }

    tabla.write(std::cout);
    std::cout << std::endl << std::endl;

    for (auto i = 1; i <= turnos; ++i){

        tabla.compute();
        tabla.write(std::cout);
        std::cout << std::endl;
    }

    return 0;
}