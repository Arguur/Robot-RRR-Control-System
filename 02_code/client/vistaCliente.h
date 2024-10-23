#ifndef VISTACLIENTE_H
#define VISTACLIENTE_H

#include <string>

class VistaCliente {
public:
    void mostrarMenu();  // Cambiado para reflejar las nuevas opciones del menú
    void mostrarEstadoRobot(const std::string& estado);
    void mostrarLogActividades(const std::string& log);
};

#endif // VISTACLIENTE_H
