#include <iostream>
#include <math.h>
#include <conio.h>
#include <stdio.h>

using namespace std;



int main() {
	float a[10][10];
	float l[10][10];
	float r[10][10];
	int n, i, j, k, h;
	float s;
	cout << "Numarul de linii si coloane este: ";
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++) {
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
	
	if (a[1][1] == 0) {
		cout << "Matricea A nu poate fi factorizata cu formulele 1";
		return 0;
	}
	else {
		for (i = 2; i <= n; i++) {
			a[i][1] = a[i][1] / a[1][1];
		}
		for (k = 2; k <= n - 1; k++) {
			for (j = k; j <= n; j++) {
				s = 0;
				for (h = 1; h <= k - 1; h++) {
					s += (a[k][h] * a[h][j]);
				}
				a[k][j] = a[k][j] - s;
			}
			if (a[k][k] == 0) {
				cout << "Matricea A nu poate fi factorizata cu formulele 1";
				return 0;
			}
			else {
				for (i = k + 1; i <= n; i++) {
					s = 0;
					for (h = 1; h <= k - 1; h++) {
						s += (a[i][h] * a[h][k]);
					}
					a[i][k] = (1 / a[k][k])*(a[i][k] - s);
				}
			}
		}
		s = 0;
		for (h = 1; h <= n - 1; h++) {
			s += (a[n][h] * a[h][n]);

		}
		a[n][n] = a[n][n] - s;
	}
	cout << "Matricea A factorizata este: " << endl;
	for (i = 1; i <= n; i++)
	{
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
			cout << l[i][j] << "   ";
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