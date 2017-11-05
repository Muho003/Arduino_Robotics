#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(0,1); //RX, TX

int data;

int motor1A = 3;
int motor1B = 5;
int motor2A = 6;
int motor2B = 10;


void setup() {
  Bluetooth.begin(9600);
  Serial.begin(9600);
  Bluetooth.println("Bluetooth On");
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT); 
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
}

void loop() {
  
 if (Bluetooth.available()){
  data = Bluetooth.read();

  switch (data){

    case '0':
      forward();
      Bluetooth.println("Robot moving forward!");
      break;
    case '1':
      backward();
      Bluetooth.println("Robot moving backward!");
      break;

     case '2':
      right();
      Bluetooth.println("Robot moving left!");
      break;

     case '3':
      left();
      Bluetooth.println("Robot moving right!");
      break;   

      case '4':
      halt();
      Bluetooth.println("Robot stopped!");  
      break;
      
  }

 }
delay(100);
}

void forward(){

  analogWrite(motor1A, 255);
  analogWrite(motor1B, 0);
  analogWrite(motor2A, 250);
  analogWrite(motor2B, 0);
  
}

void backward() {
  analogWrite(motor1A, 0);
  analogWrite(motor1B, 255);
  analogWrite(motor2A, 0);
  analogWrite(motor2B, 250);
}


void halt() {
  analogWrite(motor1A, 0);
  analogWrite(motor1B, 0);
  analogWrite(motor2A, 0);
  analogWrite(motor2B, 0);
}

void left() {
  analogWrite(motor1A, 255);
  analogWrite(motor1B, 0);
  analogWrite(motor2A, 200);
  analogWrite(motor2B, 0);
}

void right() {
  analogWrite(motor1A, 195);
  analogWrite(motor1B, 0);
  analogWrite(motor2A, 250);
  analogWrite(motor2B, 0);
}


