#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "cgLib.h"

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

void mid_point(float xc ,float yc, float r){
  int gd=DETECT, gm;
  //initgraph(&gd,&gm,"");
  initwindow(500, 500);
  int i=250,j=500;
  int k;
  for(k=0;k<500;k++)
  putpixel(i,k,3);
  for(k=0;k<500;k++)
  putpixel(k,i,3);
  //initgraph(&gd,&gm,"");
  printf("mid point circle drowing algorithm\n");

  float x,y,p,X,Y;
  //scanf("%f",&xc);
  //scanf("%f",&yc);
  //scanf("%f",&r);
  xc=xc+250;
  yc=250-yc;

  x=0;
  y=floor(r+1/2);
  X=x;
  Y=2*y;
  p=floor(5/4-r+1/2);
  putpixel(floor(xc+1/2)+x,floor(yc+1/2)+y,3);
  putpixel(floor(xc+1/2)+x,floor(yc+1/2)-y,3);
  putpixel(floor(xc+1/2)-x,floor(yc+1/2)+y,3);
  putpixel(floor(xc+1/2)-x,floor(yc+1/2)-y,3);
  while(x<=y)
  {
    x=x+1;
    X=X+2;
    if(p<0)
    {
      p=p+X+1;
    }
    else
    {
      Y=Y-2;
      p=p+X+1-Y;
      y=y-1;
    }
    putpixel(floor(xc+1/2)+x,floor(yc+1/2)+y,3);
    putpixel(floor(xc+1/2)+x,floor(yc+1/2)-y,3);
    putpixel(floor(xc+1/2)-x,floor(yc+1/2)+y,3);
    putpixel(floor(xc+1/2)-x,floor(yc+1/2)-y,3);
    putpixel(floor(xc+1/2)+y,floor(yc+1/2)+x,3);
    putpixel(floor(xc+1/2)+y,floor(yc+1/2)-x,3);
    putpixel(floor(xc+1/2)-y,floor(yc+1/2)+x,3);
    putpixel(floor(xc+1/2)-y,floor(yc+1/2)-x,3);

  }
  delay(3000);
  closegraph();
  //   return 0;
}

void Bresenham_circle(float xc, float yc, float r){
  int gd=DETECT, gm;
  initwindow(500, 500);
  int i=250,j=500;
  int k;
  for(k=0;k<500;k++)
  putpixel(i,k,3);
  for(k=0;k<500;k++)
  putpixel(k,i,3);
  //initgraph(&gd,&gm,"");
  printf("bresenham circle drowing algorithm\n");

  float x,y,p;
  // scanf("%f",&xc);
  //scanf("%f",&yc);
  //scanf("%f",&r);
  xc=xc+250;
  yc=250-yc;
  p=floor(3-(2*r)+1/2);
  x=0;
  y=floor(r+1/2);
  while(x<y)
  {
    putpixel(floor(xc+1/2)+x,floor(yc+1/2)+y,3);
    putpixel(floor(xc+1/2)+x,floor(yc+1/2)-y,3);
    putpixel(floor(xc+1/2)-x,floor(yc+1/2)+y,3);
    putpixel(floor(xc+1/2)-x,floor(yc+1/2)-y,3);
    putpixel(floor(xc+y+1/2),floor(yc+x+1/2),3);
    putpixel(floor(xc+y+1/2),floor(yc-x+1/2),3);
    putpixel(floor(xc-y+1/2),floor(yc+x+1/2),3);
    putpixel(floor(xc-y+1/2),floor(yc-x+1/2),3);
    x=x+1;
    if(p<0)
    {
      p=p+(4*x)+6;
    }
    else
    {
      y=y-1;
      p=p+(4*(x-y))+10;
    }
  }
  delay(30000);
  closegraph();
  //    return 0;
}

