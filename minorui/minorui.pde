int triX, triY;      // Position of square button
int circleX, circleY;
color triColor, circleColor, baseColor,currentColor;
color triHighlight, circleHighlight;
boolean circleOver = false;
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
  if(circleOver)
  {
    //fill(96,96,96);
  if (mousePressed == true) {
    fill(255,255,0);
  } else {
    fill(96,96,96);
  }
  }
 //up
 stroke(255);
 //fill(255,255,255);
   ellipse(128,55, 80, 80);
   stroke(0);
   fill(51,0,51);
    triangle(100, 75, 128, 20, 156, 75);
    triangle(160, 80, 160, 136, 215, 108);//right
    triangle(41, 108, 96, 80, 96, 136);//left
    triangle(100, 141,156, 141, 128, 196);//bottom
    fill(255,255,255);
}


void update(int x, int y) {
  if ( overCircle(128, 55, 80) ) {
    circleOver = true;
    triOver = true;
  } 
  else {
    circleOver = triOver = false;
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
