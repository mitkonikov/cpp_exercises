#include "bits/stdc++.h"
#define DEBUG false

using namespace std;

int a[200000]; // Initial Array
int b[200000]; // Array used for calculations

// DP Map from pair < element, height > to solution cost
map<  int, long long  > dpmap[200000];
map< int, long long  >::iterator checkDP;

map<  int, long long  > finalCost;

// Input params
int n, H;

int counti = 0;

long long dp(int i, int height) {
    counti++;

    if (i == n - 1) {
        // We are at the end of the line
        return abs(b[i] - a[i]);
    }
    
    checkDP = dpmap[i].find(height);
    if (checkDP != dpmap[i].end()) {
        return checkDP->second;
    }

    long long currentCost = abs(b[i] - a[i]);

    b[i + 1] = b[i] + H;
    long long upCost = dp(i + 1, b[i + 1]);

    b[i + 1] = b[i] - H;
    long long downCost = dp(i + 1, b[i + 1]);
    
    b[i + 1] = a[i + 1];

    long long rightCost = min(upCost, downCost) + currentCost;
    dpmap[i][height] = rightCost;
    return rightCost;
}

void reset() {
    for (int i = 0; i < n; ++i) {
        b[i] = a[i];
        // dpmap[i].clear();
    }
}

long long bs(int maxElement) {
    long long MAX = maxElement;
    int MIN = 0;
    long long BEST = LLONG_MAX;

    while(MAX > MIN) {
        int mid = (MIN + MAX) / 2;

        b[0] = (MIN + mid) / 2;
        int DOWN = b[0];
        DEBUG && cout << b[0] << ", ";

        long long valueDown;

        checkDP = finalCost.find(DOWN);
        if (checkDP != finalCost.end()) {
            valueDown = checkDP->second;
        } else {
            valueDown = dp(0, DOWN);
        }
        
        cout << "COUNT: " << counti << endl;
        counti = 0;
        DEBUG && cout << " - cost: " << valueDown << endl;

        reset();

        b[0] = (mid + MAX) / 2;
        int UP = b[0];
        DEBUG && cout << b[0] << ", ";
        
        long long valueUp;

        checkDP = finalCost.find(UP);
        if (checkDP != finalCost.end()) {
            valueUp = checkDP->second;
        } else {
            valueUp = dp(0, UP);
        }

        DEBUG && cout << " - cost: " << valueUp << endl;

        reset();

        BEST = min(BEST, min(valueDown, valueUp));

        if (valueDown < valueUp) {
            MAX = UP;
        } else {
            MIN = DOWN + 1;
        }
    }
    
    return BEST;
}

int main() {
    ios::sync_with_stdio(true);

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