#include <iostream>
#include <cmath>

using namespace std;

/**
* \brief Рассчитывает расстояние между двумя точками на координатной плоскости
* \brief по формуле ab = sqrt ((x(b) - x(a))^2 + (y(b) - y(a))^2)
* \params x_a - Координата х точки А.
* \params y_a - Координата у точки А.
* \params x_b - Координата х точки Б.
* \params y_x - Координата у точки Б.
* \return Расстояние между точками А и Б
*/
double calculate_length(const double x_a, const double y_a, const double x_b, const double y_b);

/**
* \brief Просит пользователя ввести значение координаты точки.
* \return Координату точки.
*/
double get_dot_coordinate();

/**
 * \brief Точка входа в программу
 * \return Возвращает нуль, в случае успеха
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