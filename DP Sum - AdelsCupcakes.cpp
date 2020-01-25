#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int arr[n];
        long long dp[n];

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        long long currentSum = 0;
        for (int i = 0; i < n; ++i) {
            currentSum += arr[i];
            dp[i] = currentSum;
        }

        bool call = false;
        long long maxSum = -999999999;

        for (int i = 0; i < n; ++i) {
            
            if (dp[i] > dp[n - 1]) {
                cout << "NO" << endl;
                call = true;
                break;
            }

            if (i != n - 1)
                maxSum = max(maxSum, dp[i]);

            long long negSum = 0;
            for (int k = 0; k < i; ++k) {
                negSum += arr[k];

                maxSum = max(maxSum, dp[i] - negSum);

                if (dp[i] - negSum > dp[n - 1]) {
                    // call it a day
                    cout << "NO" << endl;
                    call = true;
                    break;
                }
            }

            if (call) break;
        }

        if (call) continue;

        if (maxSum == dp[n-1])
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    // system("pause");

    return 0;
}