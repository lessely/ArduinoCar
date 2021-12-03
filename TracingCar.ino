#include <SoftwareSerial.h>
SoftwareSerial BT(8, 9);
char val;
int i;


void setup() {
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(3,OUTPUT);//LED
  pinMode(A5,INPUT);
  pinMode(A4,INPUT);
  Serial.begin(9600);
  Serial.println("Car is ready!");
  BT.begin(9600);
  Serial.begin(9600);  
  digitalWrite(3,HIGH);
  
}
 //反射越强值越小
void loop() {
  int left=0;
  int right=0;
  int total=0;
  int a;
  int b;
  delay(200);
  left=analogRead(A5);
  right=analogRead(A4); 
  total=left+right;
  a=left-right;
  b=right-left;
  BT.print("LEFT：");
  BT.print(left);
  BT.print("  RIGHT:");
  BT.print(right);
  BT.println(" ");
  
  if(10<b<30&&total>=600){//直线
  BT.println("GO Straight");    
  Gostraight(); 
  delay(50);
  Stop();
  delay(50);
  }
  
//  if(50<a<100){
//    BT.println("Turnright");    
//    Turnright();
//    delay(30);
//    Stop();
//    delay(50);
//  }
//  
//    if(100<a<200){
//    BT.println("Turnright");    
//    Turnright();
//    delay(60);
//    Stop();
//    delay(50);
//  }
//
//  if(200<a<300){
//    BT.println("Turnright");    
//    Turnright();
//    delay(90);
//    Stop();
//    delay(50);
//  }
//  
//  if(300<a<400){
//    BT.println("Turnright");    
//    Turnright();
//    delay(120);
//    Stop();
//    delay(50);
//  }
//  if(50<b<100){
//    BT.println("Turnleft");    
//    Turnleft();
//    delay(30);
//    Stop();
//    delay(50);
//  }
//    if(100<b<200){
//    BT.println("Turnleft");    
//    Turnleft();
//    delay(60);
//    Stop();
//    delay(50);
//  }
// if(200<b<300){
//    BT.println("Turnleft");    
//    Turnleft();
//    delay(90);
//    Stop();
//    delay(50);
//  }
//  if(200<b<400){
//    BT.println("Turnleft");    
//    Turnleft();
//    delay(120);
//    Stop();
//    delay(50);
//  }
//如果串口接收到数据，就输出到蓝牙串口
//  if (Serial.available()) {
//    val = Serial.read();
//    BT.print(val);
//  }
//  //如果接收到蓝牙模块的数据，输出到屏幕
//  if (BT.available()) {
//    val = BT.read();
//    switch(val){
//    case'0':
//      Stop();
//      Serial.println("Stop");
//      break;
//      
//    case'1':
//      Serial.println("Go Straight");
//      Gostraight();
//      break;
//      
//     case'2': 
//      Serial.println("Go Back");
//      Gosback();
//      break;
//      
//    case'3':
//      Serial.println("Turn Left");
//      Turnleft();
//      break;
//
//    case'4':
//      Serial.println("Turn Right");
//      Turnright();
//      break;
//
//    case'5':
//      Serial.println("Beep");
//      for(i=2;i>0;i--){
//      digitalWrite(11,HIGH);
//      delay(90);
//      digitalWrite(11,LOW);
//      delay(90);    }  
//      break;
//      
//     case'6':
//      Serial.println("Opean Light");
//      digitalWrite(3,LOW);
//      break;
//
//      case'7':
//      Serial.println("Close Light");
//      digitalWrite(3,HIGH);
//      break;
//
//  }}
}





void Stop(){  
       digitalWrite(7,LOW);//前左 IN1
       digitalWrite(6,LOW);//前左 IN2
       digitalWrite(5,LOW);//前右 IN3
       digitalWrite(4,LOW);//前右 IN4

}
void Gosback(){  
       digitalWrite(7,HIGH);//前左 IN1
       digitalWrite(6,LOW);//前左 IN2
       digitalWrite(5,HIGH);//前右 IN3
       digitalWrite(4,LOW);//前右 IN4

}      
void Gostraight(){  
       digitalWrite(7,LOW);//前左 IN1
       digitalWrite(6,HIGH);//前左 IN2
       digitalWrite(5,LOW);//前右 IN3
       digitalWrite(4,HIGH);//前右 IN4

}
       
void Turnright(){
        digitalWrite(7,HIGH);//前左 IN1
       digitalWrite(6,LOW);//前左 IN2
        digitalWrite(5,LOW);//前右 IN3
         digitalWrite(4,HIGH);//前右 IN4

}

void Turnleft(){
        digitalWrite(5,HIGH);//前右 IN3
         digitalWrite(4,LOW);//前右 IN4
         digitalWrite(7,LOW);//前左 IN1
       digitalWrite(6,HIGH);//前左 IN2

}
