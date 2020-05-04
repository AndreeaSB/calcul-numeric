#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream>

using namespace std;
int main() {

	int n,ITMAX,i,j,m ;
	float a[10],eps, y[100],x,ec;
	cout<<"n="
	cin >> n;
	for (i = 0; i <= n; i++) {
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
	cout << "ITMAX=";
	cin >> ITMAX;
	cout << "eps=";
	cin >> eps;
	
	for (int i = 0; i < 2*n; i++) {
		y[i] = 0;
	}
	y[0] = n;
	y[1] = -a[1] / a[0];
	for (i = 2; i < n; i++) {
		for (j = 1; j < i; j++) {
			y[i] = y[i] - (y[i - j] * (a[j] / a[0]));
		}
		y[i] = y[i] - i * (a[i] * a[0]);
	}
	i = 0;
	m = 0;
	do {
		for (j = 1; j <= n; j++) {
			y[n+i] = y[n+i] - y[n + i - j] * (a[j] / a[0]);
		}
		x = y[n + i] / y[n + i - 1];
		m = m + 1;
		i = i + 1;
		ec = a[0] * pow(x, n);
		for (j = 1; j <= n; j++) {
			ec = ec + a[j] * pow(x, n - j);
		}
	} while ((abs(ec)>=eps) && (m<=ITMAX));
	if (m > ITMAX) {
		cout << "in ITMAX nu a fost realizata aprox dorita";
	}
	else {
		cout << x;
	}

	_getch();
	return 0;
}