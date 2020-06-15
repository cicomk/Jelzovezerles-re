#include <Arduino.h>

//timers
unsigned long timer1;
unsigned long timer2;
int count1=0;
byte tick=0;//lomg
byte stick=0;//sort
//waiting
unsigned long tolatas = 0;
unsigned long nembiztterkoz = 0;
unsigned long nembiztfeny = 0;
unsigned long ismjel = 0;
unsigned long gurito = 0;
unsigned long otf = 0;

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
int out12 = 11;//Guritojelzo kek
int out13 = 12; //Guritojelzo Feher
int out14 = 13;//Ötfényű fehér
int out15 = 14;//Ötfényű zöld
int out16 = 15;//Ötfényű vörös
int out17 = 16;//Ötfényű felső sárga
int out18 = 17;//Ötfényű alsó sárga
int out19 = 18;
int out20 = 19;

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
int in16 = A11; //Zöld
int in17 = A11;
int in18 = A11;
int in19 = A11;
int in20 = A11;
int in21 = A11;
int in22 = A11;
int in23 = A11;
int in24 = A11;
int in25 = A11;
int in26 = A11;
int in27 = A11;
int in28 = A11;
int in29 = A11;
int in30 = A11;


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
if ((millis()-tolatas)>5000){
  if (digitalRead(in2) == HIGH ) {
      digitalWrite(out1, LOW); //Kek le
      digitalWrite(out2, HIGH); //Feher fel
      tolatas = millis();
    } else {
      digitalWrite(out1, HIGH); //Kek fel
      digitalWrite(out2, LOW); //Feher le
    }
}
}

void nbtej(/*Nem biztositott terkoz elojelzo*/) {

if ((millis()-nembiztterkoz)>5000){
  if (digitalRead(in4) == HIGH ) {
      digitalWrite(out3, LOW); //Zold le
      digitalWrite(out4, HIGH); //Sarga fel
      nembiztterkoz = millis();
    } else {
      digitalWrite(out3, HIGH); //Zold fel
      digitalWrite(out4, LOW); //Sarga le
    }
  }
}

void nbfbj(/*Nem biztosított fény bejárati jelző*/){

if ((millis()-nembiztfeny)>5000){
  if (digitalRead(in6) == HIGH ) {
      digitalWrite(out5, LOW); //Piros le
      digitalWrite(out6, HIGH); //Sarga fel
nembiztfeny = millis();
    } else {
      digitalWrite(out5, HIGH); //Piros fel
      digitalWrite(out6, LOW); //Sarga le
    }
  }
}

