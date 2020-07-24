/// Link to the problem:
/// https://www.hackerrank.com/challenges/coin-change
/// code written by Mitko Nikov

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int c[m];
    long long dp[n + 1][m];
    /// dp [ amounts ] [ coins ]

    /// INPUT
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
        dp[0][i] = 1;
        // IF THE AMOUNT IS 0,
        // YOU ALWAYS HAVE JUST ONE POSSIBLE WAY
    }

    long long x, y;
    for (int i = 1; i < n + 1; ++i) { // LOOP THROUGH THE AMOUNTS
        for (int j = 0; j < m; ++j) { // LOOP THROUGH THE COINS
            // Count of solutions including c[j]
            x = (i - c[j] >= 0) ? dp[ i - c[j] ][ j ] : 0;

            // Count of solutions excluding c[j]
            y = (j >= 1) ? dp[ i ][ j - 1 ] : 0;

            // Total count
            dp[i][j] = x + y;
        }
    }

    cout << dp[n][m - 1] << endl;

    return 0;
}
