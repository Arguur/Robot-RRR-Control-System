import serial
import re
import time

class Controlador:
    def __init__(self, puerto, baudrate, time_out):
        self.puerto = puerto
        self.baudrate = baudrate
        self.time_out = time_out
        self.serial_connection = serial.Serial(port=self.puerto, baudrate=self.baudrate, timeout=self.time_out)
        self.leer()
        self.leer()

    def leer(self, timeout=5):
        start_time = time.time()
        while True:
            if self.serial_connection.in_waiting > 0:
                data = self.serial_connection.readline().decode('utf-8').strip()
                print(f"Leído: {data}")  # Debugging print statement
                return data
            if time.time() - start_time > timeout:
                raise TimeoutError("Timeout while reading from serial port")
            time.sleep(0.1)  # Esperar un poco antes de volver a verificar

    def escribir(self, s: str) -> None:
        if self.serial_connection:
            self.serial_connection.write((s + '\r').encode('utf-8'))


    def inicializacion(self):
        self.escribir("M114")
        # Parse the response
        modo_coordenadas = 0 if "ABSOLUTE MODE" in self.leer() else 1
        respuesta = self.leer()
        coordenadas = re.findall(r'X:(-?\d+\.\d+)\sY:(-?\d+\.\d+)\sZ:(-?\d+\.\d+)\sE:(-?\d+\.\d+)', respuesta)
        x, y, z, e = map(float, coordenadas[0])
        e_bool = e != 0.0
        return modo_coordenadas, x, y, z, e_bool