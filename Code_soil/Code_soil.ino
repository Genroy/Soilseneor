#include <Wire.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_PRINT Serial
BlynkTimer timm;


char token[] = ""; //ใส่ Token Blynk
char ssid[] = ""; //ใส่ SSID WifI
char pass[] = ""; // ใสรหัส wifi

int led1 = D4;
volatile int soilse;

void setup(){
 Blynk.begin(token, ssid, pass);
  timm.setInterval(1000L, sendsoil);
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  
}

void loop() {
Blynk.run();
sendsoil();
soil();
}

void sendsoil(){

  Blynk.virtualWrite(V0 , soilse)// รับค่าจากเซ็นเซอร์เพื่อให้โชว์ใน Blynk 
  
}


void soil(){
int sensorpin = A0;
int sensorValue = analogRead(sensorpin);

soilse = sensorValue; // ส่งค่าไปให้ Blynk อ่าน

     if(sensorValue >400 && sensorValue < 800){         

       digitalWrite(led1,HIGH);
       Serial.print("ค่าความชื้น = ");
       Serial.println(sensorValue);
       Serial.print(" ไฟติด");
      }
      else{
      digitalWrite(led1, LOW);
      
       Serial.print("ค่าความชื้น = ");
      Serial.println(sensorValue);
       Serial.print(" ไฟตับ");
        
      }//else

      delay(1000);
  }//void
