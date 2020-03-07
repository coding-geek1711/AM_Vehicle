/// Success ///

#define a1 4
#define a2 5
#define b1 6
#define b2 7

int command;

void setup() {
  Serial.begin(9600);
}

void loop() {
  command = Serial.read();
  Serial.println(command);
  if(command == 1){
    Front();
  }
  else if(command == 2){
    Back();
  }
  else if(command == 3){
    Left();
  }
  else if(command == 4){
    Right();
  }
  else if(command == 5){
    Stop();
  }
  else{
    Stop();
  }
  delay(30);
}

void Front(){
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
}

void Back(){
  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  digitalWrite(b1, LOW);
  digitalWrite(b2, HIGH);
}

void Left(){
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
}

void Right(){  
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(b2, LOW);
}

void Stop(){
  digitalWrite(a1, HIGH);
  digitalWrite(a2, HIGH);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, HIGH);
}
