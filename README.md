# **Metal Detector – Embedded Systems Project**  
🚀 *An embedded system-based metal detector using a 555 Timer IC, microcontroller, and buzzer for real-time metal detection.*

![Metal Detector Circuit](./Hardware/PCB_Design/PCB_Layout.png)

## **📌 Project Overview**  
This project implements a **metal detector** using a **555 Timer IC** configured as an **astable multivibrator**. When a metal object is placed near the coil, the **inductance changes**, causing a frequency shift, which is detected by a **microcontroller**. The system provides **audible and visual feedback** through a **buzzer and LED**.

---

## **🔧 Hardware Components**
| Component | Quantity | Purpose |
|-----------|---------|----------|
| 555 Timer IC | 1 | Generates frequency output |
| 9V Battery | 1 | Powers the circuit |
| 150-Turn Coil | 1 | Detects metal presence |
| Resistors (47kΩ) | 1 | Controls oscillation frequency |
| Capacitors (2.2µF, 10µF) | 3 | Frequency stabilization |
| Speaker/Buzzer | 1 | Audible feedback for detection |
| Microcontroller (Arduino/STM32) | 1 | Reads frequency and controls buzzer/LED |

---

## **🖥️ Software & Tools Used**
✅ **Embedded C/C++** – Firmware programming  
✅ **Altium Designer** – PCB layout  
✅ **LTspice** – Circuit simulation  
✅ **Arduino IDE / STM32CubeIDE** – Microcontroller programming  
✅ **GitHub** – Version control  

---

## **📜 Code Explanation**

### **1️⃣ main.c (Metal Detection Logic)**
- Reads **frequency from the 555 Timer** using **interrupts**  
- Compares frequency changes to **detect metal presence**  
- Activates **buzzer & LED** for user feedback  
- Sends **real-time data to Serial Monitor** for debugging  

### **2️⃣ timer_config.c (STM32 Timer Handling)**
- Configures **TIM2 interrupt** to measure frequency  
- Provides **high-resolution timing** for detection  

---

## **🚀 Setup & Installation**

### **1️⃣ Hardware Setup**
1. Assemble the **circuit on a breadboard or PCB**  
2. Connect the **555 Timer IC as an astable multivibrator**  
3. Attach the **buzzer and LED to the microcontroller**  

### **2️⃣ Firmware Upload (Arduino)**
1. Open `main.c` in **Arduino IDE**  
2. Connect **Arduino to PC via USB**  
3. Select the correct **board & port**  
4. Upload the code  

### **3️⃣ Firmware Upload (STM32)**
1. Open `main.c` in **STM32CubeIDE**  
2. Compile & flash firmware via **ST-Link**
   
