/*
   meri kismat mein nahi [ ]
   aaj ke bad , I will not ......
*/
void setup(){
  
}
int wait = 0;
void loop(){
   if(Serial.available() ==1){
      String val = Serial.readString();
      
   }
   else{
      if(wait == 1000){
         wait = 0;
         // do any process here by calling a function
      }
   }
}


// time updates
int hh = 0;
int mm = 0;
int ss = 0;
void time(){
   ss++;
   if(ss > 59){
      ss = 0;
      mm++;
      if(mm > 59){
        mm = 0;
        hh++;
        if(hh > 23){
           hh = 0;
        }
      }
   }
}

/// alarms settings time function  should be befor adding this
bool alarmS = false ;
int a_pins[] = {2,3,4,5}; // output pins
/*
   for (int i = 0; i < 4; i++) {
      pinMode(a_pins[i],OUTPUT);
   }
 */  
   
int ahn[] = {7}; // alarm on hours
int amn[] = {0}; // alarms on minutes
int ahf[] = {7}; // alarm off hours
int amf[] = {5}; // alarms off minutes 
void alarm(){
  for (int i = 0; i < 1; i++) {
      if(ahn[i] == hh && amn[i] == mm){
         digitalWrite(a_pins[i],HIGH);
      }
      if(ahf[i] == hh && amf[i] == mm){
         digitalWrite(a_pins[i],LOW);
      }
  }
}

// automation Dependable 
bool autoS = false ;
int in_pins[] = {A0,A1,A2,A3};
int av[] = {500,500,500,500};
void auto1(){
  for (int i = 0; i < 4; i++) {
     if(analogRead(in_pins[i]) > av[i]){
       digitalWrite(a_pins[i],HIGH);
     }
     else{
       digitalWrite(a_pins[i],LOW);
     }
  }
}

