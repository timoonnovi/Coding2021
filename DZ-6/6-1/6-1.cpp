﻿// 5-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SmartPtr.h"

int main()
{
    double tmp, tmpx;
    std::cout << "Enter double value:\n";
    std::cin >> tmp;
    double* ptr = &tmp;

    SmartPtr ptr1(tmp);
    SmartPtr ptr2(ptr);

    std::cout << "ptr  " << ptr << '\n';
    std::cout << "ptr1 " << ptr1 << '\n';
    std::cout << "ptr2 " << ptr2 << '\n';
    std::cout << "tmp " << tmp << '\n';
    std::cout << "Value1 " << *ptr1 << '\n';
    std::cout << "Value2 " << *ptr2 << '\n';
    
    SmartPtr ptr3(ptr1);

    std::cout << "ptr3 " << ptr3 << '\n';
    std::cout << "Value3 " << *ptr3 << '\n';
    std::cout << "ptr1 " << ptr1 << '\n';
    return 0;
}
