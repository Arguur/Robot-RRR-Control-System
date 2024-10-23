import csv

class Log_de_trabajo:
    def __init__(self):
        self.actividades = []

    # Método para abrir y leer el archivo log_de_trabajo.csv
    def abrir_log(self):
        try:
            with open('../03_anexo/log_de_trabajo.csv', mode='r', newline='') as file:
                reader = csv.reader(file)
                for row in reader:
                    print(f"Leyendo registro del log: {row}")
        except FileNotFoundError:
            print("Error: No se pudo encontrar el archivo log_de_trabajo.csv")
