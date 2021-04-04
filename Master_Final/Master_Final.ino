// Arduino Serial Example #1 Remote Control Blink - Master
const int light_I = 9;
const int light_J = 8;
const int light_K = 7;
const int light_L = 6;
const int light_M = 13;
const int light_N = 12;
const int light_O = 11;
const int light_P = 10;
const int sensor_b_trig = 5;
const int sensor_b_echo = 4;
const int sensor_t_trig = 3;
const int sensor_t_echo = 2;
const int lightup_time = 800;
 
void setup() 
{
    Serial.begin(9600);  
    pinMode(light_I, OUTPUT);
    pinMode(light_J, OUTPUT);
    pinMode(light_K, OUTPUT);
    pinMode(light_L, OUTPUT);
    pinMode(light_M, OUTPUT);
    pinMode(light_N, OUTPUT);
    pinMode(light_O, OUTPUT);
    pinMode(light_P, OUTPUT);
    pinMode(sensor_b_trig, OUTPUT);
    pinMode(sensor_t_trig, OUTPUT);
    pinMode(sensor_b_echo, INPUT);
    pinMode(sensor_t_echo, INPUT);
    Serial.write(5);
}
 
 
void loop() 
{
  long duration_bot, distance_bot, duration_top, distance_top;
  digitalWrite(sensor_b_trig, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(sensor_b_trig, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(sensor_b_trig, LOW);
  duration_bot = pulseIn(sensor_b_echo, HIGH);
  distance_bot = (duration_bot/2) / 29.1;

  digitalWrite(sensor_t_trig, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(sensor_t_trig, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(sensor_t_trig, LOW);
  duration_top = pulseIn(sensor_t_echo, HIGH);
  distance_top = (duration_top/2) / 29.1;

  if (distance_bot < 120 || distance_bot > 150){
    Serial.write('0');
    delay(lightup_time); //These numbers will change
    lights_up_f();
    delay(2000+lightup_time);
    lights_down_f();
    delay(lightup_time);
    Serial.write(5);
  }
  if (distance_top < 75 || distance_top > 100){
    lights_up_b();
    Serial.write('1');
    delay(2000+lightup_time);
    lights_down_b();
    Serial.write(5);
  }
  delay(25);
}

void lights_up_f(){
  digitalWrite(light_I, HIGH);
  delay(100);
  digitalWrite(light_J, HIGH);
  delay(100);
  digitalWrite(light_K, HIGH);
  delay(100);
  digitalWrite(light_L, HIGH);
  delay(100);
  digitalWrite(light_M, HIGH);
  delay(100);
  digitalWrite(light_N, HIGH);
  delay(100);
  digitalWrite(light_O, HIGH);
  delay(100);
  digitalWrite(light_P, HIGH);
  delay(100);
}

void lights_up_b(){
  digitalWrite(light_P, HIGH);
  delay(100);
  digitalWrite(light_O, HIGH);
  delay(100);
  digitalWrite(light_N, HIGH);
  delay(100);
  digitalWrite(light_M, HIGH);
  delay(100);
  digitalWrite(light_L, HIGH);
  delay(100);
  digitalWrite(light_K, HIGH);
  delay(100);
  digitalWrite(light_J, HIGH);
  delay(100);
  digitalWrite(light_I, HIGH);
  delay(100);
}

void lights_down_b(){
  digitalWrite(light_P, LOW);
  delay(100);
  digitalWrite(light_O, LOW);
  delay(100);
  digitalWrite(light_N, LOW);
  delay(100);
  digitalWrite(light_M, LOW);
  delay(100);
  digitalWrite(light_L, LOW);
  delay(100);
  digitalWrite(light_K, LOW);
  delay(100);
  digitalWrite(light_J, LOW);
  delay(100);
  digitalWrite(light_I, LOW);
  delay(100);
}

void lights_down_f(){
  digitalWrite(light_I, LOW);
  delay(100);
  digitalWrite(light_J, LOW);
  delay(100);
  digitalWrite(light_K, LOW);
  delay(100);
  digitalWrite(light_L, LOW);
  delay(100);
  digitalWrite(light_M, LOW);
  delay(100);
  digitalWrite(light_N, LOW);
  delay(100);
  digitalWrite(light_O, LOW);
  delay(100);
  digitalWrite(light_P, LOW);
  delay(100);
}
