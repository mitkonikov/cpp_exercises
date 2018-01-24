// https://mendo.club/Task.do?id=16

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int input;
    cin >> input;

    double d1 = (-1 + sqrt(1 + 8 * (input - 1))) / 2;

    if (d1 == floor(d1)) cout << "1 ";
    else cout << "0 ";

    double d2 = (-1 + sqrt(1 + 8 * input)) / 2;

    if (d2 == floor(d2)) cout << "1";
    else cout << "0" << endl;

    return 0;
}