void Bresenham(float x ,float y, float z, float l){
  int gd=DETECT, gm;
  initgraph(&gd,&gm,"");
  float dx,dy,m;
  /* x=300;
  y=0;
  z=300;
  l=600;*/
  dx=z-x;
  dy=l-y;
  m=dy/dx;
  float i,j,step,o,w,p;

  if((0<m)&(m<1))
  {
    o=2*dy;
    w=(o-(2*dx));
    p=o-dx;
    for(i=0; i<dx; i++)
    {
      if(p<0)
      {
        x=x+1;
        putpixel(x,y,2);
        //   putpixel(x+1,y,2);
        p=p+2*dy;
      }
      else
      {
        x=x+1;
        y=y+1;
        putpixel(x,y,2);
        //   putpixel(x+1,y,2);
        p=p+2*dy-2*dx;
      }
    }
  }
  else
  {
    p=2*dx-dy;
    for(i=0;i<dy; i++)
    {
      if(p<0)
      {
        putpixel(x,y,2);
        p=p+2*dx;
        y=y+1;
      }
      else
      {
        putpixel(x,y,2);
        p=p+2*dx-2*dy;
        x=x+1;
        y=y+1;
      }
    }
  }
  delay(3000);
  closegraph();
  // return 0;
}

void wu(float x ,float y, float z, float l){
  int gd=DETECT, gm;
  initgraph(&gd,&gm,"");
  float dx,dy,m,r;
  //float x,y,z,l,dx,dy,m;
  /* printf("start point  x1 =  ");
  scanf("%d",&x);
  printf("start point  y1 =  ");
  scanf("%d",&y);
  printf("last point  x2 =  ");
  scanf("%d",&z);
  printf("last point  y2 =  ");
  scanf("%d",&l);
  x=200;
  y=150;
  z=100;
  l=110;*/

  if(x>z)
  {
    m=x;
    x=z;
    z=m;
    m=y;
    y=l;
    l=m;
  }
  r=x;
  dx=z-x;
  dy=l-y;
  m=dy/dx;
  x=floor(x+1/2);
  y=y+m*(x-r);
  float yinter,xgap;
  yinter=y+m;
  xgap=x+(1/2)-r;
  putpixel(x,floor(y),((floor(y)+1-y)*xgap));
  putpixel(x,floor(y)+1,(y-(floor(y))*xgap));

  float xf,yf,xfgap,i;
  xf=floor(z+1/2);
  yf=l+m*(xf-z);
  xfgap=z+(1/2)-(floor(x+1/2));

  putpixel(xf,floor(yf),((floor(yf)+1-yf)*xfgap));
  putpixel(xf,floor(yf)+1,(yf-(floor(yf))*xfgap));
  for(i=x+1; i<xf-1; i++)
  {
    putpixel(r,floor(yinter),(floor(yinter)+1-yinter));
    putpixel(r,floor(yinter)+1,(yinter-(floor(yinter))+1));
    r=r+1;
    yinter=yinter+m+1;
  }

  delay(3000);
  closegraph();
  //return 0;
}

void Cartesian(float xc ,float yc, float r){
  int gd=DETECT, gm;
  //initgraph(&gd,&gm,"");
  initwindow(500, 500);
  int i=250,j=500;
  int k;
  for(k=0;k<500;k++)
  putpixel(i,k,3);
  for(k=0;k<500;k++)
  putpixel(k,i,3);
  //line(250,0,250,500);
  //line(0,250,500,250);
  float x,y;
  /*scanf("%f",&xc);
  scanf("%f",&yc);
  scanf("%f",&r);*/
  r=abs(r);
  xc=xc+250;
  yc=-yc+250;
  //r=100;
  putpixel(floor(xc+1/2),floor(yc+r+1/2),3);
  putpixel(floor(xc+1/2),floor(yc-r+1/2),3);
  putpixel(floor(xc+r+1/2),floor(yc+1/2),3);
  putpixel(floor(xc-r+1/2),floor(yc+1/2),3);
  float thita=1;
  float dthita=1/r;
  while(thita<(45))
  {
    x=r*cos((float)thita*3.14/180);
    y=r*sin((float)thita*3.14/180);
    putpixel(floor(xc+x+1/2),floor(yc+y+1/2),3);
    putpixel(floor(xc+x+1/2),floor(yc-y+1/2),3);
    putpixel(floor(xc-x+1/2),floor(yc+y+1/2),3);
    putpixel(floor(xc-x+1/2),floor(yc-y+1/2),3);
    putpixel(floor(xc+y+1/2),floor(yc+x+1/2),3);
    putpixel(floor(xc+y+1/2),floor(yc-x+1/2),3);
    putpixel(floor(xc-y+1/2),floor(yc+x+1/2),3);
    putpixel(floor(xc-y+1/2),floor(yc-x+1/2),3);
    thita=thita+dthita;
  }
  if(thita==(45))
  {
    x=r*cos((float)thita*3.14/180);
    y=x;
    putpixel(floor(xc+x+1/2),floor(yc+y+1/2),3);
    putpixel(floor(xc+x+1/2),floor(yc-y+1/2),3);
    putpixel(floor(xc-y+1/2),floor(yc+y+1/2),3);
    putpixel(floor(xc-y+1/2),floor(yc-y+1/2),3);
  }
  delay(10000);
  closegraph();
  //return 0;
}

