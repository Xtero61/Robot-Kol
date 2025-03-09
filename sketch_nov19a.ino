#include <Servo.h>

// Servo motor tanımları
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

// Servo pinleri
const int pinServo1 = 8;
const int pinServo2 = 9;
const int pinServo3 = 10;
const int pinServo4 = 11;
const int pinServo5 = 12;

// Potansiyometre pinleri
const int potPin1 = A0;
const int potPin2 = A1;
const int potPin3 = A2;
const int potPin4 = A3;
const int potPin5 = A4;

void setup() {
  
  // Servo motorların pinleri belirlenmesi
  servo1.attach(pinServo1);
  servo2.attach(pinServo2);
  servo3.attach(pinServo3);
  servo4.attach(pinServo4);
  servo5.attach(pinServo5);
  
}

void loop() {

  Servo_Motor_Aci_Ayarlama(servo1, potPin1);
  Servo_Motor_Aci_Ayarlama(servo2, potPin2);
  Servo_Motor_Aci_Ayarlama(servo3, potPin3);
  Servo_Motor_Aci_Ayarlama(servo4, potPin4);
  Servo_Motor_Aci_Ayarlama(servo5, potPin5);
  
  delay(50); // Biraz bekle
  
}

// Servo motor açısını potansiyometreden okunan değere göre ayarlayan fonksiyon
void Servo_Motor_Aci_Ayarlama(Servo& ServoMotor, int potPin) {
  
  int potDeger = analogRead(potPin); // Potansiyometre değeri oku
  int servoDeger = map(potDeger, 0, 1023, 0, 180); // 0-1023'ü 0-180'e dönüştür
  ServoMotor.write(servoDeger); // Servo motorun açısını ayarla
  
}
