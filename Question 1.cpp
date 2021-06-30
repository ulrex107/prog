#define _USE_MATH_DEFINES
#include <iostream>

using namespace std;

/**
* \brief ������� ������� �
* \param x �������� x
 * \param y �������� y
 * \param z �������� z
 * \return �
*/
double get_a(const double x, const double y, const double z);

/**
 * \brief ������� ��� ������� b
 * \param x �������� x
 * \param y �������� y
 * \param z �������� z
 * \return b
 */
double get_b(const double x, const double y, const double z);

/**
 * \brief ����� ����� � ���������
 * \return ���������� ����, � ������ ������
 */

int main()
{
    const auto x = 0.61;
    const auto y = 3.4;
    const auto z = 16.5;

    const auto a = get_a(x, y, z);
    const auto b = get_b(x, y, z);

    cout << "x = " << x << ", y =  " << y << ", z = " << z << "\n";
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
};

double get_a(const double x, const double y, const double z)
{
    return pow(x, 3) * pow(tan(pow(x + y, 2)), 2) + z / sqrt(x + y);
};

double get_b(const double x, const double y, const double z)
{
    return (y * pow(x, 2) - z) / (pow(M_E, z * x) - 1);
};