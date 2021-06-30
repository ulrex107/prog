#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/**
* \brief Вычисляет значение функции.
* \param x Значение аргумента функции.
* \param a Значение параметра.
* \return y Значение функции.
*/
double my_function(const double x, const double a = 2.5);

/**
* \brief Сравнивает значение аргумента функции с параметром.
* \param x Значение аргумента функции.
* \param a Значение параметра.
* \return True если меньше, False если больше.
*/
bool is_bigger(const double x, const double a = 2.5);

/**
* \brief Перечисляемый тип, 0 - параметр по умолчанию, 1 - новое значение параметра.
*/
enum class parametr_choice
{
	default_parametr,
	new_parametr
};

/**
* \brief Считывает выбор пользователя.
* \param message Сообщение для пользователя.
* \param out Произвольный поток вывода.
* \param in Произвольный поток ввода.
* \return Выбор пользователя.
*/
parametr_choice read_user_choice(const string& message = "", ostream& out = cout, istream& in = cin);

/**
* \brief Считывает значение переменной.
* \param message Сообщение для пользователя
* \param out Произвольный поток вывода.
* \param in Произвольный поток ввода.
* \return Значение переменной
*/
double get_arg(const string& message = "\n Enter the value of the variable: ", ostream& out = cout, istream& in = cin);


/**
 * \brief Точка вход в программу
 * \return Код ошибки, если 0 - успешное выполнение
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
		y = x * pow(sin(x), 2);	// Вычисление значения функции если х > a.
	else
		y = x * pow(cos(x), 2); // Вычисление значения функции если x <= a.
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
