# Laboratorio 04: Patrones de diseño en entrevistas técnicas

### Tabla de contenidos
1. [Investigación](#investigación)
2. [Análisis y aplicación de patrones](#análisis-y-aplicación-de-patrones)



## Investigación

## Casos de Uso

### Caso 1: 

<table>
  <tr>
    <th style="background-color:#004080; color:white; padding:8px;">Precondiciones</th>
    <th style="background-color:#004080; color:white; padding:8px;">Postcondiciones</th>
  </tr>
  <tr>
    <td style="padding:8px;">El usuario debe estar registrado e iniciado sesión.</td>
    <td style="padding:8px;">El pedido se registra en la base de datos y se envía una confirmación al usuario por correo.</td>
  </tr>
</table>

<br>

<table>
  <tr>
    <th style="background-color:#006400; color:white; padding:8px;">Flujo Principal</th>
    <th style="background-color:#006400; color:white; padding:8px;">Flujo Alternativo</th>
  </tr>
  <tr>
    <td style="padding:8px;">
      1. El usuario selecciona los productos del menú.<br>
      2. Añade los productos al carrito de compras.<br>
      3. Revisa el carrito y procede al pago.<br>
      4. El sistema procesa el pago y confirma el pedido.
    </td>
    <td style="padding:8px;">
      1. El usuario modifica el carrito antes de pagar.<br>
      3. El pago falla y el usuario intenta nuevamente.
    </td>
  </tr>
</table>

<br>

### Caso 2: Reservar mesa
<table>
  <tr>
    <th style="background-color:#004080; color:white; padding:8px;">Precondiciones</th>
    <th style="background-color:#004080; color:white; padding:8px;">Postcondiciones</th>
  </tr>
  <tr>
    <td style="padding:8px;">
      El usuario debe estar registrado e iniciado sesión.
    </td>
    <td style="padding:8px;">
      La reserva se registra en la base de datos y se envía una confirmación al usuario.
    </td>
  </tr>
</table>

<br>

<table>
  <tr>
    <th style="background-color:#006400; color:white; padding:8px;">Flujo Principal</th>
    <th style="background-color:#006400; color:white; padding:8px;">Flujo Alternativo</th>
  </tr>
  <tr>
    <td style="padding:8px;">
      1. El usuario inicia una conversación con el chatbot.<br>
      2. Proporciona detalles de la reserva (fecha, hora, número de personas).<br>
      3. El chatbot verifica la disponibilidad y confirma la reserva.
    </td>
    <td style="padding:8px;">
      2a. El usuario modifica los detalles de la reserva.<br>
      3a. No hay disponibilidad y el chatbot ofrece alternativas.
    </td>
  </tr>
</table>
<br>

#### Caso 3: Gestionar perfil de usuario
<table>
  <tr>
    <th style="background-color:#004080; color:white; padding:8px;">Precondiciones</th>
    <th style="background-color:#004080; color:white; padding:8px;">Postcondiciones</th>
  </tr>
  <tr>
    <td style="padding:8px;">
      El usuario debe estar registrado e iniciado sesión.  
    </td>
    <td style="padding:8px;">
      El perfil del usuario queda actualizado o eliminado según la acción realizada. Se notifican los cambios si corresponde.
    </td>
  </tr>
</table>

<table>
  <tr>
    <th style="background-color:#006400; color:white; padding:8px;">Flujo Principal</th>
    <th style="background-color:#006400; color:white; padding:8px;">Flujo Alternativo</th>
  </tr>
  <tr>
    <td style="padding:8px;">
      1. El usuario accede a la sección de perfil.<br>
      2. Visualiza su información personal.<br>
      3. Edita datos como nombre, correo o contraseña.<br>
      4. El sistema valida los cambios y actualiza la información.
    </td>
    <td style="padding:8px;">
      3a. El usuario solicita eliminar su cuenta. Se solicita confirmación.<br>
      4a. Los datos ingresados no son válidos. El sistema muestra errores y solicita correcciones.<br>
    </td>
  </tr>
</table>


## Diagrama UML

![Diagrama UML](./Lab06E05.png)
