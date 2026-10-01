#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// TCS230/TCS3200 pins connected to Arduino
const int s0 = 8;
const int s1 = 9;
const int s2 = 11;
const int s3 = 12;
const int out = 10;

// RGB measurement variables
int red = 0;
int green = 0;
int blue = 0;

void setup() {
  Serial.begin(9600);

  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);

  // Output frequency scaling configuration
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(5, 0);
  lcd.print("Arduino");
  lcd.setCursor(1, 1);
  lcd.print("Color Detector");
}

void loop() {
  color();

  Serial.print("R =");
  Serial.print(red, DEC);
  Serial.print(" G = ");
  Serial.print(green, DEC);
  Serial.print(" B = ");
  Serial.print(blue, DEC);
  Serial.print("	");

  if (red < blue && red < green && red < 25) {
    if (green - blue >= 10 && green - blue <= 25 &&
        green - (2 * red) >= 8) {
      showColor("Red");
    } else if (green - red <= 10 && green - red >= -3 &&
               blue >= green) {
      showColor("Yellow");
    } else if (blue - red >= 3 && blue - red <= 10 &&
               green - (2 * red) <= 5) {
      showColor("Pink");
    } else if (green - blue >= -5 && green - blue <= 5 &&
               green - (2 * red) <= 5) {
      showColor("Orange");
    }
  } else if (green < red && green < blue && green < 25) {
    showColor("Green");
  } else if ((red > green && blue < green) &&
             blue < 25 && red > 40) {
    showColor("Blue");
  } else if (red - (2 * blue) >= -2 &&
             red - (2 * blue) <= 5 &&
             green - red < 10) {
    showColor("Purple");
  } else if (blue < red && blue < green &&
             (blue && red && green) < 25) {
    if (red - green <= 5 && red - green >= 0 &&
        ((green - blue) || (red - blue)) < 5 &&
        blue < 50) {
      showColor("White");
    }
  }

  Serial.println();
  delay(300);
}

void showColor(const char* detectedColor) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Color Detection");
  lcd.setCursor(0, 1);
  lcd.print("Color : ");
  lcd.print(detectedColor);

  Serial.print(" - (");
  Serial.print(detectedColor);
  Serial.println(" Color)");
}

void color() {
  // Red filter
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

  // Blue filter
  digitalWrite(s3, HIGH);
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

  // Green filter
  digitalWrite(s2, HIGH);
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}
