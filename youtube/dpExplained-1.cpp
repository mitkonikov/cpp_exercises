// Link to the Youtube video: https://www.youtube.com/watch?v=GJVjbNFH330

#include <bits/stdc++.h>

using namespace std;

int dp[100];

int fib(int n) {
    // Check if it's already calculated 📗🚀
    if (dp[n]) {
        return dp[n];
    }
    
    // The fibonacci formula 🐬
    int result = fib(n - 1) + fib(n - 2);

    // Cache 🚀
    dp[n] = result;

    // Return result 🤝
    return result;
}

int main() {
    dp[1] = 1;
    dp[2] = 1;
    cout << fib(10) << endl;
    return 0;
}