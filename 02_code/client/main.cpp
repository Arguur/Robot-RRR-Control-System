// main.cpp
#include "VistaCliente.h"
#include "ControladorCliente.h"
#include <iostream>
#include <memory>
#include <utility>

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
                    vista.mostrarMensaje("Saliendo del programa...");
                    break;

                case 1: { // Iniciar sesión
                    auto credenciales = vista.obtenerCredenciales();
                    if (controlador.conectar(credenciales.first, credenciales.second)) {
                        vista.mostrarMensaje("Sesion iniciada con exito");
                    } else {
                        vista.mostrarError("No se pudo iniciar sesión. Verifique sus credenciales.");
                    }
                    break;
                }

                case 2: // Desconectar sesión
                    controlador.desconectar();
                    vista.mostrarMensaje("Sesión cerrada");
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