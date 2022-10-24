#ifndef MODULE_BUZZER
#define MODULE_BUZZER

String digitPad(int d) {
  
for(int i=0; i<255; i++) { //do this 255 times
    analogWrite(buzzer, i); //raise the voltage sent out of the pin by 1
    delay(10); //wait 10 milliseconds to repeat 
  }

  for(int i=255; i>0; i--) { // do this 255 times
    analogWrite(buzzer, i); //lower the voltage sent out of the pin by 1
    delay(10); //wait 10 milliseconds to repeat
    
  }

#endif