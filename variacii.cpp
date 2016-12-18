#include <iostream>
#include <vector>

using namespace std;

int vs;          // Vector Size
int b;           // Pocetniot element
int n;           // Krajniot element
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
    for (int i = 0; i < vs; ++i) {
        if (vec[i] != n) {
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
    cin >> vs; // Goleminata na nizata

    // Ja polni nizata
    for (int i = 0; i < vs; ++i) {
        int current;
        cin >> current;

        if (i == 0) { // Ako e pocetniot element
            for (int i = 0; i < vs; ++i) {
                vec.push_back(current);
                // Ke ja generira pocetnata niza
            }
            b = current;
        } else if (i + 1 == vs) { // Ako e posledniot
            n = current;
        }
    }

    printArray(vec); // Pecati ja pocetnata niza

    while (true) {
        for (int i = vs - 1; i >= 0; i--) {
            // Pocnuva od posledniot element
            // t.e. elementot od desno
            if (vec[i] != n) {
                vec[i]++;
                if (i != vs - 1) { // Ako ne e posledniot
                    // Da se resetiraat drugite od desno
                    for (int ii = i + 1; ii <= vs; ++ii) {
                        vec[ii] = b;
                    }
                }
                printArray(vec);
                break;
            }
        }

        if (testCheck()) // Ako site se n,n,n,n...
            break;
    }

    return 0;
}
