# Autonomous Fire Suppression Robot

The purpose for our autonomous fire suppression robot is to aid homeowners in combating small household fires. Specifically, our robot is meant to protect homes from fires that homeowners are either unaware of or unprepared to fight. Research has shown that, “more than half of reported non-fatal home cooking fire injuries occurred when the victims tried to fight the fire themselves”. Other common house fires include heating systems. All household fires are classified under the A, B, or C class. A class fires are combustibles, B class fires are flammable liquids, and C class fires are electrical equipment.

[FULL REPORT](https://matthewcheng.carbonmade.com/projects/7128857) 

![AFSR Demo](./photos/AFSR-demo-2.gif)

## Design Solution

The design solution is a modular “payload” platform which can be attached to the “base” designed by FFR2. The reason for the modular design is to allow for replacement of either the “payload” or the “base” in case of damage to either component. The key features that needed to be addressed were fire detection, communications, and fire suppression. In the design solution, the payload platform is equipped with 5 infrared sensors. These sensors are able to detect a fire within 10 feet. The sensors then communicates with the Arduino Uno module in order to guide the robot base toward the fire, trigger the suppressant, or raise the linear actuator. The linear actuator is used to elevate the suppression nozzle in order to extinguish fires at an elevated surface approximately 5 feet high. The suppressant used was a modified ABC fire extinguisher. This retains easy maintenance by allowing the customer to change out the extinguisher or refill it as needed. The way in which the extinguisher is modified is by adding a longer hose to accommodate the linear actuator. These various components and features allow the payload system to be versatile and effective for the typical home fire, and will be able to extinguish small fires in real time. Our payload system has 6 key features: base housing, top panel, protective casing, sensors and software, arm extension, and extinguisher trigger system.

![Robot Photo](./photos/AFSR-1.png)

## Tech Stack
* Arduino
* C/C++

## Team
* Matthew Cheng (Team Lead)
* James Gallagher
* Rei Tamaoka 
* Junxian Tan
