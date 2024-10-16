from datetime import datetime
from User import User

class Actividad:
    def __init__(self, id, user=None, orden="", detalle="", exito=False, marcaTiempo=None):
        self.id = id
        self.user = user if user is not None else User()
        self.orden = orden
        self.detalle = detalle
        self.exito = exito
        self.marcaTiempo = marcaTiempo if marcaTiempo is not None else datetime.now()

    # Guardar en CSV (utiliza a sí mismo, a Actividad)
    def guardar_en_csv(self):
        # Placeholder para guardar en un archivo CSV
        print(f"Guardando en CSV: ID={self.id}, Usuario={self.user.usuario}, Orden={self.orden}, Detalle={self.detalle}, Exito={self.exito}, Marca de Tiempo={self.marcaTiempo}")

    # Tarea finalizada (dejado vacío según la consigna)
    def tarea_finalizada(self):
        pass