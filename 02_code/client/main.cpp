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
                case 0: { // Ayuda
                    vista.mostrarAyuda();
                    break;
                }

                case 1: { // Conexión/Desconexión
                    vista.mostrarMenuConexion();
                    vista.mostrarEstadoConexion(controlador.estaConectado());
                    int subOpcion = vista.obtenerOpcion();
                    
                    if (subOpcion == 1 && !controlador.estaConectado()) {
                        auto [usuario, password, alias] = vista.obtenerCredenciales();
                        if (controlador.conectar(usuario, password, alias)) {
                            vista.mostrarMensaje("Conexion establecida con exito");
                        } else {
                            vista.mostrarError("No se pudo establecer la conexion");
                        }
                    } else if (subOpcion == 2 && controlador.estaConectado()) {
                        controlador.desconectar();
                        vista.mostrarMensaje("Desconexion realizada");
                    }
                    break;
                }

                case 2: { // Activación/Desactivación de motores
                    if (!controlador.estaConectado()) {
                        vista.mostrarError("Debe conectarse primero");
                        break;
                    }
                    vista.mostrarMenuMotores();
                    int subOpcion = vista.obtenerOpcion();
                    
                    if (subOpcion == 1) {
                        if (controlador.activarDesactivarMotores()) {
                            vista.mostrarMensaje(controlador.estanMotoresActivos() ? 
                                               "Motores activados" : "Motores desactivados");
                        } else {
                            vista.mostrarError("Error al cambiar estado de los motores");
                        }
                    }
                    break;
                }

                case 3: { // Selección de modo de trabajo
                    if (!controlador.estaConectado()) {
                        vista.mostrarError("Debe conectarse primero");
                        break;
                    }
                    vista.mostrarMenuModoTrabajo();
                    int subOpcion = vista.obtenerOpcion();
                    
                    if (subOpcion == 1) {
                        if (controlador.cambiarModoTrabajo()) {
                            vista.mostrarMensaje(controlador.esModoManual() ? 
                                               "Modo manual activado" : "Modo automatico activado");
                        }
                    } else if (subOpcion == 2) {
                        if (controlador.cambiarModoCoordenadas()) {
                            vista.mostrarMensaje(controlador.esModoRelativo() ? 
                                               "Modo relativo activado" : "Modo absoluto activado");
                        }
                    }
                    break;
                }

                case 4: { // Control
                    if (!controlador.estaConectado()) {
                        vista.mostrarError("Debe conectarse primero");
                        break;
                    }
                    
                    if (!controlador.esModoManual()) {
                        vista.mostrarError("El control manual solo está disponible en modo manual");
                        break;
                    }

                    bool controlActivo = true;
                    while (controlActivo) {
                        double x, y, z;
                        controlador.obtenerPosicionActual(x, y, z);
                        vista.mostrarEstadoRobot(
                            controlador.estaConectado(),
                            controlador.estanMotoresActivos(),
                            controlador.esModoRelativo(),
                            controlador.estaGripperActivo(),
                            x, y, z
                        );

                        vista.mostrarMenuControl();
                        int subOpcion = vista.obtenerOpcion();

                        switch (subOpcion) {
                            case 1: { // Gripper
                                if (controlador.activarDesactivarGripper()) {
                                    vista.mostrarMensaje(controlador.estaGripperActivo() ? 
                                                       "Gripper activado" : "Gripper desactivado");
                                }
                                break;
                            }
                            case 2: { // Homing
                                if (controlador.realizarHoming()) {
                                    vista.mostrarMensaje("Homing completado");
                                }
                                break;
                            }
                            case 3: { // Mover
                                auto [newX, newY, newZ, vel] = vista.obtenerParametrosMovimiento();
                                if (controlador.moverRobot(newX, newY, newZ, vel)) {
                                    vista.mostrarMensaje("Movimiento completado");
                                }
                                break;
                            }
                            case 4: // Volver
                                controlActivo = false;
                                break;
                        }
                    }
                    break;
                }

                case 5: { // Reporte de información general
                    if (!controlador.estaConectado()) {
                        vista.mostrarError("Debe conectarse primero");
                        break;
                    }
                    controlador.mostrarEstadoRobot();
                    vista.esperarEnter();
                    break;
                }

                case 6: { // Log de actividades
                    if (!controlador.estaConectado()) {
                        vista.mostrarError("Debe conectarse primero");
                        break;
                    }
                    controlador.mostrarLogActividades();
                    vista.esperarEnter();
                    break;
                }

                case 7: { // Salir
                    ejecutar = false;
                    if (controlador.estaConectado()) {
                        controlador.desconectar();
                    }
                    vista.mostrarMensaje("Saliendo del programa...");
                    break;
                }

                default:
                    vista.mostrarError("Opción no valida");
                    break;
            }
        }
        catch (const std::exception& e) {
            vista.mostrarError(e.what());
            vista.esperarEnter();
        }
    }

    return 0;
}