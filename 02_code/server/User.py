class User:
    def __init__(self, usuario="", clave="", ip=""):
        self._usuario = usuario
        self._clave = clave
        self._ip = ip

    # Getters
    def get_usuario(self):
        return self._usuario

    def get_clave(self):
        return self._clave

    def get_ip(self):
        return self._ip

    # Setters
    def set_usuario(self, usuario):
        self._usuario = usuario

    def set_clave(self, clave):
        self._clave = clave

    def set_ip(self, ip):
        self._ip = ip

