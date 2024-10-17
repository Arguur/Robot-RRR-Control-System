from User import User
from Robot import Robot
from Log_de_trabajo import Log_de_trabajo


class Server:
    def __init__(self, modo_trabajo, controlador):
        self.controlador = controlador
        self.modo_trabajo = modo_trabajo
        self.users = list()
        modo, x, y, z, e = controlador.inicializacion()
        self.robot = Robot(modo, x, y, z, e)
        self.log_de_trabajo = Log_de_trabajo()

    def validar_usuario(self, ip):
        for user in self.users:
            if user.ip == ip:
                return True
        return False

    def manejar_solicitud_RPC(self, solicitud_rpc) -> str:
        # Implementation will be added later
        pass