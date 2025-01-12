﻿// 6-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Drob.h"

int main()
{
    Drob d1, d2;
    std::cin >> d1 >> d2;
    d1 = d1.sokrat();
    std::cout << "Divided fraction 1: " << d1 << '\n';
    std::cout << "d1 + d2: " << d1 + d2 << '\n';
    std::cout << "d1 - d2: " << d1 - d2 << '\n';
    std::cout << "d1 * d2: " << d1 * d2 << '\n';
    std::cout << "d1 / d2: " << d1 / d2 << '\n';
    d1 += d2;
    std::cout << "d1 + d2: " << d1 << '\n';

    std::cout << "d1: " << d1 << " d2: " << d2 << '\n';
    std::cout << "d1 == d2 ? " << (d1 == d2) << '\n';
    std::cout << "d1 > d2 ? " << (d1 > d2) << '\n';
    std::cout << "d1 < d2 ? " << (d1 < d2) << '\n';

    std::cout << "d1: " << d1 << " d2: " << d2 << '\n';
    d1 = d2;
    std::cout << "d1 = d2\n";
    std::cout << "d1: " << d1 << " d2: " << d2 << '\n';
    d2 = Drob(6, 13);
    std::cout << "d2 = 6/13\n";
    std::cout << "d1: " << d1 << " d2: " << d2 << '\n';
    d1++;
    std::cout << "d1++\n";
    std::cout << "d1: " << d1 << " d2: " << d2 << '\n';
    std::cout << "d2(d1); d1++\n";
    d2(d1);
    std::cout << "d1: " << d1 << " d2: " << d2 << '\n';
    d1++;
    std::cout << "d1: " << d1 << " d2: " << d2 << '\n';

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
