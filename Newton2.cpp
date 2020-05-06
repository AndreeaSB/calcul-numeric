#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

int main() {
	int  ITMAX, n;
	float init_x, fin_x, eps, a, p;

	cin >> a;
	cin >> p;
	cin >> init_x;
	cin >> eps;
	cin >> ITMAX;

	n = 1;
	fin_x = init_x;
	while (((pow(fin_x, p) - a) > eps) && (n <= ITMAX)) {
		fin_x = (1/p)*((p - 1)*fin_x + (a/ (pow(fin_x, (p-1)))));
		n = n + 1;
		cout << fin_x << endl;
	}
	if (n > ITMAX) {
		cout << "Nu a fost realizata aproximarea dorita";
	}
	else {
		cout << fin_x<< " " << n;
	}


	_getch();
	return 0;
 }