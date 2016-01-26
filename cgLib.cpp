#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <cgLib.h>

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
