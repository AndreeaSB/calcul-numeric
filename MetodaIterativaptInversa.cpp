#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <iostream>



using namespace std;

int main()
{
	double a[10][10], u[10], v[10], s1, s2;
	int i, j, k, n;


	cout << "n=";
	cin >> n;
	cout << "Matricea A:" << endl;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
	a[1][1] = 1 / a[1][1];
	for (k = 1; k <= n - 1; k++)
	{
		for (i = 1; i <= k; i++)
		{
			u[i] = a[i][k + 1];
			v[i] = a[k + 1][i];
		}


		s1 = 0;
		for (i = 1; i <= k; i++)
		{
			s2 = 0;
			for (j = 1; j <= k; j++) {
				s2 += a[i][j] * u[j];
			}
			s1 += v[i] * s2;
		}
		a[k + 1][k + 1] = 1 / (a[k + 1][k + 1] - s1);
		for (i = 1; i <= k; i++)
		{
			s1 = 0;
			for (j = 1; j <= k; j++)
				s1 += a[i][j] * u[j];
			a[i][k + 1] = -a[k + 1][k + 1] * s1;
		}
		for (j = 1; j <= k; j++)
		{
			s1 = 0;
			for (i = 1; i <= k; i++)
				s1 += v[i] * a[i][j];
			a[k + 1][j] = -a[k + 1][k + 1] * s1;
		}
		for (i = 1; i <= k; i++)
			for (j = 1; j <= k; j++)
				a[i][j] +=(a[i][k + 1] * a[k + 1][j])/ a[k + 1][k + 1];

		
	}
	cout << "Inversa matricei A este:" << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			cout << a[i][j] << "    ";
		cout << endl;
	}
	_getch();
	return 0;
}