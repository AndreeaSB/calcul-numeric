#include<iostream>
#include<math.h>
#include<conio.h>
#include <stdio.h>

using namespace std;

int main() {

	float a[10][10];
	int n, i, j;
	cout << "Numarul de linii si coloane este: ";
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}

	for (int k = 0; k < n - 1; k++) {
		float maxim = 0;
		int p;
		float aux;
		for (i = k; i < n; i++) {
			if (maxim < abs(a[i][k])) {
				maxim = abs(a[i][k]);
				p = i;
			}
		}
		if (a[p][k] != 0) {
			if (p != k) {
				for (i = 0; i < n; i++) {
					aux = a[p][i];
					a[p][i] = a[k][i];
					a[k][i] = aux;
				}
			}
			for (i = k + 1; i < n; i++) {
				for (j = k + 1; j < n; j++) {
					a[i][j] = a[i][j] - ((a[i][k] * a[k][j]) / a[k][k]);
				}
				a[i][k] = 0;
			}

		}
	}

	cout << "Matricea triangularizata este: " << endl;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}

	_getch();
	return 0;

}