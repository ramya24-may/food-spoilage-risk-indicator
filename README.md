# Food Spoilage Risk Indicator Using Embedded System

A team mini-project for Embedded Systems (23CSE304). This educational prototype monitors selected environmental parameters associated with food storage and provides a local audible warning when configured experimental thresholds are exceeded.

> **Important:** This is an early-warning educational prototype. It does not directly confirm that food is spoiled or safe to consume.

## Overview
The ESP32 reads temperature and relative humidity from a DHT11 sensor and an analog gas/VOC response from an MQ-135 sensor. It compares readings with experimental thresholds and activates a buzzer when any threshold is exceeded.

## Hardware
- ESP32 Dev Module — main controller
- DHT11 — temperature and humidity
- MQ-135 — general gas/VOC response
- Buzzer — audible alert
- Breadboard, jumper wires and USB cable

## Pin connections from the project report

| Module | Pin | ESP32 connection |
|---|---|---|
| DHT11 | VCC | 3.3 V |
| DHT11 | DATA | GPIO 4 |
| DHT11 | GND | GND |
| MQ-135 | VCC | VIN / 5 V (as documented) |
| MQ-135 | AO | GPIO 34, through a suitable voltage divider if required |
| MQ-135 | GND | GND |
| Buzzer | + | GPIO 25 |
| Buzzer | - | GND |

**Electrical safety:** Ensure the ESP32 ADC input remains within its permitted voltage range. Check the actual MQ-135 module output and use suitable voltage conditioning if needed.

## Threshold logic documented in the report
- Temperature > 35 °C
- Relative humidity > 80%
- MQ-135 analog response > 1800

If any one condition is true, the buzzer is activated. These are experimental project thresholds, not validated food-safety limits. They require calibration for sensor, food type, placement and environment.

## Software and setup
- Arduino IDE and ESP32 board support package
- DHT sensor library
- Arduino C/C++ (ESP32 Arduino core)

1. Open `src/food_spoilage_indicator.ino` in Arduino IDE.
2. Install the DHT sensor library and ESP32 board support.
3. Verify the wiring and electrical levels before powering the circuit.
4. Select the correct ESP32 board and serial port, then upload.
5. Open Serial Monitor at **115200 baud**.

The sketch uses the ESP32 LEDC buzzer API shown in the report. API availability varies by Arduino-ESP32 core version; compile against your installed core and adapt the LEDC calls if required.

## Repository contents
```text
food-spoilage-risk-indicator/
├── README.md
├── src/
│   └── food_spoilage_indicator.ino
├── hardware/
│   ├── prototype_photo.jpg
│   ├── system_architecture.png
│   └── flowchart.png
└── docs/
    └── embedded_systems_project_report.pdf
```

## Limitations
- MQ-135 is a general gas/VOC-response sensor; it does not identify a specific spoilage compound.
- Thresholds are experimental and not validated food-specific limits.
- DHT11 provides basic measurements.
- Sensor warm-up and calibration can affect MQ-135 readings.
- This version uses a local buzzer and Serial Monitor; cloud monitoring is not implemented.

## Future improvements
- Add Wi-Fi remote monitoring and a web dashboard.
- Store readings and alerts for trend analysis.
- Add an OLED/LCD display.
- Conduct food-specific calibration and controlled validation.
- Evaluate additional sensors.

## Team project and contribution
This was a team mini-project. The repository organizes report materials and code transcribed from the submitted report. The applicant reports contributing to team circuit assembly, ESP32 programming, and testing/debugging.

## Source note
The sketch and hardware details were transcribed from the supplied 14-page project report (code on page 11; prototype photograph on page 10). The sketch has not been independently compiled or hardware-tested during repository packaging. Please verify it with the actual board and components before describing it as a tested release.
