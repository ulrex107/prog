#include <iostream>
#include <string>

using namespace std;

/**
* \brief Перечисляемый тип, для выбора cпособа которым будут меняться значения переменных.
*/
enum class swap_type
{
	/**
	* \brief Неправильно сформированный выбор
	*/
	none,

	/**
	* \brief С использованием третьей переменной.
	*/
	extra_var,

	/**
	* \brief Без использования третьей переменной.
	*/
	classic
};

/**
* \brief Считывает выбор пользователя.
* \param message Сообщение для пользователя.
* \param out Произвольный поток вывода.
* \param in Произвольный поток ввода.
* \return Выбор пользователя.
*/
swap_type read_user_choice(const string& message = "", ostream& out = cout, istream& in = cin);

/**
* \brief Считывает значение переменной.
* \param Сообщение для пользователя
* \param out Произвольный поток вывода.
* \param in Произвольный поток ввода.
* \return Значение переменной
*/
int read_var_value(const string& message = "\n Enter the value of the variable: ", ostream& out = cout, istream& in = cin);


/**
 * \brief Точка вход в программу
 * \return Код ошибки, если 0 - успешное выполнение
 */
int main()
{
	const auto message = "Choose how to exchange variable values: "
		+ to_string(static_cast<int>(swap_type::extra_var)) + " - using an extra variable, "
		+ to_string(static_cast<int>(swap_type::classic)) + " - without using the third variable ";

	const auto swap = read_user_choice(message);

	switch (swap)
	{
	case swap_type::extra_var:
	{
		auto a = read_var_value();
		auto b = read_var_value();
		auto c = b;
		b = a;
		a = c;
		cout << "a = " << a << "b = " << b;
		break;
	}
	case swap_type::classic:
	{
		auto a = read_var_value();
		auto b = read_var_value();
		a += b;
		b = a - b;
		a -= b;
		cout << "a = " << a << "\nb = " << b;
		break;
	}
	default:
		cout << "Choose the correct way to replace the variable values.";
	};

	return 0;
};


swap_type read_user_choice(const string& message, ostream& out, istream& in)
{
	out << message;
	int input;
	in >> input;

	return static_cast<swap_type>(input);
};

int read_var_value(const string& message, ostream& out, istream& in)
{
	out << message;
	int input;
	in >> input;

	return input;
};

