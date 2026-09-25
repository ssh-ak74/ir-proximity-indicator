# IR Proximity Indicator

A simple **ESP32-based IR proximity indicator** that detects nearby objects using an infrared obstacle avoidance sensor and provides visual feedback through red and green LEDs.

Built as a small, beginner-friendly electronics project using an **ESP32 DevKit V1**, an IR obstacle sensor, LEDs, and resistors.

##  Features

*  Detects objects using an IR obstacle avoidance sensor
*  Green LED indicates a clear path
*  Red LED indicates an obstacle
*  Red LED flashes while an obstacle is detected
*  Outputs detection status through the Serial Monitor
*  Runs on an ESP32 DevKit V1
*  Built with commonly available components
*  PlatformIO project structure
*  MIT licensed

##  Hardware

| Component                             |  Quantity |
| ------------------------------------- | --------: |
| ESP32 DevKit V1                       |         1 |
| IR Infrared Obstacle Avoidance Sensor |         1 |
| Green LED                             |         1 |
| Red LED                               |         1 |
| 1 kΩ resistor                         |         2 |
| Breadboard                            |         1 |
| Jumper wires                          | As needed |

##  Wiring

### IR Sensor

The sensor used in this project has four pins:

| IR Sensor | ESP32     |
| --------- | --------- |
| `GND`     | `GND`     |
| `+`       | `3V3`     |
| `OUT`     | `GPIO 27` |
| `EN`      | `3V3`     |

### Green LED

```text
ESP32 GPIO 25
      │
     1kΩ
      │
   LED (+)
   LED (-)
      │
     GND
```

### Red LED

```text
ESP32 GPIO 26
      │
     1kΩ
      │
   LED (+)
   LED (-)
      │
     GND
```

### Complete Pin Map

| Function         | ESP32 Pin |
| ---------------- | --------- |
| IR Sensor OUT    | GPIO 27   |
| Green LED        | GPIO 25   |
| Red LED          | GPIO 26   |
| IR Sensor Power  | 3.3V      |
| IR Sensor Enable | 3.3V      |
| Ground           | GND       |

> **Note:** The 1 kΩ resistors are used to limit current through the LEDs.

##  How It Works

The IR sensor outputs a digital signal depending on whether an object is detected.

```text
IR OUT = HIGH
      ↓
No obstacle
      ↓
🟢 Green LED ON
🔴 Red LED OFF
```

```text
IR OUT = LOW
      ↓
Obstacle detected
      ↓
🟢 Green LED OFF
🔴 Red LED flashes
```

The ESP32 continuously reads GPIO 27 and changes the LED states accordingly.

##  Software

This project uses:

* **PlatformIO**
* **Arduino framework**
* **Espressif 32 platform**
* **ESP32 DevKit V1**

### Project Structure

```text
IR-Proximity-Indicator/
├── src/
│   └── main.cpp
├── platformio.ini
├── README.md
└── LICENSE
```

##  Building and Uploading

### Requirements

Install:

* PlatformIO Core
* USB drivers required by your ESP32 board
* A USB data cable

### Build

From the project directory:

```bash
pio run
```

### Upload

```bash
pio run -t upload
```

### Serial Monitor

The firmware uses **115200 baud**:

```bash
pio device monitor -b 115200
```

Or specify the ESP32's serial port:

```bash
pio device monitor -p COM3 -b 115200
```

## 🖥️ Serial Output

When no object is detected:

```text
CLEAR
CLEAR
CLEAR
```

When an object is detected:

```text
OBSTACLE
OBSTACLE
OBSTACLE
```

## 🧠 Firmware

The main firmware is located at:

```text
src/main.cpp
```

The current GPIO configuration is:

```cpp
#define IR_PIN 27
#define GREEN_LED 25
#define RED_LED 26
```

##  Notes

* The IR sensor is a **proximity/obstacle detector**, not a precise distance sensor.
* Detection range depends on the specific sensor module, object surface, lighting conditions, and the module's onboard potentiometer.
* The sensor's output polarity may vary between modules. This project assumes **LOW = obstacle detected**.
* Use a resistor in series with each LED.
* This project does not use the recovered active buzzer; it can be added in a future hardware revision using an appropriate driver circuit.

## 📸 Project

<p align="center">
  <img src="assets/from_top.jpg" alt="IR Proximity Indicator running on ESP32 taken from top" width="700">
</p>

<p align="center">
  <img src="assets/from_side.jpg" alt="IR Proximity Indicator running on ESP32 taken from side" width="700">
</p>


## 📄 License

This project is licensed under the **MIT License**.

See [`LICENSE`](LICENSE) for the full license text.

## 👤 Author

**AK74**

Software • Hardware • AI

GitHub: [@ssh-ak74](https://github.com/ssh-ak74)

---

Built with an ESP32, a few components, and curiosity. 
