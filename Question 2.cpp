#include <iostream>
#include <cmath>

using namespace std;

/**
* \brief ������������ ���������� ����� ����� ������� �� ������������ ���������
* \brief �� ������� ab = sqrt ((x(b) - x(a))^2 + (y(b) - y(a))^2)
* \params x_a - ���������� � ����� �.
* \params y_a - ���������� � ����� �.
* \params x_b - ���������� � ����� �.
* \params y_x - ���������� � ����� �.
* \return ���������� ����� ������� � � �
*/
double calculate_length(const double x_a, const double y_a, const double x_b, const double y_b);

/**
* \brief ������ ������������ ������ �������� ���������� �����.
* \return ���������� �����.
*/
double get_dot_coordinate();

/**
 * \brief ����� ����� � ���������
 * \return ���������� ����, � ������ ������
 */
int main()
{
	const auto x_a = get_dot_coordinate();
	const auto y_a = get_dot_coordinate();
	const auto x_b = get_dot_coordinate();
	const auto y_b = get_dot_coordinate();

	cout << "Length between 2 points: " << calculate_length(x_a, y_a, x_b, y_b) << endl;
	return 0;
};

double calculate_length(const double x_a, const double y_a, const double x_b, const double y_b)
{
	return sqrt(pow(x_b - x_a, 2) + pow(y_b - y_a, 2));
};

double get_dot_coordinate()
{
	cout << "Enter dot coordinate: ";
	double coordinate;
	cin >> coordinate;

	return coordinate;
}