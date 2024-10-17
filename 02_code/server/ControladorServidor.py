from Server import Server
from Controlador import Controlador
import re

class ControladorServidor:
    def __init__(self, servidor: Server):
        self.server = servidor

    def mostrar_ayuda(self) -> str:
        ayuda = (
            "+------------------------------------------------+\n"
            "|                MENSAJE DE AYUDA                |\n"
            "+------------------------------------------------+\n"
            "|  Comandos disponibles:                         |\n"
            "|  1. Conectar Robot: Se utiliza para            |\n"
            "|     establecer conexión con el robot.          |\n"
            "|     Ejemplo: conectar_robot(True)              |\n"
            "|                                                |\n"
            "|  2. Activar Motores: Permite activar o         |\n"
            "|     desactivar los motores del robot.          |\n"
            "|     Ejemplo: activar_motores(True)             |\n"
            "|                                                |\n"
            "|  3. Seleccionar Modo Trabajo: Cambia           |\n"
            "|     el modo de trabajo del robot.              |\n"
            "|     Ejemplo: modo_trabajo()                    |\n"
            "|                                                |\n"
            "|  4. Reporte General: Muestra el estado         |\n"
            "|     del sistema.                               |\n"
            "|     Ejemplo: reporte_informacion_general()     |\n"
            "|                                                |\n"
            "|  5. Ayuda: Muestra este mensaje.               |\n"
            "|     Ejemplo: mostrar_ayuda()                   |\n"
            "+------------------------------------------------+\n"
        )
        return ayuda

    def connexion_robot(self, conectar: bool) -> str:
        try:
            self.server.robot.conectado = conectar
            estado = "conectado" if conectar else "desconectado"
            return f"Robot {estado} con éxito."
        except Exception as e:
            return f"Error al intentar conectar el robot: {str(e)}"

    def activar_desactivar_motores(self, activar: bool) -> str:
        try:
            if self.server.robot.conectado is False:
                raise ValueError("El robot no está conectado.")
            if not self.server.robot.motores:
                self.server.controlador.escribir("M17")
                return "Motores activados con éxito"
            else:
                self.server.controlador.escribir("M18")
                return "Motores desactivados con éxito"
        except Exception as e:
            return f"Error al intentar activar/desactivar los motores: {str(e)}"

    def reporte_informacion_general(self):
        return self.server.controlador, self.server.robot, self.server.log_de_trabajo, self.server.estado_actividad_actual


    def reporte_log(self):
        self.server.log_de_trabajo.abrir_log()

    def modo_trabajo(self):
        try:
            if self.server.robot.conectado is False:
                raise ValueError("El robot no está conectado.")
            self.server.modo_trabajo = not self.server.modo_trabajo
            modo = "manual" if self.server.modo_trabajo else "automático"
            return f"Modo de trabajo cambiado a {modo}"
        except Exception as e:
            return f"Error al cambiar el modo de trabajo: {str(e)}"

    def modo_coordenadas(self):
        try:
            if self.server.robot.conectado is False:
                raise ValueError("El robot no está conectado.")
            if self.server.robot.modo_coordenadas:
                self.server.controlador.escribir("G90")
            else:
                self.server.controlador.escribir("G91")
            respuesta = self.server.controlador.leer()
            if "error" in respuesta.lower():
                raise Exception("El robot no respondio correctamente")
            self.server.robot.modo_coordenadas = True if "RELATIVE MODE" in respuesta else False
            modo = "relativo" if self.server.robot.modo_coordenadas else "absoluto"
            return f"Modo de coordenadas cambiado a {modo}"
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
        try:
            if self.server.robot.conectado is False:
                raise ValueError("El robot no está conectado.")
            self.server.controlador.escribir(f"G1 X{x} Y{y} Z{z} F100")
            respuesta = self.server.controlador.leer()
            if "error" in respuesta.lower():
                raise Exception("El punto esta fuera del espacio de trabajo")
            else:
                coordenadas = re.findall(r'X:(-?\d+\.\d+)\sY:(-?\d+\.\d+)\sZ:(-?\d+\.\d+)\sE:(-?\d+\.\d+)', respuesta)
                self.server.robot.x, self.server.robot.y, self.server.robot.z, self.server.robot.gripper = map(float, coordenadas[0])
            return respuesta
        except Exception as e:
            return f"Error al intentar mover Robot a ({x},{y},{z}) con una velocidad {velocidad}: {str(e)}"

    def movimiento_lineal_con_velocidad(self, x: float, y: float, z: float, velocidad: float):
        try:
            if self.server.robot.conectado is False:
                raise ValueError("El robot no está conectado.")
            self.server.controlador.escribir(f"G1 X{x} Y{y} Z{z} F{velocidad}")
            respuesta = self.server.controlador.leer()
            if "error" in respuesta.lower():
                raise Exception("El punto esta fuera del espacio de trabajo")
            else:
                coordenadas = re.findall(r'X:(-?\d+\.\d+)\sY:(-?\d+\.\d+)\sZ:(-?\d+\.\d+)\sE:(-?\d+\.\d+)', respuesta)
                self.server.robot.x, self.server.robot.y, self.server.robot.z, self.server.robot.gripper = map(float, coordenadas[0])
            return respuesta
        except Exception as e:
            return f"Error al intentar mover Robot a ({x},{y},{z}) con una velocidad {velocidad}: {str(e)}"

    def procesar_comando_gcode(self):
        pass

    def activar_desactivar_gripper(self):
        try:
            if self.server.robot.conectado is False:
                raise ValueError("El robot no está conectado.")
            if self.server.robot.gripper == False:
                self.server.controlador.escribir("M3")
                respuesta = self.server.controlador.leer()
                if "info" in respuesta.lower():
                    self.server.robot.gripper = True
                    return respuesta
                else:
                    raise Exception("El robot no confirmo la activación del gripper")
            if self.server.robot.gripper == True:
                self.server.controlador.escribir("M5")
                respuesta = self.server.controlador.leer()
                if "info" in respuesta.lower():
                    self.server.robot.gripper = False
                    return respuesta
                else:
                    raise Exception("El robot no confirmo la desactivación del gripper")
            
        except Exception as e:
            return f"Error al intentar activar/desactivar el gripper: {str(e)}"
        
    def realizar_homing(self):
        try:
            if self.server.robot.conectado is False:
                raise ValueError("El robot no está conectado.")
            self.server.controlador.escribir("G28")
            self.server.controlador.leer()
            respuesta = self.server.controlador.leer()
            if "info" in respuesta.lower():
                tiempo = re.search(r't=(\d+\.\d+)s', respuesta)
                return f"Homing realizado con éxito en {tiempo.group(1)} segundos"
            else:
                raise Exception("El robot no confirmo el homing")
        except Exception as e:
            return f"Error al intentar realizar el homing: {str(e)}"
        