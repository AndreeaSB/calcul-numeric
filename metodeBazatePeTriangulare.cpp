#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <iostream>


using namespace std;
double sum, t, max, a[10][10], s[10][10], y[10], x[10];
int i, j, k, n, p, q;
void main()
{
	cout << "Dati ordinul sistemului n=";
	cin >> n;
	cout << "Dati sistemul:";
	for (i = 1; i <= n; i++)
	{
		cout << endl;
		for (j = 1; j <= n; j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
		cout << "b[" << i << "]=";
		cin >> a[i][n + 1];
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j)
				s[i][j] = 1;
			else
				s[i][j] = 0;
	for (k = 1; k <= n - 1; k++)
	{
		max = 0;
		for (i = k; i <= n; i++)
			for (j = k; j <= n; j++)
				if (max < abs(a[i][j]))
				{
					max = abs(a[i][j]);
					p = i;
					q = j;
				}
		if (a[p][q] != 0)
		{
			if (p != k)
				for (j = k; j <= n + 1; j++)
				{
					t = a[k][j];
					a[k][j] = a[p][j];
					a[p][j] = t;
				}
			if (q != k)
			{
				for (i = 1; i <= n; i++)
				{
					t = a[i][k];
					a[i][k] = a[i][q];
					a[i][q] = t;
					t = s[i][k];
					s[i][k] = s[i][q];
					s[i][q] = t;
				}
			}
			for (i = k + 1; i <= n; i++)
			{
				for (j = k + 1; j <= n + 1; j++)
					a[i][j] -= a[i][k] * a[k][j] / a[k][k];
				a[i][k] = 0;
			}
		}
		else
		{
			cout << "Sistemul Ax=b nu poate fi rezolvat prin acest algoritm";
			exit(1);
		}
	}
	y[n] = a[n][n + 1] / a[n][n];
	for (i = n - 1; i >= 1; i--)
	{
		sum = 0;
		for (k = i + 1; k <= n; k++)
			sum += a[i][k] * y[k];
		y[i] = (a[i][n + 1] - sum) / a[i][i];
	}
	for (i = 1; i <= n; i++)
	{
		x[i] = 0;
		for (k = 1; k <= n; k++)
			x[i] += s[i][k] * y[k];
	}
	cout << "Solutia sistemului este:";
	for (i = 1; i <= n; i++)
		cout << endl << "x[" << i << "]=" << x[i] ;
	_getch();
}