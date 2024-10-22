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

public:
    ControladorCliente();
    ~ControladorCliente();

    bool conectar();
    void desconectar();
    std::string enviarComando(const std::string& comando);
    std::string recibirRespuesta();
    void mostrarEstadoRobot();
    void mostrarLogActividades();

    // Getters y setters
    void setDireccionServidor(const std::string& dir) { direccionServidor = dir; }
    void setPuerto(int port) { puerto = port; }
    std::string getDireccionServidor() const { return direccionServidor; }
    int getPuerto() const { return puerto; }
};

#endif // CONTROLADOR_CLIENTE_H