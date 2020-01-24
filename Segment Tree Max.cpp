// Rewrite of this code:
// https://www.geeksforgeeks.org/segment-tree-set-2-range-maximum-query-node-update/

#include <bits/stdc++.h>

using namespace std;

int getMid(int start, int end) {
    return start + (end - start) / 2;
}

int getMax(int* segmentTree, int start, int end, int l, int r, int node) {
    if (l <= start && r >= end) 
        return segmentTree[node];
    if (end < l || start > r) 
        return -1;

    int mid = getMid(start, end);

    return max( getMax(segmentTree, start, mid, l, r, 2 * node + 1),
                getMax(segmentTree, mid + 1, end, l, r, 2 * node + 2));
}   

int constructSTUtil(int arr[], int start, int end, int* segmentTree, int segmentIndex) {
    if (start == end) {
        segmentTree[segmentIndex] = arr[start];
        return arr[start];
    }

    int mid = getMid(start, end);

    segmentTree[segmentIndex] = max(constructSTUtil(arr, start, mid, segmentTree, segmentIndex * 2 + 1),
                                    constructSTUtil(arr, mid + 1, end, segmentTree, segmentIndex * 2 + 2));
}

int* constructST(int arr[], int n) {
    int height = (int)(ceil(log2(n)));
    int maxSize = 2 * (int)pow(2, height) - 1; 
    
    int* segmentTree = new int[maxSize];

    constructSTUtil(arr, 0, n - 1, segmentTree, 0);

    /*for (int i = 0; i < maxSize; ++i) {
        cout << segmentTree[i] << " ";
    }
    cout << endl;*/

    return segmentTree;
}

int main() {
    int arr[10000];

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int l, r;
    cin >> l >> r;

    int* segmentTree = constructST(arr, n);

    cout << "From " << l << " to " << r << ", max: ";
    cout << getMax(segmentTree, 0, n - 1, l, r, 0) << endl;

    system("pause");

    return 0;
}