// Link to the Youtube video: https://www.youtube.com/watch?v=GJVjbNFH330

#include <bits/stdc++.h>

using namespace std;

int main() {
    const int n = 16;

    int input[n];
    int dp[n];

    for (int i = 0; i < n; ++i) {
        cin >> input[i];

        if (i > n - 6) dp[i] = input[i]; // The last 5
    }
    
    // ITERATION ✨
    for (int i = n - 6; i >= 0; i--) {
        dp[i] = min(dp[i + 3], dp[i + 5]) + input[i];
    }
    
    cout << dp[0] << endl; // WOW 🤩

    return 0;
}