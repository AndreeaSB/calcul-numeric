#include <iostream>
#include <math.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {
	float a[10][10];
	float l[10][10];
	float r[10][10];
	int n, i, j, k;
	cout << "Numarul de linii si coloane este: ";
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++) {
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
	for (k = 1; k <= n - 1; k++) {
		if (a[k][k] != 0) {
			for (i = k + 1; i <= n; i++) {
				for (j = k + 1; j <= n; j++) {
					a[i][j] = a[i][j] - ((a[i][k] * a[k][j]) / a[k][k]);

				}
				a[i][k] = a[i][k] / a[k][k];
			}
		}
		else {
			cout << "Matricea A nu poate fi factorizata LR cu acest algoritm";
		}
	}
	cout << "Matricea A factorizata este: " << endl;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			if (i > j)
				l[i][j] = a[i][j];
			else if (i == j)
				l[i][j] = 1;
			else
				l[i][j] = 0;

	}
	cout << "Matricea L este: " << endl;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			cout << l[i][j] << " ";
		cout << endl;
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			if (i > j)
				r[i][j] = 0;
			else
				r[i][j] = a[i][j];


	}
	cout << "Matricea R este: " << endl;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			cout << r[i][j] << " ";
		cout << endl;
	}


	_getch();
	return 0;
}