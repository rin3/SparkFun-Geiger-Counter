/*
  SparkFun Geiger Counter
  v20
  - Outputs counts per min on the serial console.
  
 created 12 Jan 2015
 by Rin FUKUDA 
 jg1vgx@jarl.com
 */

// max of unsigned long integer
// 4,294,967,295 (2^32-1)
// cf. 50 days = 4,320,000,000 milliseconds
 
// Constants
#define LEDPIN A5  // Counter LED (green)
 
// Variables
int count = 0;     // counter
unsigned long basetime, endtime;  // keeps the start and end of one minute period in millis()
 
void setup() { 
  // pin I/O settings
  pinMode(LEDPIN, OUTPUT);
  
  // Interrupts on INT0 (OUT)
  attachInterrupt(0, onCount, RISING);
 
  //Initialize serial and wait for port to open:
  Serial.begin(9600); 

  // Wait to settle
  delay(1200);
  interrupts();
  
  Serial.println("SparkFun Geiger Counter");
  Serial.println("firmware v2.0 (JG1VGX)");
  // set current time as the base time
  basetime = millis();
} 

void loop() { 
  // turn off the LED (HIGH is the voltage level)
  digitalWrite(LEDPIN, HIGH);
  // wait for a short while for counting
  delay(30);
  
  endtime = basetime + 60000;
  if (endtime > basetime) {
    // not overflown, compare normally
    if (millis() >= endtime) {
      // if one min has elapsed
      showCount();
    }
  } else {
    // overflown, comparison between overflown values
    if (millis() + 100000 >= endtime + 100000) {
      showCount();
    }
  }
} 

void onCount() {
  noInterrupts();

  // blink LED
  digitalWrite(LEDPIN, LOW);
  delay(10);

  // show dots
  Serial.print('.');
  
  // increment counts
  count++;
  
  interrupts();
}

void showCount() {
      Serial.print(' ');
      Serial.print(count);
      Serial.println(" CPM");    

      count = 0;
      basetime = endtime;  // add 1 min
}