void Parametric(float xc ,float yc, float r){
  int gd=DETECT, gm;
  //initgraph(&gd,&gm,"");
  initwindow(500, 500);
  int i=250,j=500;
  int k;
  for(k=0;k<500;k++)
  putpixel(i,k,3);
  for(k=0;k<500;k++)
  putpixel(k,i,3);
  //line(250,0,250,500);
  //line(0,250,500,250);
  /*float xc,yc,r;
  scanf("%f",&xc);
  scanf("%f",&yc);
  scanf("%f",&r);
  r=abs(r);*/
  xc=xc+250;
  yc=-yc+250;
  //r=100;
  putpixel(floor(xc-r+1/2),floor(yc+1/2),3);
  putpixel(floor(xc+r+1/2),floor(yc+1/2),3);
  float x=0,y=0;
  x=floor(xc-r+1/2)+1;
  while(x<(floor(xc+r+1/2)-1))
  {
    y=yc+sqrt((r*r)-((xc-x)*(xc-x)));
    putpixel(x,floor(y+1/2),3);
    y=yc-sqrt((r*r)-((xc-x)*(xc-x)));
    putpixel(x,floor(y+1/2),3);
    x=x+1;
  }
  delay(10000);
  closegraph();
  // return 0;
}

void parallel(float x1,float y1,float x2,float y2){
  initwindow(1000,1000);
  float x,y;
  //x1,y1,x2,y2;

  // printf("Enter the coordinates of the starting point:");
  // scanf("%f %f",&x1,&y1);
  //printf("Enter the coordinates of the ending point:");
  //scanf("%f %f",&x2,&y2);

  float dx,dy, steps;

  dx = fabs( x2-x1);
  dy= fabs(y2-y1);

  if(dx>dy)
  steps=dx;
  else
  steps= dy;

  float deltaX,deltaY;

  deltaY= dy/steps;
  deltaX= dx/steps;

  putpixel(x1,y1,10);
  putpixel(x1,y1+20,10);

  x=x1;
  y=y1;
  int k;
  for(k=1;k<steps;steps++)
  {
    x = x+deltaX;
    y = y+deltaY;
    putpixel(x,y,10);
    putpixel(x,y+20,10);

  }
  delay(20000);
  closegraph();
  //return 1;
}

void dda(float x ,float y, float z, float l){
  int gd=DETECT, gm;
  initgraph(&gd,&gm,"");
  float dx,dy,m;
  /* printf("start point  x1 =  ");
  scanf("%d",&x);
  printf("start point  y1 =  ");
  scanf("%d",&y);
  printf("last point  x2 =  ");
  scanf("%d",&z);
  printf("last point  y2 =  ");
  scanf("%d",&l);
  x=0;
  y=0;
  z=50;
  l=50;*/
  dx=z-x;
  dy=l-y;
  m=dy/dx;

  float i,j,step,o,w;
  if(abs(dx)>abs(dy))
  {
    step=abs(dx);
    dx=dx/step;
    dy=dy/step;
  }
  else
  {
    step=abs(dy);
    dx=dx/step;
    dy=dy/step;
  }
  printf("%f  %f",dx,dy);
  for(i=0;i<step; i++)
  {
    x=x+dx;
    y=y+dy;
    putpixel(x,y,2);
  }

  delay(3000);
  closegraph();
  //return 0;
}

