#include <Servo.h>

Servo thumb, index, middle, ring, pinky, hand[6];
const int StringLength = 6;
int stas[10], counter = 0;
String received, prev= "$00000";
bool counterStart = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  thumb.attach(7);
  index.attach(8);
  middle.attach(9);
  ring.attach(10);
  pinky.attach(11);
  pinMode(LED_BUILTIN, OUTPUT);
  thumb.write(0);
}
void move(int i, char c){
  if (i == 1) {
    if (c == '1') thumb.write(180);
    else thumb.write(0);
  }
  else if (i == 2){
    if (c == '1') 
    index.write(180);
    else index.write(0);
  }
  else if (i == 3) {
    if (c == '1') middle.write(180);
    else middle.write(0);
  }
  else if (i == 4) {
    if (c == '1') ring.write(180);
    else ring.write(0);
  }
  else if (i == 5) {
    if (c == '1' )pinky.write(180);
    else pinky.write(0);
  }
  
}
void loop() {
    while (Serial.available() == 0){
      digitalWrite(LED_BUILTIN, LOW);
    }
    String s = Serial.readString();
    digitalWrite(LED_BUILTIN, HIGH);
    for (int i = 1; i <= 6; i++)
      move(i, s[i]);
    Serial.println(s);
}
