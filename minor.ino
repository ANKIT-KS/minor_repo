char val; // Data received from the serial port
 int ledPin1 = 5;//right motor
 int ledPin2 = 6; //left motor
 int sensorReading = 0;
 const int UltraSensor= A0; 
 
 void setup() {
 pinMode(ledPin1, OUTPUT); // Set pin as OUTPUT
 pinMode(ledPin2, OUTPUT);
 Serial.begin(9600); // Start serial communication at 9600 bps
 }
 
 void loop() {
 if (Serial.available()) // If data is available to read,
 { 
 val = Serial.read(); // read it and store it in val
 }
 if (val == 'U') // If U was received
 { 
 analogWrite(ledPin1, 128); // rotate right motor
 analogWrite(ledPin2, 128); // rotate left motor
 val='N';
 delay(10);
 analogWrite(ledPin1, 0); // stop the motor
 analogWrite(ledPin2, 0); //stop the motor
 }
else if (val == 'R') // If R was received
{ 
 analogWrite(ledPin1, 0); 
 analogWrite(ledPin2, 128);
 val='N';
 delay(10);
 analogWrite(ledPin1, 0); 
 analogWrite(ledPin2, 0);
 }
else if (val == 'L') // If L was received
{ 
 analogWrite(ledPin1, 128); 
 analogWrite(ledPin2, 0);
 val='N';
 delay(10);
 analogWrite(ledPin1, 0); 
 analogWrite(ledPin2, 0);
 }
else if (val == 'B') // If B was received
{ 
 analogWrite(ledPin1, -128); 
 analogWrite(ledPin2, -128);
 val='N';
 delay(10);
 analogWrite(ledPin1, 0); 
 analogWrite(ledPin2, 0);
 } 
 else if (val == 'S') // If S was received
 { 
 sensorReading = analogRead(UltraSensor); 
 Serial.write(sensorReading);
 Serial.println(sensorReading);
 val='N';
 delay(10);
 
 }
 else {
 analogWrite(ledPin1, 0); 
 analogWrite(ledPin2, 0); 
 }
 delay(100);
 analogWrite(ledPin1, 0); 
 analogWrite(ledPin2, 0);
 // Wait 100 milliseconds for next reading
 }
