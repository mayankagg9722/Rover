//Code by Reichenstein7 (thejamerson.com)

//Keyboard Controls:
//
// 1 -Motor 1 Left
// 2 -Motor 1 Stop
// 3 -Motor 1 Right
//
// 4 -Motor 2 Left
// 5 -Motor 2 Stop
// 6 -Motor 2 Right

// Declare L298N Dual H-Bridge Motor Controller directly since there is not a library to load.

// Motor R1
int dir1PinRA = 22;
int dir2PinRA = 23;
int speedPinRA = 2; 

//Motor R2

int dir1PinRB = 26;
int dir2PinRB = 27;
int speedPinRB = 4; 

//Motor R3
int dir1PinRC = 30;
int dir2PinRC = 31;
int speedPinRC = 6; 

//Motor L1
int dir1PinLA = 24;
int dir2PinLA = 25;
int speedPinLA = 3; 

//Motor L2
int dir1PinLB = 28;
int dir2PinLB = 29;
int speedPinLB = 5; 
//Motor L3
int dir1PinLC = 32;
int dir2PinLC = 33;
int speedPinLC = 7; 



void setup() {  // Setup runs once per reset
// initialize serial communication @ 9600 baud:
Serial.begin(9600);

//Define L298N Dual H-Bridge Motor Controller Pins

pinMode(dir1PinRA,OUTPUT);
pinMode(dir2PinRA,OUTPUT);
pinMode(speedPinRA,OUTPUT);

pinMode(dir1PinRB,OUTPUT);
pinMode(dir2PinRB,OUTPUT);
pinMode(speedPinRB,OUTPUT);

pinMode(dir1PinRC,OUTPUT);
pinMode(dir2PinRC,OUTPUT);
pinMode(speedPinRC,OUTPUT);

pinMode(dir1PinLA,OUTPUT);
pinMode(dir2PinLA,OUTPUT);
pinMode(speedPinLA,OUTPUT);

pinMode(dir1PinLB,OUTPUT);
pinMode(dir2PinLB,OUTPUT);
pinMode(speedPinLB,OUTPUT);

pinMode(dir1PinLC,OUTPUT);
pinMode(dir2PinLC,OUTPUT);
pinMode(speedPinLC,OUTPUT);

}

