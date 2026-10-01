# Circuit Diagram and Wiring

## TCS230/TCS3200 Connections

| TCS230/TCS3200 Pin | Arduino Pin |
|---|---:|
| S0 | D8 |
| S1 | D9 |
| OUT | D10 |
| S2 | D11 |
| S3 | D12 |
| VCC | 5V* |
| GND | GND |

*Use the voltage recommended by the specific sensor module.

## I2C LCD Connections

For a typical Arduino Uno/Nano configuration:

| LCD | Arduino |
|---|---|
| VCC | 5V* |
| GND | GND |
| SDA | SDA |
| SCL | SCL |

*Verify the voltage requirements of the specific LCD module.

## I2C Address

The source code uses:

```cpp
LiquidCrystal_I2C lcd(0x27, 16, 2);
```

If the display does not respond, scan the I2C bus and change the address if necessary.

## Wiring Notes

- Keep sensor and Arduino grounds common.
- Avoid loose jumper connections.
- Keep the sensor at a reasonably consistent distance from test objects.
- Reduce strong ambient light during calibration.
