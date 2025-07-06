#define BLYNK_TEMPLATE_ID "TMPL6CvjZoEYT"
#define BLYNK_TEMPLATE_NAME "Smart Gas Monitor System"
#define BLYNK_AUTH_TOKEN "tjxuJm1RnGBywjxz6VcFRshDIOs0pu2r"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <LiquidCrystal_I2C.h>

// WiFi credentials
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

// Sensor and LED pins
#define MQ2_PIN 32
#define RED_LED 16
#define GREEN_LED 17

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Alert flag
bool alertSent = false;

void setup() {
  Serial.begin(115200);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Connecting WiFi");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WiFi Connected");
  delay(100);
}

void loop() {
  Blynk.run();

  // Read gas value (in ppm from Wokwi)
  int gasPPM = analogRead(MQ2_PIN);
  Serial.print("Gas PPM: ");
  Serial.println(gasPPM);

  // Send gas PPM to Blynk Gauge on V0
  Blynk.virtualWrite(V0, gasPPM);

  // Update LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gas: ");
  lcd.print(gasPPM);
  lcd.print(" ppm");

  // Air quality status
  if (gasPPM > 1500) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Air: DANGER!");

    if (!alertSent) {
      Blynk.logEvent("smart_gas_monitor_system", "⚠️ High gas: " + String(gasPPM) + " ppm");
      alertSent = true;
    }

  } else if (gasPPM > 3000) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Air: MODERATE");
    alertSent = false;

  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Air: NORMAL ");
    alertSent = false;
  }

  delay(1000);  // Check every 1 seconds
}
