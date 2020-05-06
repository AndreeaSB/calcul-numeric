#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <iostream>


using namespace std;

int main()
{

	double a[20][20], s[10][10], max, t;
	int n, i, j, k, p, q;

	cout << "n=";
	cin >> n;
	cout << "Matricea A:" << endl;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i != j)
			{
				a[i][n + j] = 0;
				s[i][j] = 0;
			}
			else
			{
				a[i][n + j] = 1;
				s[i][j] = 1;
			}
	for (k = 1; k <= n - 1; k++)
	{
		max = fabs(a[k][k]);
		p = k;
		q = k;
		for (i = k ; i <= n; i++)
			for (j = k ; j <= n; j++)
				if (max < fabs(a[i][j]))
				{
					max = fabs(a[i][j]);
					p = i;
					q = j;
				}
		if (a[p][q] != 0)
		{
			if (p != k)
				for (j = k; j <= 2 * n; j++)
				{
					t = a[k][j];
					a[k][j] = a[p][j];
					a[p][j] = t;
				}
			if (q != k)
				for (i = 1; i <= n; i++)
				{
					t = a[i][k];
					a[i][k] = a[i][q];
					a[i][q] = t;
					t = s[i][k];
					s[i][k] = s[i][q];
					s[i][q] = t;
				}
			for (i = 1; i <= n; i++)
				if (i != k)
				{
					for (j = k + 1; j <= 2 * n; j++)
						a[i][j] -= a[i][k] * a[k][j] / a[k][k];
					a[i][k] = 0;
				}
			for (j = 2 * n; j >= k; j--)
				a[k][j] = a[k][j] / a[k][k];
		}
		else
		{
			cout << "Matricea A nu este inversabila.";
			return 0;
		}
	}
	if (a[n][n] != 0)
	{
		for (i = 1; i <= n - 1; i++)
		{
			for (j = n + 1; j <= 2 * n; j++)
				a[i][j] -= a[i][n] * a[n][j] / a[n][n];
			a[i][n] = 0;
		}
		for (j = 2 * n; j >= n; j--)
			a[n][j] = a[n][j] / a[n][n];
	}
	else
	{
		cout << "Matricea A nu este inversabila.";
		return 0;
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			t = 0;
			for (k = 1; k <= n; k++)
				t+= s[i][k] * a[k][n + j];
			a[i][j] = t;
		}
	cout << "Inversa matricii A este:" << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			cout << a[i][j] << "  ";
		cout << endl;
	}
	_getch();
	return 0;
}