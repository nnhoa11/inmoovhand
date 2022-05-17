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
}
void move(int i, char c){
  if (i == 1) {
    if (c == '1') thumb.write(180);
    else thumb.write(0);
  }
  else if (i == 2) index.write(180);
  else if (i == 3) middle.write(180);
  else if (i == 4) ring.write(180);
  else if (i == 5) pinky.write(180);
  delay(500);
  thumb.write(90);
  index.write(90);
  middle.write(90);
  ring.write(90);
  pinky.write(90);
}
void loop() {
  if(Serial.available() > 0){
    String s = Serial.readStringUntil('\n');
    for (int i = 1; i <= 6; i++)
      move(i, s[i]);
     Serial.print(s);
  }
}
