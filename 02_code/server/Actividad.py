from datetime import datetime
import csv

class Actividad:
    def __init__(self, id, ip=None, orden="", detalle="", exito=False, marcaTiempo=None):
        self.id = id
        self.ip = ip
        self.orden = orden
        self.detalle = detalle
        self.exito = exito
        self.marcaTiempo = marcaTiempo if marcaTiempo is not None else datetime.now()

        # Guardar la actividad en el log (CSV) inmediatamente después de crearla
        self.guardar_en_csv()