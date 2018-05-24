#include<Servo.h>
#include <float.h>
//ros化
#include <ros.h>
#include <std_msgs/Int16.h>

ros::NodeHandle node;
std_msgs::Int16 direc;
ros::Publisher pub("arduino_talker", &direc);
void Callback(const std_msgs::Int16 &char_data)
{
  if(char_data.data == 0) {
      go_straight(500);
    } else if (char_data.data == 1) {
      turn_right(500);
    } else if (char_data.data == 2) {
      turn_left(500);
    } else if (char_data.data == 3) {
      back(500);
    } else {
    }
    pub.publish(&direc);
 }
void Callback(const int& a ){}
ros::Subscriber<std_msgs::Int16> sub("arduino_server", &Callback);

/*terminalで
`roscore`
`rosrun rosserial_python serial_node.py _port:=/dev/ttyACM0`
`rostopic pub /arduino std_msgs/Int16 "data: 0"` <- 0, 1, 2,3*/

/*roslaunch works/rosprac/src/arduino_tutorial/launch/test.launch*/
//
void setup()
{
  //ros
  node.initNode();
  node.subscribe(sub);
  node.advertise(pub);
  //
  pinMode(5,OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7,OUTPUT);
  analogWrite(5, 30);
  
  pinMode(8, OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10, OUTPUT);
  analogWrite(10, 30);
  
  pinMode(11,INPUT);
  Servo my_servo;
  my_servo.attach(11);
  my_servo.write(0);
  
  pinMode(12, INPUT);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}

void go_straight(int wait_time)
{
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  delay(wait_time);
  motor_init();
}

void back(int wait_time)
{
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(wait_time);
  motor_init();
}

void turn_right(int wait_time)
{
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  delay(wait_time);
  motor_init();
 }
 
void turn_left(int wait_time)
{
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(10, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  delay(wait_time);
  motor_init();
 }

void motor_init()
{
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
 }
void wait_button_push()
{
  while (digitalRead(12) == LOW) {
    delay(10);
    }
   while (digitalRead(12) == HIGH) {
    delay(10);
    }
    delay(100);
 }
 
double front_distance() //cm
{
  double Distance = 0;
  digitalWrite(A0, LOW);
  delayMicroseconds(10);
  digitalWrite(A0, HIGH);
  delayMicroseconds(10);
  double Duration = pulseIn(A1, HIGH);
  if (Duration > 0) {
    Duration /= 2;
    Distance = Duration * 340 * 100 /1000000;
    } else {
      Distance = DBL_MAX; //float.h
    }
    return Distance;
 }
//line trace
boolean right_white()
{
  return (digitalRead(A2) == LOW);
 }
boolean right_black()
{
  return !(right_white());
 }
 
boolean left_white()
{
  return (digitalRead(A3) == LOW);
 }
boolean left_black()
{
  return !(left_white());
 }
//
void loop()
{
  node.spinOnce();
  delay(1);
 }
