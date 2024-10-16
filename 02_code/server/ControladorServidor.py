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
        # Estado de conexión
        estado_conexion = f"Puerto: {self.server.controlador.puerto}, Baudrate: {self.server.controlador.baudrate}, Timeout: {self.server.controlador.time_out}"
        # Posición del robot
        posicion = f"x: {self.server.robot.x}, y: {self.server.robot.y}, z: {self.server.robot.z}"
        # Estado de actividad actual
        estado_actividad = "Finalizada" if self.server.estado_actividad_actual else "En proceso"
        # Detalle de actividades en el log de trabajo
        actividades = "\nOrden\tDetalle\tIP\tEstado\tMarca de Tiempo\n"
        for actividad in self.server.log_de_trabajo.actividades:
            estado = "Éxito" if actividad.exito else "Fallo"
            actividades += f"{actividad.orden}\t{actividad.detalle}\t{actividad.user.ip}\t{estado}\t{actividad.marcaTiempo}\n"
        # Cantidad de actividades
        cantidad_actividades = f"Cantidad de actividades: {len(self.server.log_de_trabajo.actividades)}"

    def reporte_log(self):
        self.server.log_de_trabajo.abrir_log()

    def modo_trabajo(self):
        self.server.modo_trabajo = True
        self.server.modo_coordenadas = False
        pass

    def modo_coordenadas(self):
        self.server.modo_coordenadas = True
        self.server.modo_trabajo = False
        pass

    def mostrar_parametros_conexion(self) -> Controlador:
        return self.server.controlador

    def editar_parametros_conexion(self, puerto: str, baudrate: int, timeout: int):
        self.server.controlador.puerto = puerto
        self.server.controlador.baudrate = baudrate
        self.server.controlador.time_out = timeout
        pass

    def encender_servidor(self):
        pass

    def movimiento_lineal(self, x: float, y: float, z: float):
        self.server.robot.movimiento_lineal(x, y, z)

    def movimiento_lineal_con_velocidad(self, x: float, y: float, z: float, velocidad: float):
        self.server.robot.movimiento_lineal_con_velocidad(x, y, z, velocidad)

    def procesar_comando_gcode(self):
        pass
