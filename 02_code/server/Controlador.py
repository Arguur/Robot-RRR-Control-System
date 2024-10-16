import serial

class Controlador:
    def __init__(self, puerto: str, baudrate: int, time_out: int):
        self.puerto = puerto
        self.baudrate = baudrate
        self.time_out = time_out
        self.serial_connection = serial.Serial(port=self.puerto, baudrate=self.baudrate, timeout=self.time_out)

    def leer(self):
        if self.serial_connection.in_waiting > 0:
            return self.serial_connection.readline().decode('utf-8').strip()
        return ""

    def escribir(self, s: str):
        self.serial_connection.write((s + '\r\n').encode('utf-8'))