#include <ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Empty.h>
#include <race/drive_values.h>
ros::NodeHandle  nh;


boolean flagStop = false;
int pwm_center_value = 9830;

void messageDrive( const race::drive_values& pwm )
{

  if(flagStop == false)
  {
    analogWrite(5,pwm.pwm_drive);  
    analogWrite(6,pwm.pwm_angle);     
  }
  else
  {
    analogWrite(5,pwm_center_value);
    analogWrite(6,pwm_center_value);    
  }
}

void messageEmergencyStop( const std_msgs::Bool& flag )
{
  flagStop = flag.data;
  analogWrite(5,pwm_center_value);
  analogWrite(6,pwm_center_value);    
}
ros::Subscriber<race::drive_values> sub_drive("drive_pwm", messageDrive );
ros::Subscriber<std_msgs::Bool> sub_stop("eStop", messageEmergencyStop );

void setup() {
  Serial.begin(115200);
  
  analogWriteFrequency(5, 100);
  analogWriteFrequency(6, 100);
  analogWriteResolution(12);
  analogWrite(5,pwm_center_value);
  analogWrite(6,pwm_center_value);
  pinMode(13,OUTPUT); 
  digitalWrite(13,HIGH);

  nh.initNode();
  nh.subscribe(sub_drive);
  nh.subscribe(sub_stop);
}

void loop() {
  nh.spinOnce();
  // put your main code here, to run repeatedly:
  /*
  if(Serial.available())
  {
    int spd = Serial.read();
    if(spd>127) {
      spd = spd-128;
      spd = map(spd,0,100,410,820);
      analogWrite(5,spd);  
    }
    else {
      //angle servo
      spd = map(spd,0,100,410,820);
      analogWrite(6,spd);
    }
    
  } 
  */ 
}

