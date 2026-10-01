# System Architecture

## High-Level Architecture

```text
        INPUT
          │
          ▼
┌─────────────────────┐
│ Colored Test Object │
└──────────┬──────────┘
           │ Reflected Light
           ▼
┌─────────────────────┐
│ TCS230/TCS3200      │
│ Color Sensor        │
└──────────┬──────────┘
           │ Frequency
           ▼
┌─────────────────────┐
│ Arduino             │
│                     │
│ Filter Selection    │
│ Pulse Measurement   │
│ RGB Comparison      │
│ Color Classification│
└───────┬────────┬────┘
        │        │
        │ I2C    │ UART/USB
        ▼        ▼
┌────────────┐  ┌──────────────┐
│ 16×2 LCD   │  │ Serial       │
│ Color Name │  │ Monitor      │
└────────────┘  └──────────────┘
```

## Functional Modules

### 1. Sensor Interface

S2 and S3 select the photodiode color filter. The OUT pin provides the sensor's frequency output.

### 2. Measurement Module

The Arduino uses `pulseIn()` to measure the sensor output pulse duration.

### 3. Classification Module

The measured values are compared against fixed threshold conditions to select a color class.

### 4. Display Module

The LCD displays:

```text
Color Detection
Color : Red
```

where `Red` is replaced by the detected color.

### 5. Serial Monitoring Module

RGB measurements are sent at 9600 baud for observation and debugging.
