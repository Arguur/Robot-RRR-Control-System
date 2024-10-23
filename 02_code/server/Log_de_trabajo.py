import csv
from datetime import datetime
from Actividad import Actividad

class Log_de_trabajo:
    def __init__(self):
        self.actividades = []
        self.contador_id = 1  # Inicializar el contador de IDs en 1

    # Método para abrir y leer el archivo log_de_trabajo.csv
    def abrir_log(self):
        try:
            with open('../03_anexo/log_de_trabajo.csv', mode='r', newline='') as file:
                reader = csv.reader(file)
                for row in reader:
                    print(f"Leyendo registro del log: {row}")
        except FileNotFoundError:
            print("Error: No se pudo encontrar el archivo log_de_trabajo.csv")

     # Método para guardar una actividad en el CSV
    def guardar_en_csv(self, actividad: Actividad):
        try:
            with open('../03_anexo/log_de_trabajo.csv', mode='a', newline='') as file:
                writer = csv.writer(file)
                # Escribir los atributos de la actividad en el CSV
                writer.writerow([actividad.id, actividad.ip, actividad.orden, actividad.detalle, actividad.exito, actividad.marcaTiempo])
                print(f"Actividad guardada en CSV: ID={actividad.id}, IP={actividad.ip}, Orden={actividad.orden}, Detalle={actividad.detalle}, Exito={actividad.exito}, Informacion del error={actividad.error_detalle}, Marca de Tiempo={actividad.marcaTiempo}")
        except Exception as e:
            print(f"Error al escribir en el archivo log_de_trabajo.csv: {e}")

    # Método para crear una nueva actividad y agregarla al log y a la lista de actividades
    def crear_actividad(self, ip, orden, detalle, exito, error_detalle):
        nueva_actividad = Actividad(id=self.contador_id, ip=ip, orden=orden, detalle=detalle, exito=exito, error_detalle=error_detalle, marcaTiempo=datetime.now())
        
        # Guardar en el CSV
        self.guardar_en_csv(nueva_actividad)
        
        # Agregar la actividad a la lista interna
        self.actividades.append(nueva_actividad)
        
        # Incrementar el contador de IDs para la siguiente actividad
        self.contador_id += 1
        
        print(f"Actividad creada y añadida al log: ID={nueva_actividad.id}, Orden={orden}, Detalle={detalle}, Exito={exito}")

   
