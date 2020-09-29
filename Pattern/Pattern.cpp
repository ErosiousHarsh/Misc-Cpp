#include <iostream>
#include <math.h>
using namespace std;

class Pattern {
	public:
		void p1();
		void p2();
};

void  Pattern::p1() {
	for (int i = 0; i < 5; i++) {
		for (int j = i; j >= 0; j--) {
			cout << pow(2,j) << " ";
		}
		cout << endl;
	}
}

void  Pattern::p2() {
	int c = 1;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			cout << c << " ";
			c++;
		}
		cout << endl;
	}
}

int main() {
	Pattern p;
	p.p1();
	cout << endl;
	p.p2();
	cin.get();
}