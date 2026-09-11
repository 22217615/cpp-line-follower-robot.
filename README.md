# 🏆 Autonomous Line Follower Robot (C++)

![Course Winner Badge](https://img.shields.io/badge/Award-1st%20Place%20Course%20Winner-gold?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B%20%2F%20Arduino-blue?style=for-the-badge&logo=cplusplus)
![Domain](https://img.shields.io/badge/Field-Computer%20Engineering-green?style=for-the-badge)

An autonomous, high-speed line follower robot developed from scratch in **C++ / Arduino** as part of my Computer Engineering coursework. This project won **1st Place / Course Winner** in the university robotics competition.

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
