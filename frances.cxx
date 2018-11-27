#include <iostream>
#include "iomanip"
#include "math.h"
using namespace std;

double capital, tasa, periodo;

double cuota(double, double, double);
void calculo(void);

int main()
{
	cout << fixed << setprecision(2);

	cout << "Prestamo : ";
	cin >> capital;

	cout << "Tasa     : ";
	cin >> tasa;

	cout << "Periodo  : ";
	cin >> periodo;

	cout << cuota(capital, tasa, periodo) << endl
		 << endl;

	calculo();
}

double cuota(double capital, double tasa, double periodo)
{
	double cuota = capital * ((pow((1 + tasa), periodo)) * tasa) / ((pow((1 + tasa), periodo)) - 1);
	return cuota;
}

void calculo(void)
{
	double saldo = capital;
	double cuota = capital * ((pow((1 + tasa), periodo)) * tasa) / ((pow((1 + tasa), periodo)) - 1);
	double pura = cuota - (capital * tasa);
	
	cout << "Mes\t" << "  Cuota\t\t" << "  Capital\t" << "  Tasa\t\t" << "  Saldo \n\n";
	
	for (int i = 1; i <= periodo; i++)
	{
		cout << i << "\t";
		cout << "|  " << cuota;
		cout << "\t|  " << pura;
		cout << "\t|  " << saldo * tasa;
		cout << "\t|  " << saldo - pura << endl;

		saldo = saldo - pura;
		pura = cuota - (saldo * tasa);

		//saldo = saldo - pura;
	}
}
