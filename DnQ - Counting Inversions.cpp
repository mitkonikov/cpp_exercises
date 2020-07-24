/// Link to the problem:
/// http://mendo.mk/Task.do?id=460
/// code written by Mitko Nikov

#include <bits/stdc++.h>

using namespace std;

int arr[1000000];
int n = 0;
int tempFirst[1000000];
int tempSecond[1000000];

long long int dnqMerge(int starting, int mid, int ending) {
    // int tempFirst[mid - starting + 2];
    // int tempSecond[ending - mid + 1];

    // cout << "dnqMerge: s = " << starting << ", m = " << mid << ", e = " << ending << endl;

    /// COPYING THE FIRST PART
    for (int i = starting; i <= mid; ++i) {
        tempFirst[i - starting] = arr[i];
        // cout << arr[i] << " ";
    }

    /// COPYING THE SECOND PART
    for (int i = mid + 1; i <= ending; ++i) {
        tempSecond[i - (mid + 1)] = arr[i];
        // cout << arr[i] << " ";
    }

    // cout << endl;

    /// IN CASE ITS NOT EVEN, SET THEM TO MAX
    tempFirst[mid - starting + 1] = INT_MAX;
    tempSecond[ending - mid] = INT_MAX;

    int i = 0, j = 0;
    long long int inversions = 0;

    /// LOOP THROUGH ALL THE ELEMENTS IN BOTH OF THE ARRAYS
    for (int k = starting; k <= ending; ++k) {
        /// SORTING THEM
        if (tempFirst[i] <= tempSecond[j]) {
            arr[k] = tempFirst[i];
            i++;
        } else {
            arr[k] = tempSecond[j];
            /// IF THE SECOND ELEMENT IS SMALLER THAN THE FIRST
            /// COUNT THE INVERSIONS WITH SIMPLE MATHS
            inversions += (mid - starting + 2) - i - 1;
            j++;
        }
    }

    // cout << "inversions: " << inversions << endl;

    return inversions;
}

long long int dnq(int starting, int ending) {
    long long int inversions = 0;

    if (starting < ending) {
        int mid = (starting + ending) / 2;
        /// THE FIRST PART
        inversions += dnq(starting, mid);
        /// THE SECOND PART
        inversions += dnq(mid + 1, ending);
        /// MERGE THEM
        inversions += dnqMerge(starting, mid, ending);
    }

    return inversions;
}

int main()
{
    ios::sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    if (n % 2 != 0) arr[n] = 9999999;

    cout << dnq(0, n - 1) << endl;

    return 0;
}
