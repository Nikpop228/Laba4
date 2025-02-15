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

	bool operator == (const Credit& credit) const; // ��������������� ��������� ��������� == ��� ������ ���������� un_set

	bool operator < (const Credit& credit) const; // ��������������� ��������� ��������� ��� ������ ��������� sort

	bool operator <= (const Credit& credit) const; // ��������������� ��������� ��������� ��� ������ ��������� sort

	friend std::istream& operator >> (std::istream& stream, Credit& credit); // ��������������� ��������� �� ������ ��� ������

	friend std::ostream& operator << (std::ostream& stream, const Credit& credit); // ��������������� ������� � ����� ��� ������

	friend class CreditHasher;
};

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