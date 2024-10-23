from ControladorServidor import ControladorServidor
from Server import Server
from Controlador import Controlador
from InterfazServidor import InterfazServidor
from Log_de_trabajo import Log_de_trabajo
import threading


def run_menu():
        while True:
            interfaz.mostrar_menu_usuario()

def run_server():
    controlador_servidor.server.run_server()
    

if __name__ == "__main__":
    controlador = Controlador(puerto="COM6", baudrate=115200, time_out=1)
    server = Server(modo_trabajo=False, controlador=controlador)
    log_de_trabajo = Log_de_trabajo()
    controlador_servidor = ControladorServidor(servidor=server, log_de_trabajo=log_de_trabajo)
    interfaz = InterfazServidor(controlador_servidor=controlador_servidor)

    menu_thread = threading.Thread(target=run_menu)
    server_thread = threading.Thread(target=run_server)

    menu_thread.start()
    server_thread.start()

    menu_thread.join()
    server_thread.join()



    
    
