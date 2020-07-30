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
unsigned long atjelzo = 0;
unsigned long bfke = 0;

//valuelast
int value1last = 0;
int value2last = 0;
int value3last = 0;
int value4last = 0;
int value5last = 0;


//Out
int out1 = 33;  //tolatasjelzo Kek feny
int out2 = 32;  //tolatasjelzo Feher feny
int out3 = 44;  //nembiztositott Zold feny
int out4 = 43;  //nembiztositott Sarga feny
int out5 = 48;  //Nem biztosított fény bejárati jelzők Piros
int out6 = 47;  //Nem biztosított fény bejárati jelzők Sarga
int out7 = 39;  //Ismetlojelzo sarga
int out8 = 40;  //Ismetlojelzo Zold
int out7f = 41;  //Ismetlojelzo sarga Feher
int out8f = 42;  //Ismetlojelzo Zold Feher
int out9 = 37; //Térköz vörös
int out10 = 36; //Térköz sárga
int out11 = 38; //Térköz zöld
int out12 = 35;//Guritojelzo kek
int out13 = 34; //Guritojelzo Feher
int out14 = 49;//Ötfényű fehér
int out15 = 53;//Ötfényű zöld
int out16 = 51;//Ötfényű vörös
int out17 = 52;//Ötfényű felső sárga
int out18 = 50;//Ötfényű alsó sárga
int out19 = 46;
int out20 = 45;

//In
int in1 = A0; //Tolatasjelzo Kek
int in2 = 7; //Tolatasjelzo Feher
int in3 = A2; //Nem biztositott terkoz elojelzo zold
int in4 = 15; //Nem biztositott terkoz elojelzo sarga
int in5 = A4; //Nem biztosított fény bejárati jelzők Piros
int in6 = 19; //Nem biztosított fény bejárati jelzők Sarga
int in7 = 14; //Ismetlojelzo sarga
int in8 = 8; //Ismetlojelzo Zold
int in9 = 12; //Automata terkozjelzo Zold
int in10 = A9; //Automata terkozjelzo Piros
int in11 = A10; //Automata terkozjelzo Sarga
int in12 = 11;
int in13 = 10;
int in14 = 9;
int in15 = 13;
int in16 = 31; //Zöld
int in17 = 30;
int in18 = 29;
int in19 = 28;
int in20 = 27;
int in21 = 26;
int in22 = 25;
int in23 = 24;
int in24 = 23;
int in25 = 22;
int in26 = 21;
int in27 = 20;
int in28 = 18;
int in29 = 17;
int in30 = 16;


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
  pinMode(out15, OUTPUT);
  pinMode(out16, OUTPUT);
  pinMode(out17, OUTPUT);
  pinMode(out18, OUTPUT);
  pinMode(out19, OUTPUT);
  pinMode(out20, OUTPUT);
  pinMode(out7f, OUTPUT);
  pinMode(out8f, OUTPUT);


   pinMode(in1, INPUT_PULLUP); //-
   pinMode(in2, INPUT_PULLUP);//Szabad tolatás
   pinMode(in3, INPUT_PULLUP);//-
   pinMode(in4, INPUT_PULLUP);//Megállj
   pinMode(in5, INPUT_PULLUP);//-
   pinMode(in6, INPUT_PULLUP);//Nem biztosított fény bejárati jelző
   pinMode(in7, INPUT_PULLUP);//Megállj
   pinMode(in8, INPUT_PULLUP);//-
   pinMode(in9, INPUT_PULLUP);
   pinMode(in10, INPUT_PULLUP);
   pinMode(in11, INPUT_PULLUP);
   pinMode(in12, INPUT_PULLUP);
   pinMode(in13, INPUT_PULLUP);
   pinMode(in14, INPUT_PULLUP);
   pinMode(in15, INPUT_PULLUP); //-
   pinMode(in16, INPUT_PULLUP);//Szabad tolatás
   pinMode(in17, INPUT_PULLUP);//-
   pinMode(in18, INPUT_PULLUP);//Megállj
   pinMode(in19, INPUT_PULLUP);//-
   pinMode(in20, INPUT_PULLUP);//Nem biztosított fény bejárati jelző
   pinMode(in21, INPUT_PULLUP);//Megállj
   pinMode(in22, INPUT_PULLUP);//-
   pinMode(in23, INPUT_PULLUP);
   pinMode(in24, INPUT_PULLUP);
   pinMode(in25, INPUT_PULLUP);
   pinMode(in26, INPUT_PULLUP);
   pinMode(in27, INPUT_PULLUP);
   pinMode(in28, INPUT_PULLUP);
}




