// A solution for the Russian Peasant Exponentiation problem on HackerRank.
// Link to the problem: https://www.hackerrank.com/challenges/russian-peasant-exponentiation/problem
// Authors: Mitko Nikov & Ivan Mastev
// Have fun!

#include <bits/stdc++.h>
#define real first
#define img second
#define ll long long

using namespace std;

pair<ll,ll> exp2(pair<ll, ll> a, pair<ll, ll> b, int m) {
    pair<ll, ll> result = make_pair(0, 0);
    result.real = ((a.real * b.real) % m - (a.img * b.img) % m) % m;
    result.img = ((a.real * b.img) % m + (a.img * b.real) % m) % m;
    return result;
}

ll makeItPositive(ll a, int m) {
    return (a + ((a / m) + 1) * m) % m;
}

vector<int> solve(int a, int b, long k, int m) {
    vector<int> resultV(2, 0);
    vector<  pair<ll, ll>  > dp(100);
    dp[0] = make_pair(a, b);

    long doK = 1, count = 1;
    while (doK * 2 <= k) {
        dp[count] = exp2(dp[count - 1], dp[count - 1], m);
        doK *= 2;
        count++;
    }

    k -= doK;
    pair<ll, ll> result = dp[count - 1];
    count = 0;
    while (k != 0) {
        if (k % 2 != 0) {
            result = exp2(result, dp[count], m);
        }
        
        count++;
        k >>= 1;
    }

    resultV[0] = makeItPositive(result.real, m);
    resultV[1] = makeItPositive(result.img, m);
    return resultV;
}

// MAIN FUNCTION...