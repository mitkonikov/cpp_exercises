// Link to the Youtube video: https://www.youtube.com/watch?v=GJVjbNFH330

#include <bits/stdc++.h>

using namespace std;

// I try to keep it simple, but it should be 'n'
int input[100000];
int dp[100000];
int n;

int f(int i) {
    if (i > n - 1) return 0;
    
    // Check if it's already calculated 📗🚀
    if (dp[i]) return dp[i];
    
    // Our DP breakdown 🐬
    int result = min( f(i + 3), f(i + 5) ) + input[i];

    // Cache 🚀
    dp[i] = result;

    // Return result 🤝
    return result;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    
    cout << f(0) << endl;

    return 0;
}