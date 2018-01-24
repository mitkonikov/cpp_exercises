// you can substitute f with s - k

#include <bits/stdc++.h>

using namespace std;

int angryChildren(int k, vector <int> arr) {
    sort(arr.begin(), arr.end());

    int f = 0;
    int s = 0;

    int bestMin = INT_MAX;
    int bestMax = INT_MIN;

    for (; s < k; ++s) { // go through the first k integers
        bestMin = min(bestMin, arr[s]);
        bestMax = max(bestMax, arr[s]);
    }

    int bestDiff = bestMax - bestMin;

    if (arr.size() == k) return bestDiff;
    while (s != arr.size()) {
        int TOP = arr[f];
        if (TOP == bestMin) bestMin = arr[f + 1];
        int LAST = arr[s];
        bestMax = LAST;
        bestDiff = min(bestDiff, bestMax - bestMin);
        f++;
        s++;
    }

    return bestDiff;
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = angryChildren(k, arr);
    cout << result << endl;
    return 0;
}
