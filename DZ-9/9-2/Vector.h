#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <iostream>

// ��� ������ �� �������� �������. 
// ����� 2 ���� � ���������� ���������� ������� � ����������� ������������.
template<typename T>
class Vector
{
private:
	std::vector<T> components;
	unsigned int dim;

public:
	// ������� ������� ������ �������.
	double abs();

	// ����� �������. 
	// ������� �����������, ����� ����������.
	friend std::ostream& operator<<(std::ostream& ostr,
		const Vector<T>& vec);

	// ���� �������.
	// ������� �����������, ����� ����������.
	friend std::istream& operator>>(std::istream& istr, Vector<T>& v);

	// ��������� ������� �� �����.
	friend Vector operator*(const Vector<T>& v, const T& num);

	// ��������� ������� �� �����.
	friend Vector& operator*=(Vector<T>& v, const T& num);

	// ��������� ����� �� ������.
	friend Vector operator*(const T& num, const Vector<T>& v);

	// �������� ��������.
	friend Vector operator+(const Vector<T>& v1, const Vector<T>& v2);

	// ���� �������� ��������.
	friend Vector& operator+=(Vector<T>& v1, const Vector<T>& v2);

	// ��������� ��������.
	friend Vector operator-(const Vector<T>& v1, const Vector<T>& v2);

	// ���� ��������� ��������.
	friend Vector& operator-=(Vector<T>& v1, const Vector<T>& v2);

	// ��������� �������. � ���������. �� ����� �������.
	friend Vector& operator-(Vector<T>& v);

	// ������� ���������� ������������ ��������.
	friend T scalar(const Vector<T>& v1, const Vector<T>& v2);
};

#endif // VECTOR_H