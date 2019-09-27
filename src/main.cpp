#include <Arduino.h>

//timers
unsigned long timer1;
int count1=0;
byte tick=0;

//valuelast
int value1last = 0;
int value2last = 0;
int value3last = 0;
int value4last = 0;
int value5last = 0;


//Out
int out1 = 0;  //tolatasjelzo Kek feny
int out2 = 1;  //tolatasjelzo Feher feny
int out3 = 2;  //nembiztositott Zold feny
int out4 = 3;  //nembiztositott Sarga feny
int out5 = 4;  //Nem biztosított fény bejárati jelzők Piros
int out6 = 5;  //Nem biztosított fény bejárati jelzők Sarga
int out7 = 6;  //Ismetlojelzo sarga
int out8 = 7;  //Ismetlojelzo Zold
int out9 = 8;
int out10 = 9;
int out11 = 10;
int out12 = 11;
int out13 = 12;
int out14 = 13;

//In
int in1 = A0; //Tolatasjelzo Kek
int in2 = A1; //Tolatasjelzo Feher
int in3 = A2; //Nem biztositott terkoz elojelzo zold
int in4 = A3; //Nem biztositott terkoz elojelzo sarga
int in5 = A4; //Nem biztosított fény bejárati jelzők Piros
int in6 = A5; //Nem biztosított fény bejárati jelzők Sarga
int in7 = A6; //Ismetlojelzo sarga
int in8 = A7; //Ismetlojelzo Zold
int in9 = A8; //Automata terkozjelzo Zold
int in10 = A9; //Automata terkozjelzo Piros
int in11 = A10; //Automata terkozjelzo Sarga
int in12 = A11;
int in13 = A11;
int in14 = A11;
int in15 = A11;


void setup() {
  Serial.begin(9600);
  Serial.println("Arduino");
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);
  pinMode(out5, OUTPUT);
  pinMode(out6, OUTPUT);
  pinMode(out7, OUTPUT);
  pinMode(out8, OUTPUT);
  pinMode(out9, OUTPUT);
  pinMode(out10, OUTPUT);
  pinMode(out11, OUTPUT);
  pinMode(out12, OUTPUT);
  pinMode(out13, OUTPUT);
  pinMode(out14, OUTPUT);

   pinMode(in1, INPUT); //kek fel
   pinMode(in2, INPUT);
   pinMode(in3, INPUT);
   pinMode(in4, INPUT);
   pinMode(in5, INPUT);
   pinMode(in6, INPUT);
   pinMode(in7, INPUT);
   pinMode(in8, INPUT);
   pinMode(in9, INPUT);
   pinMode(in10, INPUT);
   pinMode(in11, INPUT);
   pinMode(in12, INPUT);
   pinMode(in13, INPUT);
   pinMode(in14, INPUT);
}



void tolatasjelzo() {

  if ((digitalRead(in1) == HIGH) && (value1last == 0)) {
    digitalWrite(out1, HIGH); //Kek fel
    digitalWrite(out2, LOW); //Feher le
    value1last = 1;
  }

  if ((digitalRead(in2) == HIGH ) && (value1last == 1)) {
      digitalWrite(out1, LOW); //Kek le
      digitalWrite(out2, HIGH); //Feher fel
      value1last = 0;
    }

}

void nbtej(/*Nem biztositott terkoz elojelzo*/) {
  if ((digitalRead(in3) == HIGH) && (value2last == 0)) {
    digitalWrite(out3, HIGH); //Zold fel
    digitalWrite(out4, LOW); //Sarga le
    value2last = 1;
  }

  if ((digitalRead(in4) == HIGH ) && (value2last == 1)) {
      digitalWrite(out3, LOW); //Zold le
      digitalWrite(out4, HIGH); //Sarga fel
      value2last = 0;
    }
}

void nbfbj(/*Nem biztosított fény bejárati jelző*/){
  if ((digitalRead(in5) == HIGH) && (value3last == 0)) {
    digitalWrite(out5, HIGH); //Piros fel
    digitalWrite(out6, LOW); //Sarga le
    value3last = 1;
  }

  if ((digitalRead(in6) == HIGH ) && (value3last == 1)) {
      digitalWrite(out5, LOW); //Piros le
      digitalWrite(out6, HIGH); //Sarga fel
      value3last = 0;
    }
}

void ismetlojelzo(){
  if ((digitalRead(in7) == HIGH) && (value4last == 0)) {
    digitalWrite(out7, HIGH); //Sarga fel
    digitalWrite(out8, LOW); //Zold le
    value4last = 1;
  }

  if ((digitalRead(in8) == HIGH ) && (value4last == 1)) {
      digitalWrite(out7, LOW); //Sarga le
      digitalWrite(out8, HIGH); //Zold fel
      value4last = 0;
    }
}

void atj(/*Automata terkozjelzo*/){
  if (digitalRead(in9) == HIGH)  {
    digitalWrite(out9, HIGH); //Sarga fel
    digitalWrite(out10, LOW); //Zold le
    digitalWrite(out11, LOW); //Zold le
    value4last = 1;
  }
  if (digitalRead(in10) == HIGH ) {
    digitalWrite(out9, LOW); //Sarga le
    digitalWrite(out10, HIGH); //Zold fel
    digitalWrite(out11, LOW); //Zold le
      value4last = 2;
    }
  if (digitalRead(in11) == HIGH ) {
    digitalWrite(out9, LOW); //Sarga le
    digitalWrite(out10, LOW); //Zold fel
    digitalWrite(out11, HIGH); //Zold le
 count1++;
 Serial.println(count1);
      value4last = 3;
      }

  if (count1>=400) {
    Serial.println(tick);
    switch (tick) {
      case 1:
        digitalWrite(out11, HIGH); //Sarga fel

        break;
      case 0:
         digitalWrite(out11, LOW); //Sarga le
         break;

    }
  }
 /*if ((digitalRead(in11) == HIGH ) && ((value5last == 1)||(value5last == 2)||(value5last == 3))) {
         count1++;
         Serial.println(count1);
         if (count1 == 1000) {
           digitalWrite(out9, LOW); //Sarga le
           digitalWrite(out10, LOW); //Zold fel
           value4last = 0;

           if (tick==1) {
             digitalWrite(out11, HIGH);
           }else {
             digitalWrite(out11, LOW);
           }
         }


       }*/


}

void loop() {
  tolatasjelzo();
  nbtej(/*Nem biztositott terkoz elojelzo*/);
  nbfbj(/*Nem biztosított fény bejárati jelző*/);
  ismetlojelzo();
  atj(/*Automata terkozjelzo*/);


//Timer
if (((millis()-timer1)>=2000) && ((millis()-timer1)<=2100)) {
  tick=1;
}else {
  tick=0;
}

}
