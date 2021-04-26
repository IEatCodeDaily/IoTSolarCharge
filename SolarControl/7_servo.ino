/*
 * Handler Servo
 */


//========= Macros ==========
#define SERVO_PIN 6

#define SERVO_MIN 0
#define SERVO_MAX 180


#define KONTROL_PERIODE 1000
#define AMBANG 10


//========= Var Declaration =======
Servo sg90;             

float kp = 0.05;
int servo_pos = SERVO_MAX/2;  

//============= Funcs ============

//Initalize Servo
void servoInit() 
{ 
  sg90.attach(SERVO_PIN);  
  sg90.write(servo_pos);
  delay(2000);
}  

//Move servo by increment of arg
int servoMove(int dp) { 
  // ubah posisi sesuai limit
  servo_pos = constrain(servo_pos + dp, SERVO_MIN, SERVO_MAX);
  sg90.write(servo_pos); 
  return servo_pos;
}

//Move servo to arg
int servoWrite(int p) 
{ 
  // ubah posisi sesuai limit
  servo_pos = constrain(p, SERVO_MIN, SERVO_MAX);
  sg90.write(servo_pos); 
  return servo_pos;
}

//Function for periodic LDR Control
void taskKontrol(struct ldrStruct &ldr) {
  int error = ldr.ldr1 - ldr.ldr2;
  if (error > AMBANG) {
    servoMove(kp*error);
  }
  else if (error < AMBANG) {
    servoMove(kp*error);
  }
}
