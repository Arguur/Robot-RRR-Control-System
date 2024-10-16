from Controlador import Controlador, re

class Robot:
    def __init__(self, modo_coordenadas, x, y, z, gripper, conectado=False, motores=False):
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
        if self.modo_coordenadas == 0:
            Controlador.escribir(f"G1 X{x} Y{y} Z{z} F100\r\n")
        else:
            Controlador.escribir(f"G1 X{x-self.x} Y{y-self.y} Z{z-self.z} F100\r\n")
        respuesta = Controlador.leer()
        if "error" in respuesta.lower():
            raise Exception("ERROR: POINT IS OUTSIDE OF WORKSPACE")
        else:
            coordenadas = re.findall(r'X:(-?\d+\.\d+)\sY:(-?\d+\.\d+)\sZ:(-?\d+\.\d+)\sE:(-?\d+\.\d+)', respuesta)
            self.x, self.y, self.z, self.gripper = map(float, coordenadas[0])
        return respuesta



    # Movimiento lineal con x, y, z y velocidad v
    def movimiento_lineal_con_velocidad(self, x, y, z, v):
        if self.modo_coordenadas == 0:
            Controlador.escribir(f"G1 X{x} Y{y} Z{z} F{v}\r\n")
        else:
            Controlador.escribir(f"G1 X{x-self.x} Y{y-self.y} Z{z-self.z} F{v}\r\n")
        respuesta = Controlador.leer()
        if "error" in respuesta.lower():
            raise Exception("ERROR: POINT IS OUTSIDE OF WORKSPACE")
        else:
            coordenadas = re.findall(r'X:(-?\d+\.\d+)\sY:(-?\d+\.\d+)\sZ:(-?\d+\.\d+)\sE:(-?\d+\.\d+)', respuesta)
            self.x, self.y, self.z, self.gripper = map(float, coordenadas[0])
        return respuesta
        

    # Activación del efector final (gripper)
    def activar_desactivar_gripper(self, activar):
        if activar==True:
            Controlador.escribir("M3")
            respuesta = Controlador.leer()
            if "info" in respuesta.lower():
                self.gripper = True
        if activar==False:
            Controlador.escribir("M5")
            respuesta = Controlador.leer()
            if "info" in respuesta.lower():
                self.gripper = False
        return respuesta

