#ifndef CONTROLADORCLIENTE_H
#define CONTROLADORCLIENTE_H

#include "conexionServidor.h"
#include "vistaCliente.h"
#include <string>

class ControladorCliente {
private:
    ConexionServidor conexion;
    VistaCliente vista;
    std::string direccionServidor;
    int puerto;
    std::string alias;

public:
    ControladorCliente(const std::string& direccion, int puerto, const std::string& usuario, const std::string& password);
    bool autenticar();
    void conectar();
    void desconectar();
    void enviarComando(const std::string& comando);
    std::string recibirRespuesta();
    void mostrarEstadoRobot();
    void mostrarLogActividades();
    void mostrarMenu();
};

#endif // CONTROLADORCLIENTE_H
