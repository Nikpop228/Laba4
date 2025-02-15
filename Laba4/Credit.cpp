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

Credit::Credit(const Credit& credit) // конструктор копирования
{
	name = credit.name;
	sum = credit.sum;
	currency = credit.currency;
	deposit = credit.deposit;
}

Credit::Credit(Credit&& credit) noexcept// конструктор перемещения
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

Credit& Credit::operator = (Credit&& credit) noexcept// переопределение опреатора присваивания с перемещеним
{
	name = credit.name;
	sum = credit.sum;
	currency = credit.currency;
	deposit = credit.deposit;

	return *this;
}

bool Credit::operator < (const Credit& credit) const // переопределения оператора сравнения для работы алгоритма sort
{
	if (name != credit.name || sum != credit.sum || currency != credit.currency || deposit != credit.deposit) 
	{ 
		if (deposit < credit.deposit) { return true; }
		else if (deposit == credit.deposit)
		{
			if (name < credit.name) { return true; }
			else if (name == credit.name)
			{
				if (currency < credit.currency) { return true; }
				else if (currency == credit.currency)
				{
					if (sum < credit.sum) { return true; }
					else return false;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

bool Credit::operator <= (const Credit& credit) const // переопределения оператора сравнения для работы алгоритма sort
{
	if (*this == credit) { return false; }
	else return deposit <= credit.deposit;
}

bool Credit::operator == (const Credit& credit) const// переопределение оператора сравнения == для работы контейнера set
{
	return (name == credit.name && sum == credit.sum && currency==credit.currency && deposit == credit.deposit);
}

std::istream& operator >> (std::istream& stream, Credit& credit) // переопределение вставки в поток
{
	getline(stream, credit.name);
	stream >> credit.sum;
	stream.ignore(2, '\n');
	getline(stream, credit.currency);
	stream >> credit.deposit;
	stream.ignore(2, '\n');

	return stream;
}

std::ostream& operator << (std::ostream& stream, const Credit& credit) // переопределение вsставки в поток
{
	stream << credit.name << '\t' << credit.sum << '\t' << credit.currency << '\t' << credit.deposit;
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

std::ostream& operator << (std::ostream& stream, const std::vector<Credit>& vec) // переопределение вставки в поток для вектора типа Credit
{
	for (auto& elem : vec)
	{
		stream << elem << std::endl;
	}
	return stream;
}

std::ostream& operator << (std::ostream& stream, const std::deque<Credit>& deq) // переопределение вставки в поток для вектора типа Credit
{
	for (auto& elem : deq)
	{
		stream << elem << std::endl;
	}
	return stream;
}

size_t CreditHasher::operator () (const Credit& credit) const // хеш функция для unset
{
	const size_t coef = 103141;
	return (coef * coef * coef * name_hash(credit.name) 
			+ coef * coef * sum_hash(credit.sum) 
			+ coef * currencu_hash(credit.currency) 
			+ deposit_hash(credit.deposit));
}
