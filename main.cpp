#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

struct Interval
{
    double left;
    double right;
} rada[5];

int Separare(double A, double B, double h);
double Bisection(double a, double b, int &k);
double Newton(double a, double b, int &k);
double ModificataTangentelor(double a, double b, int &k);
double Secantelor(double a, double b, int &k);
double Coardelor(double a, double b, int &k);
double Mixta(double a, double b, int &k);
double SimpleIteration(double a, double b, int &k);
double Gold(double a, double b, int &k);
double MyMethod(double a, double b, int &k);

double f(double x)
{
    return x * x * x + 2 * x * x - 19 * x - 38;
}
double fpr(double x)
{
    return 3 * x * x + 4 * x - 19;
}
double eps = 1e-9;

int main()
{
    /*
        numarul de intervale
    */
    int n, i, k;
    double A = -10, B = 10, h = 0.05;
    double x;
    cout << "Proiect numarul 1 elaborat de Cojocari Dmitri" << endl;
    n = Separare(A, B, h);
    for (i = 0; i < n; i++)
    {
        cout << "\n O solutie separata se afla pe [" << rada[i].left << ";" << rada[i].right << "]" << endl;
        x = Bisection(rada[i].left, rada[i].right, k);
        printf("\nBisectie: a %d aproximatie: %15.12lf; Verificare: %10.3le", k, x, f(x));
        x = Newton(rada[i].left, rada[i].right, k);
        printf("\nTangentelor: a %d aproximatie: %15.12lf; Verificare: %10.3le", k, x, f(x));
        x = ModificataTangentelor(rada[i].left, rada[i].right, k);
        printf("\nModif. tg: a %d aproximatie: %15.12lf; Verificare: %10.3le", k, x, f(x));
        x = Secantelor(rada[i].left, rada[i].right, k);
        printf("\nSecantelor: a %d aproximatie: %15.12lf; Verificare: %10.3le", k, x, f(x));
        x = Coardelor(rada[i].left, rada[i].right, k);
        printf("\nCoardelor: a %d aproximatie: %15.12lf; Verificare: %10.3le", k, x, f(x));
        x = Mixta(rada[i].left, rada[i].right, k);
        printf("\nMixta: a %d aproximatie: %15.12lf; Verificare: %10.3le", k, x, f(x));
        x = SimpleIteration(rada[i].left, rada[i].right, k);
        printf("\nIteratiei: a %d aproximatie: %15.12lf; Verificare: %10.3le", k, x, f(x));
    }
    return 0;
}

int Separare(double A, double B, double h)
{
    int n = 0;
    double x0, x;
    x0 = A;
    do
    {
        x = x0 + h;
        if (f(x) == 0)
        {
        }
        if (f(x0) * f(x) < 0)
        {
            rada[n].left = x0;
            rada[n].right = x;
            n++;
        }
        x0 = x;
    } while (x < B);
    return n;
}
double Bisection(double a, double b, int &k)
{
    double x;
    k = 0;
    do
    {
        k++;
        x = (a + b)/2;
        if(fabs(f(x)) < eps) return x;
        if(f(a)*f(x) < 0) b = x;
        else a = x;
    } while (fabs(b-a) > eps);
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
        if(fabs(f(x)) < eps) return x;
        delta = fabs(x0-x);
        x0 = x;
    } while (delta > eps);
    return x;
}
double ModificataTangentelor(double a, double b, int &k)
{
    double x0, fpr0, x, delta;
    k = 0;
    x0 = (a+b)/2;
    fpr0 = fpr(x0);
    do
    {
        k++;
        x = x0 - f(x0)/fpr0;
        if(fabs(f(x)) < eps) return x;
        delta = fabs(x0-x);
        x0 = x;
    } while (delta > eps);
    return x;
}
double Secantelor(double a, double b, int &k)
{
    double x0, x1, x, delta;
    k = 1;
    x0 = a; x1 = b;
    do
    {
        k++;
        x = x1 - f(x1)*(x1 - x0)/(f(x1) - f(x0));
        if(fabs(f(x)) < eps) return x;
        delta = fabs(x-x1);
        x0 = x1;
        x1 = x;
    } while (delta > eps);
    return x;
}

double Coardelor(double a, double b, int &k)
{
    double x0, x1, x, fx0, delta;
    k = 1;
    x0 = b; x1 = a;
    fx0 = f(x0);
    do
    {
        k++;
        x = x1 - f(x1)*(x1 - x0)/(f(x1) - fx0);
        if(fabs(f(x)) < eps) return x;
        delta = fabs(x-x1);
        x1 = x;
    } while (delta > eps);
    return x;
}
double Mixta(double a, double b, int &k)
{
    return 1;

}
double SimpleIteration(double a, double b, int &k)
{
    double x0, x, delta;
    k = 0;
    x0 = (a+b)/2;
    do
    {
        k++;
        x = fi(x0);
        if(fabs(f(x)) < eps) return x;
        delta = fabs(x0-x);
        x0 = x;
    } while (delta > eps);
    return x;
}
double Gold(double a, double b, int &k)
{
    return 1;
}
