#include "Credit.h"

Credit::Credit() // конструктор без параметров
{
	name = "No name";
	sum = 0;
	currency = "No";
	deposit = 0.0;
}

Credit::Credit(std::string name, int sum, std::string currency, double deposit) // конструктор со всеми параметрами
{
	this->name = name;
	this->sum = sum;
	this->currency = currency;
	this->deposit = deposit;
}

Credit::Credit(Credit& credit) // конструктор копирования
{
	name = credit.name;
	sum = credit.sum;
	currency = credit.currency;
	deposit = credit.deposit;
}

Credit::Credit(Credit&& credit) // конструктор перемещения
{
	name = credit.name;
	sum = credit.sum;
	currency = credit.currency;
	deposit = credit.deposit;
}

Credit& Credit::operator = (Credit& credit) // переопределение оператора присваивания с копированием
{
	name = credit.name;
	sum = credit.sum;
	currency = credit.currency;
	deposit = credit.deposit;
	return *this;
}

Credit& Credit::operator = (Credit&& credit) // переопределение опреатора присваивания с перемещеним
{
	name = credit.name;
	sum = credit.sum;
	currency = credit.currency;
	deposit = credit.deposit;

	return *this;
}

bool Credit::operator < (Credit& credit) // переопределения оператора сравнения для работы алгоритма sort
{
	return deposit < credit.deposit;
}

std::istream& operator >> (std::istream& stream, Credit& credit) // переопределение вставки в поток
{
	std::string name; // название кредита
	int sum; // сумма кредита
	std::string currency; // валюта
	double deposit; // процентная ставка

	// считывание из потока

	getline(stream, name);
	stream >> sum;
	stream.ignore(2, '\n');
	getline(stream, currency);
	stream >> deposit;
	stream.ignore(2, '\n');

	// присвоение значений объекту

	credit.set_name(name);
	credit.set_sum(sum);
	credit.set_currency(currency);
	credit.set_deposit(deposit);
	return stream;
}

std::ostream& operator << (std::ostream& stream, Credit& credit) // переопределение вставки в поток
{
	stream << credit.get_name() << '\t' << credit.get_sum() << '\t' << credit.get_currency() << '\t' << credit.get_deposit();
	return stream;
}

std::istream& operator >> (std::istream& stream, std::vector <Credit>& vec) // переопределения вставки в поток для вектора типа Credit
{
	for (auto& elem : vec)
	{
		stream >> elem;
	}
	return stream;
}

std::ostream& operator << (std::ostream& stream, std::vector<Credit>& vec) // переопределение вставки в поток для вектора типа Credit
{
	for (auto& elem : vec)
	{
		stream << elem << std::endl;
	}
	return stream;
}

std::ostream& operator << (std::ostream& stream, std::deque<Credit>& deq) // переопределение вставки в поток для вектора типа Credit
{
	for (auto& elem : deq)
	{
		stream << elem << std::endl;
	}
	return stream;
}