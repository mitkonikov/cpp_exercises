#include <bits/stdc++.h>

using namespace std;

#define MX vector<vector<T>>
#define MOD 1000000007

template<typename T>
class Matrix { // Only for NxN matrix
public:
    MX m;
    int n;
    Matrix(int n) {
        this->n = n;
        m.resize(n, vector<T>(n, 0));
    }

    Matrix(const MX &copy) {
        this->m = MX(copy);
        this->n = copy.size();
    }

    void print() const {
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m[i].size(); j++) {
                cout << m[i][j] << " ";
            }

            cout << "\n";
        }
        cout << flush;
    }

    Matrix operator*(const Matrix &b) const {
        Matrix<T> result(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    result.m[i][j] = (result.m[i][j] + (this->m[i][k] * b.m[k][j]) % MOD) % MOD;
                }
            }
        }

        return result;
    }

    Matrix binary(long long power) const {
        Matrix<T> a(this->m);
        Matrix<T> result(n);
        for (int i = 0; i < n; i++) result.m[i][i] = 1;

        while (power > 0) {
            if (power % 2 == 1) {
                result = result * a;
                power--;
            }

            a = a * a;
            power /= 2;
        }

        return result;
    }
};

int main() {
    
    return 0;
}