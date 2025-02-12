#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <deque>

class Credit
{
	std::string name; // название кредита
	int sum; // сумма кредита
	std::string currency; // валюта
	double deposit; // процентная ставка

public: 
	Credit(); // конструктор без параметров

	Credit(std::string name, int sum, std::string currency, double deposit); // конструктор со всеми параметрами

	Credit(const Credit& credit); // конструктор копирования

	Credit(Credit&& credit) noexcept; // конструктор перемещения

	Credit& operator = (Credit& credit); // переопределение оператора присваивания с копированием

	Credit& operator = (Credit&& credit) noexcept; // переопределение опреатора присваивания с перемещеним

	bool operator < (const Credit& credit) const; // переопределения оператора сравнения для работы алгоритма sort

	bool operator == (const Credit& credit) const; // переопределение оператора сравнения == для работы контейнера set

	//методы получения полей класса:

	std::string get_name() const { return name; }
	int get_sum() const { return sum; }
	std::string get_currency() const{ return currency; }
	double get_deposit() const { return deposit; }

	//методы установки значений полей класса:

	void set_name(std::string& name) { this->name = name; }
	void set_sum(int& sum) { this->sum = sum; }
	void set_currency(std::string& currency) { this->currency = currency; }
	void set_deposit(double& deposit) { this->deposit = deposit; }
};

//bool operator < (const Credit& credit_1, const Credit& credit_2) const; // переопределение оператора сравнения чтобы он мог принимать два константных объекта

std::istream& operator >> (std::istream& stream, Credit& credit); // переопределение получения из потока для класса

std::ostream& operator << (std::ostream& stream, const Credit& credit); // переопределение вставки в поток для класса

std::istream& operator >> (std::istream& stream, std::vector <Credit>& vec); // переопределения получения из потока для вектора типа Credit

std::ostream& operator << (std::ostream& stream, const std::vector<Credit>& vec); // переопределение вставки в поток для вектора типа Credit

std::ostream& operator << (std::ostream& stream, const std::deque<Credit>& deq); // переопределение вставки в поток для очереди типа Credit


class CreditHasher
{
public:
	std::hash <std::string> name_hash;
	std::hash <int> sum_hash;
	std::hash <std::string> currencu_hash;
	std::hash <double> deposit_hash;

	size_t operator () (const Credit& credit) const;
};