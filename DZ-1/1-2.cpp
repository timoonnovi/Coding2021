#include <iostream>
#include <iomanip>

#define C 29979245800

using namespace std;

int main() {
	int a;
	double b;
	setlocale(LC_ALL, "Russian");

	cout << "������� �� �� � ����.\n�������� �������:\n\t1 - �� -> ��\n\t2 - � -> �����\n\t3 - � -> �����\n";
	cin >> a;

	if (a == 1) {
		cout << "������� ��������: ";
		cin >> b;
		cout << 10 * b / C << " ��";
		return 0;
	}
	if (a == 2) {
		cout << "������� ��������: ";
		cin >> b;
		cout << b * 10 / C << " �����";
		return 0;
	}
	if (a == 3) {
		cout << "������� ��������: ";
		cin >> b;
		cout << b * C / 100000000 << " �����";
		return 0;
	}

	cout << "���������� �������� �� ����������.";

	return 0;
}