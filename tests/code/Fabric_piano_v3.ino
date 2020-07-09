#include "pins_arduino.h" // Arduino pre-1.0 needs this
int key1=A0;
int key2=A1;
int key3=A2;
int key4=A3;
int key5=A4;

int speaker = 3; // name of the speaker key

int touchValue1,touchValue2, touchValue3, touchValue4, touchValue5; //read sensor values

// musical notes
int C6 = 1046;
int CS6 = 1109;
int D6 = 1175;
int DS6 = 1245;
int E6 = 1319;

void setup() {
pinMode(key1,INPUT);
pinMode(key2,INPUT);
pinMode(key3,INPUT); 
pinMode(key2,INPUT);
pinMode(key3,INPUT);  
pinMode(speaker,OUTPUT);
Serial.begin(9600);
}

void loop() {
   touchValue1 = readCapacitivePin(key1); // read the capacitance in key1
   touchValue2 = readCapacitivePin(key2); // read the capacitance in key2
   touchValue3 = readCapacitivePin(key3); // read the capacitance in key3
//    Serial.println(touchValue);           // send touchValue to the computer
//      delay(100);                           // delay for 1/10 of a second
    if(touchValue1!=2 && touchValue1>=3)
    {tone(speaker, C6);}
    if(touchValue2!=2 && touchValue2>=3)
    {tone(speaker, CS6);}
    if(touchValue3!=2 && touchValue3>=3)
    {tone(speaker, D6);}
    if(touchValue4!=2 && touchValue4>=3)
    {tone(speaker, DS6);}
    if(touchValue5!=2 && touchValue5>=3)
    {tone(speaker, E6);}
    else
    {noTone(speaker);}
}
// readCapacitivePin

//  Input: Arduino pin number

//  Output: A number, from 0 to 17 expressing

//  how much capacitance is on the pin

//  When you touch the pin, or whatever you have

//  attached to it, the number will get higher


uint8_t readCapacitivePin(int pinToMeasure) {

  // Variables used to translate from Arduino to AVR pin naming

  volatile uint8_t* port;

  volatile uint8_t* ddr;

  volatile uint8_t* pin;

  // Here we translate the input pin number from

  //  Arduino pin number to the AVR PORT, PIN, DDR,

  //  and which bit of those registers we care about.

  byte bitmask;

  port = portOutputRegister(digitalPinToPort(pinToMeasure));

  ddr = portModeRegister(digitalPinToPort(pinToMeasure));

  bitmask = digitalPinToBitMask(pinToMeasure);

  pin = portInputRegister(digitalPinToPort(pinToMeasure));

  // Discharge the pin first by setting it low and output

  *port &= ~(bitmask);

  *ddr  |= bitmask;

  delay(1);

  uint8_t SREG_old = SREG; //back up the AVR Status Register

  // Prevent the timer IRQ from disturbing our measurement

  noInterrupts();

  // Make the pin an input with the internal pull-up on

  *ddr &= ~(bitmask);

  *port |= bitmask;



  // Now see how long the pin to get pulled up. This manual unrolling of the loop

  // decreases the number of hardware cycles between each read of the pin,

  // thus increasing sensitivity.

  uint8_t cycles = 17;

  if (*pin & bitmask) { cycles =  0;}

  else if (*pin & bitmask) { cycles =  1;}

  else if (*pin & bitmask) { cycles =  2;}

  else if (*pin & bitmask) { cycles =  3;}

  else if (*pin & bitmask) { cycles =  4;}

  else if (*pin & bitmask) { cycles =  5;}

  else if (*pin & bitmask) { cycles =  6;}

  else if (*pin & bitmask) { cycles =  7;}

  else if (*pin & bitmask) { cycles =  8;}

  else if (*pin & bitmask) { cycles =  9;}

  else if (*pin & bitmask) { cycles = 10;}

  else if (*pin & bitmask) { cycles = 11;}

  else if (*pin & bitmask) { cycles = 12;}

  else if (*pin & bitmask) { cycles = 13;}

  else if (*pin & bitmask) { cycles = 14;}

  else if (*pin & bitmask) { cycles = 15;}

  else if (*pin & bitmask) { cycles = 16;}



  // End of timing-critical section; turn interrupts back on if they were on before, or leave them off if they were off before

  SREG = SREG_old;



  // Discharge the pin again by setting it low and output

  //  It's important to leave the pins low if you want to 

  //  be able to touch more than 1 sensor at a time - if

  //  the sensor is left pulled high, when you touch

  //  two sensors, your body will transfer the charge between

  //  sensors.

  *port &= ~(bitmask);

  *ddr  |= bitmask;



  return cycles;

}
