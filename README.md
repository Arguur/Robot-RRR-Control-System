#  Sistema de Control Remoto para Robot RRR
### Arquitectura Cliente-Servidor con XML-RPC

Sistema distribuido para el control remoto de un robot RRR (3 grados de libertad) mediante protocolo XML-RPC. Implementa una arquitectura cliente-servidor donde el servidor gestiona la comunicación con el hardware y múltiples clientes pueden conectarse remotamente para controlar el robot.

![Python](https://img.shields.io/badge/Python-3.9-blue)
![C++](https://img.shields.io/badge/C%2B%2B-17-green)
![XML-RPC](https://img.shields.io/badge/Protocol-XMLRPC-orange)

##  Características

### Servidor (Python)
- ✅ Control del robot vía puerto serial (G-code)
- ✅ Servidor XML-RPC para múltiples clientes
- ✅ Log detallado de actividades con timestamps
- ✅ Sistema de autenticación de usuarios
- ✅ Modos de trabajo: Manual y Automático
- ✅ Sistemas de coordenadas: Absoluto y Relativo

### Cliente (C++)
- ✅ Interfaz de línea de comandos interactiva
- ✅ Conexión remota al servidor
- ✅ Control completo del robot (movimientos, gripper, homing)
- ✅ Visualización de estado en tiempo real
- ✅ Manejo robusto de errores

### Funcionalidades del Robot
-  Movimientos lineales con velocidad configurable
-  Control de gripper (abrir/cerrar)
-  Homing automático
-  Reporte de posición actual
-  Cambio entre modos absoluto/relativo

##  Arquitectura
```
┌─────────────────┐         XML-RPC          ┌─────────────────┐
│   Cliente C++   │ ◄──────────────────────► │  Servidor Python│
│                 │      localhost:8080      │                 │
│  - Vista        │                          │  - Controlador  │
│  - Controlador  │                          │  - Robot        │
│  - Conexión     │                          │  - Log          │
└─────────────────┘                          └────────┬────────┘
                                                      │
                                                      │ Serial
                                                      ▼
                                              ┌─────────────────┐
                                              │   Robot RRR     │
                                              │   (Hardware)    │
                                              └─────────────────┘
```

##  Requisitos

### Servidor (Python)
```bash
python >= 3.9
pyserial
```

### Cliente (C++)
```bash
g++ (C++17)
xmlrpc-c library
ws2_32 (Windows)
```

##  Instalación

### 1. Clonar el repositorio
```bash
git clone https://github.com/JuanMaDeMiguel/TPI.git
cd TPI
```

### 2. Configurar el Servidor
```bash
# Instalar dependencias
pip install pyserial

# Configurar puerto serial en main.py
# Línea 27: puerto="COM6"  # Cambiar según tu sistema
```

### 3. Compilar el Cliente

**Windows:**
```bash
g++ 02_code/client/*.cpp 02_code/libs/*.cpp -I 02_code/libs -lws2_32 -o cliente.exe
```

**Linux:**
```bash
g++ 02_code/client/*.cpp 02_code/libs/*.cpp -I 02_code/libs -lpthread -o cliente
```

## 🚀 Uso

### Iniciar el Servidor
```bash
cd 02_code/server
python main.py
```

**Menú del Servidor:**
```
+-------------------------------------------------------+
|  Panel de control servidor Robot (usuario)            |
+-------------------------------------------------------+
|  (1) Conexión / desconexión de Robot                  |
|  (2) Activación / desactivación de motores            |
|  (3) Selección de modo de trabajo                     |
|  (4) Control (en base a modo trabajo)                 |
|  (5) Reporte de información general                   |
|  (6) Reporte log de trabajo del servidor              |
+-------------------------------------------------------+
```

### Conectar Cliente
```bash
./cliente
```

**Credenciales de ejemplo:**
- Usuario: `admin`
- Password: `1234`
- Alias: `ClienteLab1`

**Menú del Cliente:**
```
+-------------------------------------------------------+
|  Panel de control Robot RRR (Cliente)                 |
+-------------------------------------------------------+
|  (1) Conexión / desconexión de Robot                  |
|  (2) Activación / desactivación de motores            |
|  (3) Selección de modo de trabajo                     |
|  (4) Control (en base a modo trabajo)                 |
|  (5) Reporte de información general                   |
|  (6) Reporte log de trabajo del servidor              |
+-------------------------------------------------------+
```

##  Estructura del Proyecto
```
TPI/
├── 01_UML/                    # Diagramas de diseño
├── 02_code/
│   ├── server/                # Código del servidor Python
│   │   ├── main.py
│   │   ├── Server.py
│   │   ├── Robot.py
│   │   ├── Controlador.py
│   │   ├── ControladorServidor.py
│   │   ├── InterfazServidor.py
│   │   ├── Log_de_trabajo.py
│   │   ├── Actividad.py
│   │   └── User.py
│   │
│   ├── client/                # Código del cliente C++
│   │   ├── main.cpp
│   │   ├── vistaCliente.cpp
│   │   ├── vistaCliente.h
│   │   ├── controladorCliente.cpp
│   │   ├── controladorCliente.h
│   │   ├── conexionServidor.cpp
│   │   └── conexionServidor.h
│   │
│   └── libs/                  # Librerías XML-RPC
│
├── 03_anexo/                  # Logs y documentación
│   ├── log_de_trabajo.csv
│   └── Informe.docx
│
└── README.md
```

##  Protocolo de Comunicación

### Comandos G-code Soportados

| Comando | Descripción | Ejemplo |
|---------|-------------|---------|
| `G1` | Movimiento lineal | `G1 X100 Y50 Z30 F100` |
| `G28` | Homing | `G28` |
| `G90` | Modo absoluto | `G90` |
| `G91` | Modo relativo | `G91` |
| `M17` | Activar motores | `M17` |
| `M18` | Desactivar motores | `M18` |
| `M3` | Activar gripper | `M3` |
| `M5` | Desactivar gripper | `M5` |
| `M114` | Reporte de posición | `M114` |

### Métodos XML-RPC

| Método | Parámetros | Descripción |
|--------|------------|-------------|
| `connexion_robot` | `(bool)` | Conectar/desconectar robot |
| `activar_desactivar_motores` | `()` | Toggle motores |
| `modo_trabajo` | `()` | Cambiar modo manual/automático |
| `modo_coordenadas` | `()` | Cambiar absoluto/relativo |
| `movimiento_lineal` | `(x, y, z)` | Mover a posición |
| `movimiento_lineal_con_velocidad` | `(x, y, z, vel)` | Mover con velocidad |
| `activar_desactivar_gripper` | `()` | Toggle gripper |
| `realizar_homing` | `()` | Ejecutar homing |

##  Contexto Académico

**Materia:** POO 
**Carrera:** Ingeniería en Mecatrónica  
**Universidad:** Universidad Nacional de Cuyo
**Año:** 2024

### Objetivos del Proyecto
- Implementar arquitectura cliente-servidor con XML-RPC
- Aplicar patrones de diseño (MVC, Observer)
- Gestionar comunicación serial con hardware
- Desarrollar sistema multi-usuario con logs
- Integrar Python y C++ en un sistema distribuido

##  Equipo

- **Juan Marcos De Miguel** ([@JuanMaDeMiguel](https://github.com/JuanMaDeMiguel))
- **Juan Francisco Huertas Coppo** ([@Arguur](https://github.com/Arguur))
- **Joaquín Alcalde** ([@joacalde](https://github.com/joacalde))
- **Julián Andrés Rayes Cano** ([@Lianju0](https://github.com/Lianju0))

##  Solución de Problemas

**Error: "No se puede abrir el puerto serial"**
```bash
# Verificar puertos disponibles
python -m serial.tools.list_ports

# Actualizar en main.py línea 27
```

**Error: "Connection refused" en cliente**
```bash
# Verificar que el servidor esté corriendo
# Verificar firewall en puerto 8080
```

##  Licencia

Este proyecto es parte de un trabajo académico universitario.

---

 **Proyecto Académico 2024** - Ingeniería en Mecatrónica
```


### .gitignore
```
# Python
__pycache__/
*.pyc
*.pyo
*.egg-info/
venv/

# C++
*.o
*.exe
*.out
cliente
servidor

# Logs
03_anexo/log_de_trabajo.csv

# IDEs
.vscode/
.idea/
*.swp

# OS
.DS_Store
Thumbs.db