void tolatasjelzo() {
if ((millis()-tolatas)>5000){
  if (digitalRead(in2) == LOW ) {
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
  if (digitalRead(in4) == LOW ) {
      digitalWrite(out3, HIGH); //Zold le
      digitalWrite(out4, LOW); //Sarga fel
      nembiztterkoz = millis();
    } else {
      digitalWrite(out3, LOW); //Zold fel
      digitalWrite(out4, HIGH); //Sarga le
    }
  }
}

void nbfbj(/*Nem biztosított fény bejárati jelző*/){

if ((millis()-nembiztfeny)>5000){
  if (digitalRead(in6) == LOW ) {
      digitalWrite(out5, LOW); //Piros le
      digitalWrite(out6, HIGH); //Sarga fel
nembiztfeny = millis();
    } else {
      digitalWrite(out5, HIGH); //Piros fel
      digitalWrite(out6, LOW); //Sarga le
    }
  }
}

void bfej(){

if ((millis()-bfke)>5000){
  if (digitalRead(in28) == LOW ) {
      digitalWrite(out19, HIGH); //Zöld
      digitalWrite(out20, LOW); //Sarga
bfke = millis();
}else if (digitalRead(in29) == LOW ) {
     switch (tick) {
       case 1:
       digitalWrite(out19, HIGH); //Zöld
       digitalWrite(out20, LOW); //Sarga
       break;
       case 0:
       digitalWrite(out19, LOW); //Zöld
       digitalWrite(out20, LOW); //Sarga
       break;
       bfke = millis();
     }
   }else if (digitalRead(in30) == LOW ) {
     switch (tick) {
       case 1:
       digitalWrite(out19, LOW); //Zöld
       digitalWrite(out20, HIGH); //Sarga
       break;
       case 0:
       digitalWrite(out13, LOW);
       digitalWrite(out12, LOW);
       break;
       bfke = millis();
     }
    } else {
      digitalWrite(out19, LOW);
      digitalWrite(out20, HIGH);
    }
  }
}

void ismetlojelzo(){
if ((millis()-ismjel)>5000){
  if (digitalRead(in7) == LOW)  {
    digitalWrite(out7, LOW); //Sarga fel
    digitalWrite(out8, HIGH); //Zold le
    digitalWrite(out7f, LOW); //Sarga fel
    digitalWrite(out8f, HIGH); //Zold le
ismjel = millis();
  } else {
    digitalWrite(out7, HIGH); //Sarga le
    digitalWrite(out8, LOW); //Zold fel
    digitalWrite(out7f, HIGH); //Sarga le
    digitalWrite(out8f, LOW); //Zold fel
  }
}

}

void atj(/*Automata terkozjelzo*/){
  //https://adoc.tips/magyar-a-mav-es-gysev-vonalain-hasznalt-fenyjelz-berendezese.html
  if ((millis()-atjelzo)>5000) {
    if (digitalRead(in9) == LOW ) { //sarga feny
        digitalWrite(out9, LOW); //Vörös le
        digitalWrite(out10, HIGH); //sárga fel
        digitalWrite(out11, LOW); //zöld le
        atjelzo = millis();
    }/* else if (digitalRead(in13) == LOW ) { //sarga villog
    switch (tick) {
     case 1:
     digitalWrite(out9, LOW); //Vörös le
     digitalWrite(out10, HIGH); //sárga fel
     digitalWrite(out11, LOW); //zöld le
     break;
     case 0:
     digitalWrite(out9, LOW); //Vörös le
     digitalWrite(out10, LOW); //sárga le
     digitalWrite(out11, LOW); //zöld le
     break;
     atjelzo = millis();
    }
  } else if (digitalRead(in14) == HIGH ) { //zold villog
    switch (tick) {
      case 1:
      digitalWrite(out9, LOW); //Vörös le
      digitalWrite(out10, LOW); //sárga le
      digitalWrite(out11, HIGH); //zöld le
      break;
      case 0:
      digitalWrite(out9, LOW); //Vörös le
      digitalWrite(out10, LOW); //sárga le
      digitalWrite(out11, LOW); //zöld le
      break;
      atjelzo = millis();
    }
  } */else if (digitalRead(in15) == LOW ) { //zöld
    digitalWrite(out9, HIGH); //Vörös le
    digitalWrite(out10, LOW); //sárga le
    digitalWrite(out11, LOW); //zöld le
    atjelzo = millis();
    } else {
      digitalWrite(out9, LOW); //Vörös le
      digitalWrite(out10, LOW); //sárga le
      digitalWrite(out11, HIGH); //zöld le
    }


  }
}

void guritojelzo(/*Automata terkozjelzo*/){
if ((millis()-gurito)>5000){
  if (digitalRead(in12) == LOW ) { //Gurits
      digitalWrite(out12, LOW); //kek le
      digitalWrite(out13, HIGH); //feher fel
      gurito = millis();
} else if (digitalRead(in13) == LOW ) { //Gyorsits
 switch (tick) {
   case 1:
   digitalWrite(out13, HIGH);
   digitalWrite(out12, LOW);
   break;
   case 0:
   digitalWrite(out13, LOW);
   digitalWrite(out12, LOW);
   break;
   gurito = millis();
 }
} else if (digitalRead(in14) == LOW ) { //Lassits
  switch (tick) {
    case 1:
    digitalWrite(out12, HIGH);
    digitalWrite(out13, LOW);
    break;
    case 0:
    digitalWrite(out12, LOW);
    digitalWrite(out13, LOW);
    break;
    gurito = millis();
}
} else if (digitalRead(in8) == LOW ) { //vissza
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
     if (digitalRead(in16) == LOW)  {//zold
       digitalWrite(out14, LOW); //Fehér le
       digitalWrite(out15, HIGH);  //Zöld fel
       digitalWrite(out16, LOW); //Vörös le
       digitalWrite(out17, LOW); //Felső sárga le
       digitalWrite(out18, LOW); //Alsó sárga le
   otf = millis();

 } else if (digitalRead(in17) == LOW)  {//zold lassan villog
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

   } else if (digitalRead(in18) == LOW)  {//zold gyorsan villog
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

 } else if (digitalRead(in19) == LOW)  {//felso sarga
   digitalWrite(out14, LOW); //Fehér le
   digitalWrite(out15, LOW);  //Zöld le
   digitalWrite(out16, LOW); //Vörös le
   digitalWrite(out17, HIGH); //Felső sárga fel
   digitalWrite(out18, LOW); //Alsó sárga le
   otf = millis();
 } else if (digitalRead(in20) == LOW)  {//felso sarga lassan villog
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
} else if (digitalRead(in21) == LOW)  {//alsó sárga és zöld világít
  digitalWrite(out14, LOW); //Fehér le
  digitalWrite(out15, HIGH);  //Zöld fel
  digitalWrite(out16, LOW); //Vörös le
  digitalWrite(out17, LOW); //Felső sárga le
  digitalWrite(out18, HIGH); //Alsó sárga fel
  otf = millis();

} else if (digitalRead(in22) == LOW)  {//alsó sárga világít és zöld lassan villog
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
} else if (digitalRead(in23) == LOW)  {//alsó sárga világít és zöld gyorsan villog
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
} else if (digitalRead(in24) == LOW)  {//alsó sárga világít, felső sárga világít
  digitalWrite(out14, LOW); //Fehér le
  digitalWrite(out16, LOW); //Vörös le
  digitalWrite(out17, HIGH); //felso sárga fel
  digitalWrite(out18, HIGH); //Alsó sárga fel
  digitalWrite(out15, LOW);  //Zöld le
  otf = millis();
} else if (digitalRead(in25) == LOW)  {//alsó sárga világít, felső sárga lassan villog
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
} else if (digitalRead(in26) == LOW)  {//vörös világít, fehér lassan villog
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
}  else if (digitalRead(in27) == LOW)  {//fehér világít
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
outfenyu();
bfej();
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
