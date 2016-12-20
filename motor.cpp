#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Cell {
private:
    int cx, cy, cv;
    bool cp, ck, visited;
public:
    Cell(int xi, int yi, bool pi, bool ki, int vi) {
        cx = xi;
        cy = yi;
        cp = pi;
        ck = ki;
        cv = vi;
        visited = false;
    }

    int getX() {
        return cx;
    }
    int getY() {
        return cy;
    }
    int getV() {
        return cv;
    }
    bool getP() {
        return cp;
    }
    bool getK() {
        return ck;
    }
    bool isnotVisited() {
        return !visited;
    }

    void setV(int input) {
        cv = input;
    }
    void setVisited() {
        visited = true;
    }
};

vector<  vector<Cell>  > matrix;
int sy, sx;
int py, px;
int ky, kx;
bool globalFOUND = false;

void printArray() {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Printing Array :" << endl;
    for (int i = 0; i < sy; ++i) {
        for (int ii = 0; ii < sx; ++ii) {
            cout << matrix[i][ii].getV() << " ";
        }
        cout << endl;
    }
    cout << "Finished Printing Array" << endl;
}

bool testCheckK(int x, int y) {
    if (matrix[y][x + 1].getK()) // Right
        return true;

    if (matrix[y + 1][x].getK()) // Down
        return true;

    if (matrix[y][x - 1].getK()) // Left
        return true;

    if (matrix[y - 1][x].getK()) // Up
        return true;

    return false;
}

int rec(int x, int y) {
    if (!globalFOUND) {
        matrix[y][x].setVisited();
        printArray();
        if (testCheckK(x, y)) { // Proveri dali nekoj od sosedite e K
            globalFOUND = true;
            return matrix[y][x].getV() + 1;
        }

        if (matrix[y][x + 1].isnotVisited() && matrix[y][x + 1].getV() == 0) { // Right
            matrix[y][x + 1].setV(matrix[y][x].getV() + 1);
            return rec(x + 1, y);
        }

        if (matrix[y + 1][x].isnotVisited() && matrix[y + 1][x].getV() == 0) { // Down
            matrix[y + 1][x].setV(matrix[y][x].getV() + 1);
            return rec(x, y + 1);
        }

        if (matrix[y][x - 1].isnotVisited() && matrix[y][x - 1].getK() == 0) { // Left
            matrix[y][x - 1].setV(matrix[y][x].getV() + 1);
            return rec(x - 1, y);
        }

        if (matrix[y - 1][x].isnotVisited() && matrix[y - 1][x].getK() == 0) { // Up
            matrix[y - 1][x].setV(matrix[y][x].getV() + 1);
            return rec(x, y - 1);
        }
    } else
        return -1;
}

int calc() {
    printArray();

    // Go bara P
    for (int i = 0; i < sy; ++i) {
        for (int ii = 0; ii < sx; ++ii) {
            if (matrix[i][ii].getP()) // Proveri dali e P
                return rec(ii, i);
        }
    }

    return -1;
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
        vector<Cell> temp;
        for (int x = 0; x < sx; ++x) {
            if (cont[y][x] == '.') {
                temp.push_back(Cell(x, y, false, false, 0)); // MOZE
            } else if (cont[y][x] == 'x') {
                temp.push_back(Cell(x, y, false, false, -1)); // ZID
            } else if (cont[y][x] == 'P') {
                temp.push_back(Cell(x, y, true, false, 0)); // POCETOk
            } else if (cont[y][x] == 'K') {
                temp.push_back(Cell(x, y, false, true, 0)); // KRAJ
            } else {
                temp.push_back(Cell(x, y, false, false, -1));
            }
        }
        matrix.push_back(temp);
    }

    int c = calc();
    cout << endl;
    cout << "-------------------" << endl;
    cout << endl;
    if (c == -1) {
        cout << "FAILED!" << endl;
    } else {
        cout << c << endl;
    }

    return 0;
}
