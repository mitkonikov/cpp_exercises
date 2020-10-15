#include <iostream>

using namespace std;

void move(string f, string t) {
	cout << "Move from " << f << " to " << t << endl;
}

void hanoi(int n, string f, string v, string t) {
	if (n == 0) return;
	hanoi(n - 1, f, t, v);
	move(f, t);
	hanoi(n - 1, v, f, t);
}

int main()
{
	hanoi(4, "A", "B", "C");

	return 0;
}