#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream>

using namespace std;

float max1(float x, float y) {

	if (x >= y) {
		return(x);
	}
	else {
		return(y);
	}
}

void ecGrad2(float a, float b, float c) {

	float delta1 = b * b - 4 * a*c;


	if (delta1 > 0) {
		cout << (-b - sqrt(delta1)) / (2 * a) << "  ";

		cout << (-b + sqrt(delta1)) / (2 * a) << "  ";
	}
	else {
		if (delta1 == 0) {
			cout << (-b) / (2 * a) << "  ";
			cout << (-b) / (2 * a) << "  ";
		}
		else {
			if (delta1 < 0) {
				cout << (-b) / (2 * a) << "+i*" << sqrt(-delta1) / (2 * a) << "  ";
				cout << (-b) / (2 * a) << "-i*" << sqrt(-delta1) / (2 * a) << "  ";
			}
		}
	}

}

void ecGrad1(float a, float b) {


	cout << -b / a;


}

int main()
{

	int n; //gradul ecuatiei
	cout << "Introduceti gradul ecuatiei:" << endl;
	cin >> n;
	float a[50], b[50], c[50];
	float p, q, e, delta, P, Q;

	//adaugare elemente n vector(adica coeficientii ecuatiei)
	for (int i = 0; i <= n; i++) {
		cout << "Coeficient x^" << n-i << ":";
		cin >> a[i];
	}

	if (n >= 3) {
		cout << "p=";
		cin >> p;
		cout << "q=";
		cin >> q;
		cout << "e=";
		cin >> e;
	}

	cout << endl;

	while (n >= 3) {
		do {
			b[0] = a[0];
			b[1] = a[1] - p * b[0];
			for (int i = 2; i <= n; i++) {
				b[i] = a[i] - (p * b[i - 1]) - (q * b[i - 2]);
			}
			c[0] = b[0];
			c[1] = b[1] - p * c[0];
			for (int i = 2; i <= n - 1; i++) {
				c[i] = b[i] - (p * c[i - 1]) - (q * c[i - 2]);
			}
			delta = pow(c[n - 2], 2) - (c[n - 3] * c[n - 1]) + (c[n - 3] * b[n - 1]);
			P = -(b[n - 1] * c[n - 2]) + (b[n] * c[n - 3]);
			Q = -(b[n] * c[n - 2] )+( b[n - 1] * c[n - 1]) - pow(b[n - 1], 2);
			p = p - (P / delta);
			q = q - (Q / delta);


		} while (max1(abs(b[n - 1]), abs(b[n] + p * b[n - 1])) >= e);
		ecGrad2(1, p, q);

		n = n - 2;
		for (int i = 0; i <= n; i++) {
			a[i] = b[i];
		}
	}

	if (n == 2) {
		ecGrad2(a[0], a[1], a[2]);
	}
	else {
		ecGrad1(a[0], a[1]);
	}


	_getch();

	return 0;
}