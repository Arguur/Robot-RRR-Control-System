#ifndef CONTROLADORCLIENTE_H
#define CONTROLADORCLIENTE_H

#include "conexionServidor.h"
#include "vistaCliente.h"

class ControladorCliente {
private:
    ConexionServidor conexion;
    VistaCliente vista;
    std::string direccionServidor;
    int puerto;

public:
    ControladorCliente(const std::string& direccion, int puerto);
    void conectar();
    void desconectar();
    void enviarComando(const std::string& comando);
    std::string recibirRespuesta();
    void mostrarEstadoRobot();
    void mostrarLogActividades();
};

#endif // CONTROLADORCLIENTE_H
