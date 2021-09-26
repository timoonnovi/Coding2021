#ifndef TIMO_H
#define TIMO_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

// ��������������� ��������� ������ ��� ������� ���� int
std::ostream& operator<<(std::ostream& ostr,
    const std::vector<int>& nums);

// ��������������� ��������� ����� ��� ������� ���� int
std::istream& operator>>(std::istream& istr, std::vector<int>& v);

#endif // !TIMO_H
