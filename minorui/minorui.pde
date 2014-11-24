int triX, triY,x2,y2;// Position of square button
int x1=700;
int y1=500;
int y3=500;
int i=1;
int j;
int circleX, circleY;
color triColor, circleColor, baseColor,currentColor;
color triHighlight, circleHighlight;
boolean circleOverU = false;
boolean circleOverR = false;
boolean circleOverL = false;
boolean circleOverB = false;
boolean triOver = false;
boolean circleOverS = false;
String lines[] = loadStrings("/home/ankit/sketchbook/minorui/list.txt");

void setup()
{
size(1360, 700);
  background(51, 0, 51);
  
  triHighlight = color(150);
  circleHighlight = color(204);
  triColor = color(200);
  circleColor = color(255);
  }


void draw() {
  update(mouseX, mouseY);
  if(circleOverU)
  {
    //fill(96,96,96);
  if (mousePressed == true) {
    fill(255,255,0);
    x2=x1;
    y2=y1-1;
    stroke(255);
    strokeWeight(4);
    line(x1,y1,x2,y2);
    x1=x2;
    y1=y2;
  }
  else 
  fill(196,196,196);
  }
   else if(circleOverR)
  {
    //fill(96,96,96);
  if (mousePressed == true) {
    fill(255,255,0);
    x2=x1+1;
    y2=y1;
    stroke(255);
    strokeWeight(4);
    line(x1,y1,x2,y2);
    x1=x2;
    y1=y2;
  } else {
    fill(196,196,196);
  }
  }
  
  //fill(255,255,255);
   else if(circleOverL)
  {
    //fill(96,96,96);
  if (mousePressed == true) {
    fill(255,255,0);
    x2=x1-1;
    y2=y1;
    stroke(255);
    strokeWeight(4);
    line(x1,y1,x2,y2);
    x1=x2;
    y1=y2;
  } else {
    fill(196,196,196);
  }
  
  //fill(255,255,255);
  }
   else if(circleOverB)
  {
    //fill(96,96,96);
  if (mousePressed == true) {
     fill(255,255,0);
    x2=x1;
    y2=y1+1;
    stroke(255);
    strokeWeight(4);
    line(x1,y1,x2,y2);
    x1=x2;
    y1=y2;
    line(x1,y1,x2,y2);
  }
  else
  fill(196,196,196);
  }
 //else if(circleOverS && mousePressed)
  //{
    //mouseClicked();
  
    //fill(96,96,96);
  //if (mousePressed == true ){
    //mouseClicked();
    //for(i=1;i<=lines.length;i++)
    //text(lines[1],128,y3);
    //y3=y3+4;
    //i++;
    //fill(255,255,0);
   
    //x2=x1+1;
    //y2=y1;
    //stroke(255);
    //strokeWeight(4);
    //line(x1,y1,x2,y2);
    //x1=x2;
    //y1=y2;
  //}
  
  //else
  //fill(196,196,196);
 // }
  else {
    fill(196,196,196);
  }
  //fill(255,255,255);


 //up
 stroke(255);
 text("Sensor Values",115,470);
 //fill(255,255,255);
   ellipse(128,55, 75, 75);
   ellipse(186,110, 75, 75);
   ellipse(70,108, 75, 75);
   ellipse(127,164, 75, 75);
   ellipse(127,400, 75, 75);
   stroke(0);
   fill(51,0,51);
    triangle(113,63.5,128,37.5,143,63.5);//up
    triangle(173, 95, 173, 121, 202, 108);//right
    triangle(54, 108, 83, 95, 83, 121);//left
    triangle(113, 154,143, 154, 128, 183);//bottom
    fill(255,255,255);

}




void mouseClicked(){
  if(circleOverS){
  text(lines[1],128,y3);
  text(lines[1],x2+3,y2+20);
    y3=y3+10;
    i++;
  }
  else
  j++;
  }
  
  
  
  
void update(int x, int y) {
  if ( overCircle(128, 55, 75) ) {
    circleOverU = true;
    }
    else if(overCircle(186,110,75)){
    circleOverR = true;
    }
    else if(overCircle(70,108,75)){
    circleOverL = true;
    }
    else if(overCircle(127,164,75)){
    circleOverB = true;
    }
    else if(overCircle(128,400,75)){
    circleOverS = true;
    //fill(255,255,0)
    }
    //triOver = true;
  else {
    circleOverU = triOver = circleOverR = circleOverL = circleOverB = circleOverS = false;
  }
}


boolean overCircle(int x, int y, int diameter) {
  float disX = x - mouseX;
  float disY = y - mouseY;
  if (sqrt(sq(disX) + sq(disY)) < diameter/2 ) {
    return true;
  } else {
    return false;
  }
}





import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;      // Data received from the serial port

void setup() 
{
  size(200, 200);
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
}

void draw()
{
  if ( myPort.available() > 0) {  // If data is available,
    val = myPort.read();         // read it and store it in val
  }
  background(255);             // Set background to white
  if (val == 0) {              // If the serial value is 0,
    fill(0);                   // set fill to black
  } 
  else {                       // If the serial value is not 0,
    fill(204);                 // set fill to light gray
  }
  rect(50, 50, 100, 100);
}
