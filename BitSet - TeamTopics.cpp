// hackerrank link: https://www.hackerrank.com/challenges/acm-icpc-team/problem

#include <bits/stdc++.h>

using namespace std;

vector <int> acmTeam(vector <string> topic, int m, int n) {
    vector<int> result(2, 0);
    vector<  bitset<500>  > bitSets;
    for (int i = 0; i < topic.size(); ++i) {
        bitset<500> current(topic[i]);
        bitSets.push_back(current);
    }

    bitset<500> BIGGEST;
    for (int i = 0; i < n; ++i) {
        for (int k = i + 1; k < n; ++k) {
            bitset<500> ORed = bitSets[i] | bitSets[k];
            if (ORed.count() > BIGGEST.count()) {
                BIGGEST = ORed;
                result[1] = 1;
                //cout << "CHANGED" << endl;
            } else if (ORed.count() == BIGGEST.count()) {
                result[1]++;
                //cout << "ADDED" << endl;
            }
        }
    }

    result[0] = BIGGEST.count();

    return result;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<string> topic(n);
    for(int topic_i = 0; topic_i < n; topic_i++){
       cin >> topic[topic_i];
    }
    vector <int> result = acmTeam(topic, m, n);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
