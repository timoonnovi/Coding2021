#include <iostream>
#include <vector>
#include <type_traits>

template <typename T>
auto get_argument_and_do_something(T&& argument) { // ������������� ������, ��������� � lvalue, � rvalue
    do_something(std::forward<T>(argument)); // ���� lvalue -- ������ ��������,
                                             // ���� rvalue -- std::move
}

// �� ��������� ���������� �������� �� ��������
// �� ������ -- ������ ���� ��� ����������

// SFINAE -- substitution failure is not an error
// ������ ����������� ������� �� ��������

template <typename T, typename = std::enable_if_t<std::is_convertible_v<T, double>>>
auto multiply_by_three(T argument) {
    return argument * 3;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vector) {
    for(const auto& item : vector) {
        os << item << ' ';
    }
    return os;
}


int main() {
    std::vector<int> numbers;
    std::cout << numbers; // ��� ��� �� ���������� �������� ������, ������ ���
    // ����� ����� ������ � ���, ��� ���������� ������� �� ������� -- ������ �����������
    std::cout << multiply_by_three(5) << std::endl;
    std::cout << multiply_by_three("NIKI") << std::endl; // �� ��������, ��� ���������� �������
    // ��������� ������ �����������, � ������ � ������� ������� ��� -- �� ������� ��� ������
    // �� �����������
}