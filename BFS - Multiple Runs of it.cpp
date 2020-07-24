/// Link to the problem:
/// http://mendo.mk/Task.do?id=704
/// code written by Mitko Nikov

#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

int matrix[1000][1000]; // MAIN MATRIX
int c[1000][1000];      // BFS CHAR MATRIX
int a[1000][1000];      // BFS SEARCH MATRIX
queue<  pair<int, int>  > flowers;
int width, height;

bool valid(int a, int b) {
    if (a >= 0 && b >= 0 && a < height && b < width && (c[a][b] == '.' || c[a][b] == 'C'))
        return true;
    return false;
}

void printArray(int b[1000][1000]) {
    cout << endl;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << setw(8) << b[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);

    cin >> height >> width;

    int Power;
    cin >> Power;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            char current;
            cin >> current;
            c[i][j] = current;
            matrix[i][j] = 0;
            a[i][j] = 101000;

            if (current == 'C') {
                flowers.push(make_pair(i, j));
            }
        }
    }

    int counter = 1;
    while (!flowers.empty()) {
        queue<  pair<int, int>  > q;
        pair<int, int> cur = flowers.front();
        q.push(cur);
        flowers.pop();
        a[cur.f][cur.s] = 101000 - counter * 1000;

        // BFS
        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            if (a[current.f][current.s] + 1 - (101000 - counter * 1000) <= Power) {
                if (valid(current.f + 1, current.s) && a[current.f + 1][current.s] > a[current.f][current.s] && a[current.f + 1][current.s] > 101000 - (counter + 1) * 1000 && a[current.f + 1][current.s] != a[current.f][current.s] + 1) {
                    a[current.f + 1][current.s] = a[current.f][current.s] + 1;
                    matrix[current.f + 1][current.s]++;
                    q.push(make_pair(current.f + 1, current.s));
                }
                if (valid(current.f, current.s + 1) && a[current.f][current.s + 1] > a[current.f][current.s] && a[current.f][current.s + 1] > 101000 - (counter + 1) * 1000 && a[current.f][current.s + 1] != a[current.f][current.s] + 1) {
                    a[current.f][current.s + 1] = a[current.f][current.s] + 1;
                    matrix[current.f][current.s + 1]++;
                    q.push(make_pair(current.f, current.s + 1));
                }
                if (valid(current.f - 1, current.s) && a[current.f - 1][current.s] > a[current.f][current.s] && a[current.f - 1][current.s] > 101000 - (counter + 1) * 1000 && a[current.f - 1][current.s] != a[current.f][current.s] + 1) {
                    a[current.f - 1][current.s] = a[current.f][current.s] + 1;
                    matrix[current.f - 1][current.s]++;
                    q.push(make_pair(current.f - 1, current.s));
                }
                if (valid(current.f, current.s - 1) && a[current.f][current.s - 1] > a[current.f][current.s] && a[current.f][current.s - 1] > 101000 - (counter + 1) * 1000 && a[current.f][current.s - 1] != a[current.f][current.s] + 1) {
                    a[current.f][current.s - 1] = a[current.f][current.s] + 1;
                    matrix[current.f][current.s - 1]++;
                    q.push(make_pair(current.f, current.s - 1));
                }
            }


            // printArray(a);
        }

        counter++;

        // printArray(a);
        // printArray(matrix);
    }

    int bx, by, best = 0;
    for (int k = 0; k < height; ++k) {
        for (int p = 0; p < width; ++p) {
            if (matrix[k][p] > best) {
                best = matrix[k][p];
                by = k + 1;
                bx = p + 1;
            }
        }
    }

    cout << by << " " << bx << endl;

    return 0;
}
