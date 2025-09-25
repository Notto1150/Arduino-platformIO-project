#include <Arduino.h>

// กำหนดพิน
const int LED_PIN = 13;
const int BUTTON_PIN = 2;

// ตัวแปรสถานะ
bool ledState = false;
int buttonState = 0;

void setup() {
  // เริ่มต้น Serial
  Serial.begin(9600);
  
  // ตั้งค่าโหมดพิน
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  Serial.println("Arduino Project Started!");
}

void loop() {
  // อ่านค่าปุ่ม
  buttonState = digitalRead(BUTTON_PIN);
  
  // ถ้ากดปุ่ม
  if (buttonState == LOW) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    
    Serial.print("LED: ");
    Serial.println(ledState ? "ON" : "OFF");
    
    delay(300); // 防抖动
  }
  
  delay(100);
}
//Hello World2