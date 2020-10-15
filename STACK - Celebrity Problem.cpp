#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<  vector<int>  > am(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            cin >> am[i][k];
        }
    }

    stack<int> s;
    for (int i = 0; i < n; i++) s.push(i);

    while (!s.empty()) {
        if (s.size() == 1) {
            cout << "Celebrity is " << s.top() << endl;
            break;
        }

        int first = s.top();
        s.pop();

        int second = s.top();
        s.pop();

        if (am[first][second]) {
            s.push(second);
        } else {
            s.push(first);
        }
    }
}