char val; // Data received from the serial port
 int ledPin1 = 5;//right motor
 int ledPin2 = 6; //left motor
 int sensorReading = 0;
 const int UltraSensor= A0; 
 
 void setup() {
 pinMode(ledPin1, OUTPUT); // Set pin as OUTPUT
 pinMode(ledPin2, OUTPUT);
 pinMode(UltraSensor, INPUT);
 Serial.begin(9600); // Start serial communication at 9600 bps
 //Serial.flush();
 }
 
 void loop() {//digitalWrite(13, LOW);
   
 //Serial.flush(); 
 //val = ''; 
 if (Serial.available()) // If data is available to read,
 { 
 val = Serial.read();
 Serial.println(val); // read it and store it in val
 }
 if (val == 'U') // If U was received
 { 
 //digitalWrite(13, LOW);
 analogWrite(5, 128); // rotate right motor
 analogWrite(6, 128); // rotate left motor
 analogWrite(10, 0); // rotate right motor
 analogWrite(11, 0); // rotate left motor
 val='N';
 delay(100);
 analogWrite(5, 0); // stop the motor
 analogWrite(6, 0); //stop the motor
 analogWrite(10, 0); // rotate right motor
 analogWrite(11, 0); // rotate left motor
 //digitalWrite(13, HIGH);
 }
else if (val == 'R') // If R was received
{ 
 analogWrite(5, 0); 
 analogWrite(6, 128);
 analogWrite(10, 0); // rotate right motor
 analogWrite(11, 0); // rotate left motor
 val='N';
 delay(100);
 analogWrite(5, 0); 
 analogWrite(6, 0);
 analogWrite(10, 0); // rotate right motor
 analogWrite(11, 0); // rotate left motor
 }
else if (val == 'L') // If L was received
{ 
 analogWrite(5, 128); 
 analogWrite(6, 0);
 analogWrite(10, 0); // rotate right motor
 analogWrite(11, 0); // rotate left motor
 val='N';
 delay(100);
 analogWrite(5, 0); 
 analogWrite(6, 0);
 analogWrite(10, 0); // rotate right motor
 analogWrite(11, 0); // rotate left motor
 }
else if (val == 'B') // If B was received
{ 
 analogWrite(5, 0); 
 analogWrite(6, 0);
 analogWrite(10, 128); // rotate right motor
 analogWrite(11, 128); // rotate left motor
 val='N';
 delay(100);
 analogWrite(5, 0); 
 analogWrite(6, 0);
 analogWrite(10, 0); // rotate right motor
 analogWrite(11, 0); // rotate left motor
 } 
 else if (val == 'S') // If S was received
 { 
   Serial.flush();
 sensorReading = analogRead(UltraSensor); 
 
 Serial.println(sensorReading);
 //Serial.println(" ");
 Serial.write(sensorReading);
 val='N';
 sensorReading = 0;
 delay(100);
 
 }
 else {
 analogWrite(5, 0); 
 analogWrite(6, 0);
 analogWrite(10, 0); // rotate right motor
 analogWrite(11, 0); // rotate left motor 
 }
 delay(100);
 analogWrite(5, 0); 
 analogWrite(6, 0);
 analogWrite(10, 0); // rotate right motor
 analogWrite(11, 0); // rotate left motor
 // Wait 100 milliseconds for next reading
 }
