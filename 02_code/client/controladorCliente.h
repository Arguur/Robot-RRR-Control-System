// ControladorCliente.h
#ifndef CONTROLADOR_CLIENTE_H
#define CONTROLADOR_CLIENTE_H

#include "ConexionServidor.h"
#include <string>
#include <memory>

class ControladorCliente {
private:
    std::unique_ptr<ConexionServidor> conexion;
    std::string direccionServidor;
    int puerto;
    bool modo_trabajo;  // false = manual, true = automático

public:
    ControladorCliente();
    ~ControladorCliente();

    // Métodos principales
    bool conectar(const std::string& user, const std::string& pass, const std::string& alias);
    void desconectar();
    
    // Control del robot
    bool activarDesactivarMotores();
    bool cambiarModoTrabajo();
    bool cambiarModoCoordenadas();
    bool moverRobot(double x, double y, double z, double velocidad = 100.0);
    bool activarDesactivarGripper();
    bool realizarHoming();
    
    // Información y reportes
    void mostrarEstadoRobot();
    void mostrarLogActividades();

    // Getters
    bool estaConectado() const;
    bool estanMotoresActivos() const;
    bool esModoManual() const { return !modo_trabajo; }
    bool esModoRelativo() const;
    bool estaGripperActivo() const;
    void obtenerPosicionActual(double& x, double& y, double& z) const;
};

#endif // CONTROLADOR_CLIENTE_H