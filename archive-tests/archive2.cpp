#include "bits/stdc++.h"
#define DEBUG false

using namespace std;

int a[200000]; // Initial Array
int b[200000]; // Array used for calculations

// DP Map from pair < element, height > to solution cost
map<  pair<  int, int  >, long long  > dpmap;

// Recursion Stack
stack<  pair<  int, int  >  > rec;

// Input params
int n, H;

long long dp() {
    // Start at the first element
    rec.push(make_pair(0, b[0]));
    
    while(!rec.empty()) {
        pair<int, int> current = rec.top();
        rec.pop();

        int i = current.first;
        int height = current.second;

        if (i == n - 1) {
            // We are at the end of the line
            dpmap[make_pair(i, height)] = abs(b[i] - a[i]);
            continue;
        }
        
        long long currentCost = abs(b[i] - a[i]);

        b[i + 1] = b[i] + H;

        map<pair<int, int>, long long>::iterator checkDP = dpmap.find(make_pair(i + 1, b[i + 1]));
        if (checkDP != dpmap.end()) {
            return checkDP->second;
        } else {
            rec.push(make_pair(i + 1, b[i + 1]));
        }

        b[i + 1] = b[i] - H;
        
        map<pair<int, int>, long long>::iterator checkDP = dpmap.find(make_pair(i + 1, b[i + 1]));
        if (checkDP != dpmap.end()) {
            return checkDP->second;
        } else {
            rec.push(make_pair(i + 1, b[i + 1]));
        }
        
        b[i + 1] = a[i + 1];

        long long rightCost = min(upCost, downCost) + currentCost;
        dpmap[make_pair(i, height)] = rightCost;
    }
    return rightCost;
}

void reset() {
    for (int i = 0; i < n; ++i) b[i] = a[i];
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
        long long valueDown = dp();

        DEBUG && cout << " - cost: " << valueDown << endl;

        reset();

        b[0] = (mid + MAX) / 2;
        int UP = b[0];
        DEBUG && cout << b[0] << ", ";
        long long valueUp = dp();
        
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