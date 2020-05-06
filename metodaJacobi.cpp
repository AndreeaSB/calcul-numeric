#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <iostream>


using namespace std;

int main()
{
	double q, s, eps, max, a[10][10], b[10], x[10], y[10];
	int i, j, k, n, m;
	cout << "Ordinul sistemului n=";
	cin >> n;
	cout << "Sistemul:" << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
		cout << "b[" << i << "]=";
		cin >> b[i];
	}
	cout << "eps=";
	cin >> eps;
	cout << "Aproximarea initiala a solutiei:" << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "x[" << i << "]=";
		cin >> x[i];
	}

	s = 0;
	for (j = 1; j <= n; j++)
		if (j != 1)
			s += abs(a[1][j]);
	q = s / abs(a[1][1]);
	for (i = 2; i <= n; i++)
	{
		s = 0;
		for (j = 1; j <= n; j++)
			if (i != j)
				s += abs(a[i][j]);
		max = s / abs(a[i][i]);
		if (max > q)
			q = max;
	}
	if (q < 1)
	{
		m = 1;
		for (i = 1; i <= n; i++)
		{
			s = 0;
			for (j = 1; j <= n; j++)
				if (j != i)
					s += a[i][j] * x[j];
			y[i] = (b[i] - s) / a[i][i];
		}
		max = abs(x[1] - y[1]);
		for (i = 2; i <= n; i++)
			if (max < abs(x[i] - y[i]))
				max = abs(x[i] - y[i]);
		k = 1;
		while (pow(q, k) * max / (1 - q) > eps)
			k++;
		for (m = 2; m <= k; m++)
		{
			for (i = 1; i <= n; i++)
				x[i] = y[i];
			for (i = 1; i <= n; i++)
			{
				s = 0;
				for (j = 1; j <= n; j++)
					if (j != i)
						s += a[i][j] * y[j];
				y[i] = (b[i] - s) / a[i][i];
			}
		}
	}
	else
	{
		cout << "Nu este asigurata convergenta algoritmului.";
		_getch();
		return 0;
	}
	cout << "Ultima aproximatie calculata este:";
	for (i = 1; i <= n; i++)
		cout << "x[" << i << "]=" << y[i] << endl;
	cout << "Numarul de iteratii efectuate este: " << k;
	_getch();
	return 0;
}