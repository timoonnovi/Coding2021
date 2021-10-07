#include <iostream>
#include <vector>
#include "Vector.h"

int main()
{
	Vector v;

	setlocale(LC_ALL, "Russian");

	std::cout << "������� ������ v (����������� � ����������):\n";
	std::cin >> v;
	std::cout << '\n';
	std::cout << "������ ������� v: ";
	std::cout << v.abs() << "\n\n";
	std::cout << "���������� ������ v:\n";
	std::cout << -v << '\n';

	int a;

	std::cout << "������� �����:\n";
	std::cin >> a;
	std::cout << "\nv * a =\n" << v * a << '\n';
	std::cout << "������� ������ ������ u:\n";

	Vector u;

	std::cin >> u;
	std::cout << "v + u =\n" << v + u << '\n';
	std::cout << "v - u =\n" << v - u << '\n';
	std::cout << "��������� ������������ (v, u) = " << scalar(v, u) << '\n';

	return 0;
}
