#include <bits/stdc++.h>
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
long long upCost = LLONG_MAX;
long long downCost = LLONG_MAX;
int maxElement = INT_MIN;

long long dp(int i, int height) {
    long long currentCost = abs(b[i] - a[i]);

    if (i == n - 1) {
        // We are at the end of the line
        return currentCost;
    }
    
    checkDP = dpmap[i].find(height);
    if (checkDP != dpmap[i].end()) {
        return checkDP->second;
    }

    if (b[i] + (long)H <= maxElement) {
        b[i + 1] = b[i] + H;
        upCost = dp(i + 1, b[i + 1]);
    } else {
        upCost = LLONG_MAX;
    }

    if (b[i] - H >= 0) {
        b[i + 1] = b[i] - H;
        downCost = dp(i + 1, b[i + 1]);
    } else {
        downCost = LLONG_MAX;
    }

    b[i + 1] = a[i + 1]; // Reset

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

long long bs() {
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
            finalCost[DOWN] = valueDown;
        }
        
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
            finalCost[UP] = valueUp;
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
        cout << bs() << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}