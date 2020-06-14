#include <Arduino.h>

//timers
unsigned long timer1;
int count1=0;
byte tick=0;//lomg
byte stick=0;//sort

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
int out13 = 12; //Guritojelzo kek
int out14 = 13; //Guritojelzo feher

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

   pinMode(in1, INPUT); //-
   pinMode(in2, INPUT);//Szabad tolatás
   pinMode(in3, INPUT);//-
   pinMode(in4, INPUT);//Megállj
   pinMode(in5, INPUT);//-
   pinMode(in6, INPUT);//Nem biztosított fény bejárati jelző
   pinMode(in7, INPUT);//Megállj
   pinMode(in8, INPUT);//-
   pinMode(in9, INPUT);
   pinMode(in10, INPUT);
   pinMode(in11, INPUT);
   pinMode(in12, INPUT);
   pinMode(in13, INPUT);
   pinMode(in14, INPUT);
}



void tolatasjelzo() {

  if (digitalRead(in2) == HIGH ) {
      digitalWrite(out1, LOW); //Kek le
      digitalWrite(out2, HIGH); //Feher fel
      value1last = 0;
    } else {
      digitalWrite(out1, HIGH); //Kek fel
      digitalWrite(out2, LOW); //Feher le
    }

}

void nbtej(/*Nem biztositott terkoz elojelzo*/) {


  if (digitalRead(in4) == HIGH ) {
      digitalWrite(out3, LOW); //Zold le
      digitalWrite(out4, HIGH); //Sarga fel
      value2last = 0;
    } else {
      digitalWrite(out3, HIGH); //Zold fel
      digitalWrite(out4, LOW); //Sarga le
    }
}

void nbfbj(/*Nem biztosított fény bejárati jelző*/){


  if (digitalRead(in6) == HIGH ) {
      digitalWrite(out5, LOW); //Piros le
      digitalWrite(out6, HIGH); //Sarga fel

    } else {
      digitalWrite(out5, HIGH); //Piros fel
      digitalWrite(out6, LOW); //Sarga le
    }
}

void ismetlojelzo(){
  if (digitalRead(in7) == HIGH)  {
    digitalWrite(out7, HIGH); //Sarga fel
    digitalWrite(out8, LOW); //Zold le

  } else {
    digitalWrite(out7, LOW); //Sarga le
    digitalWrite(out8, HIGH); //Zold fel
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

void guritojelzo(/*Automata terkozjelzo*/){
  if (digitalRead(in12) == HIGH ) { //Gurits
      digitalWrite(out12, LOW); //kek le
      digitalWrite(out13, HIGH); //feher fel
} else if (digitalRead(in13) == HIGH ) { //Gyorsits
 switch (tick) {
   case 1:
   digitalWrite(out13, HIGH);
   break;
   case 0:
   digitalWrite(out13, LOW);
   break;
 }
} else if (digitalRead(in14) == HIGH ) { //Lassits
  switch (tick) {
    case 1:
    digitalWrite(out12, HIGH);
    break;
    case 0:
    digitalWrite(out12, LOW);
    break;
}
} else if (digitalRead(in15) == HIGH ) { //vissza
  digitalWrite(out12, HIGH);
  digitalWrite(out13, HIGH);
} else {
  digitalWrite(out12, HIGH);
  digitalWrite(out13, LOW);
}

}


void loop() {
  tolatasjelzo();
  nbtej(/*Nem biztositott terkoz elojelzo*/);
  nbfbj(/*Nem biztosított fény bejárati jelző*/);
  ismetlojelzo();
  atj(/*Automata terkozjelzo*/);
guritojelzo();

//Timer
if (((millis()-timer1)>=1000) && ((millis()-timer1)<=1100)) {
  tick=1;
}
if (((millis()-timer1)>=2000) && ((millis()-timer1)<=2100)) {
  tick=0;
  timer1 = timer1+millis();
}

}
