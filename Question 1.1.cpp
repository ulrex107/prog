#include <iostream>
#include <string>

using namespace std;

/**
* \brief ������������� ���, ��� ������ c������ ������� ����� �������� �������� ����������.
*/
enum class swap_type
{
	/**
	* \brief ����������� �������������� �����
	*/
	none,

	/**
	* \brief � �������������� ������� ����������.
	*/
	extra_var,

	/**
	* \brief ��� ������������� ������� ����������.
	*/
	classic
};

/**
* \brief ��������� ����� ������������.
* \param message ��������� ��� ������������.
* \param out ������������ ����� ������.
* \param in ������������ ����� �����.
* \return ����� ������������.
*/
swap_type read_user_choice(const string& message = "", ostream& out = cout, istream& in = cin);

/**
* \brief ��������� �������� ����������.
* \param ��������� ��� ������������
* \param out ������������ ����� ������.
* \param in ������������ ����� �����.
* \return �������� ����������
*/
int read_var_value(const string& message = "\n Enter the value of the variable: ", ostream& out = cout, istream& in = cin);


/**
 * \brief ����� ���� � ���������
 * \return ��� ������, ���� 0 - �������� ����������
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

