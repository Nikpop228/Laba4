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

bool Credit::operator < (const Credit& credit) const// переопределения оператора сравнения для работы алгоритма sort
{
	return deposit < credit.deposit;
}

//bool operator < (const Credit& credit_1, const Credit& credit_2) // переопределение оператора сравнения чтобы он мог принимать два константных объекта
//{
//	int deposit_1 = credit_1.get_deposit();
//	int deposit_2 = credit_2.get_deposit();
//
//	return deposit_1 < deposit_2;
//}


bool Credit::operator == (const Credit& credit) const// переопределение оператора сравнения == для работы контейнера set
{
	return deposit == credit.deposit;
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

std::ostream& operator << (std::ostream& stream, const Credit& credit) // переопределение вставки в поток
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

size_t CreditHasher::operator () (const Credit& credit) const
{
	const size_t coef = 103141;
	return (coef * coef * coef * name_hash(credit.get_name()) 
			+ coef * coef * sum_hash(credit.get_sum()) 
			+ coef * currencu_hash(credit.get_currency()) 
			+ deposit_hash(credit.get_deposit()));
}
