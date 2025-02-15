#include "Credit.h"
#include <fstream>
#include <algorithm>
#include <unordered_set>
#include <set>

int main(int argc, char* argv[])
{
	std::string filename_input = argv[1]; // файл с входными данными
	std::string filename_output = argv[2]; // файл с выходными данными

	std::ifstream fin(filename_input); // входной поток
	std::ofstream fout(filename_output); // выходной поток

	// узнаем число элементов

	int n;
	fin >> n;
	fin.ignore(2, '\n');

	// заполнение и вывод контейнера set

	std::set <Credit> set;
	Credit credit;
	for (int i = 0; i < n; i++)
	{
		fin >> credit;
		set.insert(credit);
	}

	for (auto& elem : set)
	{
		fout << elem << std::endl;
	}

	fout << std::endl;

	// установка курсора в файле после переменной с количеством элементов

	fin.clear();
	fin.seekg(3);

	// заполнение и вывод контейнера unoredered_set

	std::unordered_set <Credit, CreditHasher> un_set;
	for (int i = 0; i < n; i++)
	{
		fin >> credit;
		un_set.insert(credit);
	}

	for (auto& elem : un_set)
	{
		fout << elem << std::endl;
	}

	fin.close();
	fout.close();
}
