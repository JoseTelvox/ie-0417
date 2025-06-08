# Laboratorio 8 - Sistema de Autenticación

Este laboratorio implementa un sistema de autenticación simple con pruebas unitarias utilizando Google Test y Google Mock.

## Estructura del Proyecto

- `authentication.h`: Implementación de la clase Authentication que maneja el login y registro de usuarios
- `database.h`: Interfaz para la base de datos de usuarios
- `mock_database.h`: Implementación mock de la base de datos para pruebas
- `test_authentication.cpp`: Pruebas unitarias para el sistema de autenticación
- `test_random_seed.cpp`: Pruebas opcionales para la generación de semillas aleatorias
- `CMakeLists.txt`: Configuración del proyecto para CMake

## Requisitos

- CMake (versión 3.10 o superior)
- Compilador C++ con soporte para C++17
- Google Test y Google Mock
- pthread

## Instalación de Dependencias

### En macOS (usando Homebrew):

```bash
# Instalar CMake si no está instalado
brew install cmake

# Instalar Google Test y Google Mock
brew install googletest
```

### En Ubuntu/Debian:

```bash
# Instalar CMake si no está instalado
sudo apt-get install cmake

# Instalar Google Test y Google Mock
sudo apt-get install libgtest-dev
```

### En Windows (usando vcpkg):

```bash
# Instalar vcpkg si no está instalado
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh

# Instalar Google Test
vcpkg install gtest
```

## Compilación

Para compilar el proyecto:

```bash
mkdir build
cd build
cmake ..
make
```

## Ejecución de la Aplicación

Después de compilar el proyecto, puedes ejecutar la aplicación desde el directorio `build`:

```bash
# Ejecutar la aplicación principal
./random_seed
```

La aplicación implementa un sistema de autenticación que permite:
- Registrar nuevos usuarios
- Iniciar sesión con credenciales existentes

## Ejecución de Pruebas

El proyecto incluye dos conjuntos de pruebas:

1. Pruebas de Autenticación:
```bash
./test_authentication
```

2. Pruebas de Semilla Aleatoria (opcional):
```bash
./test_random_seed
```

## Funcionalidades Implementadas

- Sistema de login con verificación de credenciales
- Registro de nuevos usuarios
- Pruebas unitarias para validar el funcionamiento del sistema
- Mock de la base de datos para pruebas aisladas

## Notas

- El sistema utiliza una interfaz de base de datos abstracta que puede ser implementada de diferentes maneras
- Las pruebas utilizan Google Mock para simular el comportamiento de la base de datos
- El código está escrito siguiendo los estándares de C++17

## Solución de Problemas

Si encuentras el error `fatal error: 'gtest/gtest.h' file not found`:

1. Asegúrate de haber instalado Google Test correctamente usando los comandos de instalación anteriores
2. En macOS, verifica que los archivos de cabecera estén en `/opt/homebrew/include`
3. Si el problema persiste, puedes intentar:
   ```bash
   # En macOS
   brew reinstall googletest
   
   # Limpiar y reconstruir el proyecto
   cd build
   rm -rf *
   cmake ..
   make
   ``` 