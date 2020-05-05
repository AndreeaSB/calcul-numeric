#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cmath>
using namespace std;

void produs(int n, double a[10][10], double b[10][10], double rez[10][10]) {
	double aux[10][10];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			aux[i][j] = 0;
			for (int k = 0; k < n; k++) {
				aux[i][j] = aux[i][j] + (a[i][k] * b[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			rez[i][j] = aux[i][j];
}
	

int main() {

	int n=3;
	double a[10][10], r[10][10], h[10][10], q[10][10];
	double v[10];
	double delta, beta,s;
	cout << "n=";
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
	}


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j)
				q[i][j] = 1;
			else
				q[i][j] = 0;

	for (int i = 0; i < n; i++) {
		v[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			h[i][j] = 0;
		}
	}

	for (int k = 0; k < n-1; k++) {
		s = 0;
		for (int t = k; t < n; t++) {
			s = s + pow(a[t][k], 2);
		}

		delta = sqrt(s);

		if (delta != 0) {
			if (a[k][k] < 0) {
				delta = (-1)*delta;
			}

			v[k] = a[k][k] + delta;
			for (int i = 0; i < k; i++) {
				v[i] = 0;
			}
			cout << "k="<<k<<endl;
			for (int i = k+1; i < n; i++) {

				v[i] = a[i][k];

			}


			s = 0;
			for (int i = k; i < n; i++) {
				s = s + pow(v[i], 2);

			}

			beta = s*(1.00 / 2.00);

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
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

			produs(n,h, a, a);

			cout << "Matricea A este" << endl;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << a[i][j] << " ";
				}
				cout << endl;
			}

			produs(n, q, h, q);

		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			r[i][j] = a[i][j];
		}
	}

	cout << "Matricea A este" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Matricea Q este" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout<<q[i][j]<<" ";
		}
		cout << endl;
	}

	cout << "Matricea R este" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << r[i][j] << " ";
		}
		cout << endl;
	}

	_getch();
	return 0;
}