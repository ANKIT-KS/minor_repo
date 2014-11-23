int triX, triY,x2,y2;// Position of square button
int x1=700;
int y1=500;
int circleX, circleY;
color triColor, circleColor, baseColor,currentColor;
color triHighlight, circleHighlight;
boolean circleOverU = false;
boolean circleOverR = false;
boolean circleOverL = false;
boolean circleOverB = false;
boolean triOver = false;


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
    y2=y1-4;
    stroke(255);
    strokeWeight(4);
    line(x1,y1,x2,y2);
    x1=x2;
    y1=y2;
  }
 
  else {
    fill(196,196,196);
  }
  
  //fill(255,255,255);
  }
   else if(circleOverR)
  {
    //fill(96,96,96);
  if (mousePressed == true) {
    fill(255,255,0);
    x2=x1+4;
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
   else if(circleOverL)
  {
    //fill(96,96,96);
  if (mousePressed == true) {
    fill(255,255,0);
    x2=x1-4;
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
    y2=y1+4;
    stroke(255);
    strokeWeight(4);
    line(x1,y1,x2,y2);
    x1=x2;
    y1=y2;
    line(x1,y1,x2,y2);
  } else {
    fill(196,196,196);
  }
  }
  //fill(255,255,255);

 //up
 stroke(255);
 //fill(255,255,255);
   ellipse(128,55, 75, 75);
   ellipse(186,110, 75, 75);
   ellipse(70,108, 75, 75);
   ellipse(127,164, 75, 75);
   stroke(0);
   fill(51,0,51);
    triangle(113,63.5,128,37.5,143,63.5);//up
    triangle(173, 95, 173, 121, 202, 108);//right
    triangle(54, 108, 83, 95, 83, 121);//left
    triangle(113, 154,143, 154, 128, 183);//bottom
    fill(255,255,255);

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
    //triOver = true;
  else {
    circleOverU = triOver = circleOverR = circleOverL = circleOverB = false;
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
