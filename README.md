# Project

This project is a systems includes Sensors, LED, speaker and Joystick. We created a graphical interface for the LED. In
the main menu, we can choose to display the information of distance via Ultrasound, or the temperature via Temperature
Sensor. We can also choose to turn on the Fan, and play songs. If we choose to play Song, we will access to the Song
menu in which we will be able to choose the song for the buzzer to play. We use the Joystick to move in the menu and
between menus

Demo video of the project is
available [here](https://drive.google.com/file/d/1kI8XR3BWHTZ6K34wA1EKu4E3_fub6izn/view?usp=sharing).

# Materials used

1. Ultrasound Sensor
2. Temperature Sensor
3. Passive Buzzer
4. Fan Blade and 3-6V Motor
5. LED 1602A
6. Joystick
7. Arduino UNO R3

# Pin connected

1. Ultrasound Sensor:
    - Trigger pin: D5
    - Echo pin : D7
2. Temperature Sensor : A0,A1
3. Passive Buzzer : A2
4. Fan Blade and 3-6V Motor : A5
5. LED 1602A :
    - RS : D4
    - RW : D6
    - D4 : D10
    - D5 : D11
    - D6 : D12
    - D7 : D13
6. Joystick :
    - VRx : A3
    - VRy : A4

# Uploading to Arduino

## With `PlatformIO`

1. Install [PlatformIO](https://docs.platformio.org/en/latest//core/installation.html).

```bash
pio init
pio run -t upload
```

## With `Arduino IDE`

1. Open `Arduino.ino` inside `Arduino/`.