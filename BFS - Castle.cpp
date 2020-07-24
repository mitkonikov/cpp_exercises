/// Link to the problem:
/// https://www.hackerrank.com/challenges/castle-on-the-grid
/// code written by Mitko Nikov

#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

int n;

bool valid(int a, int b) {
    if (a >= 0 && a < n && b >= 0 && b < n)
        return true;
    return false;
}

int main() {
    cin >> n;

    char ch[n][n];
    int a[n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char current;
            cin >> current;
            ch[i][j] = current;
            a[i][j] = 9999999;
        }
    }

    int xc, yc, xg, yg;
    cin >> xc >> yc >> xg >> yg;

    queue<  pair<int, int>  > q;
    q.push(make_pair(xc, yc));
    a[xc][yc] = 0;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!q.empty()) {
        pair<int, int> c = q.front(); // CURRENT COORDS
        int cv = a[c.f][c.s]; // CURRENT VALUE
        q.pop();

        int ox, oy; // OFFSET VARS
        for (int i = 0; i < 4; ++i) {
            // COUNTERS VARS FOR ONE DIRECTION
            int counterX = dx[i];
            int counterY = dy[i];

            // WHILE WE HAVEN'T HIT A WALL
            // IN THAT DIRECTION
            while (true) {
                ox = c.f + counterX;
                oy = c.s + counterY;
                if (valid(ox, oy) && ch[ox][oy] != 'X' && cv + 1 <= a[ox][oy]) {
                    a[ox][oy] = cv + 1;
                    q.push(make_pair(ox, oy));
                    counterX += dx[i];
                    counterY += dy[i];
                } else {
                    break;
                }
            }
        }
    }

    /*cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }*/

    cout << a[xg][yg] << endl;

    return 0;
}
