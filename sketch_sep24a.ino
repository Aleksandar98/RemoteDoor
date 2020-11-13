#include <SPI.h>
#include <WiFi.h>
#include <ESP8266WiFi.h>  
#include <FirebaseArduino.h>

#define FIREBASE_HOST "nodemcu-34d53.firebaseio.com"                         // the project name address from firebase id
#define FIREBASE_AUTH "p8h1hSxAtaaBCHMmBpwSIKSvBE9bL2f33xJNbeBi"                    // the secret key generated from firebase
#define WIFI_SSID ""                                          // input your home or public wifi name 
#define WIFI_PASSWORD "" 


#define LED_NOTIF 4
void setup() {
  // put your setup code here, to run once:

  pinMode(LED_NOTIF, OUTPUT);

  Serial.begin(9600);

  delay(1000);
  //pinMode(2, OUTPUT);                
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                  
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

    int fireStatus = Firebase.getInt("DOOR_STATUS");
    Serial.print(fireStatus);

}

void loop() {
  // put your main code here, to run repeatedly:

}
