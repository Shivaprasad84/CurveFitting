#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;
float x[100],y[100];

int main()
{
    int i;
    float Xsum = 0,Ysum = 0,Xavg = 0,Yavg = 0,r,p,q,NR,DR;
    float XYS=0,XSS=0,m,c,DET,DX,DY;
    float t,u,v,XCS = 0,XQS = 0,XSYS = 0,det,dx,dy,dz;
    printf("Enter the number of data points\n");
    scanf("%d",&n);
    printf("Enter the values of the independent variable X\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&x[i]);
    }
    printf("Enter the values of the dependent variable Y\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&y[i]);
    }
    for(i=0;i<n;i++)
    {
        Xsum += x[i];
        Ysum += y[i];
    }
    Xavg = Xsum/n;
    Yavg = Ysum/n;
    for(i=0;i<n;i++)
    {
        NR += (x[i] - Xavg)*(y[i] - Yavg);
    }
    for(i=0;i<n;i++)
    {
        p += (x[i] - Xavg)*(x[i] - Xavg);
        q += (y[i] - Yavg)*(y[i] - Yavg);
    }

    DR = sqrt(p*q);
    r = NR/DR;

    printf("\nThe Correlation Coefficient is %.4f\n\n",r);
    if(r>=-1&&r<=-0.8)
    {
        printf("There is a very strong negative correlation\n");
    }
    else if(r>=-0.79&&r<=-0.6)
    {
        printf("There is a strong negative correlation\n");
    }
    else if(r>=-0.59&&r<=-0.4)
    {
        printf("There is a moderate negative correlation\n");
    }
    else if(r>=-0.39&&r<=-0.2)
    {
        printf("There is a weak negative correlation\n");
    }
    else if(r>=-0.19&&r<=0)
    {
        printf("There is a very weak negative correlation\n");
    }
    else if(r>=0&&r<=0.19)
    {
        printf("There is a very weak positive correlation\n");
    }
    else if(r>=0.2&&r<=0.39)
    {
        printf("There is a weak positive correlation\n");
    }
    else if(r>=0.4&&r<=0.59)
    {
        printf("There is a moderate positive correlation\n");
    }
    else if(r>=0.6&&r<=0.79)
    {
        printf("There is a strong positive correlation\n");
    }
    else
    {
        printf("There is a very strong positive correlation\n");
    }

    for(i=0;i<n;i++)
    {
        XYS += x[i]*y[i];
        XSS += x[i]*x[i];
    }

    DET = Xsum*Xsum - n*XSS;
    DX = Ysum*Xsum - n*XYS;
    DY = Xsum*XYS - Ysum*XSS;

    m = DX/DET;
    c = DY/DET;
    if(c>0)
    printf("\nThe best fit line of the form y = mx + c is\n\n Y = %.4fX + %.4f\n",m,c);
    else
    printf("\nThe best fit line of the form y = mx + c is\n\n Y = %.4fX - %.4f\n",m,-1*c);

    for(i=0;i<n;i++)
    {
        XCS += x[i]*x[i]*x[i];
        XQS += x[i]*x[i]*x[i]*x[i];
        XSYS += x[i]*x[i]*y[i];
    }

    det =  XSS*(XSS*XSS - XCS*Xsum) - Xsum*(XCS*XSS - Xsum*XQS) + n*(XCS*XCS - XQS*XSS);
    dx  =  Ysum*(XSS*XSS - Xsum*XCS) - Xsum*(XYS*XSS - Xsum*XSYS) + n*(XYS*XCS - XSS*XSYS);
    dy  =  XSS*(XYS*XSS - Xsum*XSYS) - Ysum*(XCS*XSS - Xsum*XQS) + n*(XCS*XSS - XQS*Xsum);
    dz  =  XSS*(XSS*XSYS - XYS*XCS) - Xsum*(XCS*XSYS - XYS*XQS) + Ysum*(XCS*XCS - XQS*XSS);

    t = dx/det;
    u = dy/det;
    v = dz/det;
    if(u>=0&&v>=0)
    printf("\nThe best fit parabola of the form y = ax^2 + bx + c is\n\n Y = %.4fX^2 + %.4fX + %.4f\n",t,u,v);
    else if(u<0&&v>0)
    printf("\nThe best fit parabola of the form y = ax^2 + bx + c is\n\n Y = %.4fX^2 - %.4fX + %.4f\n",t,-1*u,v);
    else if(u>0&&v<0)
    printf("\nThe best fit parabola of the form y = ax^2 + bx + c is\n\n Y = %.4fX^2 + %.4fX - %.4f\n",t,u,-1*v);
    else
    printf("\nThe best fit parabola of the form y = ax^2 + bx + c is\n\n Y = %.4fX^2 - %.4fX - %.4f\n",t,-1*u,-1*v);

    getchar();
    getchar();
    return 0;
}


