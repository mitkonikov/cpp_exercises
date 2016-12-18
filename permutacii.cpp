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
    for (int i = 0; i < n; ++i) {
        if (vec[i] != n-i) {
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

    // Ja polni nizata
    for (int i = 1; i <= n; ++i) {
        int current = 1;
        cout << "Element: ";
        cin >> current;
        vec.push_back(current);
    }

    cout << endl;

    printArray(vec); // Pecati ja pocetnata niza

    while (true) {
        for (int i = n - 2; i >= 0; i--) {
            // Pocnuva od posledniot element
            // t.e. elementot od desno
            if (vec[i + 1] > vec[i]) {
                for (int z = n - 1; z >= 0; z--) {
                    if (vec[z] > vec[i]) {
                        int t = vec[z];
                        vec[z] = vec[i];
                        vec[i] = t;

                        // Zameni gi mestata na
                        // elementite desno od i
                        vector<int> temp;
                        for (int y = i + 1; y < n; ++y) {
                            temp.push_back(vec[y]);
                        }
                        for (int x = 0; x < temp.size(); ++x) {
                            vec[i + 1 + x] = temp[temp.size() - 1 - x];
                        }
                        // ---------------------------

                        printArray(vec);
                        break;
                    }
                }
            }
        }

        if (testCheck()) // Ako e (n-k+1), (n-k+2)...n
            break;
    }

    return 0;
}
