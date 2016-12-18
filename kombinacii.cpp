#include <iostream>
#include <vector>

using namespace std;

int n;           // Goleminata na nizata
int k;           // Klasa
vector<int> vec; // Nizata elementi

void printArray(vector<int> arr) {
    for (int i = 0; i < arr.size(); ++i) {
        if (i + 1 == arr.size())
            cout << arr[i];
        else
            cout << arr[i] << ", ";
    }
    cout << endl;
}

bool testCheck() {
    bool breaking = true;
    for (int i = 0; i < k; ++i) {
        if (vec[i] != n-k+i+1) {
            breaking = false;
            break;
        }
    }

    if (breaking)
        return true;

    return false;
}

int main()
{
    cout << "Golemina (n) : ";
    cin >> n; // Goleminata na nizata
    cout << "Klasa (k) : ";
    cin >> k; // Klasa

    // Ja polni nizata
    for (int i = 1; i <= k; ++i) {
        vec.push_back(i);
    }

    printArray(vec); // Pecati ja pocetnata niza

    while (true) {
        for (int i = k - 1; i >= 0; i--) {
            // Pocnuva od posledniot element
            // t.e. elementot od desno
            if (vec[i] < n-k+i+1) {
                vec[i]++;
                if (i != n - 1) { // Ako ne e posledniot
                    // Da se zgolemat drugite od desno
                    for (int ii = i + 1; ii <= k; ++ii) {
                        vec[ii] = vec[ii - 1] + 1;
                    }
                }
                printArray(vec);
                break;
            }
        }

        if (testCheck()) // Ako e (n-k+1), (n-k+2)...n
            break;
    }

    return 0;
}
