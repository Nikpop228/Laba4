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

	Credit(Credit&& credit); // ����������� �����������

	Credit& operator = (Credit& credit); // ��������������� ��������� ������������ � ������������

	Credit& operator = (Credit&& credit); // ��������������� ��������� ������������ � �����������

	bool operator < (Credit& credit); // ��������������� ��������� ��������� ��� ������ ��������� sort

	//������ ��������� ����� ������:

	std::string get_name() { return name; }
	int get_sum() { return sum; }
	std::string get_currency() { return currency; }
	double get_deposit() { return deposit; }

	//������ ��������� �������� ����� ������:

	void set_name(std::string& name) { this->name = name; }
	void set_sum(int& sum) { this->sum = sum; }
	void set_currency(std::string& currency) { this->currency = currency; }
	void set_deposit(double& deposit) { this->deposit = deposit; }
};

std::istream& operator >> (std::istream& stream, Credit& credit); // ��������������� ��������� �� ������ ��� ������

std::ostream& operator << (std::ostream& stream, Credit& credit); // ��������������� ������� � ����� ��� ������

std::istream& operator >> (std::istream& stream, std::vector <Credit>& vec); // ��������������� ��������� �� ������ ��� ������� ���� Credit

std::ostream& operator << (std::ostream& stream, std::vector<Credit>& vec); // ��������������� ������� � ����� ��� ������� ���� Credit

std::ostream& operator << (std::ostream& stream, std::deque<Credit>& deq); // ��������������� ������� � ����� ��� ������� ���� Credit
