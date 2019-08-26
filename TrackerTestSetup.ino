#include <AccelStepper.h>

// Define two steppers and the pins they will use
AccelStepper armGear(AccelStepper::DRIVER, 9, 8);
AccelStepper baseGear(AccelStepper::DRIVER, 7, 6);

String one;
String two;

int position1;
int position2;

void setup()
{ 
  //setMaxSpeed: Sets the maximum permitted speed. The run() function will accelerate up to the speed set by this function.
  //CAUTION:The desired maximum speed in steps per second. Must be > 0. 
  //Caution: Speeds that exceed the maximum speed supported by the processor may Result in non-linear accelerations and decelerations. 
  
  //setAcceleration: Sets the acceleration/deceleration rate.
  //acceleration  The desired acceleration in steps per second per second. Must be > 0.0.

  Serial.begin(9600);
  
  armGear.setMaxSpeed(3000);
  armGear.setAcceleration(1000);
  baseGear.setMaxSpeed(2000);
  baseGear.setAcceleration(800);
}

void loop(){

  //distanceToGo: The distance from the current position to the target position. 
  
  //moveTo: Set the target position. The run() function will try to move the motor 
  //(at most one step per call) from the current position to the target position 
  //set by the most recent call to this function. 
  //Caution: moveTo() also recalculates the speed for the next step. 
  //If you are trying to use constant speed movements, you should call setSpeed() 
  //after calling moveTo(). 
  if(!Serial.available()){


  while(one == ""){
  Serial.println("Enter First Gears Position: ");
  one = Serial.readString();
  position1 = one.toInt();
  
  }


  while(two == ""){
  Serial.println("Enter Second Gears Position: ");
  two = Serial.readString();
  position2 = two.toInt();
  
  }

  armGear.moveTo(position1);
  //baseGear.moveTo(position2);
  //&& baseGear.distanceToGo() != 0

  while(armGear.distanceToGo() ){
    
    //for(int runner = 0; runner <= 10; runner++){
    armGear.run();
    //baseGear.run(); 

    //}
    
    
  }

  one = "";
  two = "";

  Serial.println(position1);
  Serial.println(position2);

  armGear.setCurrentPosition(0);
  //baseGear.setCurrentPosition(0);


  }
    
}
