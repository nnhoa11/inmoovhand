#include <Servo.h>
Servo thumb, index, middle, ring, pinky, hand[6];
const int StringLength = 6;
int stas[10], counter = 0;
String received, prev= "$00000";
bool counterStart = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  hand[0].attach(7);
  hand[1].attach(8);
  hand[2].attach(9);
  hand[3].attach(10);
  hand[4].attach(11);
}
void Input(){
   while(Serial.available()){
    char c = Serial.read();
    if (c == '$') counterStart = true;
    if (counterStart){
      received += c;
      counter++;
    }
    if (counter >= StringLength){
      for (int i = 0; i < 5; i++){
        stas[i] = received.substring(i, i + 1).toInt();
      }
      counter = 0;
      counterStart = false;
      //received = "";
    }
  }
}
void loop() {
  Input();
  if (prev != received){ prev = received;
  for (int i = 0; i < 5; i++){
    if (stas[i]) hand[i].write(180); else hand[i].write(0);
  }
    }
  received = "";
}
