#include <ESP32Servo.h>
#define servo1Pin 25  
#define servo2Pin 26  
#define servo3Pin 27  
String str = "";
const char separator = ',';
const int dataLength = 3;
int data[dataLength];
int angulo_s1;
int angulo_s2;
int angulo_s3;
bool actuador;
int angulo_anterior_s1;
int angulo_anterior_s2;
int angulo_anterior_s3;
Servo Servo1;
Servo Servo2;
Servo Servo3;
void setup()
{   
   angulo_anterior_s1 = 0;
   angulo_anterior_s2 = 0;
   angulo_anterior_s3 = 0;
   Servo1.attach(servo1Pin);
   Servo2.attach(servo2Pin);
   Servo3.attach(servo3Pin);
   Servo1.write(0);  
   Servo2.write(0);
   Servo3.write(0);  
   Serial.begin(9600);
}

void loop()
{
   if (Serial.available())
   {
    str = Serial.readStringUntil('\n');
      for (int i = 0; i < dataLength ; i++)
        {
          int index = str.indexOf(separator);
          data[i] = str.substring(0, index).toInt();
          str = str.substring(index + 1);
       }
       if(data[0] == 1){
          angulo_s1 = data[1];
          Serial.println("Servo1");
          servo1_movimiento(angulo_s1);
          angulo_anterior_s1 = angulo_s1;
       }
       if(data[0] == 2){
          angulo_s2 = data[1];
          Serial.println("Servo2");
          servo2_movimiento(angulo_s2);
          angulo_anterior_s2 = angulo_s2;
       }
       if(data[0] == 3){
          angulo_s3 = data[1];
          Serial.println("Servo3");
          servo3_movimiento(angulo_s3);
          angulo_anterior_s3 = angulo_s3;
       }
       
    }
}
void servo1_movimiento(int angulo){
 
   if(angulo <= 180 && angulo >= 0){
     Serial.println("SERV");
        if (angulo > angulo_anterior_s1){
          
        for(int i = angulo_anterior_s1; i<= angulo ; i++){
              Servo1.write(i);
              Serial.println(i);
              delay(50);
          }
          }
        if (angulo < angulo_anterior_s1){
        for(int i = angulo_anterior_s1; i>= angulo ; i--){
              Servo1.write(i);
              Serial.println(i);
              delay(50);
          }
          }
        if (angulo == angulo_anterior_s1){
              Servo1.write(angulo);
              Serial.println(angulo);
          }
        }
      

   }
   
void servo2_movimiento(int angulo){
   if(angulo <= 180 && angulo >= 0){
        if (angulo > angulo_anterior_s2){
        for(int i = angulo_anterior_s2; i<= angulo ; i++){
              Servo2.write(i);
              Serial.println(i);
              delay(50);
          }
          }
        if (angulo < angulo_anterior_s2){
        for(int i = angulo_anterior_s2; i>= angulo ; i--){
              Servo2.write(i);
              Serial.println(i);
              delay(50);
          }
          }
        if (angulo == angulo_anterior_s2){
              Servo2.write(angulo);
              Serial.println(angulo);
          }
        }
      

   }

  void servo3_movimiento(int angulo){
   if(angulo <= 180 && angulo >= 0){
        if (angulo > angulo_anterior_s3){
        for(int i = angulo_anterior_s3; i<= angulo ; i++){
              Servo3.write(i);
              Serial.println(i);
              delay(50);
          }
          }
        if (angulo < angulo_anterior_s3){
        for(int i = angulo_anterior_s3; i>= angulo ; i--){
              Servo3.write(i);
              Serial.println(i);
              delay(50);
          }
          }
        if (angulo == angulo_anterior_s3){
              Servo3.write(angulo);
              Serial.println(angulo);
          }
        }
      

   }
