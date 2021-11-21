#include <iostream>
#include <vector>

// ����������� ������� -- ��������� � ���� ������������� ���������� ����������
// ����� ���������� �������
// ��������� ������ -- ��������� ��������� �������� ��������� � ��������� ������
// 1) ... OPERATOR args <=> ((arg1 OPERATOR arg2) OPERATOR arg3) OPERATOR arg4 � ��� �����
// 2) args OPERATOR ... <=> arg1 OPERATOR (arg2 OPERATOR (arg3 OPERATOR arg4))
// 3) special_arg OPERATOR ... OPERATOR args <=> ((special_arg OPERATOR arg1) OPERATOR arg2) OPERATOR arg3
// 4) args OPERATOR ... OPERATOR special_arg <=> arg1 OPERATOR (arg2 OPERATOR (arg3 OPERATOR special_arg))

// ����������� � ������������ �����������
// ����� ������������ ������������ -- ������������ �����������
// perimeter, area, info -- virtual
// ����� ������� -- ����������� �����������

// ����������� �-�
template<typename Figure>
auto perimeter(Figure& figure) {
    return figure.perimeter();
}

// ������ ���������� ������� print ����� ����������� ���������
// ������� -- ������� ��������� ��������
template<typename T>
void print_first_realization(T first_argument) {
    std::cout << first_argument << ' ';
}

// ������ ���������� ������� print ����� ����������� ���������
// �������� �������
template<typename T, typename... Types>
void print_first_realization(T first_argument, Types... arguments) {
    print_first_realization(first_argument);
    print_first_realization(arguments...);
}

// �������, ������������ ���������� ���������� � ������
template<typename... Types>
auto get_amount_of_arguments(Types... arguments) {
    return sizeof...(arguments);
}

// ������ ���������� print -- ����� if constexpr
template<typename T, typename... Types>
void print_second_realization(T first_argument, Types... arguments) {
    std::cout << first_argument << ' ';
    if constexpr(sizeof...(arguments) > 0) {
        print_second_realization(arguments...);
    }
}

// ������� ����� ���� ���������� ����� ��������� ������
template <typename... Types>
auto sum(Types... arguments) {
    auto result = (arguments + ...);
    return result;
}

// ������� ����������� ������� ����� ��������� ������
template <typename... Types>
auto divide(Types... arguments) {
//    return (... / arguments);
    return (arguments / ...);
}

// �����, ����������� ����������� ��� ������� ���������� print
template<typename T>
class SeparatorAdder {
public:
    explicit SeparatorAdder(T& argument) : argument(argument) {}

    friend std::ostream& operator<<(std::ostream& os, const SeparatorAdder& wrapper) {
        return os << wrapper.argument << ' ';
    }

private:
    T& argument;
};

// ������ ���������� ������� print ����� ��������� ������
template<typename... Types>
void print(Types... arguments) {
    (std::cout << ... << SeparatorAdder(arguments));
}

// ������� ��������� i-�� ���������
template <size_t needed_index, typename T, typename... Types>
auto get(T first_argument, Types... arguments) {
    if constexpr(needed_index == 0) {
        return first_argument;
    } else {
        return get<needed_index - 1>(arguments...);
    }
}

// ����������� ��������� ������� ������ �������
template <typename Element>
std::ostream& operator<<(std::ostream& ostr, const std::vector<Element>& elements) {
    for(const auto& item: elements) {
        ostr << item << ' ';
    }
    return ostr;
}

// CRTP -- curiosly recurring template pattern
// ����������, ����������� ������������, �� ��� ��� �������

// ������� ����� -- � �������� ������� ��������� �����������
template <typename DerivedClass>
class Base {
public:
    auto virtual_function_analog() {
        // ����� ������� ������������ ������ � �������
        // ����� this � ��������� �� ����������� �����

        static_cast<DerivedClass*>(this)->virtual_function_analog();
    }
};

// ����������� ����� -- ��������� ���� ��� �������� �������
// �������� ��� ������������ �� ����

class Derived : public Base<Derived> {
public:
    auto virtual_function_analog() {
        std::cout << "Hello from derived!" << std::endl;
    }
};

int main() {
//    print_first_realization(1, true, "Niki", 8.85);
//    std::cout << get_amount_of_arguments(1, true, "Niki", 8.85) << std::endl;
//    print_second_realization(1, 5.6, "MIPT");
//    std::cout << sum(1, 2, 3, 4, 5);
//    std::cout << std::endl;
//    std::cout << divide(6, 3, 2);
//    print(5, "Third Print!", 322);
//    std::cout << get<2>(1, 2, 3, 4, 5);

//    std::vector<int> numbers{1, 3, 5, 42};
//    std::cout << numbers;

    Derived derived;
    Base<Derived>* base_derived_ptr = &derived;
    base_derived_ptr->virtual_function_analog();
    return 0;

}