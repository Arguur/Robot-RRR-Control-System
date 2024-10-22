// ConexionServidor.h
#ifndef CONEXION_SERVIDOR_H
#define CONEXION_SERVIDOR_H

#include <string>

class ConexionServidor {
private:
    std::string direccion;
    int puerto;
    bool conectado;

public:
    ConexionServidor(const std::string& dir = "localhost", int port = 8080);
    ~ConexionServidor();
    
    bool establecerConexion();
    void cerrarConexion();
    std::string enviarDatos(const std::string& datos);
    std::string recibirDatos();
    
    // Getters
    bool estaConectado() const { return conectado; }
    std::string getDireccion() const { return direccion; }
    int getPuerto() const { return puerto; }
};

#endif // CONEXION_SERVIDOR_H