#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <iostream>
using namespace std;



int main() {

	double a[10][10], b[10][10];
	double det, max, aux;
	int n, p, q, t;

	cout << "n=";
	cin >> n;
	cout << "Matrice A:" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
	}
	t = 1;
	while (n >= 3) {
		max = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (abs(a[i][j]) > max) {
					max = abs(a[i][j]);
					p = i;
					q = j;
				}
			}
		}
		if (a[p][q] == 0) {
			det = 0;
			return 0;
		}
		else {
			if (p != 1) {
				for (int i = 1; i <= n; i++) {
					aux = a[1][i];
					a[1][i] = a[p][i];
					a[p][i] = aux;
				}
				t = -t;
			}
			if (q != 1) {
				for (int i = 1; i <= n; i++) {
					aux = a[i][q];
					a[i][q] = a[i][1];
					a[i][1] = aux;
				}
				t = -t;
			}

			for (int i = 3; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					a[i][j] = a[i][j] / a[1][1];
				}
			}

			for (int i = 1; i < n; i++) {
				for (int j = 1; j < n; j++) {
					b[i][j] = a[1][1] * a[i + 1][j + 1] - a[i + 1][1] * a[1][j + 1];
				}
			}
			n = n - 1;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					a[i][j] = b[i][j];
				}
			}
		}
	}
	det = t * (a[1][1] * a[2][2] - a[1][2] * a[2][1]);
	cout << "det=" << det;
	_getch();
	return 0;
}