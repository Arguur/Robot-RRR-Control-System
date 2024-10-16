class Robot:
    def __init__(self, modo_coordenadas, x, y, z, gripper=False, conectado=False, motores=False):
        # Modo coordenadas
        self.modo_coordenadas = modo_coordenadas
        # Coordenadas del robot
        self.x = float(x)
        self.y = float(y)
        self.z = float(z)
        # Estados del robot
        self.gripper = bool(gripper)
        self.conectado = bool(conectado)
        self.motores = bool(motores)

    # Movimiento lineal con x, y, z
    def movimiento_lineal(self, x, y, z):
        self.x = float(x)
        self.y = float(y)
        self.z = float(z)
        print(f"Movimiento lineal ejecutado. Nueva posición: x={self.x}, y={self.y}, z={self.z}")

    # Movimiento lineal con x, y, z y velocidad v
    def movimiento_lineal_con_velocidad(self, x, y, z, v):
        self.x = float(x)
        self.y = float(y)
        self.z = float(z)
        print(f"Movimiento lineal ejecutado con velocidad {v}. Nueva posición: x={self.x}, y={self.y}, z={self.z}")

    # Activación del efector final (gripper)
    def activar_gripper(self):
        if not self.gripper:
            self.gripper = True
            velocidad_trabajo = 1.0  # Valor inicial para la velocidad de trabajo
            tiempo_operacion = 2.0   # Valor inicial para el tiempo de operación
            sentido_movimiento = "horario"  # Valor inicial para el sentido de movimiento
            print(f"Gripper activado. Velocidad de trabajo: {velocidad_trabajo}, Tiempo de operación: {tiempo_operacion}, Sentido de movimiento: {sentido_movimiento}")
        else:
            print("Gripper ya está activado.")