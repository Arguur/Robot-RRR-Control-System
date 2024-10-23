// ConexionServidor.h
#ifndef CONEXION_SERVIDOR_H
#define CONEXION_SERVIDOR_H

#include <string>

class ConexionServidor {
private:
    std::string direccion;
    int puerto;
    bool conectado;
    std::string usuario;
    std::string password;
    std::string alias;

    // Estado del robot
    bool modo_coordenadas;  // false = absoluto, true = relativo
    double x, y, z;
    bool gripper;
    bool motores;

public:
    ConexionServidor(const std::string& dir = "localhost", int port = 8080);
    ~ConexionServidor();
    
    bool establecerConexion(const std::string& user, const std::string& pass, const std::string& alias);
    void cerrarConexion();
    std::string enviarDatos(const std::string& comando, const std::string& parametros = "");
    
    // Métodos específicos que coinciden con el servidor
    bool activarDesactivarMotores();
    bool cambiarModoTrabajo(bool modo);
    bool cambiarModoCoordenadas();
    bool moverRobot(double x, double y, double z, double velocidad = 100);
    bool activarDesactivarGripper();
    bool realizarHoming();
    std::string obtenerEstadoRobot();
    std::string obtenerLogActividades();
    
    // Getters
    bool estaConectado() const { return conectado; }
    std::string getDireccion() const { return direccion; }
    int getPuerto() const { return puerto; }
    std::string getAlias() const { return alias; }
    bool getModoRelativo() const { return modo_coordenadas; }
    bool getGripperActivo() const { return gripper; }
    bool getMotoresActivos() const { return motores; }
    void getPosicionActual(double& outX, double& outY, double& outZ) const {
        outX = x; outY = y; outZ = z;
    }
};

#endif // CONEXION_SERVIDOR_H