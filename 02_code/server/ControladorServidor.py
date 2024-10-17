from Server import Server
from Controlador import Controlador

class ControladorServidor:
    def __init__(self, servidor: Server):
        self.server = servidor

    def mostrar_ayuda(self) -> str:
        ayuda = (
            "+-----------------------------------------+\n"
            "|           MENSAJE DE AYUDA               |\n"
            "+-----------------------------------------+\n"
            "|  Comandos disponibles:                  |\n"
            "|  1. Conectar Robot: Se utiliza para     |\n"
            "|     establecer conexión con el robot.   |\n"
            "|     Ejemplo: conectar_robot(True)       |\n"
            "|                                         |\n"
            "|  2. Activar Motores: Permite activar o  |\n"
            "|     desactivar los motores del robot.   |\n"
            "|     Ejemplo: activar_motores(True)      |\n"
            "|                                         |\n"
            "|  3. Seleccionar Modo Trabajo: Cambia    |\n"
            "|     el modo de trabajo del robot.       |\n"
            "|     Ejemplo: modo_trabajo()             |\n"
            "|                                         |\n"
            "|  4. Reporte General: Muestra el estado  |\n"
            "|     del sistema.                        |\n"
            "|     Ejemplo: reporte_informacion_general()|\n"
            "|                                         |\n"
            "|  5. Ayuda: Muestra este mensaje.        |\n"
            "|     Ejemplo: mostrar_ayuda()            |\n"
            "+-----------------------------------------+\n"
        )
        return ayuda

    def connexion_robot(self, conectar: bool) -> str:
        try:
            self.server.robot.conectado = conectar
            estado = "conectado" if conectar else "desconectado"
            return f"Robot {estado} con éxito."
        except Exception as e:
            return f"Error al intentar conectar el robot: {str(e)}"

    def activar_motores(self, activar: bool) -> str:
        try:
            self.server.robot.motores = activar
            estado = "activados" if activar else "desactivados"
            return f"Motores {estado} con éxito."
        except Exception as e:
            return f"Error al intentar activar/desactivar los motores: {str(e)}"

    def reporte_informacion_general(self):
        return self.server.controlador, self.server.robot, self.server.log_de_trabajo, self.server.estado_actividad_actual


    def reporte_log(self):
        self.server.log_de_trabajo.abrir_log()

    def modo_trabajo(self):
        try:
            self.server.modo_trabajo = not self.server.modo_trabajo
            return f"Modo de trabajo cambiado a {self.server.modo_trabajo}"
        except Exception as e:
            return f"Error al cambiar el modo de trabajo: {str(e)}"

    def modo_coordenadas(self):
        try:
            self.server.modo_coordenadas = not self.server.modo_coordenadas
            return f"Modo de coordenadas cambiado a {self.server.modo_coordenadas}"
        except Exception as e:
            return f"Error al cambiar el modo de coordenadas: {str(e)}"


    def mostrar_parametros_conexion(self) -> Controlador:
        try:
            controlador = self.server.controlador
            if controlador is None:
                raise ValueError("El controlador no está configurado.")
            return controlador
        except AttributeError as e:
            raise AttributeError(f"Error de atributo: {str(e)}")
        except Exception as e:
            raise RuntimeError(f"Error inesperado al obtener el controlador: {str(e)}")


    def editar_parametros_conexion(self, puerto: str, baudrate: int, timeout: int):
        try:
            self.server.controlador.puerto = puerto
            self.server.controlador.baudrate = baudrate
            self.server.controlador.time_out = timeout
            return f"Se han actualizado los parametros de conexión a: puerto: {puerto}, baudrate: {baudrate}, timeout: {timeout} con éxito"
        except Exception as e:
            return f"Error al intentar actualizar los parametros de conexión a: puerto: {puerto}, baudrate: {baudrate}, timeout: {timeout}: {str(e)}"

    def encender_servidor(self):
        pass

    def movimiento_lineal(self, x: float, y: float, z: float):
        self.server.robot.movimiento_lineal(x, y, z)

    def movimiento_lineal_con_velocidad(self, x: float, y: float, z: float, velocidad: float):
        try:
            self.server.robot.movimiento_lineal_con_velocidad(x, y, z, velocidad)
            return f"Robot se ha movido a ({x},{y},{z}) con una velocidad: {velocidad} con éxito"
        except Exception as e:
            return f"Error al intentar mover Robot a ({x},{y},{z}) con una velocidad {velocidad}: {str(e)}"

    def procesar_comando_gcode(self):
        pass
