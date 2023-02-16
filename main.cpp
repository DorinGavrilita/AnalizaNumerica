#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

struct Interval
{
    double left;
    double right;
} rada[5];

double f(double x)
{
    return x*x*x + 3*x*x - 18*x - 54;
}
int Separation(double A, double B, double h);
double Bisection(double a, double b, int &k);

eps =

int main()
{
    int i, n;
    double A = -5, B = 5, h = 0.05;
    double x;
    cout << "Project nr1!" << endl;
    n = Separation(A, B, h);
    for(i=0; i<n; i++)
    {
        cout << ""
        cout << "O solutie se afla pe [" << rada[i].left << "; " << rada[i].right << "]" << endl;
    };
    return 0;
}

int Separation(double A, double B, double h)
{
    int n = 0;
    double x0, x;
    x0 = A;
    do {
        x = x0 + h;
        //if (f(x)  == 0) ...
        if(f(x0)*f(x) < 0){
            rada[n].left = x0; rada[n].right = x;
            n++;
        }
        x0 = x;
    }  while(x<B);
    return n;
}
int Bisection(double a, double b, int &k)
{
    double x;
    k = 0;
    do
    {
        k++;
        x = (a+b)/2;
        if(fabs(f(x))<eps) return x;
        if(f(a)*f(x) < 0) b = x;
        else a =x;
    }  while(fabs(b-a) > eps);
    return (a+b)/2;
}
 double Newton(double a, double b, int &k)
 {
    double x0, x, delta;
    k = 0;
    x0 = (a+b)/2;
    do
    {
        k++;
        x = x0 - f(x0)/fpr(x0);
        if(fabs(f(x))<eps) return x;
        delta = (fabs(x0-x);
        x0 =x;
    }  while (delta > eps);
    return x;
}
double ModificataTabgentelor(double a, double b, int &k)
 {
    double x0, x, delta;
    k = 0;
    x0 = (a+b)/2;
    do
    {
        k++;
        x = x0 - f(x0)/fpr0;
        if(fabs(f(x))<eps) return x;
        delta = (fabs(x0-x);
        x0 = x;
    }  while (delta > eps);
    return x;
}

double Coardelor(double a, double b, int &k)
 {
    double x0, x1, x, delta;
    k = 1;
    x0 = a; x1 = b;
    do
    {
        k++;
        x = x1 - f(x01)*(X1 - X0)/(f(x1) - f(x0));
        if(fabs(f(x))<eps) return x;
        delta = (fabs(x-x1);
        x0 = x1;
        x1 = x
    }  while (delta > eps);
    return x;
}
