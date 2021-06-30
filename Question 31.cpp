#define _USE_MATH_DEFINES
#include <cmath>
#include <limits>
#include <string>
#include <iostream>

using namespace std;

/**
* \brief ������ ������������ ������ �������� ���������� �����.
* \param message ��������� ��� ������������
* \param out ������������ ����� ������.
* \param in ������������ ����� �����.
* \return ���������� �����.
*/
double get_dot_coordinate(const string& message = "\n Enter the value of the variable: ", ostream& out = cout, istream& in = cin);

/**
* \brief ���������, ����� �� ����� �� ���������.
* \param x_a ���������� � ����� �
* \param y_a ���������� � ����� �
* \param x_b ���������� � ����� B
* \param y_b ���������� � ����� B
* \param x_c ���������� � ����� C
* \param y_c ���������� � ����� �
* \return True ���� ����� ����� �� ����� ������, False ���� �� �����.
*/
bool is_points_on_line(const double x_a, const double y_a, const double x_b, const double y_b, const double x_c, const double y_c);

/**
* \brief ������� ���� ����� �� � ��.
* \param x_a ���������� � ����� �
* \param y_a ���������� � ����� �
* \param x_b ���������� � ����� B
* \param y_b ���������� � ����� B
* \param x_c ���������� � ����� C
* \param y_c ���������� � ����� �
* \return ���� � ��������.
*/
double angle_B(const double x_a, const double y_a, const double x_b, const double y_b, const double x_c, const double y_c);

/**
* \brief ��������� ����� ������� ��
* \param x_a ���������� � ����� �
* \param y_a ���������� � ����� �
* \param x_b ���������� � ����� B
* \param y_b ���������� � ����� B
* \return ����� �������
*/
double line_length(const double x_a, const double y_a, const double x_b, const double y_b);

/**
* \brief ��������� ��������� ������������ �������� �� � ��
* \param x_a ���������� � ����� �
* \param y_a ���������� � ����� �
* \param x_b ���������� � ����� B
* \param y_b ���������� � ����� B
* \param x_c ���������� � ����� C
* \param y_c ���������� � ����� �
* \return ��������� ������������
*/
double scalar_prod(const double x_a, const double y_a, const double x_b, const double y_b, const double x_c, const double y_c);

/**
* \brief ��������� �� ���� ���� � �������� � ���������� � ��������.
* \param angle - ���� � ��������.
* \return ���� � ��������.
*/
double in_degrees(double angle);

/**
 * \brief ����� ���� � ���������
 * \return ��� ������, ���� 0 - �������� ����������
 */
int main()
{
	const string message = "Please enter a dot coordinate: ";
	const auto x_a = get_dot_coordinate(message);
	const auto y_a = get_dot_coordinate(message);
	const auto x_b = get_dot_coordinate(message);
	const auto y_b = get_dot_coordinate(message);
	const auto x_c = get_dot_coordinate(message);
	const auto y_c = get_dot_coordinate(message);
	if (is_points_on_line(x_a, y_a, x_b, y_b, x_c, y_c))
	{
		cout << "Points on one line. \n";
	}
	else
		cout << "Angle between AB and BC is " << angle_B(x_a, y_a, x_b, y_b, x_c, y_c);

	return 0;
};


double angle_B(double x_a, double y_a, double x_b, double y_b, double x_c, double y_c)
{
	const auto angle = acos(scalar_prod(x_a, y_a, x_b, y_b, x_c, y_c) / (line_length(x_a, y_a, x_b, y_b) * line_length(x_b, y_b, x_c, y_c)));

	return in_degrees(angle);
};

double in_degrees(const double angle)
{
	return angle * 180 / M_PI;
};

double line_length(double x_a, double y_a, double x_b, double y_b)
{
	return sqrt(pow(x_b - x_a, 2) + pow(y_b - y_a, 2));
};

double scalar_prod(double x_a, double y_a, double x_b, double y_b, double x_c, double y_c)
{
	const auto dx_a = x_a - x_b;	// ���������� � ������� �
	const auto dx_b = x_c - x_b;	// ���������� � ������� �
	const auto dy_a = y_a - y_b;	// ���������� � ������� �
	const auto dy_b = y_c - y_b;	// ���������� � ������� �

	return dx_a * dx_b + dy_a * dy_b;
}

bool is_points_on_line(double x_a, double y_a, double x_b, double y_b, double x_c, double y_c)
{ 
	return (((int)angle_B(x_a, y_a, x_b, y_b, x_c, y_c) % 180) == 0) ? true : false;
	// ������ ���� ��������� �������� �� ���� ����� ������� ������� 180. ���� �� - ��� ����� �� ����� ������.
};

double get_dot_coordinate(const string& message, ostream& out, istream& in)
{
	out << message;
	double coordinate;
	in >> coordinate;

	return coordinate;
}