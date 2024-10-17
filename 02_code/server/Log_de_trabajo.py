from Actividad import Actividad

class Log_de_trabajo:
    def __init__(self):
        self.actividades = []

    # Método para abrir el archivo logDeTrabajo.txt
    def abrir_log(self):
        try:
            with open('../03_anexo/log_de_trabajo.txt', 'r') as file:
                for line in file:
                    print(f"Leyendo línea del log: {line.strip()}")
        except FileNotFoundError:
            print("Error: No se pudo encontrar el archivo log_de_trabajo.txt")