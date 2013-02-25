int pulses, pulsesB=10000, A_SIG=0, B_SIG=1, AB_SIG=0, BB_SIG=1;

void setup(){
  attachInterrupt(0, A_RISE, RISING);
  attachInterrupt(1, B_RISE, RISING);
  attachInterrupt(4, AB_RISE, RISING);
  attachInterrupt(5, BB_RISE, RISING);
  Serial.begin(115200);
}//setup


void loop(){
    
}

void A_RISE(){
 detachInterrupt(0);
 A_SIG=1;
 
 if(B_SIG==0)
 pulses++;//moving forward
 if(B_SIG==1)
 pulses--;//moving reverse
 //Serial.println("Right: ");
 Serial.println(pulses);
 attachInterrupt(0, A_FALL, FALLING);
}

void A_FALL(){
  detachInterrupt(0);
 A_SIG=0;
 
 if(B_SIG==1)
 pulses++;//moving forward
 if(B_SIG==0)
 pulses--;//moving reverse
 //Serial.println("Right: ");
 Serial.println(pulses);
 attachInterrupt(0, A_RISE, RISING);  
}

void B_RISE(){
 detachInterrupt(1);
 B_SIG=1;
 
 if(A_SIG==1)
 pulses++;//moving forward
 if(A_SIG==0)
 pulses--;//moving reverse
 //Serial.println("Right: ");
 Serial.println(pulses);
 attachInterrupt(1, B_FALL, FALLING);
}

void B_FALL(){
 detachInterrupt(1);
 B_SIG=0;
 
 if(A_SIG==0)
 pulses++;//moving forward
 if(A_SIG==1)
 pulses--;//moving reverse
 //Serial.println("Right: ");
 Serial.println(pulses);
 attachInterrupt(1, B_RISE, RISING);
}

void AB_RISE(){
 detachInterrupt(4);
 AB_SIG=1;
 
 if(BB_SIG==0)
 pulsesB++;//moving forward
 if(BB_SIG==1)
 pulsesB--;//moving reverse
 //Serial.println("Left: ");
 Serial.println(pulsesB);
 attachInterrupt(4, AB_FALL, FALLING);
}

void AB_FALL(){
  detachInterrupt(4);
 AB_SIG=0;
 
 if(BB_SIG==1)
 pulsesB++;//moving forward
 if(BB_SIG==0)
 pulsesB--;//moving reverse
 //Serial.println("Left: ");
 Serial.println(pulsesB);
 attachInterrupt(4, AB_RISE, RISING);  
}

void BB_RISE(){
 detachInterrupt(5);
 BB_SIG=1;
 
 if(AB_SIG==1)
 pulsesB++;//moving forward
 if(AB_SIG==0)
 pulsesB--;//moving reverse
 //Serial.println("Left: ");
 Serial.println(pulsesB);
 attachInterrupt(5, BB_FALL, FALLING);
}

void BB_FALL(){
 detachInterrupt(5);
 BB_SIG=0;
 
 if(AB_SIG==0)
 pulsesB++;//moving forward
 if(AB_SIG==1)
 pulsesB--;//moving reverse
 //Serial.println("Left: ");
 Serial.println(pulsesB);
 attachInterrupt(5, BB_RISE, RISING);
}
