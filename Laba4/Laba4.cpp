#include "Credit.h"
#include <fstream>
#include <algorithm>

int main(int argc, char* argv[])
{
	std::string filename_input = argv[1]; // файл с входными данными
	std::string filename_output = argv[2]; // файл с выходными данными

	std::ifstream fin(filename_input); // входной поток
	std::ofstream fout(filename_output); // выходной поток

	int n;
	fin >> n;
	fin.ignore(2, '\n');

	std::vector <Credit> vec(n);
	std::deque <Credit> deq(n);

	fin >> vec; // заполнение вектора
	fout << vec << std::endl; // вывод в файл исходного вектора

	std::sort(vec.begin(), vec.end()); // сортировка вектора

	fout << vec << std::endl; // вывод в файл отсортированного вектора

	std::copy(vec.begin(), vec.end(), deq.begin()); // копирование вектора в очередь

	fout << vec << std::endl; // проверка ничего ли не случилось с вектором после копирования

	fout << deq << std::endl; // вывод очереди в файл

	fin.close();
	fout.close();
}
