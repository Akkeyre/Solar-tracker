//Solar Tracker v1.0
//Author: Akkeyre
//Github:https://github.com/Akkeyre/Solar-tracker
//Arduino/Genuino Uno



#include<Servo.h>
int ldrvals[4]={0,0,0,0};
int topleft=0;
int topright=0;
int bottomright = 0;
int bottomleft = 0;
int delay_time = 15;
Servo bottom;
Servo top;
int Servo_pos_bottom = 90;
int Servo_pos_top = 90;
void ldr_receive(void){
  ldrvals[0] = analogRead(A0);//topleft
  ldrvals[1] = analogRead(A1);//topright
  ldrvals[2] = analogRead(A2);//bottomright
  ldrvals[3] = analogRead(A3);//bottomleft
  topleft = ldrvals[0];
   topright =ldrvals[1];
   bottomright = ldrvals[2];
   bottomleft = ldrvals[3];
  Serial.print(analogRead(A0));
  Serial.print(",");
  Serial.print(topright);
  Serial.println("");
}

void setup() {
  // put your setup code here, to run once:
  bottom.attach(9);
  top.attach(10);
  bottom.write(Servo_pos_bottom);
  delay(delay_time);
  top.write(Servo_pos_top);
    delay(delay_time);
    Serial.begin(9600);
  
}

void loop() {
  ldr_receive();
  // put your main code here, to run repeatedly:
  if((topleft > topright)&&(topleft-topright>=150)) {
  
      Servo_pos_bottom--;
    bottom.write(Servo_pos_bottom);
    delay(delay_time);
    if(Servo_pos_bottom<=0){
      Servo_pos_bottom=0;
    }
    
  }
  if((topright > topleft)&&(topright-topleft>=150)) {
    
     
    
      Servo_pos_bottom++;
    bottom.write(Servo_pos_bottom);
    delay(delay_time);
    if(Servo_pos_bottom>=180){
      Servo_pos_bottom = 180;
    }
  }
  if((bottomleft > bottomright)&&(bottomleft-bottomright>=150)) {
  
      Servo_pos_bottom--;
    bottom.write(Servo_pos_bottom);
    delay(delay_time);
    if(Servo_pos_bottom<=0){
      Servo_pos_bottom=0;
    }
    
  }
  if((bottomright > bottomleft)&&(bottomright-bottomleft>=150)) {
    
     
    
      Servo_pos_bottom++;
    bottom.write(Servo_pos_bottom);
    delay(delay_time);
    if(Servo_pos_bottom>=180){
      Servo_pos_bottom = 180;
    }
  }

  if(bottomright >topright && bottomright - topright >=100){
    Servo_pos_top--;
    top.write(Servo_pos_top);
    delay(delay_time);
    if(Servo_pos_top<=0){
      Servo_pos_top = 0;
    }
  }
   if(topright >bottomright && topright - bottomright >=100){
    Servo_pos_top++;
    top.write(Servo_pos_top);
    delay(delay_time);
    if(Servo_pos_top>=180){
      Servo_pos_top = 180;
    }
  }
  if(bottomleft >topleft && bottomleft - topleft >=150){
    Servo_pos_top--;
    top.write(Servo_pos_top);
    delay(delay_time);
    if(Servo_pos_top<=0){
      Servo_pos_top = 0;
    }
  }
   if(topleft >bottomleft && topleft - bottomleft >=150){
    Servo_pos_top++;
    top.write(Servo_pos_top);
    delay(delay_time);
    if(Servo_pos_top>=180){
      Servo_pos_top = 180;
    }
  }
  Serial.println(Servo_pos_bottom);
}
  
  
