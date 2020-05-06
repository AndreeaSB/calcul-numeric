#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <iostream>
using namespace std;

double a[10][10], b[10][10], at[10][10], sigma[10], u;
int i, j, n, k;
double urma(double a[10][10])
{
	int i;
	float u;
	u = 0;
	for (i = 1; i <= n; i++)
		u = u + a[i][i];
	return u;
}
void cit_mat(double a[10][10])
{
	cout << "n=";
	cin >> n;
	cout << "Matricea A:" << endl;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
}
void produs(double a[10][10], double b[10][10], double c[10][10])
{
	double s;
	int p;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			s = 0;
			for (p = 1; p <= n; p++)
				s += a[i][p] * b[p][j];
			c[i][j] = s;
		}
}
int main()
{
	cit_mat(a);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			at[i][j] = a[i][j];

	sigma[1] = urma(at);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i != j)
				b[i][j] = -at[i][j];
			else
				b[i][j] = sigma[1] - at[i][j];

	for (k = 2; k <= n - 1; k++)
	{
		produs(a, b, at);

		sigma[k] = urma(at);
		sigma[k] = sigma[k] / k;

		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (i != j)
					b[i][j] = -at[i][j];
				else
					b[i][j] = sigma[k] - at[i][j];
	}

	produs(a, b, at);

	sigma[n] = urma(at);
	sigma[n] = sigma[n] / n;

	cout << "Polinomul caracteristic este:" << endl;
	cout << "f(x)=x^" << n;
	for (i = 1; i <= n; i++)
		if (i % 2 == 0)
		{
			if (sigma[i] >= 0)
				cout << "+" << sigma[i] << "*x^" << n - i;
			else
				cout << sigma[i] << "*x^" << n - i;
		}
		else
		{
			if (sigma[i] >= 0)
				cout << "-" << sigma[i] << "*x^" << n - i;
			else
				cout << "+" << -sigma[i] << "*x^" << n - i;
		}
	cout << endl;
	cout << "Determinantul matricei A este: det(A)=" << sigma[n];
	cout << endl;
	if (sigma[n] != 0)
	{
		cout << "Inversa matricei A este:" << endl;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
				cout << b[i][j] / sigma[n] << "\t";
			cout << endl;
		}
	}
	else
		cout << "Matricea A nu este inversabila.";

	_getch();
	return 0;
}