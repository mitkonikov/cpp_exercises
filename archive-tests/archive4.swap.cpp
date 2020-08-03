#include "bits/stdc++.h"
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

long long swapping() {
    long long value = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (b[i-1] > b[i] && b[i+1] > b[i]) {
            int cost1 = abs(b[i] - a[i]);
            int cost2 = abs((b[i] + 2*H) - a[i]);
            if (cost2 < cost1) value += abs(cost1 - cost2);
        } else {
            int cost1 = abs(b[i] - a[i]);
            int cost2 = abs((b[i] - 2*H) - a[i]);
            if (cost2 < cost1) value += abs(cost1 - cost2);
        }
    }

    return value;
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
        long long valueDown = iterate();
        long long swapAddDown = swapping();
        int costDown = abs(a[0] - b[0]);
        
        DEBUG && cout << " - cost: " << valueDown + costDown - swapAddDown << endl;

        reset();

        b[0] = (mid + MAX) / 2;
        int UP = b[0];
        DEBUG && cout << b[0] << ", ";
        long long valueUp = iterate();
        long long swapAddUp = swapping();
        int costUp = abs(a[0] - b[0]);

        DEBUG && cout << " - cost: " << valueUp + costUp - swapAddUp << endl;

        reset();

        long long finalCostDown = valueDown + costDown - swapAddDown;
        long long finalCostUp = valueUp + costUp - swapAddUp;

        BEST = min(BEST, min(finalCostDown, finalCostUp));

        if (finalCostDown < finalCostUp) {
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