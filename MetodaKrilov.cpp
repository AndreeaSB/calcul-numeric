#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <iostream>
using namespace std;

int i, j, k, n, h;
double a[10][10], x[10], y[10][10], yy[10][10], d;

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
void det(int n, double a[10][10], double e)
{
	double max, c, b[10][10];
	int t, p, q;
	t = 1;
	while (n >= 3)
	{
		max = fabs(a[1][0]);
		p = 1;
		q = 1;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (max < fabs(a[i][j]))
				{
					max = fabs(a[i][j]);
					p = i;
					q = j;
				}
		if (a[p][q] == 0)
		{
			h = 1;
			break;
		}
		else
		{
			if (p != 1)
			{
				for (j = 1; j <= n; j++)
				{
					c = a[1][j];
					a[1][j] = a[p][j];
					a[p][j] = c;
				}
				t = -t;
			}

			if (q != 1)
			{
				for (i = 1; i <= n; i++)
				{
					c = a[i][1];
					a[i][1] = a[i][q];
					a[i][q] = c;
				}
				t = -t;
			}
			for (i = 3; i <= n; i++)
				for (j = 1; j <= n; j++)
					a[i][j] = a[i][j] / a[1][1];
			for (i = 1; i <= n - 1; i++)
				for (j = 1; j <= n - 1; j++)
					b[i][j] = a[1][1] * a[i + 1][j + 1] - a[i + 1][1] * a[1][j + 1];
			n = n - 1;
			for (i = 1; i <= n; i++)
				for (j = 1; j <= n; j++)
					a[i][j] = b[i][j];
		}
	}
	e = t * (a[1][1] * a[2][2] - a[1][2] * a[2][1]);
}
void Alg28(double a[10][10], double x[10])
{
	double s[10][10], max, t;
	int p, q;
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
					for (j = k + 1; j <= n + 1; j++)
						a[i][j] -= a[i][k] * a[k][j] / a[k][k];
					a[i][k] = 0;
				}
			for (j = n + 1; j >= k; j--)
				a[k][j] = a[k][j] / a[k][k];
		}
		else
		{
			cout << "Sistemul nu poate fi rezolvat prin acest algoritm";
			h = 1;
			break;
		}
	}
	if (a[n][n] != 0)
	{
		for (i = 1; i <= n - 1; i++)
		{
			a[i][n + 1] -= a[i][n] * a[n][n + 1] / a[n][n];
			a[i][n] = 0;
		}
		a[n][n + 1] = a[n][n + 1] / a[n][n];
		a[n][n] = 1;
		for (i = 1; i <= n; i++)
		{
			x[i] = 0;
			for (k = 1; k <= n; k++)
				x[i] += s[i][k] * a[k][n + 1];
		}
	}
	else
	{
		cout << "Sistemul nu poate fi rezolvat prin acest algoritm";
		h = 1;
	}
}
void main(void)
{
	cit_mat(a);
	h = 0;
	do
	{
		if (h == 0)
			cout << "Alege un vector nenul de componente y[i][0]:" << endl;
		else
			cout << "Alege un alt vector nenul de componente y[i][0]:" << endl;
		for (i = 1; i <= n; i++)
		{
			cout << "y[" << i << "][0]=";
			cin >> y[i][0];
		}

		for (i = 1; i <= n; i++)
			for (k = 1; k <= n; k++)
			{
				double s = 0;
				for (j = 1; j <= n; j++)
					s += a[k][j] * y[j][i - 1];
				y[k][i] = s;
			}
		for (i = 1; i <= n; i++)
			for (j = 0; j <= n - 1; j++)
				yy[i][j + 1] = y[i][j];
		det(n, yy, d);
		if (abs(d) <= 0.000000000000001)
		{
			d = 0;
			h = 1;
		}
	} while (d == 0);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			a[i][j] = y[i][j - 1];
		a[i][n + 1] = -y[i][n];
	}
	Alg28(a, x);
	cout << "Polinomul caracteristic este:" << endl;
	cout << "f(x)=x^" << n;
	for (i = 1; i <= n; i++)
		if (x[n - i + 1] >= 0)
			cout << "+" << x[n - i + 1] << "*x^" << n - i;
		else
			cout << x[n - i + 1] << "*x^" << n - i;
	cout << endl;
	cout << "Determinantul matricei A este: det(A)=" << pow(-1, n) * x[1];
	_getch();
}