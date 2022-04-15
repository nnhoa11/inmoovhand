#include <Servo.h>
Servo thumb, index, middle, ring, pinky;
const int StringLength = 6;
int stas[10], counter = 0;
String received;
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
    }
  }
}
void loop() {
  Input();
  thumb.write(180 * stas[0]);
  index.write(180 * stas[1]);
  middle.write(180 * stas[2]);
  ring.write(180 * stas[3]);
  pinky.write(180 * stas[4]);
}
