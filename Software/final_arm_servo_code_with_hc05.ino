#include <Servo.h>

Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;

int pos0 = 90;
int pos1 = 180;
int pos2 = 90;
int pos3 = 90;

int servoAmount = 4;
int servoSwitch = 0;
int servoDelay = 10;

#define selPin 8
#define horzPin A0
#define vertPin A1

int servoDelayNew = 10;


#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'

bool leftOn0 = false;
bool leftOn1 = false;
bool leftOn2 = false;
bool leftOn3 = false;


bool rightOn0 = false;
bool rightOn1 = false;
bool rightOn2 = false;
bool rightOn3 = false;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(selPin, INPUT_PULLUP);
  pinMode(vertPin, INPUT);
  pinMode(horzPin, INPUT);

  servo0.attach(3);

  servo1.attach(5);
  servo1.write(pos1);

  servo2.attach(6);
  servo2.write(pos2);

  servo3.attach(9);
  servo3.write(pos3);



}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available()) {
    char command = Serial.read();
    executeCommand(command);
  }
  
  Serial.println(servoSwitch);
  Serial.println(pos1);

  boolOnServo();
}

void executeCommand(char command) {
  switch (command) {
    case FORWARD:
      // Perform action for moving forward
      Serial.println("f");

      if ((servoSwitch + 1) == servoAmount)
      {
        servoSwitch = 0;
      }
      else
      {
        servoSwitch++;
      }

      break;
    case BACKWARD:
      // Perform action for moving backward
      Serial.println("b");

      if (servoSwitch == 0)
      {
        servoSwitch = servoAmount - 1;
      }
      else
      {
        servoSwitch--;
      }

      break;
    case LEFT:
      // Perform action for turning left
      Serial.println("l");
      switch(servoSwitch)
      {
        case 0:
          if(!leftOn0)
          {
            Serial.println("moveLeft");
            servo0.write(75);
            leftOn0 = true;
          }
          else
          {
            Serial.println("stopMoveLeft");
            servo0.write(90);
            leftOn0 = false;
          }
          Serial.println("case0");
          break;

        case 1:
          if(!leftOn1)
          {
            leftOn1 = true;
          }
          else
          {
            leftOn1 = false;
          }
      
          break;

        case 2:
          if(!leftOn2)
          {
            leftOn2 = true;
          }
          else
          {
            leftOn2 = false;
          }
          break;

        case 3:
          if(!leftOn3)
          {
            leftOn3 = true;
          }
          else
          {
            leftOn3 = false;
          }
          break;

        default: break;
      }


      break;
    case RIGHT:
      // Perform action for turning right
      Serial.println("r");

      switch(servoSwitch)
      {
        case 0:
          if(!rightOn0)
          {
            Serial.println("moveRight");
            servo0.write(105);
            rightOn0 = true;
          }
          else
          {
            Serial.println("stopMoveRight");
            servo0.write(90);
            rightOn0 = false;
          }
          Serial.println("case0");
          break;

        case 1:
          
          if(!rightOn1)
          {
            rightOn1 = true;
          }
          else
          {
            rightOn1 = false;
          }
      
          break;

        case 2:

          if(!rightOn2)
          {
            rightOn2 = true;
          }
          else
          {
            rightOn2 = false;
          }

          break;

        case 3:

          if(!rightOn3)
          {
            rightOn3 = true;
          }
          else
          {
            rightOn3 = false;
          }

          break;

        default: break;
      }

      break;
    default:
      // Invalid command received
      break;
  }
}

void boolOnServo(){
  if(leftOn1)
  {
    if(pos1 <= 180)
    {
      pos1++;
      delay(30);
    }
  }
  if(rightOn1)
  {
    if(pos1 >= 0)
    {
      pos1--;
      delay(30);
    }
  }
  servo1.write(pos1);

  if(leftOn2)
  {
    if(pos2 <= 180)
    {
      pos2++;
      delay(30);
    }
  }
  if(rightOn2)
  {
    if(pos2 >= 0)
    {
      pos2--;
      delay(30);
    }
  }
  servo2.write(pos2);

  if(leftOn3)
  {
    if(pos3 <= 180)
    {
      pos3++;
      delay(15);
    }
  }
  if(rightOn3)
  {
    if(pos3 >= 0)
    {
      pos3--;
      delay(15);
    }
  }
  servo3.write(pos3);
}
