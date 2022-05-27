  #include <Servo.h>

  /**************initializing motors and buttons************/
  Servo myservo;
  Servo myservo1;
  Servo myservo2;
  Servo myservo3;
  Servo myservo4;
  Servo myservo5;
  int   intializing_flag=0;
  int Button=13;
  int button_state=0;
  void initialize();
void setup() {
  //setting the button  
  pinMode(Button,INPUT_PULLUP);
   
/*setting the servos*/
  myservo.attach(3);       //base 
  myservo1.attach(A1);     
  myservo2.attach(6);
  myservo3.attach(A3);
  myservo4.attach(9);
  myservo5.attach(A5);


 initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
 button_state = digitalRead(Button);
 if(button_state== HIGH)
 {
  if(intializing_flag!=0)
  {
    initialize();
    intializing_flag=0;
  }
 }

 else if(button_state==LOW)
 {
  moving();
  intializing_flag=1;
 
 }
  
}
void initialize()
{
  delay(800);
  myservo.write(0);

  myservo1.write(60);
  delay(800);

  myservo5.write(0);
  delay(800);

  myservo4.write(90);
  delay(800);

  myservo3.write(30);
  delay(800);


  myservo2.write(30);
  delay(800);
  
  for(int init_pos=60;init_pos>0;init_pos-=2)
     {   
         myservo1.write(init_pos);
         delay (50);
     } 
  delay(500);
}

void moving()
{
  for(int init_pos=0;init_pos<90;init_pos+=2)
     {   
         myservo1.write(init_pos);
         delay (50);
     } 

     for(int init_pos=30;init_pos<120;init_pos+=2)
     {   
         myservo2.write(init_pos);
         delay (50);
     } 
     for(int init_pos=30;init_pos<115;init_pos+=2)
     {   
         myservo3.write(init_pos);
         delay (20);
     }
      myservo5.write(80);
      delay(2000);
      
      myservo.write(0);
    
      myservo1.write(60);
      delay(800);
    
      myservo4.write(90);
      delay(800);
    
      myservo3.write(30);
      delay(800);
    
    
      myservo2.write(30);
      delay(800);
  
     myservo.write(90);
     /*after rotating to leave the piece*/
     for(int init_pos=0;init_pos<90;init_pos+=2)
     {   
         myservo1.write(init_pos);
         delay (50);
     } 

     for(int init_pos=30;init_pos<120;init_pos+=2)
     {   
         myservo2.write(init_pos);
         delay (50);
     } 
     for(int init_pos=30;init_pos<115;init_pos+=2)
     {   
         myservo3.write(init_pos);
         delay (20);
     }
     for(int init_pos=90;init_pos>0;init_pos-=2)
     {   
         myservo4.write(init_pos);
         delay (20);
     }
     myservo5.write(0);

     for(int init_pos=90;init_pos>0;init_pos-=2)
     {   
         myservo1.write(init_pos);
         delay (50);
     }
}
