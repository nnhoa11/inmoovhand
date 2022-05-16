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
}

void loop() {
  if(Serial.available() > 0){
    char c = Serial.read();
    if (c == '$'){
      received = "";
      counter = 0;
    }
    if (c == '1') { 
      thumb.writeMicroseconds(1500);
    }
    if (c == '0' ){
    }
    counter++;
  }
}
