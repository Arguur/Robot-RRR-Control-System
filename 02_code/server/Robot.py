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

        
    
    

