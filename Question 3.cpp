#include <iostream>

using namespace std;

const auto g = 9.81;

/**
* \brief ������������ ���� ��������.
* \param mass ����� �����
* \return ���� ��������.
*/
double get_pressure_power(double mass);

/**
* \brief ������������ ��������, ������������ �������� ����� �� �������� �������
* \param f - ���� ��������, s - �������, �� ������� ������������ ��������.
* \return ��������.
*/
double get_pressure(double f, double s);

/**
 * \brief ����� ����� � ���������
 * \return ���������� ����, � ������ ������
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