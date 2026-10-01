# Project Report — Arduino Color Detection System

## 1. Title

**Arduino-Based Color Detection System Using TCS230/TCS3200 Sensor and I2C LCD**

## 2. Abstract

Color identification is useful in automation, sorting, inspection and educational embedded-system applications. This project presents a simple Arduino-based color detection system that uses a TCS230/TCS3200 color sensor to measure the red, green and blue components of reflected light.

The sensor provides a frequency-based output corresponding to the selected color component. The Arduino reads the sensor output, obtains RGB-related measurements and applies threshold-based decision logic. The resulting color classification is displayed on a 16×2 I2C LCD, while the measured values are also transmitted through the Serial Monitor.

The prototype is intended as a low-cost demonstration of sensor interfacing, embedded programming, signal measurement and rule-based classification.

## 3. Objectives

- Interface a TCS230/TCS3200 color sensor with Arduino.
- Measure red, green and blue components.
- Implement color classification using programmed thresholds.
- Display the detected color on a 16×2 I2C LCD.
- Print sensor readings through serial communication.
- Demonstrate a simple embedded color-recognition application.

## 4. Components

1. Arduino-compatible development board
2. TCS230/TCS3200 color sensor
3. 16×2 LCD with I2C interface
4. Breadboard
5. Jumper wires
6. USB cable
7. Suitable power source

## 5. Working Principle

The TCS230/TCS3200 contains photodiodes with different color filters. The selected filter determines which component of the incident light is measured. The sensor converts the measured light intensity into a frequency signal.

The Arduino selects the sensor filters through S2 and S3 and measures the output pulse using `pulseIn()`. The program obtains red, blue and green readings and compares them with predefined threshold conditions.

If a set of conditions is satisfied, the corresponding color name is displayed on the LCD.

## 6. Block Diagram

```text
Colored Object
      │
      ▼
┌──────────────────┐
│ TCS230/TCS3200   │
│ Color Sensor     │
└────────┬─────────┘
         │ Frequency Output
         ▼
┌──────────────────┐
│ Arduino          │
│ RGB Measurement  │
│ Classification   │
└───────┬─────┬────┘
        │     │
       I2C   Serial
        │     │
        ▼     ▼
     LCD     PC
```

## 7. Pin Configuration

| TCS230/TCS3200 | Arduino |
|---|---:|
| S0 | D8 |
| S1 | D9 |
| OUT | D10 |
| S2 | D11 |
| S3 | D12 |

LCD uses the I2C interface. The source code is configured for I2C address `0x27`.

## 8. Software

- Arduino IDE
- C/C++ based Arduino sketch
- Wire library
- LiquidCrystal_I2C library

## 9. Algorithm

1. Initialize serial communication.
2. Configure sensor pins.
3. Configure LCD.
4. Select the red filter and measure the output pulse.
5. Select the blue filter and measure the output pulse.
6. Select the green filter and measure the output pulse.
7. Compare the three readings with programmed thresholds.
8. Identify the corresponding color class.
9. Display the result on the LCD.
10. Print RGB readings through Serial Monitor.
11. Repeat continuously.

## 10. Color Classification

The current program includes rule-based classification for:

- Red
- Green
- Blue
- Yellow
- Pink
- Orange
- Purple
- White

The exact thresholds are empirical and should be calibrated against the actual sensor, lighting and test objects.

## 11. Testing

Testing should be performed using known colored objects under controlled lighting. For every test object, record:

| Test | Object Color | R | G | B | LCD Result | Correct? |
|---:|---|---:|---:|---:|---|---|
| 1 | Red | Add measured value | Add measured value | Add measured value | Add result | Yes/No |
| 2 | Green | Add measured value | Add measured value | Add measured value | Add result | Yes/No |
| 3 | Blue | Add measured value | Add measured value | Add measured value | Add result | Yes/No |
| 4 | Yellow | Add measured value | Add measured value | Add measured value | Add result | Yes/No |
| 5 | Pink | Add measured value | Add measured value | Add measured value | Add result | Yes/No |
| 6 | Orange | Add measured value | Add measured value | Add measured value | Add result | Yes/No |
| 7 | Purple | Add measured value | Add measured value | Add measured value | Add result | Yes/No |
| 8 | White | Add measured value | Add measured value | Add measured value | Add result | Yes/No |

> Do not publish invented measurements. Replace the placeholders with values recorded from the real prototype.

## 12. Results

### Repository Demonstration Data

An illustrative RGB dataset is included in `results/illustrative-test-data.csv` and plotted in `results/illustrative-rgb-results.png`. These values are provided only to demonstrate how experimental results can be documented; they are not measurements from the physical prototype.

For an academic submission, replace them with actual readings obtained during hardware testing.


The implemented program provides an LCD-based color output and serial RGB readings. Actual accuracy depends on calibration, illumination, sensor distance and the test surface.

Add photographs and real test results under `results/`.

## 13. Advantages

- Low-cost implementation
- Simple hardware
- Easy to understand and modify
- Real-time output
- Useful for embedded-systems learning
- Can be extended to automation applications

## 14. Limitations

- Fixed thresholds may not work equally well under all lighting conditions.
- Ambient light can influence sensor readings.
- Different surfaces can produce different reflected intensities.
- Calibration is required for improved reliability.

## 15. Applications

- Object/color sorting demonstrations
- Educational embedded systems
- Basic industrial color sensing
- Robotic object identification
- Prototype inspection systems

## 16. Future Scope

- Automatic calibration
- Averaging/filtering of readings
- Better color classification algorithms
- Data logging
- Wireless monitoring
- Conveyor-based automatic sorting
- Integration with robotics

## 17. Conclusion

The project demonstrates how an Arduino can interface with a TCS230/TCS3200 color sensor to measure RGB-related signals and classify colors using embedded software. A 16×2 I2C LCD provides immediate user feedback, while the Serial Monitor provides measurement data useful for testing and calibration.

The system provides a practical foundation for more advanced color-sensing and automated sorting applications.