void eclips(float xc ,float yc, float rx, float ry){
  int gd=DETECT, gm;
  //initgraph(&gd,&gm,"");
  initwindow(500, 500);
  int i=250,j=500;
  int k;
  for(k=0;k<500;k++)
  putpixel(i,k,3);
  for(k=0;k<500;k++)
  putpixel(k,i,3);
  //line(250,0,250,500);
  //line(0,250,500,250);
  float x,y;

  rx=abs(rx);
  ry=abs(ry);
  xc=xc+250;
  yc=-yc+250;
  //r=100;

  putpixel(floor(xc+rx+1/2),floor(yc+1/2),3);
  putpixel(floor(xc-rx+1/2),floor(yc+1/2),3);
  putpixel(floor(xc+1/2),floor(yc-ry+1/2),3);
  putpixel(floor(xc+1/2),floor(yc-ry+1/2),3);
  float thita=1;
  float dthita=1;
  while(thita<(90))
  {
    x=rx*cos((float)thita*3.14/180);
    y=ry*sin((float)thita*3.14/180);
    putpixel(floor(xc+x+1/2),floor(yc+y+1/2),3);
    putpixel(floor(xc-x+1/2),floor(yc+y+1/2),3);
    putpixel(floor(xc+x+1/2),floor(yc-y+1/2),3);
    putpixel(floor(xc-x+1/2),floor(yc-y+1/2),3);
    thita=thita+dthita;
  }
  delay(10000);
  closegraph();
  // return 0;
}

void cartisian_eci(float Xc,float Yc,float radius_x,float radius_y){

  initwindow(1300, 700);
  int i=650,j;
  for(j=0;j<=700;j++)
  {
    putpixel(i,j,8);
  }
  j=350;
  for(i=0;i<=1300;i++)
  {
    putpixel(i,j,8);
  }

  float x,y;
  //printf("Enter the radius r_x,r_y\n");
  //scanf("%f%f",&radius_x,&radius_y);
  //printf("Enter the center coordinates\n");
  //scanf("%f%f",&Xc,&Yc);
  Xc += 650;
  Yc = 350 - Yc;
  putpixel(floor(Xc + radius_x + 0.5),floor(Yc + 0.5),15);
  putpixel(floor(Xc - radius_x + 0.5),floor(Yc + 0.5),15);
  putpixel(floor(Xc + 0.5),floor(Yc + radius_y + 0.5),15);
  putpixel(floor(Xc + 0.5),floor(Yc - radius_y + 0.5),15);
  float theta =1;
  float d_theta =1;
  for(;theta <= 90;)
  {
    x = radius_x * cos((float)theta*3.14/180);
    y = radius_y * sin((float)theta*3.14/180);
    putpixel(floor(Xc + x + 0.5),floor(Yc + y + 0.5),15);
    putpixel(floor(Xc + x + 0.5),floor(Yc - y + 0.5),15);
    putpixel(floor(Xc - x + 0.5),floor(Yc + y + 0.5),15);
    putpixel(floor(Xc - x + 0.5),floor(Yc - y + 0.5),15);
    //putpixel(floor(Xc + y + 0.5),floor(Yc + x + 0.5),8);
    //putpixel(floor(Xc + y + 0.5),floor(Yc - x + 0.5),8);
    //putpixel(floor(Xc - y + 0.5),floor(Yc + x + 0.5),8);
    //putpixel(floor(Xc - y + 0.5),floor(Yc - x + 0.5),8);
    theta += d_theta;
  }


  delay(5000);
  closegraph();

  //   return 0;

}

