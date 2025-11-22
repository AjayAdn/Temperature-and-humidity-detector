# Temperature & Humidity Monitoring System (Arduino)

## 📌 Overview
This project is a **Temperature & Humidity Monitoring System** using **Arduino**, **DHT11 sensor**, **I2C LCD**, and an automatic cooling fan.  
The system reads temperature & humidity, displays them on an LCD, and activates the fan when the temperature exceeds the threshold.

---

## ⚙ Features
- Real-time temperature & humidity monitoring  
- LCD display with centered text  
- Automatic fan control if temperature > **28°C**  
- Status indicators: **Santai**, **Panas**, **Tropis**  
- Serial output logging  
- Sensor error handling  

---

## 🛠 Components Used
| Component | Description |
|----------|-------------|
| Arduino UNO / Nano | Main microcontroller board |
| DHT11 Sensor | Reads temperature & humidity |
| LCD 16x2 I2C (0x27) | Displays sensor data |
| Cooling Fan | Automatically activated when temp is high |
| Jumper Wires | For connections |
| USB Cable | Upload code & power supply |

---


## 🔌 Wiring
| Component | Arduino Pin |
|----------|-------------|
| DHT11 Signal | D2 |
| Fan | D3 |
| LCD SDA | A4 |
| LCD SCL | A5 |
| DHT11 VCC | 5V |
| LCD VCC | 5V |

---

## 🔧 Custom Temperature & Humidity Thresholds
You can easily change when the fan (or any other output device) should turn on by modifying these two variables in the code:

```cpp
const int batasSuhu = 28;        // Default temperature limit (°C)
const int batasKelembaban = 70;  // Default humidity limit (%)
```

---
Created by **Fajar Kastara**
