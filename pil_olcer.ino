#include <LCD5110_Graph.h>
LCD5110 myGLCD(8,9,10,11,12); //LCD pinlerinin hangi Arduino pinlerine bağlı olduğunu belirtiyoruz.
    extern uint8_t SmallFont[]; // Küçük harflerle yazı yazmamızı sağlayan SmallFont'u tanıtıyoruz.
    extern uint8_t MediumNumbers[]; // Ortanca boy sayıları yazmamızı sağlayan MediumNumbers'ı tanıtıyoruz.
    extern uint8_t BigNumbers[]; // Büyük sayıları yazmamızı sağlayan BigNumbers'ı tanıtıyoruz.
    extern uint8_t empty[];
    extern uint8_t yirmi[];
    extern uint8_t kirk[];
    extern uint8_t altmis[];
    extern uint8_t seksen[];
    extern uint8_t full[];
    
float vPow = 4.7; 
float r1 = 100000; 
float r2 = 10000;


void setup() {
    myGLCD.InitLCD(); //Ekranı başlatıyoruz.
    myGLCD.setContrast(60); //Kontrast'ı ayarlıyoruz, "60" iyi bir değer.
pinMode(7,OUTPUT);
digitalWrite(7,LOW);
myGLCD.setFont(MediumNumbers); //Harfleri kullanacağımızı bildiriyoruz.
}

void loop() {
    float v = (analogRead(0) * vPow) / 1024.0; 
    float v2 = v / (r2 / (r1 + r2));



if (v2 <0.9){ 
myGLCD.clrScr(); //Ekranı temizliyoruz.
myGLCD.drawBitmap(0,0,empty,84,48);
myGLCD.printNumF(v2,2,35,15); // Yazacağımız şeyi ve koordinatlarını giriyoruz.
myGLCD.update();
}
if (v2 >0.9 && v2 <1.0){ 
myGLCD.clrScr(); 
myGLCD.drawBitmap(0,0,yirmi,84,48);
myGLCD.printNumF(v2,2,35,15); 
myGLCD.update();
}
if (v2 >1.0 && v2 <1.1){ 
myGLCD.clrScr(); 
myGLCD.drawBitmap(0,0,kirk,84,48);
myGLCD.printNumF(v2,2,35,15); 
myGLCD.update();
}
if (v2 >1.1 && v2 <1.2){ 
myGLCD.clrScr(); 
myGLCD.drawBitmap(0,0,altmis,84,48);
myGLCD.printNumF(v2,2,35,15); 
myGLCD.update();
}
if (v2 >1.2 && v2 <1.3){ 
myGLCD.clrScr(); 
myGLCD.drawBitmap(0,0,seksen,84,48);
myGLCD.printNumF(v2,2,35,15); 
myGLCD.update();
}
if (v2 >1.3){ 
myGLCD.clrScr(); 
myGLCD.drawBitmap(0,0,full,84,48);
myGLCD.printNumF(v2,2,35,15); 
myGLCD.update();
}

}
