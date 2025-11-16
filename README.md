# arDJuino!

Meet arDJuino!
Have you ever wanted to remix your favorite song or create your own DJ set? 

arDJuino is a mini DJ controller, controlled by an Arduino R3. It allows you to control functions such as synth, volume, and pause/play. These functions are controlled by a mini joystick, ultrasonic sensor, potentiometer and button. Arduino IDE, Hairless Midi, LoopMidi, and FL Studio are required to run and operate the project. 

[picture of the project]

Watch the demo [here](https://youtube.com/shorts/_P8-qAyXvgU?feature=share)!

We made this project to explore hardware and learn more about electronic systems while making music production more interactive. arDJuino was developed as a part of Hack Club's Parthenon. 

[image of wiring diagram]

## BOM

x1 [Elegoo Uno R3 Controller Board](https://a.co/d/9Zi0U5r) \
x1 [Joystick](https://www.digikey.com/en/products/detail/adafruit-industries-llc/512/7056915?) \
x1 [USB Cable](https://a.co/d/9Zi0U5r) \
x1 [Ultrasonic Sensor](https://a.co/d/9Zi0U5r) \
x1 [B10K Potentiometer](https://a.co/d/foRXb5b) \
x3 [Push Buttons](https://a.co/d/foRXb5b) \
x10 [Female to Male Dupont Wire](https://www.digikey.com/en/products/detail/adafruit-industries-llc/512/7056915?) \
x65 [Breadboard Jumper Wire Set](https://www.digikey.com/en/products/detail/adafruit-industries-llc/512/7056915?) \


Journal

| Challenge | Solution |
|----------|----------|
| Arduino being unable to play music | Integrate loopMIDI & Hairless MIDI |
| Button not working | Ensure all jumper wires are firmly connected |
| Ultrasensor not receiving power | Do **NOT** connect 5V & GND when switching orientation |
| Buttons placed incorrectly | Place buttons along the breadboard gap |
| FL Studio only taking in one remote control input | Delay initiation of the other control that is overriding it (comment out code when linking controller) |
| System being overridden with signals | Create `lastJoy` & `lastUltra` variables so signals send only when values change |

