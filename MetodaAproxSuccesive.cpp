#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

float function(float x) {
	x = (-1)* x;
	return exp(x);
}
int main() {
	float init_x=5.0, fin_x, eps=0.001;
	int ITMAX=100, n;

	//cin >> init_x;
	//cin >> eps;
	//cin >> ITMAX;

	fin_x = init_x;
	n = 1;
	while ((abs(fin_x - function(fin_x)) > eps) && (n <= ITMAX)) {
		fin_x = function(fin_x);
		n++;
		cout <<n << "+"<< fin_x << endl;
	}

	if (n > ITMAX) {
		cout << "Nu a fost realizata aproximarea dorita";
	}
	else {
		cout << fin_x << " " << n;
	}

	_getch();
	return 0;
}