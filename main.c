#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;
float x[100], y[100], XS = 0, YS = 0, XYS = 0, XSS = 0, XCS = 0, XQS = 0, XSYS = 0, Xavg = 0, Yavg = 0;
int calculate(void);

int calculate()
{
    int i;
    for (i = 0; i < n; i++)
    {
        XS += x[i];
        YS += y[i];
        XYS += x[i] * y[i];
        XSS += x[i] * x[i];
        XCS += x[i] * x[i] * x[i];
        XQS += x[i] * x[i] * x[i] * x[i];
        XSYS += x[i] * x[i] * y[i];
    }

    Xavg = XS / n;
    Yavg = YS / n;
    return 0;
}

int main()
{
    int i, choice;
    float NR, DR, p, q, r;
    float DX, DY, DET, m, c;
    float t, u, v, det, dx, dy, dz;

    printf("Enter the number of data points\n");
    scanf("%d", &n);
    printf("Enter the values of the independent variable X\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("Enter the values of the dependent variable Y\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &y[i]);
    }

    calculate();

    while (1)
    {
top:
        system("cls");
        printf("\n1. Correlation coefficient\n");
        printf("2. Best fitting line\n");
        printf("3. Best fitting parabola\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            //correlation

            for (i = 0; i < n; i++)
            {
                NR += (x[i] - Xavg) * (y[i] - Yavg);
            }
            for (i = 0; i < n; i++)
            {
                p += (x[i] - Xavg) * (x[i] - Xavg);
                q += (y[i] - Yavg) * (y[i] - Yavg);
            }

            DR = sqrt(p * q);
            r = NR / DR;

            printf("\nThe Correlation Coefficient is %.4f\n\n", r);
            if (r >= -1 && r <= -0.8)
            {
                printf("There is a very strong negative correlation\n");
            }
            else if (r >= -0.79 && r <= -0.6)
            {
                printf("There is a strong negative correlation\n");
            }
            else if (r >= -0.59 && r <= -0.4)
            {
                printf("There is a moderate negative correlation\n");
            }
            else if (r >= -0.39 && r <= -0.2)
            {
                printf("There is a weak negative correlation\n");
            }
            else if (r >= -0.19 && r <= 0)
            {
                printf("There is a very weak negative correlation\n");
            }
            else if (r >= 0 && r <= 0.19)
            {
                printf("There is a very weak positive correlation\n");
            }
            else if (r >= 0.2 && r <= 0.39)
            {
                printf("There is a weak positive correlation\n");
            }
            else if (r >= 0.4 && r <= 0.59)
            {
                printf("There is a moderate positive correlation\n");
            }
            else if (r >= 0.6 && r <= 0.79)
            {
                printf("There is a strong positive correlation\n");
            }
            else
            {
                printf("There is a very strong positive correlation\n");
            }
            getchar();
            getchar();
        }

        else if (choice == 2)
        {
            //Best fitting line

            DET = XS * XS - n * XSS;
            DX = YS * XS - n * XYS;
            DY = XS * XYS - YS * XSS;

            m = DX / DET;
            c = DY / DET;

            if (c > 0)
                printf("\nThe best fit line of the form y = mx + c is\n\n Y = %.4fX + %.4f\n", m, c);
            else
                printf("\nThe best fit line of the form y = mx + c is\n\n Y = %.4fX - %.4f\n", m, -1 * c);
            getchar();
            getchar();
        }
        else if (choice ==  3)
        {
            //best fitting parabola

            det =  XSS * (XSS * XSS - XCS * XS) - XS * (XCS * XSS - XS * XQS) + n * (XCS * XCS - XQS * XSS);
            dx  =  YS * (XSS * XSS - XS * XCS) - XS * (XYS * XSS - XS * XSYS) + n * (XYS * XCS - XSS * XSYS);
            dy  =  XSS * (XYS * XSS - XS * XSYS) - YS * (XCS * XSS - XS * XQS) + n * (XCS * XSYS - XQS * XYS);
            dz  =  XSS * (XSS * XSYS - XYS * XCS) - XS * (XCS * XSYS - XYS * XQS) + YS * (XCS * XCS - XQS * XSS);

            t = dx / det;
            u = dy / det;
            v = dz / det;

            if (u >= 0 && v >= 0)
                printf("\nThe best fit parabola of the form y = ax^2 + bx + c is\n\n Y = %.4fX^2 + %.4fX + %.4f\n", t, u, v);
            else if (u < 0 && v > 0)
                printf("\nThe best fit parabola of the form y = ax^2 + bx + c is\n\n Y = %.4fX^2 - %.4fX + %.4f\n", t, -1 * u, v);
            else if (u > 0 && v < 0)
            {
                printf("\nThe best fit parabola of the form y = ax^2 + bx + c is\n\n Y = %.4fX^2 + %.4fX - %.4f\n", t, u, -1 * v);
            }
            else
            {
                printf("\nThe best fit parabola of the form y = ax^2 + bx + c is\n\n Y = %.4fX^2 - %.4fX - %.4f\n", t, -1 * u, -1 * v);
            }

            getchar();
            getchar();
        }
        else if (choice == 4)
        {
            exit(0);
        }
        else
        {
            printf("Invalid choice\n");
            getchar();
            getchar();
            goto top;
        }
    }

    getchar();
    getchar();

    return 0;
}


