/// Link to the code:
/// http://mendo.mk/Task.do?id=275
/// code written by Mitko Nikov

#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, int>  > vec(n);
    vector<double> minDist(n, 9999999);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i].f >> vec[i].s;
    }

    /// PQ : f = weight till now, s = destination
    priority_queue<pair<double, int>, vector<pair<double, int>  >, greater<pair<double, int>  >  > pq;
    pair<int, int> z = vec[0];
    for (int i = 1; i < n; ++i) {
        double currentDist = dist(z.f, z.s, vec[i].f, vec[i].s);
        if (currentDist <= 10) {
            pq.push(make_pair(currentDist, i));
            minDist[i] = currentDist;
        }
	}

    while (!pq.empty()) {
        pair<double, int> current = pq.top();
        pq.pop();

        if (current.s == n - 1) {
            cout << fixed << setprecision(7) << current.f << endl;
            break;
        }

        double currentDist, finalDist;
        for (int i = 1; i < n; ++i) {
			currentDist = dist(vec[current.s].f, vec[current.s].s, vec[i].f, vec[i].s);
            if (currentDist <= 10 && currentDist != (double)0.00) {
                finalDist = current.f + currentDist;
                if (finalDist <= minDist[i]) {
                    pq.push(make_pair(finalDist, i));
                    minDist[i] = finalDist;
                }
            }
        }
    }

    return 0;
}
