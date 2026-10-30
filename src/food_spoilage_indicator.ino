#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11
#define MQ135_PIN 34
#define BUZZER_PIN 25

float temperatureThreshold = 35.0;
float humidityThreshold = 80.0;
int gasThreshold = 1800;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(MQ135_PIN, INPUT);
  ledcAttach(BUZZER_PIN, 3000, 8);
  ledcWriteTone(BUZZER_PIN, 0);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int gasValue = analogRead(MQ135_PIN);

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT11 Sensor Error!");
    delay(2000);
    return;
  }

  bool tempAlert = temperature > temperatureThreshold;
  bool humidityAlert = humidity > humidityThreshold;
  bool gasAlert = gasValue > gasThreshold;

  Serial.println("--------------------------------");
  Serial.print("Temperature: "); Serial.print(temperature); Serial.println(" °C");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.println(" %");
  Serial.print("MQ-135 Gas Response: "); Serial.println(gasValue);

  if (tempAlert || humidityAlert || gasAlert) {
    Serial.println("SPOILAGE RISK DETECTED");
    ledcWriteTone(BUZZER_PIN, 3000);
  } else {
    Serial.println("NORMAL STORAGE CONDITIONS");
    ledcWriteTone(BUZZER_PIN, 0);
  }

  delay(3000);
}
