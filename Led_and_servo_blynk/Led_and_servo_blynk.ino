
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6Yf0M7axz"
#define BLYNK_TEMPLATE_NAME "led"
#define BLYNK_AUTH_TOKEN "j5wUnKMdWbyVJ0_AutXkL-Z3Ai557Akc"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char ssid[] = "YOUR_WIFI_NAM";
char pass[] = "YOUR_PASSOWRD";
int ledPin = D2;
Servo myservo;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(ledPin, OUTPUT);
  myservo.attach(D3);
  digitalWrite(ledPin, 0);
}

BLYNK_WRITE(V0) {  
  int ledState = param.asInt(); 
  Serial.print("ledState: ");
  Serial.println(ledState);
  if (ledState == 1) {  
    digitalWrite(ledPin , 1);
  } else {
    digitalWrite(ledPin,0);
  }
}
BLYNK_WRITE(V1) { 
  int value = param.asInt();  
  Serial.print("Servo value: ");
  Serial.println(value);
  if(value == 1){
    myservo.write(180);
  }else{
    myservo.write(0);
  }
}
void loop()
{
  Blynk.run();
}

