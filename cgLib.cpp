#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <cgLib.h>

float degToRad(float deg) {
  return float(deg * 3.14)/ 180.0;
}

void drawLine(float _x1,float _y1,float _x2, float _y2) {
  float x1,x2,y1,y2;
  x1=_x1,y1=_y1;
  x2=_x2,y2=_y2;
  if (x1 > x2) {
    //swap
    float temp = x1;
    x1 = x2;
    x2 = temp;
    temp = y1;
    y1 = y2;
    y2 = temp;
  }
  float dx = x2 - x1;
  float dy = y2 - y1;
  float m = dy/dx;
  float xs = floor(x1+ (1.0/2.0));
  float ys = floor(y1 + m * (xs - x1));
  float yi = ys + m;
  float xsgap = floor(xs) + (1.0/2.0) - x1;
  putpixel(xs,floor(ys),(floor(ys)+1-ys)*xsgap);
  putpixel(xs,floor(ys)+1,(floor(ys)-ys)*xsgap);

  float xf = floor(x2 + (1.0/2.0));
  float yf = floor(y2 + m * (xf - x2));

  float xfgap = x2 + (1.0/2.0) - floor(x2 - (1.0/2.0));

  putpixel(xf,floor(yf),(floor(yf)+1-yf)*xfgap);
  putpixel(xf,floor(yf)+1,(yf-floor(yf))*xfgap);

  for(int x = xs+1;x<= xf-1;x++) {
    putpixel(x,floor(yi),floor(yi)+1-yi);
    printf("%f\n",floor(yi)+1-yi);
    printf("%f\n",yi-floor(yi));
    putpixel(x,floor(yi)+1,yi-floor(yi)+1);
    yi = yi + m;
  }

}

void drawCircle(float _xc, float _yc, float _r) {
  /*
  _xc = x-coordinate of the center of the circle
  _yc = y-coordinated of the center of the circle
  _r = radius of the circle
  */

  /* code */
  float r = _r;
  float xc = _xc, yc = _yc;

  putpixel(floor(xc+0.5),floor(yc+r+0.5),4);
  putpixel(floor(xc+0.5),floor(yc-r+0.5),4);
  putpixel(floor(xc+r+0.5),floor(yc+0.5),4);
  putpixel(floor(xc-r+0.5),floor(yc+0.5),4);

  float theta = 1;
  float a0 = 1.0/r;
  float x,y;
  for(theta = 1; theta <= 45; theta++) {
    x = r * cos(degToRad(theta));
    y = r * sin(degToRad(theta));

    putpixel(floor(xc+x+0.5),floor(yc+y+0.5),4);
    putpixel(floor(xc+x+0.5),floor(yc-y+0.5),4);
    putpixel(floor(xc-x+0.5),floor(yc+y+0.5),4);
    putpixel(floor(xc-x+0.5),floor(yc-y+0.5),4);
    putpixel(floor(xc+y+0.5),floor(yc+x+0.5),4);
    putpixel(floor(xc+y+0.5),floor(yc-x+0.5),4);
    putpixel(floor(xc-y+0.5),floor(yc+x+0.5),4);
    putpixel(floor(xc-y+0.5),floor(yc-x+0.5),4);

    theta = theta + a0;

    if(theta == 45) {
      x = r * cos(degToRad(theta));
      y = r * cos(degToRad(theta));

      putpixel(floor(xc+x+0.5),floor(yc+y+0.5),4);
      putpixel(floor(xc+x+0.5),floor(yc-y+0.5),4);
      putpixel(floor(xc-x+0.5),floor(yc+y+0.5),4);
      putpixel(floor(xc-x+0.5),floor(yc-y+0.5),4);
    }

  }

}
