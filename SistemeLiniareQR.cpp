#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <iostream>
using namespace std;

void produs(int n, double a[10][10], double b[10][10], double rez[10][10]) {
	double aux[10][10];
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <=n; j++) {
			aux[i][j] = 0;
			for (int k = 1; k <=n; k++) {
				aux[i][j] = aux[i][j] + (a[i][k] * b[k][j]);
			}
		}
	}

	for (int i = 1; i <=n; i++)
		for (int j = 1; j <=n; j++)
			rez[i][j] = aux[i][j];
}

void factorizareQR(int n, double A[10][10]) {
	double a[10][10], r[10][10], h[10][10], q[10][10];
	double v[10];
	double delta, beta, s;
	for (int i = 1; i <=n; i++)
		for (int j = 1; j <=n; j++)
			if (i == j)
				q[i][j] = 1;
			else
				q[i][j] = 0;

	for (int i = 1; i <=n; i++) {
		v[i] = 0;
	}

	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <=n; j++) {
			h[i][j] = 0;
		}
	}

	for (int k = 1; k < n - 1; k++) {
		s = 0;
		for (int t = k; t <=n; t++) {
			s = s + pow(a[t][k], 2);
		}

		delta = sqrt(s);

		if (delta != 0) {
			if (a[k][k] < 0) {
				delta = (-1)*delta;
			}

			v[k] = a[k][k] + delta;
			for (int i = 1; i < k; i++) {
				v[i] = 0;
			}
			for (int i = k + 1; i <=n; i++) {

				v[i] = a[i][k];

			}


			s = 0;
			for (int i = k; i <=n; i++) {
				s = s + pow(v[i], 2);

			}

			beta = s * (1.00 / 2.00);

			for (int i = 1; i <=n; i++) {
				for (int j = 1; j <=n; j++) {
					if (i != j) {
						h[i][j] = -(v[i] * v[j]) / beta;
						if (h[i][j] == (-0))
							h[i][j] = 0;

					}
					else {
						h[i][j] = 1 - (pow(v[i], 2) / beta);

					}
				}
			}

			produs(n, h, a, a);
			produs(n, q, h, q);

		}
	}
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <=n; j++) {
			A[i][j] = a[i][j];
		}
	}
}

int main() {

	double a[10][10], q[10][10], r[10][10];
	double b[10], x[10], y[10], prod = 1.0, s;
	int n;

	cout << "n=";
	cin >> n;
	cout << "Matricea A:" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
	}

	cout << "Termenii liberi:" << endl;
	for (int i = 1; i <= n; i++) {
		cout << "b[" << i << "]=";
		cin >> b[i];
	}

	factorizareQR(n, a);

	for (int k = 1; k <= n; k++) {
		prod = prod * a[k][k];
	}

	if (prod != 0) {
		for (int i = 1; i <= n; i++) {
			 s = 0.0;
			for (int k = 1; k <= n; k++) {
				s += q[k][i] * b[k];
			}
			y[i] = s;
		}
		x[n] = y[n] / a[n][n];
		for (int i = n - 1; i >= 1; i++) {
			s = 0.0;
			for (int k = i + 1; k <= n; k++) {
				s += a[i][k] * x[k];
			}
			s = y[i] - s;
			x[i] = s / a[i][i];
		}

		cout << "Solutia este:" << endl;
		for (int i = 1; i <= n; i++) {
			cout << "x[" << i << "]=" << x[i] << endl;
		}

	}
	else {
		cout << "Sistemul nu poate fi rezolvat prin acest algoritm" << endl;
	}

	_getch();
	return 0;
}