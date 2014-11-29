char val; // Data received from the serial port
 int ledPin = 13; // Set the pin to digital I/O 13
 int sensorReading = 0;
 const int UltraSensor= A0; 
 
 void setup() {
 pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
 Serial.begin(9600); // Start serial communication at 9600 bps
 }
 
 void loop() {
 if (Serial.available()) { // If data is available to read,
 val = Serial.read(); // read it and store it in val
 }
 if (val == 'U') { // If H was received
 digitalWrite(ledPin, HIGH); // turn the LED on
 }
else if (val == 'R') { // If H was received
 digitalWrite(ledPin, HIGH); // turn the LED on
 }
else if (val == 'L') { // If H was received
 digitalWrite(ledPin, HIGH); // turn the LED on
 }
else if (val == 'B') { // If H was received
 digitalWrite(ledPin, HIGH); // turn the LED on
 } 
 else if (val == 'S') { // If H was received
 sensorReading = analogRead(UltraSensor); // turn the LED on
 Serial.println(sensorReading);
 }
 else {
   digitalWrite(ledPin, LOW); // Otherwise turn it OFF
 }
 delay(100);
 digitalWrite(ledPin, LOW);
 // Wait 100 milliseconds for next reading
 }
