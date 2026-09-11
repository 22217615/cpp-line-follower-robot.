# 🏆 Autonomous Line Follower Robot (C++)

![Course Winner Badge](https://img.shields.io/badge/Award-1st%20Place%20Course%20Winner-gold?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B%20%2F%20Arduino-blue?style=for-the-badge&logo=cplusplus)
![Domain](https://img.shields.io/badge/Field-Computer%20Engineering-green?style=for-the-badge)

An autonomous, high-speed line follower robot developed from scratch in **C++ / Arduino** as part of my Computer Engineering coursework. This project won **1st Place / Course Winner** in the university robotics competition.
<img width="1200" height="1600" alt="WhatsApp Image at 7 04 55 PM" src="https://github.com/user-attachments/assets/8b340779-dfad-4e9e-91a0-c82672f1f1a2" />
<img width="1200" height="1600" alt="WhatsApp Image 2026-09-11 at 7 04 55 PM" src="https://github.com/user-attachments/assets/0389437b-8b4a-4213-b5b8-7e751ae5ed60" />


https://github.com/user-attachments/assets/adeb1c74-039f-4724-b38c-0b19419f4ed8


---

## 🛠️ Modular C++ Architecture

The project is designed using modular C++ components to keep code clean, fast, and hardware-aware:

* **Main Controller (`robot_project_code`):** Manages initialization, sensor polling loop, and system execution state.
* **Motor Control (`motor`):** Low-level PWM driver logic to control motor direction, acceleration, and speed differential.
* **Steering & Steering Logic (`turning`):** Implements closed-loop feedback/PID corrections to negotiate sharp turns smoothly at high speed.
* **Line Detection (`line detector`):** Real-time IR sensor processing with signal filtering to accurately locate the track position.

---

##  Tech Stack & Hardware

| Category | Component / Tool |
| :--- | :--- |
| **Language** | C++ / Embedded C |

| **Platform** | Arduino IDE / Microcontroller |

| **Sensors** | IR Reflectance Sensor Array |

| **Actuators** | DC Motors + Motor Driver Module |

| **Control System** | PID / Closed-loop Feedback Control |

---

## 🎓 Award & Recognition

* **1st Place Winner** in university Computer Engineering course competition.
* Completed the course with the fastest overall time and 100% track navigation accuracy.
