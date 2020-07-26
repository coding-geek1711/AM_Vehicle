/// Arduino Code with Manual and Auto Config ///

#define a1 4
#define a2 5
#define b1 6
#define b2 7

int command;      // Command to move
int reciever;     // Data from NodeMCU
int speed;        // Speed at which to run

int DELAY = 30;

void setup() {
  Serial.begin(9600);
}

void loop() {
  reciever = Serial.read();
  Serial.println(reciever);
  speed = reciever / 100;
  command = reciever % 100;
  while(reciever != 9999){
      switch(command){
      case 1:
        Front(speed);
        break;
      case 2:
        Back(speed);
        break;
      case 3:
        Left(speed);
        break;
      case 4:
        Right(speed);
        break;
      case 5:
        Stop(speed);
        break;
      default :
        Stop(speed);
        break;
    }
  }
  if(reciever == 9999){
    printf("Auto Code Here....");
  }
  delay(DELAY);
}

void Front(int speed){
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
}

void Back(int speed){
  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  digitalWrite(b1, LOW);
  digitalWrite(b2, HIGH);
}

void Left(int speed){
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
}

void Right(int speed){  
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(b2, LOW);
}

void Stop(int speed){
  digitalWrite(a1, HIGH);
  digitalWrite(a2, HIGH);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, HIGH);
}
