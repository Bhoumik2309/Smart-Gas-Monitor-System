# Smart-Gas-Monitor-System
This is an IoT-based Smart Gas Monitoring System developed using ESP32, simulated on Wokwi, and integrated with Blynk for real-time alerts and email notifications.

## 🚀 Features

✅ Real-time gas leakage detection  
✅ Live monitoring via **Blynk IoT Dashboard**  
✅ **Instant notifications** on gas leakage  
✅ **Email alerts** for emergency awareness  
✅ **Wokwi simulation** - No hardware required for testing  
✅ Can be extended to control fans/valves for automation

-## 🧰 Tech Stack

- **Microcontroller:** ESP32  
- **Simulator:** [Wokwi](https://wokwi.com/)  
- **IoT Platform:** [Blynk](https://blynk.io/)  
- **Programming Language:** Arduino C++  
- **Gas Sensor:** MQ-2 (or MQ-135)  
- **Notification System:** Blynk + Gmail SMTP  
- **Display:** (Optional) I2C LCD 16x2

- ## 🛠️ How It Works

1. **MQ Gas Sensor** continuously monitors air quality.
2. If gas concentration exceeds a threshold:
   - Triggers an **alert in Blynk app**.
   - Sends an **email notification** to the user.
   - (Optional) Activates a buzzer or exhaust fan.
3. All simulation handled in **Wokwi**.

## 🔗 Simulation Link
[👉 Open in Wokwi](https://wokwi.com/projects/434301684860440577)
