// MENDO Problem:
// https://mendo.mk/Task.do?id=869

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<  vector<int>, int  > dp;
    vector<  pair<int, int>  > strings(n);
    vector<string> stringsMain(n);
    vector<int> score(n, 0);
    vector<int> nextString(n, -1);
    vector<int> foundStartingPointsIndex;

    for (int i = 0; i < n; ++i) {
        string currentString;
        cin >> currentString;

        strings[i] = make_pair(currentString.length(), i);
        stringsMain[i] = currentString;
        score[i] = 0;

        vector<int> currentVec(26, 0);
        for (int k = 0; k < currentString.length(); k++)
        {
            currentVec[currentString[k] - 'A']++;
        }

        dp[currentVec] = i + 1;
    }

    std::map<  vector<int>, int  >::reverse_iterator it;
    for (it = dp.rbegin(); it != dp.rend(); ++it) {
        int stringIndex = it->second - 1;

        if (stringIndex == -1) continue;

        if (strings[stringIndex].first == 1) continue;

        vector<int> currentVec = it->first;
        vector<int> mod = currentVec;
        bool taken = false;

        for (int k = 0; k < 26; k++)
        {            
            if (taken) {
                mod[k - 1]++;
            }
            
            if (currentVec[k] > 0) {
                mod[k]--;
                taken = true;

                int lowerIndex = dp[mod] - 1;
                if (lowerIndex == -1) continue;

                if (score[stringIndex] + 1 > score[lowerIndex]) {
                    nextString[lowerIndex] = stringIndex;
                    score[lowerIndex] = score[stringIndex] + 1;
                } else {
                    score[lowerIndex] = score[lowerIndex];
                }
            } else {
                taken = false;
            }
        }
        
        if (strings[stringIndex].first == 2) {
            foundStartingPointsIndex.push_back(stringIndex);
        }
    }

    // FIND THE MAX SCORE
    int maxScore = 0;
    int maxScoreIndex = -1;
    for (int i = 0; i < foundStartingPointsIndex.size(); ++i) {
        int nextStringIndex = foundStartingPointsIndex[i];
        if (score[nextStringIndex] > maxScore) {
            maxScore = score[nextStringIndex];
            maxScoreIndex = nextStringIndex;
        }
    }

    // PRINT
    cout << maxScore + 2 << endl;

    int nextStringIndex = maxScoreIndex;
    cout << stringsMain[nextStringIndex][0] << endl;
    while(true) {
        cout << stringsMain[nextStringIndex] << endl;
        nextStringIndex = nextString[nextStringIndex];
        if (nextStringIndex == -1) break;
    }

    // system("pause");

    return 0;
 }