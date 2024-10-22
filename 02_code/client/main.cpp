#include "controladorCliente.h"
#include <iostream>

int main() {
    std::string direccion = "localhost";
    int puerto = 8080;

    ControladorCliente controlador(direccion, puerto);
    VistaCliente vista;
    
    int opcion;
    do {
        vista.mostrarMenu();
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                controlador.conectar();
                break;
            case 2:
                controlador.desconectar();
                break;
            case 3:
                controlador.mostrarEstadoRobot();
                break;
            case 4:
                controlador.mostrarLogActividades();
                break;
            case 5:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción no válida.\n";
                break;
        }
    } while (opcion != 5);

    return 0;
}
