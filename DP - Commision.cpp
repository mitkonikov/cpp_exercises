/// Link to the problem:
/// http://mendo.mk/Task.do?id=15
/// written by Mitko Nikov

#include <bits/stdc++.h>

using namespace std;

int n, k;
int M[15][16];

int sum(int a, int b) {
    int result = 0;
    for (int i = b; i <= a; ++i)
        result += M[i][0];
    return result;
}

void printarray() {
    cout << setw(4) << "#";
    for (int i = 0; i < k + 1; ++i)
        cout << setw(4) << i;
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << setw(4) << i;
        for (int j = 0; j < k + 1; ++j) {
            cout << setw(4) << M[i][j];
        }
        cout << endl;
    }
}

int main()
{
    cin >> k >> n;

    memset(M, -1, 15 * 16);

    int initSum = 0;
    for (int i = 0; i < n; ++i) {
        int current;
        cin >> current;
        initSum += current;
        M[i][0] = current;
        M[i][1] = initSum;
    }

    for (int i = 2; i < k + 1; ++i) { /// K - COLUMNS
        for (int j = 0; j < n; ++j) { /// N - ROWS
            if (i > j + 1) M[j][i] = -1;
            else if (i == j + 1) {
                for (int p = 0; p <= j; ++p)
                    M[j][i] = max(M[j][i], M[p][0]);
            } else {
                int temp = INT_MAX;
                for (int p = 0; p < j; ++p) {
                    // cout << "M[" << p << "][" << i - 1 << "] = " << M[p][i - 1] << endl;
                    // cout << "sum(" << j << ", " << p + 1 << ") = " << sum(j, p + 1) << endl;
                    int current = max(M[p][i - 1], sum(j, p + 1));
                    temp = min(temp, current);
                }
                M[j][i] = temp;
            }
        }
    }

    // printarray();

    cout << M[n - 1][k] << endl;

    return 0;
}
