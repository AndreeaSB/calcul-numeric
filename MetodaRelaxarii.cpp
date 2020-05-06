#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <iostream>
using namespace std;



int main() {

	double a[10][10];
	double b[10], x[10], r[10];
	double eps, s, max;
	int n, m, p, ITMAX;

	cout << "n=";
	cin >> n;

	cout << "Matricea sistemului:" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
		cout << "b[" << i << "]=";
		cin >> b[i];
	}

	cout << "eps=";
	cin >> eps;

	cout << "Aproximarea initiala a solutiei:" << endl;
	for (int i = 1; i <= n; i++) {
		cout << "x[" << i << "]=";
		cin >> x[i];
	}
	cout << "ITMAX=";
	cin >> ITMAX;

	m = 1;
	for (int i = 1; i <= n; i++) {
		r[i] = b[i] - x[i];
		s = 0.0;
		for (int j = 1; j <= n; j++) {
			if (j != i) {
				s += a[i][j] * x[i];
			}
		}
		r[i] = r[i] + s;
	}

	max = 0;
	for (int i = 1; i <= n; i++) {
		if (abs(r[i]) > max) {
			max = abs(r[i]);
			p = i;
		}
	}

	while (max >= eps && m <= ITMAX) {
		x[p] = x[p] + r[p];
		for (int q = 1; q <= n; q++) 
			if (q != p) {
				r[q] += a[q][p] * r[p];
			}
			else {
				r[q] = 0;
			}
		max = 0;
		for (int i = 1; i <= n; i++) {
			if (abs(r[i]) >max) {
				max = abs(r[i]);
				p = i;
			}
		}
		m++;
	}

	if (m > ITMAX) {
		cout << "In " << ITMAX << " iteratii nu este obtinuta aproximare dorita";
		_getch();
		return 0;
	}
	else {
		cout << "Aproximarea obtinuta este:" << endl;
		for (int i = 1; i <= n; i++) {
			cout << "x[" << i << "]=" << x[i] << endl;
		}
	}
	
	_getch();
	return 0;
}