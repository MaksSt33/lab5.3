// lab5.3
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double z(const double x);
int main()
{
	double pp, pk, b ;
	int n;
	cout << "pp = "; cin >> pp;
	cout << "pk = "; cin >> pk;
	cout << "n = "; cin >> n;
	cout << fixed;
	cout << "----------------------------------" << endl;
	cout << "|" << setw(5) << "p" << "     |"
		<< setw(7) << "b" << "      |"
		<< setw(5) << " n " << "  |"
		<< endl;
	cout << "----------------------------------" << endl;
	double dp = (pk - pp) / n;
	double p = pp;
	while (p <= pk)
	{
		b = z(p*p) + 2*z(2*p + p*p) + 1 ;
		cout << "|" << setw(7) << setprecision(2) << p << "   |"
		 << setw(10) << setprecision(5) << b << "   |"
			<< setw(4) << n << "   |"
			<< endl;
		p += dp;
	}
	cout << "----------------------------------" << endl;

	return 0;
}
double z(const double x)
{
	if (abs(x) >= 1)
		return (cos(2*x) + 1) / (cos(x)+sin(x)*sin(x));
	else
	{
		double S = 0;
		int k = 0;
		double a = 2*x;
		S = a;
		do
		{
			k++;
			double R = (2 * pow(x,2)) / (2 * pow(x,2) + k);
			a *= R;
			S += a;
		} while (k < 6);

		return S;

	}
}