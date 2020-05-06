#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

float function(float x) {
	return (x * exp(x)) - 1;
}
int main() {
	float x0, x1,fin_x, eps;
	int ITMAX,n;
	cin >> x0;
	cin >> x1;
	cin >> eps;
	cin >> ITMAX;

	n = 1;
	while ((abs(function(x1)) > eps) && (n <= ITMAX)) {
		fin_x = x1 - ((function(x1)*(x1 - x0)) / (function(x1) - function(x0)));
		x0 = x1;
		x1 = fin_x;
		n++;
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