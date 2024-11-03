# ESP32 REST Client for ThirstySeed

## Summary
Este proyecto es un sistema embebido desarrollado por el equipo **IoTeam** para el proyecto **ThirstySeed**, diseñado para recopilar registros de humedad y temperatura. Los datos se obtienen a través de un sensor DHT22, se muestran en una pantalla LCD, y se envían mediante una solicitud HTTP PUT al backend de nuestra aplicación. Este proyecto está implementado en C++ dentro del entorno de Arduino.

## Hardware
- ESP32 DevKit v1
- DHT22 (sensor de temperatura y humedad)
- Pantalla LCD 16x2
- Potenciómetro para ajuste de contraste de la pantalla

## Libraries
- **WiFi**: Para conectarse a una red WiFi.
- **HTTPClient**: Para manejar las solicitudes HTTP.
- **ArduinoJson**: Para construir y analizar datos JSON.
- **DHT sensor library for ESPx**: Para leer datos del sensor DHT22.
- **LiquidCrystal**: Para controlar la pantalla LCD.

## API Endpoint
La API para actualizar los datos de humedad se encuentra en:
`https://thirstyseedapi-production.up.railway.app/api/v1/node/{NODE_ID}/moisture`


## Funcionamiento
1. **Conexión WiFi**: El sistema se conecta a una red WiFi.
2. **Lectura de Sensores**: Lee los valores de temperatura y humedad del sensor DHT22.
3. **Visualización en LCD**: Muestra los valores de temperatura y humedad en la pantalla LCD.
4. **Envío de Datos al Backend**: Envía el valor de humedad al backend usando una solicitud PUT en formato JSON.
    - En caso de redirección (códigos HTTP 301 o 302), sigue la URL indicada en la cabecera `Location` y vuelve a enviar la solicitud.

## External Services
La API está desplegada en Railway (https://railway.app/).

## Estructura del JSON
La estructura del JSON enviada al endpoint es la siguiente:
```json
{
  "moisture": <humedad_actual>
}
