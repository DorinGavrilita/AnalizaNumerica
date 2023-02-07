#include <iostream>

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

int main()
{
    int i, n;
    double A = -5, B = 5, h = 0.05;
    double x;
    cout << "Project nr1!" << endl;
    n = Separation(A, B, h);
    for(i=0; i<n; i++)
    {
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
