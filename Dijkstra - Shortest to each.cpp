/// Link to the problem:
/// https://www.hackerrank.com/challenges/dijkstrashortreach
/// code written by Mitko Nikov

#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

int main()
{
    ios::sync_with_stdio(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int n, m;
        cin >> n >> m;

        long int minDist[n];
        for (int i = 0; i < n; ++i) minDist[i] = LONG_MAX;
        vector<  pair<long int, int>  > vec[n];

        int xp = 99999999, yp = 99999999;
        for (int i = 0; i < m; ++i) {
            int x, y, d;
            cin >> x >> y >> d;
            x--; y--;

            if (!(x == xp && y == yp)) {
                vec[x].push_back(make_pair(d, y));
                vec[y].push_back(make_pair(d, x));
                xp = x;
                yp = y;
            } else {
                if (d < vec[xp].back().f) {
                    vec[xp].pop_back();
                    vec[yp].pop_back();
                    vec[x].push_back(make_pair(d, y));
                    vec[y].push_back(make_pair(d, x));
                    xp = x;
                    yp = y;
                }
            }
        }

        priority_queue<  pair<long int, int>, vector<  pair<long int, int>  >, greater<  pair<long int, int>  >  > pq;

        int st;
        cin >> st;
        st--;

        pq.push(make_pair(0, st));
        minDist[st] = 0;

        long int nextNode, nextDist;
        while (!pq.empty()) {
            pair<long int, int> c = pq.top();
            pq.pop();

            if (c.f > minDist[c.s]) continue;

            for (int i = 0; i < vec[c.s].size(); ++i) {
                nextNode = vec[c.s][i].s;
                nextDist = c.f + vec[c.s][i].f;
                if (nextDist < minDist[nextNode]) {
                    pq.push(make_pair(nextDist, nextNode));
                    minDist[nextNode] = nextDist;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i != st) {
                if (minDist[i] == LONG_MAX) cout << -1 << " ";
                else cout << minDist[i] << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
