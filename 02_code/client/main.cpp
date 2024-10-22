// main.cpp
#include "VistaCliente.h"
#include "ControladorCliente.h"
#include <iostream>
#include <memory>

int main() {
    VistaCliente vista;
    ControladorCliente controlador;
    bool ejecutar = true;

    while (ejecutar) {
        try {
            vista.mostrarMenu();
            int opcion = vista.obtenerOpcion();

            switch (opcion) {
                case 0:
                    ejecutar = false;
                    break;

                case 1: // Conectar
                    if (controlador.conectar()) {
                        vista.mostrarMensaje("Conexión establecida con éxito");
                    } else {
                        vista.mostrarError("No se pudo establecer la conexión");
                    }
                    break;

                case 2: // Desconectar
                    controlador.desconectar();
                    vista.mostrarMensaje("Desconexión realizada");
                    break;

                case 3: { // Enviar comando
                    std::string comando = vista.obtenerComando();
                    std::string respuesta = controlador.enviarComando(comando);
                    vista.mostrarMensaje("Respuesta: " + respuesta);
                    break;
                }

                case 4: // Ver estado
                    controlador.mostrarEstadoRobot();
                    break;

                case 5: // Ver log
                    controlador.mostrarLogActividades();
                    break;

                default:
                    vista.mostrarError("Opción no válida");
                    break;
            }
        }
        catch (const std::exception& e) {
            vista.mostrarError(e.what());
        }
    }

    return 0;
}