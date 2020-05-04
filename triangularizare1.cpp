#include<iostream>
#include<math.h>
#include<conio.h>

using namespace std;

int main() {
	float a[10][10];
	int n, i, j;
	cout << "Numarul de linii si coloane este: ";
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}

	for (int k = 0; k < n-1; k++) {
		if (a[k][k] != 0) {
			for (i = k + 1; i < n; i++) {
				for (j = k + 1; j < n; j++) {
					a[i][j] = a[i][j] - ((a[i][k] * a[k][j]) / a[k][k]);
				}
				a[i][k] = 0;
			}
		}
		else {
			cout << "Matricea A nu poate fi triangularizata prin acest algoritm";
		}
	}
	cout<<"Matricea finala este:"
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j]<<" ";
		}
		cout << endl;
	}

	_getch();
	return 0;
}