
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6f0RGWq3p"
#define BLYNK_TEMPLATE_NAME "DHT22"
#define BLYNK_AUTH_TOKEN "1zqvVmKeDWXCKNNqzfplgHEYgu11lb0M"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#define DHTPIN D7       
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);
int SOIL_PIN = A0;

char ssid[] = "Dee";
char pass[] = "bbbbbbbb";

void setup()
{
  Serial.begin(9600);
  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(SOIL_PIN, INPUT);
}


void dht22Data() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    if (isnan(h) || isnan(t)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }
    Serial.print("Humidity: "); Serial.print(h);
    Serial.print(" %\t Temperature: "); Serial.print(t);
    Serial.println(" °C");

    Blynk.virtualWrite(V1, t);
    Blynk.virtualWrite(V2, h);
}
void soilData()
{
    int soilValue = analogRead(SOIL_PIN); 
    int moisturePercent = map(soilValue, 1023, 0, 0, 100);

    Serial.print("Soil Moisture: ");
    Serial.print(moisturePercent);
    Serial.println("%");

    Blynk.virtualWrite(V3, moisturePercent);
}

void loop()
{
  dht22Data();
  soilData();
  Blynk.run();
  delay(2000);
}

