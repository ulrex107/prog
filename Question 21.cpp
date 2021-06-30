#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/**
* \brief ��������� �������� �������.
* \param x �������� ��������� �������.
* \param a �������� ���������.
* \return y �������� �������.
*/
double my_function(const double x, const double a = 2.5);

/**
* \brief ���������� �������� ��������� ������� � ����������.
* \param x �������� ��������� �������.
* \param a �������� ���������.
* \return True ���� ������, False ���� ������.
*/
bool is_bigger(const double x, const double a = 2.5);

/**
* \brief ������������� ���, 0 - �������� �� ���������, 1 - ����� �������� ���������.
*/
enum class parametr_choice
{
	default_parametr,
	new_parametr
};

/**
* \brief ��������� ����� ������������.
* \param message ��������� ��� ������������.
* \param out ������������ ����� ������.
* \param in ������������ ����� �����.
* \return ����� ������������.
*/
parametr_choice read_user_choice(const string& message = "", ostream& out = cout, istream& in = cin);

/**
* \brief ��������� �������� ����������.
* \param message ��������� ��� ������������
* \param out ������������ ����� ������.
* \param in ������������ ����� �����.
* \return �������� ����������
*/
double get_arg(const string& message = "\n Enter the value of the variable: ", ostream& out = cout, istream& in = cin);


/**
 * \brief ����� ���� � ���������
 * \return ��� ������, ���� 0 - �������� ����������
 */
int main()
{
	const auto message = "Do you want to change constant value? "
		+ to_string(static_cast<int>(parametr_choice::default_parametr)) + " - using default constant (a = 2.5), "
		+ to_string(static_cast<int>(parametr_choice::new_parametr)) + " - change the constant value. ";
	
	const auto parametr = read_user_choice(message);
	
	switch (parametr)
	{
	case parametr_choice::default_parametr:
		{
			const auto x = get_arg();
			const auto y = my_function(x);
			cout << "Argument value: " << x << '\n' << "Function value: " << y;
			break;
		}
	case parametr_choice::new_parametr:
		{
			cout << "Please enter the new value of parametr: ";
			double a;
			cin >> a;
			const auto x = get_arg();
			const auto y = my_function(x, a);
			cout << "Argument value: " << x << '\n' << "Function value: " << y;
			break;
		}
	default:
		cout << "Please enter the correct value.";
	};

	return 0;
	
};


double my_function(const double x, const double a)
{
	double y;
	if (is_bigger(x, a))
		y = x * pow(sin(x), 2);	// ���������� �������� ������� ���� � > a.
	else
		y = x * pow(cos(x), 2); // ���������� �������� ������� ���� x <= a.
	return y;
};

bool is_bigger(const double x, const double a)
{
	return (x > a) ? true : false;
};

parametr_choice read_user_choice(const string& message, ostream& out, istream& in)
{
	out << message;
	int input;
	in >> input;
	return static_cast<parametr_choice>(input);
};

double get_arg(const string& message, ostream& out, istream& in)
{
	out << message;
	double input;
	in >> input;
	return input;
}
