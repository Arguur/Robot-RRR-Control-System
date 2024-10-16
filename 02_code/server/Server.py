from User import User
from Robot import Robot
from LogDeTrabajo import LogDeTrabajo


class Server:
    def __init__(self, modo_trabajo, controlador):
        self.controlador = controlador
        self.modo_trabajo = modo_trabajo
        self.users = list()
        self.robot = Robot()
        self.logDeTrabajo = LogDeTrabajo()

    def validar_usuario(self, ip):
        for user in self.users:
            if user.ip == ip:
                return True
        return False

    def manejar_solicitud_RPC(self, solicitud_rpc) -> str:
        # Implementation will be added later
        pass