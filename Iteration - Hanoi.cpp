#include <iostream>
#include <list>

using namespace std;

list<int>* lhs = new list<int>;
list<int>* mid = new list<int>;
list<int>* rhs = new list<int>;

void initTower(int size) {
    while (size--)
        lhs->push_back(size + 1);
}

void printList(list<int> p) {
    if (p.empty()) {
        cout << "empty" << endl;
    }
    else {
        for (int i : p)
            cout << i << " ";
        cout << endl;
    }
}

void printTower() {
    cout << "==============" << endl;
    printList(*lhs);
    printList(*mid);
    printList(*rhs);
    cout << "==============" << endl << endl;
}

void move(list<int>* from, list<int>* to) {
    int fVal = 0;
    int toVal = 0;

    if (!from->empty()) fVal = from->back();
    if (!to->empty()) toVal = to->back();

    if ((fVal < toVal || toVal == 0) && fVal != 0) {
        from->pop_back();
        to->push_back(fVal);
    } else {
        to->pop_back();
        from->push_back(toVal);
    }
    
    printTower();
}

int main() {
    int SIZE;
    cin >> SIZE;
    initTower(SIZE);
    printTower();

    while (rhs->size() != SIZE) {
        if (SIZE % 2 == 0) {
            move(lhs, mid);
            move(lhs, rhs);
            move(mid, rhs);
        }
        else {
            move(lhs, rhs);
            move(lhs, mid);
            move(rhs, mid);
        }
    }

    return 0;
}