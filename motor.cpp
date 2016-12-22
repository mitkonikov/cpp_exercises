#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<  vector<int>  > matrix;
bool globalFOUND = false;
int best = 0;
int sy, sx;
int py, px;
int counter = 1;

void printArray() {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Printing Array :" << endl;
    for (int i = 0; i < sy; ++i) {
        for (int ii = 0; ii < sx; ++ii) {
            cout << matrix[i][ii] << " ";
        }
        cout << endl;
    }
    cout << "Finished Printing Array" << endl;
}

bool testCheckK(int x, int y) {
    if (matrix[y][x + 1] == -5) // Right
        return true;

    if (matrix[y + 1][x] == -5) // Down
        return true;

    if (matrix[y][x - 1] == -5) // Left
        return true;

    if (matrix[y - 1][x] == -5) // Up
        return true;

    return false;
}

void setting(int x, int y, int input) {
    if (matrix[y][x + 1] == 0) { // Right
        matrix[y][x + 1] = input;
    }

    if (matrix[y + 1][x] == 0) { // Down
        matrix[y + 1][x] = input;
    }

    if (matrix[y][x - 1] == 0) { // Left
        matrix[y][x - 1] = input;
    }

    if (matrix[y - 1][x] == 0) { // Up
        matrix[y - 1][x] = input;
    }
}

void setSurroundingP(int x, int y) {
    printArray();
    if (testCheckK(x, y)) { // Proveri dali nekoj od sosedite e K
        globalFOUND = true;
        best = 1;
    }
    setting(x, y, 1);
}

void setSurrounding(int x, int y) {
    if (!globalFOUND) {
        printArray();
        if (testCheckK(x, y)) { // Proveri dali nekoj od sosedite e K
            globalFOUND = true;
            best = matrix[y][x] + 1;
        }
        setting(x, y, matrix[y][x] + 1);
    }
}

void calc() {
    printArray();

    while (true) {
        for (int i = 0; i < sy; ++i) {
            for (int ii = 0; ii < sx; ++ii) {
                if (matrix[i][ii] == -3) // Proveri dali e P
                    setSurroundingP(ii, i);
                else if (matrix[i][ii] == counter)
                    setSurrounding(ii, i);
            }
        }

        if (best > 0)
            break;

        counter++;
    }
}

int main()
{
    vector<string> cont;

    cout << "Size Y: ";
    cin >> sy;
    cout << "Size X: ";
    cin >> sx;

    // Ja polni matricata
    for (int i = 0; i < sy; ++i) {
        string current;
        cin >> current;
        cont.push_back(current);
    }

    // Ja pretvara matricata vo brojki za polesna obrabotka
    for (int y = 0; y < sy; ++y) {
        vector<int> temp;
        for (int x = 0; x < sx; ++x) {
            if (cont[y][x] == '.') {
                temp.push_back(0); // MOZE
            } else if (cont[y][x] == '+') {
                temp.push_back(-1); // ZID
            } else if (cont[y][x] == 'P') {
                temp.push_back(-3); // POCETOk
            } else if (cont[y][x] == 'K') {
                temp.push_back(-5); // KRAJ
            } else {
                temp.push_back(-1);
            }
        }
        matrix.push_back(temp);
    }

    calc();
    cout << "\n-------------------\n\n" << best << endl;

    return 0;
}
