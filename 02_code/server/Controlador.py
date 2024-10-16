import serial
import re

class Controlador:
    def __init__(self, puerto, baudrate, time_out):
        self.puerto = puerto
        self.baudrate = baudrate
        self.time_out = time_out
        self.serial_connection = serial.Serial(port=self.puerto, baudrate=self.baudrate, timeout=self.time_out)

    def leer(self):
        if self.serial_connection.in_waiting > 0:
            return self.serial_connection.readline().decode('utf-8').strip()
        return ""

    def escribir(self, s: str) -> None:
        self.serial_connection.write((s + '\r\n').encode('utf-8'))

    def inicializacion(self):
        self.escribir("M114\r\n")
        respuesta = self.leer()
        # Parse the response
        modo_coordenadas = 0 if "ABSOLUTE MODE" in respuesta else 1
        coordenadas = re.findall(r'X:(-?\d+\.\d+)\sY:(-?\d+\.\d+)\sZ:(-?\d+\.\d+)\sE:(-?\d+\.\d+)', respuesta)
        x, y, z, e = map(float, coordenadas[0])
        e_bool = e != 0.0
        return [modo_coordenadas, x, y, z, e_bool]


        