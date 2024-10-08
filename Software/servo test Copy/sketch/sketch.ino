#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 90;    // variable to store the servo position
int servoAmount = 3; // amount of servos in circuit
int servoSwitch = 0; // variable for servo pin in use
#define selPin 2
#define vertPin A0
#define horzPin A1

void setup() {
  
  int servoPin[servoAmount] = {3, 5, 6}; // list of PWM pins for servos

  Serial.begin(9600);
  myservo.attach(servoPin[servoSwitch]);  // attaches the servo on a pin to the servo object
  pinMode(selPin, INPUT_PULLUP);
  pinMode(vertPin, INPUT);
  pinMode(horzPin, INPUT);

  // int tempPos[servoAmount] = {90, 90, 90};


  /*
  delay(15);
  myservo.write(-15);
  delay(15);
  */
}

void loop() {
  if(millis() % 100 == 0){
      Serial.println(pos);
  }

  // int tempPos[servoAmount];

  int servoPin[servoAmount] = {3, 5, 6}; // list of PWM pins for servos

  myservo.attach(servoPin[servoSwitch]);

  int vert = map(analogRead(vertPin), 0, 1023, -100, 100);
  int horz = map(analogRead(horzPin), 0, 1023, -100, 100);
  bool selPressed = digitalRead(selPin) == LOW;

  /*
  Serial.println(vert);
  Serial.println(horz);
  Serial.println(selPressed);
  delay(1000);
  */

  
  // switching active servo

  if (vert == -100)
  {

    // tempPos[servoSwitch] = pos;

    if ((servoSwitch + 1) == servoAmount)
    {
      servoSwitch = 0;
      // pos = tempPos[servoSwitch];
    }
    else
    {
      servoSwitch++;
      // pos = tempPos[servoSwitch];
    }

    delay(200);

  }

  if (vert == 100)
  {
    if (servoSwitch == 0)
    {
      servoSwitch = servoAmount - 1;
    }
    else
    {
      servoSwitch--;
    }

    delay(200);

  }

  // servo sweep when using left and right of joystick
  if (horz == 100)
  {
    if (pos >= 0)
    {
    myservo.write(pos);
    pos--;
    delay(10);
    }
  }

  if (horz == -100)
  {
    if (pos <= 180)
    {
    myservo.write(pos);
    pos++;
    delay(10);
    }
  }

  /*
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  */
}