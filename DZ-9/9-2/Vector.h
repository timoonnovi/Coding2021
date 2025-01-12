#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <iostream>
#include <cmath>

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
	double abs()
	{
		double tmp = 0;
		for (auto item : components)
		{
			tmp += pow(item, 2);
		}

		tmp = pow(tmp, 0.5);

		return tmp;
	}

	// ����� �������. 
// ������� �����������, ����� ����������.
	friend std::ostream& operator<<(std::ostream& ostr,
		const Vector<T>& vec)
	{
		setlocale(LC_ALL, "Russian");
		ostr << "����������� �������: " << vec.dim << '\n';
		ostr << "���������� �������:  ";

		for (auto i = 0u; i < vec.components.size(); i++) {
			ostr << vec.components[i] << ' ';
		}
		ostr << '\n';
		return ostr;
	}

	// ���� �������.
// ������� �����������, ����� ����������.
	friend std::istream& operator>>(std::istream& istr, Vector<T>& v)
	{
		setlocale(LC_ALL, "Russian");
		std::cout << "������� ����������� �������: ";
		istr >> v.dim;
		std::cout << "������� ���������� �������:  ";

		for (unsigned int i = 0u; i < v.dim; i++)
		{
			T tmp;
			istr >> tmp;
			v.components.push_back(tmp);
		}

		std::cout << '\n';

		return istr;
	}

	// ��������� ������� �� �����.
	friend Vector<T> operator*(const Vector<T>& v, const T& num)
	{
		Vector<T> tmp;
		tmp.dim = v.dim;
		for (auto item : v.components)
		{
			tmp.components.push_back(item * num);
		}

		return tmp;
	}

	// ��������� ������� �� �����.
	friend Vector<T>& operator*=(Vector<T>& v, const T& num)
	{
		for (auto& item : v.components)
		{
			item *= num;
		}

		return v;
	}

	// ��������� ����� �� ������.
	friend Vector<T> operator*(const T& num, const Vector<T>& v)
	{
		Vector<T> tmp;
		tmp.dim = v.dim;
		for (auto item : v.components)
		{
			tmp.components.push_back(item * num);
		}

		return tmp;
	}

	// �������� ��������.
	friend Vector<T> operator+(const Vector<T>& v1, const Vector<T>& v2)
	{
		if (v1.dim != v2.dim)
		{
			setlocale(LC_ALL, "Russian");
			std::cout << "������: ���������� ������� ������� ������ ������������.\n";
			Vector<T> tmp;
			return tmp;
		}

		Vector<T> tmp;
		tmp.dim = v1.dim;

		for (unsigned int i = 0u; i < v1.dim; i++)
		{
			tmp.components.push_back(v1.components[i] + v2.components[i]);
		}

		return tmp;
	}

	// ���� �������� ��������.
	friend Vector<T>& operator+=(Vector<T>& v1, const Vector<T>& v2)
	{
		if (v1.dim != v2.dim)
		{
			setlocale(LC_ALL, "Russian");
			std::cout << "������: ���������� ������� ������� ������ ������������.\n";
			Vector<T> tmp;
			return tmp;
		}

		for (unsigned int i = 0u; i < v1.dim; i++)
		{
			v1.components[i] += v2.components[i];
		}

		return v1;
	}

	// ��������� ��������.
	friend Vector<T> operator-(const Vector<T>& v1, const Vector<T>& v2)
	{
		if (v1.dim != v2.dim)
		{
			setlocale(LC_ALL, "Russian");
			std::cout << "������: ���������� ������� ������� ������ ������������.\n";
			Vector<T> tmp;
			return tmp;
		}

		Vector<T> tmp;
		tmp.dim = v1.dim;

		for (unsigned int i = 0u; i < v1.dim; i++)
		{
			tmp.components.push_back(v1.components[i] - v2.components[i]);
		}

		return tmp;
	}

	// ���� ��������� ��������.
	friend Vector<T>& operator-=(Vector<T>& v1, const Vector<T>& v2)
	{
		if (v1.dim != v2.dim)
		{
			setlocale(LC_ALL, "Russian");
			std::cout << "������: ���������� ������� ������� ������ ������������.\n";
			Vector<T> tmp;
			return tmp;
		}

		for (unsigned int i = 0u; i < v1.dim; i++)
		{
			v1.components[i] -= v2.components[i];
		}

		return v1;
	}

	// ��������� �������. � ���������. �� ����� �������.
	friend Vector<T>& operator-(Vector<T>& v)
	{
		for (auto& item : v.components)
		{
			item = -item;
		}

		return v;
	}

	// ������� ���������� ������������ ��������.
	friend T scalar(const Vector<T>& v1, const Vector<T>& v2)
	{
		if (v1.dim != v2.dim)
		{
			setlocale(LC_ALL, "Russian");
			std::cout << "������: ���������� �������� ��������� ������������ �������� ������ �����������.";
			return -228;
		}

		T result = 0;

		for (unsigned int i = 0u; i < v1.dim; i++)
		{
			result += v1.components[i] * v2.components[i];
		}

		return result;
	}
};


#endif // VECTOR_H