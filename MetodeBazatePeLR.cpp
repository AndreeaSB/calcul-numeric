#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <iostream>


using namespace std;
double a[10][10], b[10], y[10], x[10], s;
int i, j, n, k;
void cit_sist(double a[10][10], double b[10])
{
	cout << "Dati ordinul sistemului:";
	cin >> n;
	cout << "Dati sistemul:" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
		cout << "b[" << i << "]=";
		cin >> b[i];
	}
}
void Alg()
{
	for (k = 1; k <= n - 1; k++)
	{
		if (a[k][k] != 0)
		{
			for (i = k + 1; i <= n; i++)
				for (j = k + 1; j <= n; j++)
					a[i][j] -= a[i][k] * a[k][j] / a[k][k];
			for (i = k + 1; i <= n; i++)
				a[i][k] = a[i][k] / a[k][k];
		}
		else
		{
			cout << "Matricea sistemului nu poate fi factorizata LR cu acest algoritm." << endl;
			cout << "Sistemul nu poate fi rezolvat cu acest algoritm" << endl;
			exit(1);
		}
	}
}
int main(){
	cit_sist(a, b);
	Alg();
	y[1] = b[1];
	for (i = 2; i <= n; i++)
	{
		y[i] = 0;
		for (k = 1; k <= i - 1; k++)
			y[i] += a[i][k] * y[k];
		y[i] = b[i] - y[i];
	}
	x[n] = y[n] / a[n][n];
	for (i = n - 1; i >= 1; i--)
	{
		x[i] = 0;
		for (k = i + 1; k <= n; k++)
			x[i] += a[i][k] * x[k];
		x[i] = (y[i] - x[i]) / a[i][i];
	}
	cout << "Solutia sistemului este:" << endl;
	for (i = 1; i <= n; i++)
		cout << "x[" << i << "]=" << x[i] << endl;
	_getch();
	return 0;
}