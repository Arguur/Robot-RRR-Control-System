from ControladorServidor import ControladorServidor
import os

class InterfazServidor:
    def __init__(self, controlador_servidor: ControladorServidor):
        self.controlador_servidor = controlador_servidor
    
    def limpiar_pantalla(self):
        os.system('cls' if os.name == 'nt' else 'clear')

    def mostrar_menu_usuario(self):
        self.limpiar_pantalla()
        print("""
+-------------------------------------------------------+
|  Panel de control servidor Robot (usuario)            |
+-------------------------------------------------------+
|  (0) Ayuda                                            |
|  (1) Conexión / desconexión de Robot                  |
|  (2) Activación / desactivación de motores            |
|  (3) Selección de modo de trabajo                     |
|  (4) Control (en base a modo trabajo)                 |
|  (5) Reporte de información general                   |
|  (6) Reporte log de trabajo del servidor              |
+-------------------------------------------------------+
""")
        self.seleccionar_opcion_usuario()

    def mostrar_menu_admin(self):
        print("""
+-------------------------------------------------------+
|  Panel de control servidor Robot (administrador)      |
+-------------------------------------------------------+
|  (0) Ayuda                                            |
|  (1) Conexión / desconexión de Robot                  |
|  (2) Activación / desactivación de motores            |
|  (3) Selección de modo de trabajo                     |
|  (4) Control (en base a modo trabajo)                 |
|  (5) Reporte de información general                   |
|  (6) Reporte log de trabajo del servidor              |
|  (7) Mostrar / editar parámetros de conexión          |
|  (8) Encender / apagar servidor RPC                   |
|  (9) Mostrar ultimas 100 líneas log de trabajo        |
+-------------------------------------------------------+
""")
        self.seleccionar_opcion_admin()

    def seleccionar_opcion_usuario(self):
        opcion = input("Seleccione una opción: ")
        if opcion == "0":
            self.mostrar_ayuda()
        elif opcion == "1":
            self.menu_conexion_robot()
        elif opcion == "2":
            self.menu_motores()
        elif opcion == "3":
            self.menu_modo_trabajo()
        elif opcion == "4":
            self.menu_control()
        elif opcion == "5":
            controlador, robot, log_de_trabajo, estado_actividad_actual = self.controlador_servidor.reporte_informacion_general()
    
            # Estado de conexión
            estado_conexion = f"Puerto: {controlador.puerto}, Baudrate: {controlador.baudrate}, Timeout: {controlador.time_out}"
            print(estado_conexion)
    
            # Posición del robot
            posicion = f"x: {robot.x}, y: {robot.y}, z: {robot.z}"
            print(posicion)
    
            # Estado de actividad actual
            estado_actividad = "Finalizada" if estado_actividad_actual else "En proceso"
            print(f"Estado de actividad actual: {estado_actividad}")
    
            # Detalle de actividades en el log de trabajo
            print("\nOrden\tDetalle\tIP\tEstado\tMarca de Tiempo")
            for actividad in log_de_trabajo.actividades:
                estado = "Éxito" if actividad.exito else "Fallo"
                print(f"{actividad.orden}\t{actividad.detalle}\t{actividad.user.ip}\t{estado}\t{actividad.marcaTiempo}")
    
            # Cantidad de actividades
            cantidad_actividades = f"Cantidad de actividades: {len(log_de_trabajo.actividades)}"
            print(cantidad_actividades)
        elif opcion == "6":
            self.controlador_servidor.reporte_log()
        else:
            print("Opción no válida.")

    def seleccionar_opcion_admin(self):
        opcion = input("Seleccione una opción: ")
        if opcion == "0":
            print(self.controlador_servidor.mostrar_ayuda())
        elif opcion == "1":
            self.menu_conexion_robot()
        elif opcion == "2":
            self.menu_motores()
        elif opcion == "3":
            self.menu_modo_trabajo()
        elif opcion == "4":
            self.menu_control()
        elif opcion == "5":
            controlador, robot, log_de_trabajo, estado_actividad_actual = self.controlador_servidor.reporte_informacion_general()
    
            # Estado de conexión
            estado_conexion = f"Puerto: {controlador.puerto}, Baudrate: {controlador.baudrate}, Timeout: {controlador.time_out}"
            print(estado_conexion)
    
            # Posición del robot
            posicion = f"x: {robot.x}, y: {robot.y}, z: {robot.z}"
            print(posicion)
    
            # Estado de actividad actual
            estado_actividad = "Finalizada" if estado_actividad_actual else "En proceso"
            print(f"Estado de actividad actual: {estado_actividad}")
    
            # Detalle de actividades en el log de trabajo
            print("\nOrden\tDetalle\tIP\tEstado\tMarca de Tiempo")
            for actividad in log_de_trabajo.actividades:
                estado = "Éxito" if actividad.exito else "Fallo"
                print(f"{actividad.orden}\t{actividad.detalle}\t{actividad.user.ip}\t{estado}\t{actividad.marcaTiempo}")
    
            # Cantidad de actividades
            cantidad_actividades = f"Cantidad de actividades: {len(log_de_trabajo.actividades)}"
            print(cantidad_actividades)

        elif opcion == "6":
            self.controlador_servidor.reporte_log()
        elif opcion == "7":
            try:
                controlador = self.controlador_servidor.mostrar_parametros_conexion()
                print(f"Puerto: {controlador.puerto}, Baudrate: {controlador.baudrate}, Timeout: {controlador.time_out}")
            except (ValueError, AttributeError, RuntimeError) as e:
                print(f"Error al mostrar los parámetros de conexión: {str(e)}")

        elif opcion == "8":
            self.controlador_servidor.encender_servidor()
        elif opcion == "9":
            print("Mostrar ultimas 100 líneas del log no implementado todavía.")
        else:
            print("Opción no válida.")

    def mostrar_ayuda(self) -> str:

        print("""
+------------------------------------------------+
|                MENSAJE DE AYUDA                |
+------------------------------------------------+
|  Comandos disponibles:                         |
|  1. Conectar Robot: Se utiliza para            |
|     establecer conexión con el robot.          |
|     Ejemplo: conectar_robot(True)              |
|                                                |
|  2. Activar Motores: Permite activar o         |
|     desactivar los motores del robot.          |
|     Ejemplo: activar_motores(True)             |
|                                                |
|  3. Seleccionar Modo Trabajo: Cambia           |
|     el modo de trabajo del robot.              |
|     Ejemplo: modo_trabajo()                    |
|                                                |
|  4. Reporte General: Muestra el estado         |
|     del sistema.                               |
|     Ejemplo: reporte_informacion_general()     |
|                                                |
|  5. Ayuda: Muestra este mensaje.               |
|     Ejemplo: mostrar_ayuda()                   |
+------------------------------------------------+
""")
        input("Presione enter para regresar al menu principal.")

    def menu_conexion_robot(self):
        self.limpiar_pantalla()
        estado = "conectado" if self.controlador_servidor.server.robot.conectado else "desconectado"
        estado_string = f"Estado actual: [{estado}]"
        estado_string = f"  {estado_string.ljust(53)}"
        print(f"""
+-------------------------------------------------------+
|  1. Conexión / desconexión de Robot                   |
+-------------------------------------------------------+
|{estado_string}|
+-------------------------------------------------------+
|  (0) Ayuda                                            |
|  (1) Conectar                                         |
|  (2) Desconectar                                      |
|  (3) Volver                                           |
+-------------------------------------------------------+
""")
        opcion = input("Seleccione una opción: ")
        if opcion == "0":
            print(self.controlador_servidor.mostrar_ayuda())
        elif opcion == "1":
            print(self.controlador_servidor.connexion_robot(True))
        elif opcion == "2":
            print(self.controlador_servidor.connexion_robot(False))
        elif opcion == "3":
            return
        else:
            print("Opción no válida.")

    def menu_motores(self):
        self.limpiar_pantalla()
        estado = "activados" if self.controlador_servidor.server.robot.motores else "desactivados"
        estado_string = f"Estado actual: [{estado}]"
        estado_string = f"  {estado_string.ljust(53)}"
        print(f"""
+-------------------------------------------------------+
|  2. Activación / desactivación de motores             |
+-------------------------------------------------------+
|{estado_string}|
+-------------------------------------------------------+
|  (0) Ayuda                                            |
|  (1) Activar                                          |
|  (2) Desactivar                                       |
|  (3) Volver                                           |
+-------------------------------------------------------+
""")
        opcion = input("Seleccione una opción: ")
        if opcion == "0":
            print(self.controlador_servidor.mostrar_ayuda())
        elif opcion == "1":
            print(self.controlador_servidor.activar_desactivar_motores(True))
        elif opcion == "2":
            print(self.controlador_servidor.activar_motores(False))
        elif opcion == "3":
            return
        else:
            print("Opción no válida.")

    def menu_modo_trabajo(self):
        self.limpiar_pantalla()
        instruccion = "manual" if not self.controlador_servidor.server.modo_trabajo else "automático"
        coordenadas = "absoluto" if not self.controlador_servidor.server.robot.modo_coordenadas else "relativo"
        instruccion_string = f"Tipo de instrucción: [{instruccion}]"
        coordenadas_string = f"Sistema de coordenadas: [{coordenadas}]"
        instruccion_string = f"  {instruccion_string.ljust(53)}"
        coordenadas_string = f"  {coordenadas_string.ljust(53)}"
        print(f"""
+-------------------------------------------------------+
|  3. Selección de modo de trabajo                      |
+-------------------------------------------------------+
|  Estado actual:                                       |
|{instruccion_string}|
|{coordenadas_string}|
+-------------------------------------------------------+
|  (0) Ayuda                                            |
|  (1) Cambiar tipo de instrucción                      |
|  (2) Cambiar sistema de coordenadas                   |
|  (3) Volver                                           |
+-------------------------------------------------------+
""")
        opcion = input("Seleccione una opción: ")
        if opcion == "0":
            print(self.controlador_servidor.mostrar_ayuda())
        elif opcion == "1":
            print(self.controlador_servidor.modo_trabajo())
        elif opcion == "2":
            print(self.controlador_servidor.modo_coordenadas())
        elif opcion == "3":
            return
        else:
            print("Opción no válida.")

    def menu_control(self):
        while True:
            self.limpiar_pantalla()
            if not self.controlador_servidor.server.modo_trabajo:  # Modo manual
                robot = self.controlador_servidor.server.robot
                posicion_actual = f"x: {robot.x}, y: {robot.y}, z: {robot.z}"
                estado_gripper = "abierto" if not robot.gripper else "cerrado"
                modo_coordenadas = "absoluto" if not robot.modo_coordenadas else "relativo"
                posicion_string = f"Posición actual: [{posicion_actual}]"
                gripper_string = f"Estado del gripper: [{estado_gripper}]"
                modo_coordenadas_string = f"Modo de coordenadas: [{modo_coordenadas}]"
                posicion_string = f"  {posicion_string.ljust(53)}"
                gripper_string = f"  {gripper_string.ljust(53)}"
                modo_coordenadas_string = f"  {modo_coordenadas_string.ljust(53)}"
                print(f"""
+-------------------------------------------------------+
|  Control en modo manual                               |
|{modo_coordenadas_string}|
+-------------------------------------------------------+
|{posicion_string}|
|{gripper_string}|
+-------------------------------------------------------+
|  (0) Ayuda                                            |
|  (1) Cambiar estado del gripper                       |
|  (2) Realizar homing                                  |
|  (3) Realizar movimiento                              |
|  (4) Cambiar el modo de coordenadas                   |
|  (5) Volver al menu principal                         |
+-------------------------------------------------------+
    """)
                opcion = input("Seleccione una opción: ")
                if opcion == "0":
                    print(self.controlador_servidor.mostrar_ayuda())
                elif opcion == "1":
                    print(self.controlador_servidor.activar_desactivar_gripper())
                elif opcion == "2":
                    print(self.controlador_servidor.realizar_homing())
                elif opcion == "3":
                    x = float(input("Ingrese la coordenada X: "))
                    y = float(input("Ingrese la coordenada Y: "))
                    z = float(input("Ingrese la coordenada Z: "))
                    v_string = input("Ingrese la velocidad, enter para usar velocidad por defecto: 100mm/s: ")
                    v = float(v_string) if v_string else None
                    if v:
                        print(self.controlador_servidor.movimiento_lineal_con_velocidad(x, y, z, v))
                    else:
                        print(self.controlador_servidor.movimiento_lineal(x, y, z))
                elif opcion == "4":
                    print(self.controlador_servidor.modo_coordenadas())
                elif opcion == "5":
                    return
                else:
                    print("Opción no válida.")
            else:
                print("Control en modo automático no implementado todavía.")