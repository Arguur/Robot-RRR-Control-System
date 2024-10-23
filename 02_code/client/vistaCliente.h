// VistaCliente.h
#ifndef VISTA_CLIENTE_H
#define VISTA_CLIENTE_H

#include <string>
#include <tuple>

class VistaCliente {
public:
    void mostrarMenu() const;
    void mostrarMenuConexion() const;
    void mostrarMenuMotores() const;
    void mostrarMenuModoTrabajo() const;
    void mostrarMenuControl() const;
    void mostrarAyuda() const;
    void mostrarEstadoConexion(bool conectado) const;
    void mostrarEstadoRobot(bool conectado, bool motoresActivos, bool modoRelativo, 
                           bool gripperActivo, double x, double y, double z) const;
    
    int obtenerOpcion() const;
    std::tuple<std::string, std::string, std::string> obtenerCredenciales() const;
    std::tuple<double, double, double, double> obtenerParametrosMovimiento() const;
    void mostrarMensaje(const std::string& mensaje) const;
    void mostrarError(const std::string& error) const;
    void limpiarPantalla() const;
    void esperarEnter() const;
};

#endif // VISTA_CLIENTE_H