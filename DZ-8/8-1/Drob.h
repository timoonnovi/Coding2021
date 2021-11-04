#ifndef DROB_H
#define DROB_H

#include <iostream>
#include <stdexcept>

class BadDenominator : public std::exception
{
private:
    std::string m_error;

public:
    BadDenominator(std::string error) : m_error(error) {}

    const char* what() const noexcept { return m_error.c_str(); }
};

class Drob
{
private:
    int m_numerator;
    int m_denominator;

    int gcd(int a, int b) const;

public:
    // ����������� �� ���������
    Drob(int numerator = 0, int denominator = 1) :
        m_numerator(numerator), m_denominator(denominator)
    {
        if (m_denominator == 0)
        {
            throw BadDenominator("Denominator cannot be zero.");
        }
    }

    // ���������� �����������
    Drob(const Drob&);

    // ����-�����
    friend std::ostream& operator<<(std::ostream& out, const Drob& d1);
    friend std::istream& operator>>(std::istream& istr, Drob& d);

    // �������� �������������� ���������
    friend Drob operator+(const Drob& d1, const Drob& d2);
    friend Drob operator-(const Drob& d1, const Drob& d2);
    friend Drob operator*(const Drob& d1, const Drob& d2);
    friend Drob operator/(const Drob& d1, const Drob& d2);

    // ������� �������������� ���������
    friend Drob& operator+=(Drob& d1, const Drob& d2);
    friend Drob& operator-=(Drob& d1, const Drob& d2);
    friend Drob& operator*=(Drob& d1, const Drob& d2);
    friend Drob& operator/=(Drob& d1, const Drob& d2);
    friend Drob& operator-(Drob& d1);

    // ��������� ���������
    friend bool operator==(const Drob& d1, const Drob& d2);
    friend bool operator!=(const Drob& d1, const Drob& d2);
    friend bool operator>(const Drob& d1, const Drob& d2);
    friend bool operator<(const Drob& d1, const Drob& d2);
    friend bool operator>=(const Drob& d1, const Drob& d2);
    friend bool operator<=(const Drob& d1, const Drob& d2);

    // ��������� ������������ (���������� � ������������)
    Drob& operator=(const Drob& d);
    Drob& operator()(Drob& d);

    // ��������� ���������� � ����������
    Drob& operator++();
    Drob& operator--();
    Drob operator++(int);
    Drob operator--(int);

    // ���������� � -1 �������
    Drob obr() const;

    // ����������
    Drob sokrat() const;

    // ����������� � double
    double Drob_to_double() const;

    int get_num() { return m_numerator; }
    int get_denum() { return m_denominator; }

};

#endif // DROB_H