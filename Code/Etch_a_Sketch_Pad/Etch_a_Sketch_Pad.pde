import processing.serial.*;
Serial myPort;        // The serial port

int pulses;
int NpulsesX;
int NpulsesY;
int pulsesX, pulsesY;
int startX = 100, startY = 100;
void setup () {
  // set the window size:
  size(500, 500);        
  background(0);
  // List all the available serial ports
  println(Serial.list());// look in the window when the program runs to see which port to use
  myPort = new Serial(this, Serial.list()[0], 115200);  // for me com 26 was port 0, so I put a 0 here
  
  // don't generate a serialEvent() unless you get a newline character:
  myPort.bufferUntil('\n');
  // set inital background:
}
void draw () {
  
  if (pulses < 5000) {
      pulsesX = pulses + startX;
    }
    
  if (pulses > 5000) {
      pulsesY = (pulses + startY)- 10000;
    }
  stroke(255);
  
  line(NpulsesX, NpulsesY, pulsesX, pulsesY);
  
  NpulsesX = pulsesX;
  NpulsesY = pulsesY;
}

void serialEvent (Serial myPort) {// triggers when new data comes in

  String pulses_raw = myPort.readStringUntil('\n'); //read until the new line, like print ln

  if (pulses_raw != null) {
    // trim off any whitespace:
    pulses_raw = trim(pulses_raw);
    // convert to an int and map to the screen height:
    pulses = int(pulses_raw); 
 }
}


