// Arduino Serial Example #1 Remote Control Blink - Slave
const int light_A = 9;
const int light_B = 8;
const int light_C = 7;
const int light_D = 6;
const int light_E = 13;
const int light_F = 12;
const int light_G = 11;
const int light_H = 10;
char c  = ' ';
const int lightup_time = 800;
 
void setup() 
{
   Serial.begin(9600);
   pinMode(light_A, OUTPUT);
   pinMode(light_B, OUTPUT);
   pinMode(light_C, OUTPUT);
   pinMode(light_D, OUTPUT);
   pinMode(light_E, OUTPUT);
   pinMode(light_F, OUTPUT);
   pinMode(light_G, OUTPUT);
   pinMode(light_H, OUTPUT);
   Serial.println("START");
}
 
 
void loop()
{
   if(Serial.available())
   {
      char c = Serial.read();
      if (c=='0') { 
        lights_up_f();
        delay(lightup_time);
        delay(2000 + lightup_time);
        lights_down_f();
      }
      else if (c=='1') { 
        lights_up_b();
        delay(2000);
        lights_down_b();
      }
      Serial.println(c);
   }
 
}

void lights_up_f(){
  digitalWrite(light_A, HIGH);
  delay(100);
  digitalWrite(light_B, HIGH);
  delay(100);
  digitalWrite(light_C, HIGH);
  delay(100);
  digitalWrite(light_D, HIGH);
  delay(100);
  digitalWrite(light_E, HIGH);
  delay(100);
  digitalWrite(light_F, HIGH);
  delay(100);
  digitalWrite(light_G, HIGH);
  delay(100);
  digitalWrite(light_H, HIGH);
  delay(100);
}

void lights_up_b(){
  digitalWrite(light_H, HIGH);
  delay(100);
  digitalWrite(light_G, HIGH);
  delay(100);
  digitalWrite(light_F, HIGH);
  delay(100);
  digitalWrite(light_E, HIGH);
  delay(100);
  digitalWrite(light_D, HIGH);
  delay(100);
  digitalWrite(light_C, HIGH);
  delay(100);
  digitalWrite(light_B, HIGH);
  delay(100);
  digitalWrite(light_A, HIGH);
  delay(100);
}

void lights_down_b(){
  digitalWrite(light_H, LOW);
  delay(100);
  digitalWrite(light_G, LOW);
  delay(100);
  digitalWrite(light_F, LOW);
  delay(100);
  digitalWrite(light_E, LOW);
  delay(100);
  digitalWrite(light_D, LOW);
  delay(100);
  digitalWrite(light_C, LOW);
  delay(100);
  digitalWrite(light_B, LOW);
  delay(100);
  digitalWrite(light_A, LOW);
  delay(100);
}

void lights_down_f(){
  digitalWrite(light_A, LOW);
  delay(100);
  digitalWrite(light_B, LOW);
  delay(100);
  digitalWrite(light_C, LOW);
  delay(100);
  digitalWrite(light_D, LOW);
  delay(100);
  digitalWrite(light_E, LOW);
  delay(100);
  digitalWrite(light_F, LOW);
  delay(100);
  digitalWrite(light_G, LOW);
  delay(100);
  digitalWrite(light_H, LOW);
  delay(100);
}
