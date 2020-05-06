#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <iostream>



using namespace std;
double a[10][10], b[10][10], s[10], sigma[10];
int n, k, i;
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
void unitate(double a[10][10])
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == j)
				a[i][j] = 1;
			else
				a[i][j] = 0;
}
void produs(double a[10][10], double b[10][10], double c[10][10])
{
	double c1[10][10];
	int j, p;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			c1[i][j] = 0;
			for (p = 1; p <= n; p++)
				c1[i][j] += a[i][p] * b[p][j];
		}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			c[i][j] = c1[i][j];
}
void main()
{
	cit_mat(a);
	unitate(b);
	for (k = 1; k <= n; k++)
	{
		produs(a, b, b);
		s[k] = 0;
		for (i = 1; i <= n; i++)
			s[k] += b[i][i];
	}
	sigma[1] = s[1];
	for (k = 2; k <= n; k++)
	{
		sigma[k] = 0;
		for (i = 1; i <= k - 1; i++)
			sigma[k] += pow(-1, i + 1) * s[i] * sigma[k - i];
		sigma[k] = (sigma[k] + pow(-1, k + 1) * s[k]) / k;
	}
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
	_getch();
}