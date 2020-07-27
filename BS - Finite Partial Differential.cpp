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
    long long MAX = maxElement;
    int MIN = 0;
    long long BEST = LLONG_MAX;

    while(MAX > MIN) {
        int mid = (MIN + MAX) / 2;

        b[0] = (MIN + mid) / 2;
        int DOWN = b[0];
        DEBUG && cout << b[0] << ", ";
        long long valueDown = iterate();
        int costDown = abs(a[0] - b[0]);
        
        DEBUG && cout << " - cost: " << valueDown + costDown << endl;

        reset();

        b[0] = (mid + MAX) / 2;
        int UP = b[0];
        DEBUG && cout << b[0] << ", ";
        long long valueUp = iterate();
        int costUp = abs(a[0] - b[0]);

        DEBUG && cout << " - cost: " << valueUp + costUp << endl;

        reset();

        BEST = min(BEST, min(valueDown + costDown, valueUp + costUp));

        if (valueDown + costDown < valueUp + costUp) {
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