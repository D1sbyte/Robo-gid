
char inChar;
#define LED_PIN 9

void setup() {
  pinMode(LED_PIN, OUTPUT); // Инициализация светодиода
  Serial.begin(115200); // Инициализация Serial - порта
}

void loop() {
  if (Serial.available() > 0)
  {
    inChar = Serial.read();
    if (inChar=='e') // e - Enable - включить
    {
      digitalWrite(LED_PIN,HIGH);
      Serial.write("Enable");
    }
  
  
  else if (inChar=='d') // d - Disable - выключить
  {
      digitalWrite(LED_PIN,LOW);
      Serial.write("Disable");
  }
  
    else if (inChar=='b')  // b - Blink - выключить режим мигания
    {
      digitalWrite(LED_PIN,HIGH);
      delay(1000);
      digitalWrite(LED_PIN,LOW);
      delay(1000);
      Serial.write("Blink");
    }
  }
}













//// крутим мотор туда-сюда плавно с ускорением
//#include "GyverStepper.h"
//
//int step_ = 7;
//int dir = 4;
//int en = 2;
//
//GStepper< STEPPER2WIRE> stepper(1012, step_, dir, en); // драйвер step-dir + пин enable
//// мотор с драйвером ULN2003 подключается по порядку пинов, но крайние нужно поменять местами
//// то есть у меня подключено D2-IN1, D3-IN2, D4-IN3, D5-IN4, но в программе поменял 5 и 2
//void setup() {
//  Serial.begin(115200);
//  // режим следования к целевй позиции
//  stepper.setRunMode(FOLLOW_POS);
//  // установка макс. скорости в шагах/сек
//  stepper.setMaxSpeed(400);
//  // установка ускорения в шагах/сек/сек
//  stepper.setAcceleration(500);
//}
//void loop() {
//  // просто крутим туды-сюды
//  if (!stepper.tick()) {
//    static bool dir;
//    dir = !dir;
//    stepper.setTarget(dir ? -400 : 400);
//  }
//  // график положения
//  static uint32_t tmr2;
//  if (millis() - tmr2 > 20) {
//    tmr2 = millis();
//    Serial.println(stepper.getCurrent());
//  }
//}
