## Smart Home

![Device Photo](journal/SmartHome.2.jpeg)

A smart home is a device that can be connected to lights and home appliances to control them through a website that operates on the home's local network, with many great features.

## Custom Features

- Powerful ESP32 controller with Wi-Fi connectivity.
- Neon-style web interface that performs perfectly on PCs and smartphones.
- Mobile Stacking support for convenient vertical tile rearrangement on mobile screens.
- Background command execution via JavaScript Fetch for instant execution without page reloading.
- Intelligent timer system for automatic relay shutdown after a specified time.
- Independent control of 8 relay channels.
- Smart LAN handling to support the responsiveness of various devices connected to the local server.

# Web Interface Preview

![Web Interface](journal/website_screenshot.png)
This website controls the home and is connected to the ESP32 It operates only on the local network using the ESP's IP address.

## Hardware Components (BOM)

If you wish to build a similar home control panel, here are the hardware details:
- ESP32 Development Board
- 8-Channel Relay Module
- Female to Female Jumper Wires pack
- 5V Power / USB Cable

## Setup & Operation

1. Open the code in the Arduino IDE and enter your Wi-Fi name and password (`SSID` and `PASSWORD`).
2. Connect the ESP32 to your PC by USB and click the **Upload** button.
3. Open the **Serial Monitor** in the Arduino IDE to get the local IP address assigned to the ESP32.
4. Open any web browser on your PC or smartphone (must be connected to the same Wi-Fi), type the IP address into the URL bar, and start controlling the relays.

## Hardware Connections

| ESP32 Pin | Relay Module Pin |
|-----------|------------------|
| D19       | Relay 1          |
| D18       | Relay 2          |
| D5        | Relay 3          |
| D17       | Relay 4          |
| D16       | Relay 5          |
| D4        | Relay 6          |
| D2        | Relay 7          |
| D15       | Relay 8          |
| GND       | GND              |
| 5V / VIN  | VCC              |

