# Proyecto: Sistema con Docker Compose

## Arquitectura del Sistema

El sistema está compuesto por varios contenedores Docker orquestados mediante Docker Compose. La arquitectura incluye:

- **Aplicación principal**: Servicio web que corre en un contenedor.
- **Base de datos**: Contenedor que aloja la base de datos persistente.
- **Red interna**: Todos los contenedores están conectados a una red Docker privada para comunicación segura.
- **Volúmenes**: Se utilizan volúmenes Docker para persistir datos, logs y configuración, garantizando que la información no se pierda al reiniciar los contenedores.

### Diagrama de arquitectura


---

## Descripción de Archivos Clave

- **docker-compose.yml**  
  Archivo de configuración principal que define los servicios, redes y volúmenes del sistema.

- **Dockerfile**  
  Contiene las instrucciones para construir la imagen del contenedor de la aplicación.

- **.env**  
  Variables de entorno que configuran parámetros como puertos, credenciales y rutas.

- **src/**  
  Carpeta con el código fuente de la aplicación.

- **data/**  
  Volumen o carpeta usada para persistir los datos de la base de datos.

- **logs/**  
  Carpeta donde se almacenan los archivos de registro generados por la aplicación.

---

## Instrucciones para Ejecutar el Entorno desde Cero

1. **Clonar el repositorio**

```bash
git clone https://github.com/usuario/proyecto.git
cd proyecto
