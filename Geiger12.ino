/*
  SparkFun Geiger Counter
  Official v12 firmware on Arduino
  
 created 10 Jan 2015
 by Rin FUKUDA 
 jg1vgx@jarl.com
 */
 
// Constants
#define LEDPIN A5  // Counter LED (green)
 
// Variables
volatile long j=0;      // Interval since the last count
volatile long jlast;    // previous interval
byte cbit;     // '0' or '1' for char output on terminal
 
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
} 

void loop() { 
  digitalWrite(LEDPIN, HIGH);   // turn off the LED (HIGH is the voltage level)
  delay(30);                // wait for a short while for counting
  j++;
} 

void onCount() {
  noInterrupts();

  // blink LED
  digitalWrite(LEDPIN, LOW);
  delay(10);

  // check intervals  
  if(jlast < j) cbit = 0;
  if(jlast > j) cbit = 1;
  
  // send byte char to console
  Serial.print(cbit);
  
  // reset intervals
  jlast = j;
  j = 0;
  
  interrupts();
}
