#include <bits/stdc++.h>

using namespace std;

vector<  pair<int, pair<int, int>  >  > vec;

bool sorting(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
    if (a.first > b.first)
        return true;
    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        vec.push_back(make_pair(a, make_pair(b, i)));
    }

    sort(vec.begin(), vec.end(), sorting);

    int best = -9999999;
    int bestPlace = 0;
    for (int i = 0; i < k; ++i) {
        if (vec[i].second.first > best) {
            best = vec[i].second.first;
            bestPlace = vec[i].second.second + 1;
        }
    }

    cout << bestPlace << endl;

    return 0;
}
