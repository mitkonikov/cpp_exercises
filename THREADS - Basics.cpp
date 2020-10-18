// Example code using multiple threads

#include <bits/stdc++.h>
#include <thread>

using namespace std;

// Example function that requires huge computational power
// This function should be independent of anything else in memory
void f(long long x, string name) {
    long long sum = 0;
    for (long long i = 0; i < x; i++) {
        sum = (sum + i) % 1000000009;
    }

    cout << name << " - " << sum << endl;
}

int main() {
    // We intentially called first the 100M operations
    // But you'll see that these take the most time executing

    thread th1(f, 100000000, "100M");
    thread th2(f, 1000000, "1M");
    thread th3(f, 10000000, "10M");
    thread th4(f, 1000000, "1M");

    th1.join();
    th2.join();
    th3.join();
    th4.join();

    return 0;
}