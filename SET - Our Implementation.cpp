/**
 * This is the way a simple SET is implemented.
 * With this solution you can create a set, insert a new value and traverse through it.
 * > This was coded as an exercise.
 * Author: Mitko Nikov
 */

#include <bits/stdc++.h>
#define DEBUG false

using namespace std;

struct node {
    node* left = NULL;
    node* right = NULL;
    int value;
};

// Inserts an element into the set
// And returns a boolean whether that element matches an already existing one
bool insert(node* root, int value) {
    if (value == root->value) {
        return false;
    }

    if (value < root->value) {
        if (!root->left) {
            node* newNode = new node();
            newNode->value = value;
            root->left = newNode;
            if (DEBUG) cout << "Added to the Left. Value: " << newNode->value << endl;
            return true;
        } else {
            return insert(root->left, value);
        }
    } else {
        if (!root->right) {
            node* newNode = new node();
            newNode->value = value;
            root->right = newNode;
            if (DEBUG) cout << "Added to the Right. Value: " << newNode->value << endl;
            return true;
        } else {
            return insert(root->right, value);
        }
    }
}

// Creates a set from an array
node* createSet(int* ls, int n) {
    if (DEBUG) cout << "Creating Set..." << endl;

    node* main = new node();
    main->value = ls[0];

    for (int i = 1; i < n; ++i) {
        insert(main, ls[i]);
    }

    return main;
}

// Traverses the set and pushes the values into a vector
void convertToList(node* root, vector<int>* ls) {
    if (DEBUG) cout << "Converting to Vector..." << endl;

    ls->push_back((int)root->value);
    if (DEBUG) cout << "Push value " << root->value << endl;

    if (root->left) {
        convertToList(root->left, ls);
    }

    if (root->right) {
        convertToList(root->right, ls);
    }
}

int main() {
    // Input a list
    int n;
    cin >> n;

    int ls[n];

    for (int i = 0; i < n; ++i) {
        cin >> ls[i];
    }

    // Create a set
    node* root = createSet(ls, n);

    // Convert it to vector
    vector<int> afterSet;
    convertToList(root, &afterSet);

    // Print it
    for (int i = 0; i < afterSet.size(); ++i) {
        cout << afterSet[i] << ", ";
    }

    cout << endl;

    system("pause");

    return 0;
}
