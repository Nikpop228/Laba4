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

	Credit(Credit& credit); // ����������� �����������

	Credit(Credit&& credit) noexcept; // ����������� �����������

	Credit& operator = (Credit& credit); // ��������������� ��������� ������������ � ������������

	Credit& operator = (Credit&& credit) noexcept; // ��������������� ��������� ������������ � �����������

	bool operator < (const Credit& credit); // ��������������� ��������� ��������� ��� ������ ��������� sort

	bool operator == (const Credit& credit); // ��������������� ��������� ��������� == ��� ������ ���������� set

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

std::istream& operator >> (std::istream& stream, const Credit& credit); // ��������������� ��������� �� ������ ��� ������

std::ostream& operator << (std::ostream& stream, const Credit& credit); // ��������������� ������� � ����� ��� ������

std::istream& operator >> (std::istream& stream, const std::vector <Credit>& vec); // ��������������� ��������� �� ������ ��� ������� ���� Credit

std::ostream& operator << (std::ostream& stream, const std::vector<Credit>& vec); // ��������������� ������� � ����� ��� ������� ���� Credit

std::ostream& operator << (std::ostream& stream, const std::deque<Credit>& deq); // ��������������� ������� � ����� ��� ������� ���� Credit
