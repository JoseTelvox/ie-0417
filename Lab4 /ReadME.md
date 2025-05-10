# Lab 4

## 1) ¿Cuál es la diferencia entre principios de diseño y patrones de diseño?

Los **principios de diseño** son seguidos durante el diseño del sistema de software en cualquier plataforma, sin importar el lenguaje de programación. Los principios **SOLID** son utilizados por los desarrolladores para crear implementaciones robustas, extensibles y escalables.

Los **patrones de diseño** son soluciones reutilizables para problemas comunes, que pueden personalizarse según los requisitos del problema. Son soluciones bien implementadas, probadas y seguras de usar.

---

## 2) Diseño de un sistema de logging global

**¿Cómo diseñarías un sistema que registre logs de múltiples microservicios y permita consultas eficientes?**

- **Escalabilidad:** Uso de colas de mensajería (Kafka, RabbitMQ) para manejar alta carga.
- **Almacenamiento:** Bases de datos distribuidas como Elasticsearch para búsquedas rápidas.

**Patrones de diseño utilizados:**

- **Observer:** Notificar a sistemas externos cuando ocurren eventos críticos.
- **Decorator:** Añadir funcionalidades de encriptación o formato de logs sin modificar el código base.
- **Singleton:** Garantiza una única instancia global para el manejo centralizado del registro.

### Ejemplo de Singleton en Python

```python
class Logger:
    _instance = None

    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(Logger, cls).__new__(cls)
        return cls._instance

    def log(self, message):
        print(f"[LOG] {message}")

# Ejemplo de uso:
logger1 = Logger()
logger2 = Logger()

logger1.log("Primera instancia")
logger2.log("Segunda instancia")

print(logger1 is logger2)  # True, ambos son la misma instancia
```
---
## 3) ¿Cómo diseñarías un sistema de notificaciones o feed, similar a Twitter, y comente el patrón de diseño que puede utilizar para ese requerimiento?

Para ello se puede utilizar el patrón de diseño llamado **Observer Pattern**, para cumplir con la tarea de seguimiento de usuarios y generación del feed. Ya que cuando un usuario A sigue a usuarios B, quiere ser notificado de los nuevos tweets de usuario B. El patrón Observer permite que los usuarios sean notificados de actualizaciones sin acoplamiento fuerte.

#### Código en Python usando el patrón de diseño Observer

```python
class User:
    def __init__(self, username):
        self.username = username
        self.followers = []
        self.feed = []

    def follow(self, other_user):
        other_user.add_follower(self)

    def add_follower(self, follower):
        self.followers.append(follower)

    def tweet(self, message):
        tweet = f"{self.username}: {message}"
        print(f"[TWEET] {tweet}")
        for follower in self.followers:
            follower.receive_tweet(tweet)

    def receive_tweet(self, tweet):
        self.feed.insert(0, tweet)  # Insertar al principio (orden cronológico inverso)

    def show_feed(self):
        print(f"\nFeed de {self.username}:")
        for tweet in self.feed:
            print(tweet)
```

---

## 4) ¿Cómo modelarías una aplicación que requiere múltiples algoritmos de ordenamiento intercambiables en tiempo de ejecución?

Diseñar una arquitectura que permita cambiar fácilmente entre distintos algoritmos de ordenamiento en tiempo de ejecución sin alterar el código cliente, manteniendo bajo acoplamiento.

#### Patrón de diseño adecuado: Strategy Pattern

Permite definir una familia de algoritmos, encapsular cada uno y hacerlos intercambiables. Este patrón permite que el algoritmo varíe independientemente de los clientes que los usan.

#### Justificación

| Criterio                                       | Strategy Pattern |
|-----------------------------------------------|------------------|
| Intercambio dinámico de comportamiento         | ✅               |
| Abstracción del algoritmo                      | ✅               |
| Bajo acoplamiento entre el cliente y algoritmos| ✅               |
| Fácil extensión con nuevos algoritmos          | ✅               |

#### Código en Java (Pseudocódigo)

