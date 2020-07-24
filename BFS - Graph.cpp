/// Link to the problem:
/// https://www.hackerrank.com/challenges/bfsshortreach
/// code written by Mitko Nikov

#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

int main()
{
    int q;
    cin >> q;

    for (int qs = 0; qs < q; ++qs) {
        int n, m; /// n = nodes , m = edges
        cin >> n >> m;

        vector<int> nodes[n];
        vector<int> minDist(n, 9999999);
        for (int i = 0; i < m; ++i) {
            int s, d;
            cin >> s >> d;
            s--; d--;

            nodes[s].push_back(d);
            nodes[d].push_back(s);
        }

        int s;
        cin >> s;
        s--;

        queue<pair<int, int>  > q;
        q.push(make_pair(0, s));
        minDist[s] = 0;

        while (!q.empty()) {
            pair<int, int> current = q.front(); /// F = PATH TO THE NODE, S = DEST NODE
            q.pop();

            int nodeEdges = nodes[current.s].size();
            for (int i = 0; i < nodeEdges; ++i) {
                int nextNode = nodes[current.s][i];
                if (nextNode != current.s && minDist[nextNode] > current.f + 6) {
                    q.push(make_pair(current.f + 6, nextNode));
                    minDist[nextNode] = current.f + 6;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i != s) {
                if (minDist[i] == 9999999)
                    cout << -1 << " ";
                else
                    cout << minDist[i] << " ";
            }
        }

        cout << endl;
    }

    cout << endl;

    return 0;
}
