#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <deque>

class Credit
{
	std::string name; // �������� �������
	int sum; // ����� �������
	std::string currency; // ������
	double deposit; // ���������� ������

public: 
	Credit(); // ����������� ��� ����������

	Credit(std::string name, int sum, std::string currency, double deposit); // ����������� �� ����� �����������

	Credit(const Credit& credit); // ����������� �����������

	Credit(Credit&& credit) noexcept; // ����������� �����������

	Credit& operator = (Credit& credit); // ��������������� ��������� ������������ � ������������

	Credit& operator = (Credit&& credit) noexcept; // ��������������� ��������� ������������ � �����������

	bool operator < (const Credit& credit) const; // ��������������� ��������� ��������� ��� ������ ��������� sort

	bool operator == (const Credit& credit) const; // ��������������� ��������� ��������� == ��� ������ ���������� set

	//������ ��������� ����� ������:

	std::string get_name() const { return name; }
	int get_sum() const { return sum; }
	std::string get_currency() const{ return currency; }
	double get_deposit() const { return deposit; }

	//������ ��������� �������� ����� ������:

	void set_name(std::string& name) { this->name = name; }
	void set_sum(int& sum) { this->sum = sum; }
	void set_currency(std::string& currency) { this->currency = currency; }
	void set_deposit(double& deposit) { this->deposit = deposit; }
};

//bool operator < (const Credit& credit_1, const Credit& credit_2) const; // ��������������� ��������� ��������� ����� �� ��� ��������� ��� ����������� �������

std::istream& operator >> (std::istream& stream, Credit& credit); // ��������������� ��������� �� ������ ��� ������

std::ostream& operator << (std::ostream& stream, const Credit& credit); // ��������������� ������� � ����� ��� ������

std::istream& operator >> (std::istream& stream, std::vector <Credit>& vec); // ��������������� ��������� �� ������ ��� ������� ���� Credit

std::ostream& operator << (std::ostream& stream, const std::vector<Credit>& vec); // ��������������� ������� � ����� ��� ������� ���� Credit

std::ostream& operator << (std::ostream& stream, const std::deque<Credit>& deq); // ��������������� ������� � ����� ��� ������� ���� Credit


class CreditHasher
{
public:
	std::hash <std::string> name_hash;
	std::hash <int> sum_hash;
	std::hash <std::string> currencu_hash;
	std::hash <double> deposit_hash;

	size_t operator () (const Credit& credit) const;
};