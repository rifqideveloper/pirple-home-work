#include <math.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float a, b, c, x1, x2, discriminant, realPart, imaginaryPart;
    const string text = "enter the value for ";
    const string value = "This quadratic has the following roots\n";

    cout << text << "a" << endl;
    cin >> a;
    cout << text << "b" << endl;
    cin >> b;
    cout << text << "c" << endl;
    cin >> c;
    discriminant = b * b - 4 * a * c;

    if (discriminant > 0)
    {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << value << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }

    else if (discriminant == 0)
    {
        cout << value << endl;
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        cout << "x1 = x2 =" << x1 << endl;
    }

    else
    {
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << value << endl;
        cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
        cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
    }

    return 0;
}