void loop() {

// Initialize the Serial interface:

if (Serial.available() > 0) {
int inByte = Serial.read();
int speed; // Local variable

switch (inByte) {

//______________Motor 1______________

case 'w': // Motor 1 Forward
analogWrite(speedPinRA, 100);//Sets speed variable via PWM 
digitalWrite(dir1PinRA, LOW);
digitalWrite(dir2PinRA, HIGH);

analogWrite(speedPinRB, 100);
digitalWrite(dir1PinRB, LOW);
digitalWrite(dir2PinRB, HIGH);

analogWrite(speedPinRC, 100);
digitalWrite(dir1PinRC, LOW);
digitalWrite(dir2PinRC, HIGH);

analogWrite(speedPinLA, 100);
digitalWrite(dir1PinLA, LOW);
digitalWrite(dir2PinLA, HIGH);

analogWrite(speedPinLB, 100);
digitalWrite(dir1PinLB, LOW);
digitalWrite(dir2PinLB, HIGH);

analogWrite(speedPinLC, 100);
digitalWrite(dir1PinLC, LOW);
digitalWrite(dir2PinLC, HIGH);
Serial.println("Motor 1 Forward"); // Prints out “Motor 1 Forward” on the serial monitor
Serial.println("   "); // Creates a blank line printed on the serial monitor
break;


case 's': // Motor 1 Reverse
analogWrite(speedPinRA, 0);
digitalWrite(dir1PinRA, LOW);
digitalWrite(dir2PinRA, HIGH);

analogWrite(speedPinRB, 0);
digitalWrite(dir1PinRB, LOW);
digitalWrite(dir2PinRB, HIGH);

analogWrite(speedPinRC, 0);
digitalWrite(dir1PinRC, LOW);
digitalWrite(dir2PinRC, HIGH);


analogWrite(speedPinLA, 250);
digitalWrite(dir1PinLA, HIGH);
digitalWrite(dir2PinLA, LOW);

analogWrite(speedPinLB, 250);
digitalWrite(dir1PinLB, HIGH);
digitalWrite(dir2PinLB, LOW);

analogWrite(speedPinLC, 250);
digitalWrite(dir1PinLC, HIGH);
digitalWrite(dir2PinLC, LOW);
Serial.println("Motor 1 Reverse");
Serial.println("   ");
break;

case 'a': // Motor 1 Left
analogWrite(speedPinRA, 250);
digitalWrite(dir1PinRA, HIGH);
digitalWrite(dir2PinRA, LOW);

analogWrite(speedPinRB, 250);
digitalWrite(dir1PinRB, HIGH);
digitalWrite(dir2PinRB, LOW);

analogWrite(speedPinRC, 250);
digitalWrite(dir1PinRC, HIGH);
digitalWrite(dir2PinRC, LOW);

analogWrite(speedPinLA, 250);
digitalWrite(dir1PinLA, LOW);
digitalWrite(dir2PinLA, HIGH);

analogWrite(speedPinLB, 250);
digitalWrite(dir1PinLB, LOW);
digitalWrite(dir2PinLB, HIGH);

analogWrite(speedPinLC, 250);
digitalWrite(dir1PinLC, LOW);
digitalWrite(dir2PinLC, HIGH);
Serial.println("Motor  Left");
Serial.println("   ");
break;

case 'd': // Motor 1 Right
analogWrite(speedPinRA, 250);//Sets speed variable via PWM 
digitalWrite(dir1PinRA, LOW);
digitalWrite(dir2PinRA, HIGH);

analogWrite(speedPinRB, 250);
digitalWrite(dir1PinRB, LOW);
digitalWrite(dir2PinRB, HIGH);

analogWrite(speedPinRC, 250);
digitalWrite(dir1PinRC, LOW);
digitalWrite(dir2PinRC, HIGH);

analogWrite(speedPinLA, 0);
digitalWrite(dir1PinLA, LOW);
digitalWrite(dir2PinLA, HIGH);

analogWrite(speedPinLB, 0);
digitalWrite(dir1PinLB, LOW);
digitalWrite(dir2PinLB, HIGH);

analogWrite(speedPinLC, 0);
digitalWrite(dir1PinLC, LOW);
digitalWrite(dir2PinLC, HIGH);
Serial.println("Motor 1 Right"); // Prints out “Motor 1 Forward” on the serial monitor
Serial.println("   "); // Creates a blank line printed on the serial monitor
break;

case 'x': // Motor 1 Right
analogWrite(speedPinRA, 0);//Sets speed variable via PWM 
digitalWrite(dir1PinRA, LOW);
digitalWrite(dir2PinRA, HIGH);

analogWrite(speedPinRB, 0);
digitalWrite(dir1PinRB, LOW);
digitalWrite(dir2PinRB, HIGH);

analogWrite(speedPinRC, 0);
digitalWrite(dir1PinRC, LOW);
digitalWrite(dir2PinRC, HIGH);

analogWrite(speedPinLA, 0);
digitalWrite(dir1PinLA, LOW);
digitalWrite(dir2PinLA, HIGH);

analogWrite(speedPinLB, 0);
digitalWrite(dir1PinLB, LOW);
digitalWrite(dir2PinLB, HIGH);

analogWrite(speedPinLC, 0);
digitalWrite(dir1PinLC, LOW);
digitalWrite(dir2PinLC, HIGH);
Serial.println("Motor 1 Right"); // Prints out “Motor 1 Forward” on the serial monitor
Serial.println("   "); // Creates a blank line printed on the serial monitor
break;
default:
// turn all the connections off if an unmapped key is pressed:
Serial.println("working");
}
}
}