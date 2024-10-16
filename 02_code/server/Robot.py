class Robot:
    def __init__(self, x=0.0, y=0.0, z=0.0, gripper=False, conectado=False, motores=False):
        # Coordenadas del robot
        self._x = float(x)
        self._y = float(y)
        self._z = float(z)
        # Estados del robot
        self._gripper = bool(gripper)
        self._conectado = bool(conectado)
        self._motores = bool(motores)

    # Getters
    def get_x(self):
        return self._x

    def get_y(self):
        return self._y

    def get_z(self):
        return self._z

    def get_gripper(self):
        return self._gripper

    def get_conectado(self):
        return self._conectado

    def get_motores(self):
        return self._motores

    # Setters
    def set_x(self, x):
        self._x = float(x)

    def set_y(self, y):
        self._y = float(y)

    def set_z(self, z):
        self._z = float(z)

    def set_gripper(self, gripper):
        self._gripper = bool(gripper)

    def set_conectado(self, conectado):
        self._conectado = bool(conectado)

    def set_motores(self, motores):
        self._motores = bool(motores)

    # Movimiento lineal con x, y, z
    def movimiento_lineal(self, x, y, z):
        self._x = float(x)
        self._y = float(y)
        self._z = float(z)
        print(f"Movimiento lineal ejecutado. Nueva posición: x={self._x}, y={self._y}, z={self._z}")

    # Movimiento lineal con x, y, z y velocidad v
    def movimiento_lineal_con_velocidad(self, x, y, z, v):
        self._x = float(x)
        self._y = float(y)
        self._z = float(z)
        print(f"Movimiento lineal ejecutado con velocidad {v}. Nueva posición: x={self._x}, y={self._y}, z={self._z}")

    # Activación del efector final (gripper)
    def activar_gripper(self):
        if not self._gripper:
            self._gripper = True
            velocidad_trabajo = 1.0  # Valor inicial para la velocidad de trabajo
            tiempo_operacion = 2.0   # Valor inicial para el tiempo de operación
            sentido_movimiento = "horario"  # Valor inicial para el sentido de movimiento
            print(f"Gripper activado. Velocidad de trabajo: {velocidad_trabajo}, Tiempo de operación: {tiempo_operacion}, Sentido de movimiento: {sentido_movimiento}")
        else:
            print("Gripper ya está activado.")

# Ejemplo de uso
robot = Robot()
robot.movimiento_lineal(5.0, 10.0, 15.0)
robot.movimiento_lineal_con_velocidad(3.0, 6.0, 9.0, 1.5)
robot.activar_gripper()