```java
// Estrategia (interfaz común)
public interface SortStrategy {
    void sort(List<Integer> data);
}

// Algoritmos concretos
public class QuickSort implements SortStrategy {
    public void sort(List<Integer> data) {
        // implementación de quicksort
    }
}

public class MergeSort implements SortStrategy {
    public void sort(List<Integer> data) {
        // implementación de mergesort
    }
}

// Contexto
public class Sorter {
    private SortStrategy strategy;

    public void setStrategy(SortStrategy strategy) {
        this.strategy = strategy;
    }

    public void sort(List<Integer> data) {
        strategy.sort(data);
    }
}

// Uso en tiempo de ejecución
Sorter sorter = new Sorter();
sorter.setStrategy(new QuickSort());
sorter.sort(myData);

sorter.setStrategy(new MergeSort());
sorter.sort(myData);
```
## 5) ¿Cómo construirías una interfaz para distintos sistemas operativos sin acoplarte a uno específico?

Queremos construir una interfaz de aplicación que funcione en distintos sistemas operativos, sin acoplarnos directamente a las APIs específicas de cada sistema operativo, ya sea Windows, Linux o macOS.

Para este tipo de aplicaciones se recomienda el uso de **Abstract Factory**, permitiendo crear familias de objetos relacionados sin especificar sus clases concretas. Se define una interfaz para crear objetos, dejando que las subclases decidan qué objetos concretos instanciar. Esto permite ser independiente del sistema operativo, manteniendo una arquitectura limpia y escalable.

Una de las ventajas de este patrón de diseño es desacoplar completamente la lógica del sistema operativo; además, permite cambiar todo el conjunto de elementos visuales simplemente cambiando el proceso de fabricación. También es fácil de extender para nuevos sistemas operativos.

### Implementación sencilla en Python (Abstract Factory)

```python
# Interfaces
class Button:
    def render(self):
        raise NotImplementedError

class Window:
    def open(self):
        raise NotImplementedError

# Implementaciones para Windows
class WindowsButton(Button):
    def render(self):
        print("Botón estilo Windows")

class WindowsWindow(Window):
    def open(self):
        print("Ventana estilo Windows")

# Implementaciones para macOS
class MacButton(Button):
    def render(self):
        print("Botón estilo macOS")

class MacWindow(Window):
    def open(self):
        print("Ventana estilo macOS")

# Abstract Factory
class UIFactory:
    def create_button(self) -> Button:
        raise NotImplementedError

    def create_window(self) -> Window:
        raise NotImplementedError

# Factories concretas
class WindowsFactory(UIFactory):
    def create_button(self):
        return WindowsButton()

    def create_window(self):
        return WindowsWindow()

class MacFactory(UIFactory):
    def create_button(self):
        return MacButton()

    def create_window(self):
        return MacWindow()

# Cliente
def create_ui(factory: UIFactory):
    button = factory.create_button()
    window = factory.create_window()
    button.render()
    window.open()

# Uso
os_type = "mac"  # podría obtenerse del entorno

if os_type == "windows":
    factory = WindowsFactory()
else:
    factory = MacFactory()

create_ui(factory)
```

---

## 6) Diseñar un servicio de almacenamiento en la nube

Queremos modelar un sistema de almacenamiento en la nube que permita a los usuarios, como requisitos principales:

- Subir, descargar y eliminar archivos.  
- Sincronizar archivos entre dispositivos  
- Manejar distintos tipos de almacenamiento  
- Escalar para múltiples usuarios y dispositivos  

#### Uso de los patrones de diseño: Strategy y Composite

- **Strategy** permite elegir el backend de almacenamiento de forma dinámica, muy útil para entornos mixtos.
- **Composite** es ideal para manejar estructuras de archivos y carpetas de forma uniforme.

---

#### Strategy para el tipo de almacenamiento:

```python
# Interfaz común para almacenamiento
class StorageStrategy:
    def upload(self, filename, content): pass
    def download(self, filename): pass

# Estrategia: almacenamiento local
class LocalStorage(StorageStrategy):
    def upload(self, filename, content):
        with open(filename, 'w') as f:
            f.write(content)
        print(f"Archivo '{filename}' guardado localmente.")

    def download(self, filename):
        with open(filename, 'r') as f:
            return f.read()

# Estrategia: simulación de S3
class S3Storage(StorageStrategy):
    def upload(self, filename, content):
        print(f"Archivo '{filename}' subido a Amazon S3 (simulado).")

    def download(self, filename):
        return f"Contenido de '{filename}' desde S3 (simulado)"
```

---
