#define trigPin 8
#define echoPin 12
char val; // Data received from the serial port
 int ledPin1 = 5;//right motor
 int ledPin2 = 6; //left motor
 int ledPin3 = 10;//right motor
 int ledPin4 = 11; //left motor
 int sensorReading = 1;
 int sensorReading1 = 1;
 const int UltraSensor= A0; 
 
 void setup() {
 pinMode(ledPin1, OUTPUT); // Set pin as OUTPUT
 pinMode(ledPin2, OUTPUT);
 pinMode(ledPin3, OUTPUT); // Set pin as OUTPUT
 pinMode(ledPin4, OUTPUT);
 pinMode(UltraSensor, INPUT);
 pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 Serial.begin(9600); // Start serial communication at 9600 bps
 //Serial.flush();
 }
 
 void loop() {//digitalWrite(13, LOW);
   
 //Serial.flush(); 
 //val = ''; 
 long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  //Serial.println(distance);
  if (distance < 4) {
 analogWrite(5, 0); 
 analogWrite(6, 0);
 analogWrite(10, 255); // rotate right motor
 analogWrite(11, 255); // rotate left motor
 //val='N';
 delay(1000);
 analogWrite(5, 0); 
 analogWrite(6, 0);
 analogWrite(10, 0); // rotate right motor
 analogWrite(11, 0); // rotate left motor
 }
 else
 digitalWrite(13, LOW);
 if (Serial.available()) // If data is available to read,
 { 
 val = Serial.read();
 Serial.println(val); // read it and store it in val
 
    
 }
 if (val == 'U') // If U was received
 { 
 //digitalWrite(13, LOW);
 analogWrite(5, 255); // rotate right motor
 analogWrite(6, 255); // rotate left motor
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
 analogWrite(6, 255);
 analogWrite(10, 255); // rotate right motor
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
 analogWrite(5, 255); 
 analogWrite(6, 0);
 analogWrite(10, 0); // rotate right motor
 analogWrite(11, 255); // rotate left motor
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
 analogWrite(10, 255); // rotate right motor
 analogWrite(11, 255); // rotate left motor
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
 //int reading=sensorReading/10;
 //int x = 2;
 //Serial.print(sensorReading1);
 //Serial.println(" ");
 Serial.write(sensorReading);
 val='N';
 Serial.flush();
 //sensorReading = 0;
 delay(100);
 
 }
 else {
   delay(100);
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
