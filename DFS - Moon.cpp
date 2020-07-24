/// Link from the problem:
/// https://www.hackerrank.com/challenges/journey-to-the-moon
/// code written by Mitko Nikov

#include <bits/stdc++.h>

using namespace std;

vector<  vector<int>  > pairs;
vector<bool> visited;
int N, I;

int dfs(int node) {
    int result = 1;
    visited[node] = true;
    for (int i = 0; i < pairs[node].size(); ++i) {
        int nextNode = pairs[node][i];
        if (visited[nextNode] == false) {
            result += dfs(nextNode);
        }
    }

    return result;
}

int main()
{
    cin >> N >> I;

    vector<int> temp;
    for (int i = 0; i < N; ++i) {
        pairs.push_back(temp);
        visited.push_back(false);
    }

    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }

    long long Mresult = 0;
    vector<int> countries;
    for (int i = 0; i < N; ++i) {
        if (visited[i] == false) {
            countries.push_back(dfs(i));
        }
    }

    int cs = countries.size();
    sort(countries.begin(), countries.end());

    int oneCalc = 0;
    if (countries[0] == 1) {
        for (int j = 1; j < cs; ++j) {
            oneCalc += countries[j];
        }

    }

    for (int i = 0; i < cs; ++i) {
        // cout << countries[i] << endl;
        if (countries[i] == 1) {
            Mresult += oneCalc - i;
            continue;
        }

        int currentDotProduct = 0;
        for (int j = i + 1; j < cs; ++j) {
            currentDotProduct += countries[i] * countries[j];
        }
        Mresult += currentDotProduct;
    }

    cout << Mresult << endl;
    return 0;
}
