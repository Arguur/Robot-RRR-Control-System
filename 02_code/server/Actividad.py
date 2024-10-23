from datetime import datetime
from User import User
import csv

class Actividad:
    def __init__(self, id, user=None, orden="", detalle="", exito=False, marcaTiempo=None):
        self.id = id
        self.user = user if user is not None else User()
        self.orden = orden
        self.detalle = detalle
        self.exito = exito
        self.marcaTiempo = marcaTiempo if marcaTiempo is not None else datetime.now()

        # Guardar la actividad en el log (CSV) inmediatamente después de crearla
        self.guardar_en_csv()

    # Guardar en CSV (utiliza a sí mismo, a Actividad)
    def guardar_en_csv(self):
        try:
            # Abrir el archivo en modo 'a' (append) para agregar sin borrar el contenido
            with open('../03_anexo/log_de_trabajo.csv', mode='a', newline='') as file:
                writer = csv.writer(file)
                # Escribir los atributos de la actividad en el CSV
                writer.writerow([self.id, self.user.usuario, self.orden, self.detalle, self.exito, self.marcaTiempo])
                print(f"Actividad guardada en CSV: ID={self.id}, Usuario={self.user.usuario}, Orden={self.orden}, Detalle={self.detalle}, Exito={self.exito}, Marca de Tiempo={self.marcaTiempo}")
        except Exception as e:
            print(f"Error al escribir en el archivo log_de_trabajo.csv: {e}")

    # Tarea finalizada (dejado vacío según la consigna)
    def tarea_finalizada(self):
        pass
