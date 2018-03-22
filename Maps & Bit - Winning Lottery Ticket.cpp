// hackerrank link: https://www.hackerrank.com/challenges/winning-lottery-ticket/problem

#include <bits/stdc++.h>

using namespace std;

unsigned long long winningLotteryTicket(vector <string> tickets) {
    map<int, long> converted;
    map<int, long>::iterator it1;
    map<int, long>::iterator it2;
    
    long numOfTickets = tickets.size();
    for (long i = 0; i < numOfTickets; ++i) {
        int ticketDigits = 0;
        for (long s = 0; s < tickets[i].length(); ++s) {
            ticketDigits |= (1LL << (tickets[i][s] - '0'));
            if (ticketDigits == (1LL << 10) - 1) break;
        }
        //cout << ticketDigits << endl;
        converted[ticketDigits]++;
    }
    
    unsigned long long goal = (1 << 10) - 1;
    unsigned long long count = 0;
    for (it1 = converted.begin(); it1 != prev(converted.end()); ++it1) {
        for (it2 = next(it1); it2 != converted.end(); ++it2) {
            if ((it1->first | it2->first) == goal) {
                count += it1->second * it2->second;
                //cout << " i ; k = " << i << " ; " << k << " = " << (converted[i] | converted[k]) << endl;
            }
        }
    }
    
    return count + converted[goal] * (converted[goal] - 1) / 2;
}

int main() {
    int n;
    cin >> n;
    vector<string> tickets(n);
    for(int tickets_i = 0; tickets_i < n; tickets_i++){
       cin >> tickets[tickets_i];
    }
    unsigned long long result = winningLotteryTicket(tickets);
    cout << result << endl;
    return 0;
}
