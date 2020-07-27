#include <bits/stdc++.h>
#define DEBUG false

using namespace std;

int a[200000];
int b[200000];
int n, H;

long long iterate() {
    long long value = 0;
    for (int i = 1; i < n; ++i) {
        int prev = b[i];
        if (b[i] > b[i - 1] + H) {
            b[i] = b[i - 1] + H;
            value += prev - b[i];
        } else if (b[i] < b[i - 1] - H) {
            b[i] = b[i - 1] - H;
            value += b[i] - prev;
        }

        DEBUG && cout << b[i] << ", ";
    }

    return value;
}

void reset() {
    for (int i = 0; i < n; ++i) b[i] = a[i];
}

long long bs(int maxElement) {
    long long MAX = maxElement * 2;
    int MIN = 0;
    long long BEST = LLONG_MAX;

    for (int i = 0; i < maxElement; ++i) {
        b[0] = i;
        long long value = iterate();
        BEST = min(BEST, value + abs(a[0] - b[0]));
        reset();
    }
    
    return BEST;
}

int main() {
    cin >> n >> H;

    int maxElement = INT_MIN;
    bool run = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];

        if (i > 0 && abs(a[i] - a[i-1]) > H) {
            run = true;
        }

        maxElement = max(maxElement, a[i]);
    }

    if (run) {
        cout << bs(maxElement) << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}