from ControladorServidor import ControladorServidor

class InterfazServidor:
    def __init__(self, controlador_servidor: ControladorServidor):
        self.controlador_servidor = controlador_servidor

    def mostrar_menu_usuario(self):
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
            print(self.controlador_servidor.mostrar_ayuda())
        elif opcion == "1":
            self.menu_conexion_robot()
        elif opcion == "2":
            self.menu_motores()
        elif opcion == "3":
            self.menu_modo_trabajo()
        elif opcion == "4":
            print("Control en base al modo de trabajo no implementado todavía.")
        elif opcion == "5":
            self.controlador_servidor.reporte_informacion_general()
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
            print("Control en base al modo de trabajo no implementado todavía.")
        elif opcion == "5":
            self.controlador_servidor.reporte_informacion_general()
        elif opcion == "6":
            self.controlador_servidor.reporte_log()
        elif opcion == "7":
            controlador = self.controlador_servidor.mostrar_parametros_conexion()
            print(f"Parámetros actuales: Puerto={controlador.puerto}, Baudrate={controlador.baudrate}, Timeout={controlador.time_out}")
        elif opcion == "8":
            self.controlador_servidor.encender_servidor()
        elif opcion == "9":
            print("Mostrar ultimas 100 líneas del log no implementado todavía.")
        else:
            print("Opción no válida.")

    def menu_conexion_robot(self):
        print("""
+-------------------------------------------------------+
|  1. Conexión / desconexión de Robot                   |
+-------------------------------------------------------+
|  Estado actual: [conectado/desconectado]              |
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
            self.controlador_servidor.connexion_robot(True)
        elif opcion == "2":
            self.controlador_servidor.connexion_robot(False)
        elif opcion == "3":
            return
        else:
            print("Opción no válida.")

    def menu_motores(self):
        print("""
+-------------------------------------------------------+
|  2. Activación / desactivación de motores             |
+-------------------------------------------------------+
|  Estado actual: [activados/desactivados]              |
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
            self.controlador_servidor.activar_motores(True)
        elif opcion == "2":
            self.controlador_servidor.activar_motores(False)
        elif opcion == "3":
            return
        else:
            print("Opción no válida.")

    def menu_modo_trabajo(self):
        print("""
+-------------------------------------------------------+
|  3. Selección de modo de trabajo                      |
+-------------------------------------------------------+
|  Estado actual:                                       |
|  Tipo de instrucción: [manual/automático]             |
|  Sistema de coordenadas: [absoluto/relativo]          |
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
            self.controlador_servidor.modo_trabajo()
        elif opcion == "2":
            self.controlador_servidor.modo_coordenadas()
        elif opcion == "3":
            return
        else:
            print("Opción no válida.")