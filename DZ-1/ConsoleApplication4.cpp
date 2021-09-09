#include <iostream>>
#include <cmath>

using namespace std;

int main() {
	double a, b, c;

	setlocale(LC_ALL, "Russian");

	cout << "���������� ��������� ����� ��� ��^2 + bx + c = 0" << endl;
	cout << "������� ����������� � : ";
	cin >> a;
	cout << "������� ����������� b: ";
	cin >> b;
	cout << "������� ����������� c: ";
	cin >> c;

	cout << '\n';

	if (a == 0)
	{
		if ((b == 0) && (c != 0))
		{
			cout << "��� �������";
			return 0;
		}
		if (b == 0)
		{
			cout << "������������� �������, � = ����� ������������ �����";
			return 0;
		}
		cout << "��������� �������� � ����� ���� �������: � = ";
		cout << -c / b;
		return 0;
	}

	double D = b * b - (4 * a * c);

	if (D < 0) cout << "��������� �� ����� ������� � �������������� ������";
	else {
		if (D == 0) {
			cout << "��������� ����� ���� �������: � = ";
			cout << -b / (2 * a);
		}
		else {
			cout << "��������� ����� ��� �������: �1 = ";
			cout << (-b + pow(D, 0.5)) / (2 * a);
			cout << ", �2 = ";
			cout << (-b - pow(D, 0.5)) / (2 * a);
		}
	}

	return 0;
}