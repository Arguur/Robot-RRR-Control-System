from ControladorServidor import ControladorServidor
from Server import Server
from Controlador import Controlador
from InterfazServidor import InterfazServidor

# Main del programa
if __name__ == "__main__":
    controlador = Controlador(puerto="COM3", baudrate=9600, time_out=1)
    server = Server(modo_coordenadas=False, modo_trabajo=True, controlador=controlador)
    controlador_servidor = ControladorServidor(servidor=server)
    interfaz = InterfazServidor(controlador_servidor=controlador_servidor)

    # Ejemplo: se inicia con el menú de usuario
    interfaz.mostrar_menu_usuario()
