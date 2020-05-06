#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

float function(float x) {
	return (x * exp(x)) - 1;
}

float derfunction(float x) {
	return (x + 1)* exp(x);
}

int main() {
	int	ITMAX, n;
	float init_x, eps, fin_x;

	cin >> init_x;
	cin >> eps;
	cin >> ITMAX;

	fin_x = init_x;
	n = 1;

	while ((abs(function(fin_x)) > eps) && (n <= ITMAX)) {
		fin_x = fin_x - (function(fin_x) / derfunction(fin_x));
		n++;
	}

	if( n > ITMAX ) {
		cout << "Nu a fost realizata aproximarea dorita";
	}
	else {
		cout << fin_x;
		cout << n;
	}
	_getch();
	return 0;
}