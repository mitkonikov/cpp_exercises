// Generating the threads in a for loop
// You will see a 100% CPU usage, if you're CPU has 8 threads

#include <bits/stdc++.h>
#include <thread>

using namespace std;

// These are the results from each thread
vector<string> results(8);

// Example function that requires huge computational power
// This function should be independent of anything else in memory
void f(long long x, int iThread) {
    long long sum = 0;
    for (long long i = 0; i < x; i++) {
        sum = (sum + i) % 1000000009;
    }

    results[iThread] = "Thread " + to_string(iThread) + " - " + to_string(sum);
}

int main() {
    vector<thread*> ths;

    // We create the threads
    for (int i = 0; i < 8; i++) {
        thread* th = new thread(f, 900000000, i);
        ths.push_back(th);
    }

    // We call join on them
    for (int i = 0; i < 8; i++) {
        ths[i]->join();
    }

    // We read the results when they are all done
    for (int i = 0; i < 8; i++) {
        cout << results[i] << endl;
    }

    return 0;
}