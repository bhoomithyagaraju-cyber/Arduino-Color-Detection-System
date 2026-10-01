# Demo Instructions

## Hardware Setup

1. Connect the TCS230/TCS3200 to the Arduino using the pin mapping in `docs/CIRCUIT_DIAGRAM.md`.
2. Connect the 16×2 I2C LCD.
3. Connect the Arduino to the computer using USB.

## Upload

1. Open `src/color_detection.ino` in Arduino IDE.
2. Install `LiquidCrystal_I2C` if required.
3. Select the correct Arduino board.
4. Select the correct COM port.
5. Upload the sketch.

## Demonstration

1. Power the system.
2. Wait for the LCD startup message.
3. Open Serial Monitor at 9600 baud.
4. Place a known colored object in front of the sensor.
5. Observe the RGB readings.
6. Observe the color classification on the LCD.
7. Repeat with different colors.

## Recommended Demo Recording

For a GitHub project video, show:

- Complete hardware setup
- Sensor close-up
- LCD startup
- Red object detection
- Green object detection
- Blue object detection
- Serial Monitor readings

Only show results that were actually obtained from the physical prototype.
