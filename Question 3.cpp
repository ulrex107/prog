#include <iostream>

using namespace std;

const auto g = 9.81;

/**
* \brief Рассчитывает силу давления.
* \param mass масса плиты
* \return Силу давлнеия.
*/
double get_pressure_power(double mass);

/**
* \brief Рассчитывает давление, производимое заданной силой на заданную площадь
* \param f - сила давления, s - площадь, на которую производится давление.
* \return Давление.
*/
double get_pressure(double f, double s);

/**
 * \brief Точка входа в программу
 * \return Возвращает нуль, в случае успеха
 */
int main()
{
	cout << "Enter plate weight: ";
	double mass;
	cin >> mass;

	cout << "Enter bearing area: ";
	double area;
	cin >> area;

	cout << "Pressure is: " << get_pressure(get_pressure_power(mass), area);
	return 0;
};

double get_pressure_power(double mass)
{
	return mass * g;
};

double get_pressure(double f, double s)
{
	return f / s;
};