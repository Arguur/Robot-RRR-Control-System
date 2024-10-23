#include "controladorCliente.h"
#include <iostream>

int main() {
    std::string direccion = "localhost";
    int puerto = 8080;
    std::string usuario, password;

    std::cout << "Ingrese nombre de usuario: ";
    std::cin >> usuario;
    std::cout << "Ingrese contraseña: ";
    std::cin >> password;

    ControladorCliente controlador(direccion, puerto, usuario, password);

    if (!controlador.autenticar()) {
        std::cout << "Autenticación fallida. Saliendo...\n";
        return 1;
    }

    int opcion;
    std::string comando;

    do {
        controlador.mostrarMenu();
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
                std::cout << "Introduzca el comando a enviar: ";
                std::cin.ignore();  // Ignorar el salto de línea pendiente
                std::getline(std::cin, comando);
                controlador.enviarComando(comando);
                break;
            case 4:
                controlador.mostrarEstadoRobot();
                break;
            case 5:
                controlador.mostrarLogActividades();
                break;
            case 6:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción no válida.\n";
                break;
        }
    } while (opcion != 6);

    return 0;
}
