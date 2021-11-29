#include <iostream>
#include <cmath>

// ���� ����� ���������, ��������� �� ����� ����������, ������� ����� ��������� �� ����� ����������.
constexpr auto compute_coefficient(double e, double m_e, double h, double c) {
    return e * h / m_e / c;
}

auto compute_answer(double coefficient, double x) {
    return coefficient * x;
}

// constexpr -- constant expression
// ����� ���� ������� � ����������

// ��������, ��� �� constexpr-���������� ������������� ��������� �����������
// constexpr-������� �� ����������� ����������� �� ����� ����������

// ����������� �� constexpr-���������� � �������
// ����������:
// 1. ���������� ����� ��������� ���
// 2. ���������� �������� ����������
// 3. ���������� �������� �������� � constexpr-������������� ��� ��� ������������; ����� � ��������
// ����� ������ ��������� ����; ����� ���������� �� ���������.
// 4. ���������� �������� ����������� ��������.

// �������:
// 1. �� ����� ������������ �������
// 2. �� ����� goto-���������
// 3. ���������� ������ ���� ������ ������ constexpr-������� � ���������

// ����� ����� � �������� ����� �������� ��� ���:
// https://habr.com/ru/post/228181/
// ��������! ��� ������� � ��� C++11, � ��� C++14, ����������� ������ �������. ��� C++11 ����������� ������.

constexpr auto factorial(unsigned n) {
    unsigned result = 1;
    for(auto i = 1u; i <= n; i++) {
        result *= i;
    }
    return result;
}


int main() {
    constexpr double e = 1.6e-19;
    constexpr double m_e = 9.1e-31;
    constexpr double h = 6.63e-34;
    constexpr double c = 3e8;
    // ����������� ����������� �� ����� ����������
    constexpr auto coefficient = compute_coefficient(e, m_e, h, c); // �������� ������, ���
                                                                    // ��������� constexpr
    // ����� ��� ������� ����������, ���� ����� constexpr
    double x;
    std::cin >> x;
    std::cout << compute_answer(coefficient, x) << std::endl;

    // ����������� �� ����� ���������� -- ����� ��������� constexpr-���������� ���� �� ������
    constexpr auto result = factorial(5);
    std::cout << result;
}