void ismetlojelzo(){
if ((millis()-ismjel)>5000){
  if (digitalRead(in7) == HIGH)  {
    digitalWrite(out7, HIGH); //Sarga fel
    digitalWrite(out8, LOW); //Zold le
ismjel = millis();
  } else {
    digitalWrite(out7, LOW); //Sarga le
    digitalWrite(out8, HIGH); //Zold fel
  }
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
if ((millis()-gurito)>5000){
  if (digitalRead(in12) == HIGH ) { //Gurits
      digitalWrite(out12, LOW); //kek le
      digitalWrite(out13, HIGH); //feher fel
      gurito = millis();
} else if (digitalRead(in13) == HIGH ) { //Gyorsits
 switch (tick) {
   case 1:
   digitalWrite(out13, HIGH);
   break;
   case 0:
   digitalWrite(out13, LOW);
   break;
   gurito = millis();
 }
} else if (digitalRead(in14) == HIGH ) { //Lassits
  switch (tick) {
    case 1:
    digitalWrite(out12, HIGH);
    break;
    case 0:
    digitalWrite(out12, LOW);
    break;
    gurito = millis();
}
} else if (digitalRead(in15) == HIGH ) { //vissza
  digitalWrite(out12, HIGH);
  digitalWrite(out13, HIGH);
  gurito = millis();
} else {
  digitalWrite(out12, HIGH);
  digitalWrite(out13, LOW);
}
}
}

 void outfenyu(/* 5 fényű */) {
   if ((millis()-otf)>5000){
     if (digitalRead(in16) == HIGH)  {//zold
       digitalWrite(out14, LOW); //Fehér le
       digitalWrite(out15, HIGH);  //Zöld fel
       digitalWrite(out16, LOW); //Vörös le
       digitalWrite(out17, LOW); //Felső sárga le
       digitalWrite(out18, LOW); //Alsó sárga le
   otf = millis();

 } else if (digitalRead(in17) == HIGH)  {//zold lassan villog
       digitalWrite(out14, LOW); //Fehér le
       digitalWrite(out16, LOW); //Vörös le
       digitalWrite(out17, LOW); //Felső sárga le
       digitalWrite(out18, LOW); //Alsó sárga le
       switch (tick) {
         case 1:
         digitalWrite(out15, HIGH);  //Zöld fel
         break;
         case 0:
         digitalWrite(out15, LOW);  //Zöld le
         break;
       }
       otf = millis();

   } else if (digitalRead(in18) == HIGH)  {//zold gyorsan villog
     digitalWrite(out14, LOW); //Fehér le
     digitalWrite(out16, LOW); //Vörös le
     digitalWrite(out17, LOW); //Felső sárga le
     digitalWrite(out18, LOW); //Alsó sárga le
     switch (stick) {
       case 1:
       digitalWrite(out15, HIGH);  //Zöld fel
       break;
       case 0:
       digitalWrite(out15, LOW);  //Zöld le
       break;
     }
     otf = millis();

 } else if (digitalRead(in19) == HIGH)  {//felso sarga
   digitalWrite(out14, LOW); //Fehér le
   digitalWrite(out15, LOW);  //Zöld le
   digitalWrite(out16, LOW); //Vörös le
   digitalWrite(out17, HIGH); //Felső sárga fel
   digitalWrite(out18, LOW); //Alsó sárga le
   otf = millis();
 } else if (digitalRead(in20) == HIGH)  {//felso sarga lassan villog
   digitalWrite(out14, LOW); //Fehér le
   digitalWrite(out16, LOW); //Vörös le
   digitalWrite(out15, LOW); //zold
   digitalWrite(out18, LOW); //Alsó sárga le
   switch (tick) {
     case 1:
     digitalWrite(out17, HIGH);  //felso sarga fel
     break;
     case 0:
     digitalWrite(out17, LOW);  //Zöld le
     break;
   }
   otf = millis();
} else if (digitalRead(in21) == HIGH)  {//alsó sárga és zöld világít
  digitalWrite(out14, LOW); //Fehér le
  digitalWrite(out15, HIGH);  //Zöld fel
  digitalWrite(out16, LOW); //Vörös le
  digitalWrite(out17, LOW); //Felső sárga le
  digitalWrite(out18, HIGH); //Alsó sárga fel
  otf = millis();

} else if (digitalRead(in22) == HIGH)  {//alsó sárga világít és zöld lassan villog
  digitalWrite(out14, LOW); //Fehér le
  digitalWrite(out16, LOW); //Vörös le
  digitalWrite(out17, LOW); //felso sárga le
  digitalWrite(out18, HIGH); //Alsó sárga fel
  switch (tick) {
    case 1:
    digitalWrite(out15, HIGH);  //Zöld fel
    break;
    case 0:
    digitalWrite(out15, LOW);  //Zöld le
    break;
  }
  otf = millis();
} else if (digitalRead(in23) == HIGH)  {//alsó sárga világít és zöld gyorsan villog
  digitalWrite(out14, LOW); //Fehér le
  digitalWrite(out16, LOW); //Vörös le
  digitalWrite(out17, LOW); //felso sárga le
  digitalWrite(out18, HIGH); //Alsó sárga fel
  switch (stick) {
    case 1:
    digitalWrite(out15, HIGH);  //Zöld fel
    break;
    case 0:
    digitalWrite(out15, LOW);  //Zöld le
    break;
  }
  otf = millis();
} else if (digitalRead(in24) == HIGH)  {//alsó sárga világít, felső sárga világít
  digitalWrite(out14, LOW); //Fehér le
  digitalWrite(out16, LOW); //Vörös le
  digitalWrite(out17, HIGH); //felso sárga fel
  digitalWrite(out18, HIGH); //Alsó sárga fel
  digitalWrite(out15, LOW);  //Zöld le
  otf = millis();
} else if (digitalRead(in25) == HIGH)  {//alsó sárga világít, felső sárga lassan villog
  digitalWrite(out14, LOW); //Fehér le
  digitalWrite(out16, LOW); //Vörös le
  digitalWrite(out15, LOW); //zöld le
  digitalWrite(out18, HIGH); //Alsó sárga fel
  switch (tick) {
    case 1:
    digitalWrite(out17, HIGH);  //felso sárga fel
    break;
    case 0:
    digitalWrite(out17, LOW);  //felso sárga le
    break;
  }
  otf = millis();
} else if (digitalRead(in26) == HIGH)  {//vörös világít, fehér lassan villog
  digitalWrite(out17, LOW); //felso sárga le
  digitalWrite(out16, HIGH); //Vörös fel
  digitalWrite(out15, LOW); //zöld le
  digitalWrite(out18, LOW); //Alsó sárga le
  switch (tick) {
    case 1:
    digitalWrite(out14, HIGH);  //feher fel
    break;
    case 0:
    digitalWrite(out14, LOW);  //feher le
    break;
  }
  otf = millis();
}  else if (digitalRead(in27) == HIGH)  {//fehér világít
  digitalWrite(out14, HIGH); //Fehér fel
  digitalWrite(out16, LOW); //Vörös le
  digitalWrite(out17, LOW); //felso sárga le
  digitalWrite(out18, LOW); //Alsó sárga le
  digitalWrite(out15, LOW);  //Zöld le
  otf = millis();
} else {
  digitalWrite(out14, LOW); //Fehér le
  digitalWrite(out16, HIGH); //Vörös fel
  digitalWrite(out17, LOW); //felso sárga le
  digitalWrite(out18, LOW); //Alsó sárga le
  digitalWrite(out15, LOW);  //Zöld le
}
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
//long
if (((millis()-timer1)>=500) && ((millis()-timer1)<=600)) {
  tick=1;
}
if (((millis()-timer1)>=1000) && ((millis()-timer1)<=1100)) {
  tick=0;
  timer1 = millis();
}

//sort
if (((millis()-timer2)>=250) && ((millis()-timer2)<=350)) {
  stick=1;
}
if (((millis()-timer2)>=500) && ((millis()-timer2)<=600)) {
  stick=0;
  timer2 = millis();
}

}
