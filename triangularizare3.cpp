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

	for (int k = 0; k < n-1; k++) {
		float max = 0;
		int p, q;
		float aux;
		for (i = k; i < n; i++) {
			for (j = k; j < n; j++) {
				if (max < abs(a[i][j])) {
					max = abs(a[i][j]);
					p = i;
					q = j;
				}
			}
		}
		if (a[p][q] != 0) {
			if (p != k) {
				for (i = 0; i < n; i++) {
					aux = a[p][i];
					a[p][i] = a[k][i];
					a[k][i] = aux;
				}
			}
			if (q != k) {
				for (j = 0; j < n; j++) {
					aux = a[j][q];
					a[j][q] = a[j][k];
					a[j][k] = aux;
				}
			}
			for (i = k + 1; i < n; i++) {
				for (j = k + 1; j < n; j++) {
					a[i][j] = a[i][j] - ((a[i][k] * a[k][j]) / a[k][k]);
				}
				a[i][k] = 0;
			}
		}
		else {
			cout << "Matricea este superior trianghiulara" << endl;
			k = n;
		}
	}
	cout << "Matricea triangularizata este:" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}

	_getch();
	return 0;
}