void mid_eci(float xc,float yc, float rx, float ry){
  int gd=DETECT, gm;
  //initgraph(&gd,&gm,"");
  initwindow(500, 500);
  float rx2,ry2,X,Y,x1,x,y,p1;
  //rx=200;
  //ry=50;
  //xc=0;
  //yc=0;
  x=0;
  //y=0;
  xc=xc+250;
  yc=250-yc;
  //rx=rx+250;
  //ry=250-ry;
  int i=250,j=500;
  int k;
  for(k=0;k<500;k++)
  putpixel(i,k,3);
  for(k=0;k<500;k++)
  putpixel(k,i,3);

  x1=floor(rx+1/2);
  y=floor(ry+1/2);
  rx2=floor(rx*rx+1/2);
  ry2=floor(ry*ry+1/2);
  X=x;
  Y=2*rx2*y;
  p1=ry2-rx2*y+floor(0.25*rx2);
  putpixel(floor(xc+1/2),floor(yc+1/2)+y,3);
  putpixel(floor(xc+1/2),floor(yc+1/2)-y,3);
  putpixel(floor(xc+1/2)+x1,floor(yc+1/2),3);
  putpixel(floor(xc+1/2)-x1,floor(yc+1/2),3);

  while((2*ry2*x)<=(2*rx2*y))
  {
    x=x+1;
    X=X+2*ry2;
    if(p1<0)
    {
      p1=p1+X+ry2;
    }
    else
    {
      Y=Y-2*rx2;
      p1=p1+X+ry2-Y;
      y=y-1;
    }
    putpixel(floor(xc+1/2)+x,floor(yc+1/2)+y,3);
    putpixel(floor(xc+1/2)+x,floor(yc+1/2)-y,3);
    putpixel(floor(xc+1/2)-x,floor(yc+1/2)+y,3);
    putpixel(floor(xc+1/2)-x,floor(yc+1/2)-y,3);

  }
  float p2;
  p2=ry2*floor((x+1/2)*(x+1/2))+rx2*(y-1)*(y-1)-rx2*ry2;
  while(y>0)
  {
    y=y-1;
    Y=Y-2*rx2;
    if(p2>0)
    {
      p2=p2+rx2-Y;
    }
    else
    {
      X=X+2*ry2;
      p2=p2-Y+rx2+X;
      x=x+1;
    }
    putpixel(floor(xc+1/2)+x,floor(yc+1/2)+y,3);
    putpixel(floor(xc+1/2)+x,floor(yc+1/2)-y,3);
    putpixel(floor(xc+1/2)-x,floor(yc+1/2)+y,3);
    putpixel(floor(xc+1/2)-x,floor(yc+1/2)-y,3);

  }
  //dx=z-x;
  //dy=l-y;
  delay(3000);
  closegraph();
  //return 0;
}

void mid_line(float x1, float y1,float x2, float y2){
  initwindow(500,500);
  int i=250,j=500;
  int k;
  for(k=0;k<500;k++)
  putpixel(i,k,3);
  for(k=0;k<500;k++)
  putpixel(k,i,3);
  //float x,y;
  float dx,dy,x,y;
  dx = x2-x1;
  dy = y2-y1;
  x1=x1+250;
  y1=y1;
  x2=x2+250;
  y2=y2;
  x=x1;
  y=y1;
  // line(x1,y1,x2,y2);
  //float m = (float) dy/dx;
  //float x0,y0;
  //if(m<1.0)
  //{
  float d;// = 2*dy - dx;
  float delta_d_E;// = 2*dy;
  float delta_d_NE;// = 2 * ( dy-dx);
  //putpixel(x,y,8);
  if(dy/dx <= 1)
  {
    d = 2*dy - dx;
    delta_d_E = 2*dy;
    delta_d_NE = 2 * ( dy-dx);
    putpixel(x,-y+250,8);
    while(x<x2)
    {
      if( d <= 0)
      {
        d = d + delta_d_E;
      }
      else
      {
        d=d+ delta_d_NE;
        y++;
      }
      x++;
      putpixel(x,-y+250,3);
    }
  }
  else
  {
    d = 2*dx - dy;
    delta_d_E = 2*dx;
    delta_d_NE = 2 * ( dx-dy);
    putpixel(x,-y+250,3);
    while(y<y2)
    {
      if( d <= 0)
      {
        d = d + delta_d_E;
      }
      else
      {
        d=d+ delta_d_NE;
        x++;
      }
      y++;
      putpixel(x,-y+250,3);
    }
  }
  delay(10000);
  closegraph();
}
