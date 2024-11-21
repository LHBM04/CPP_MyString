#pragma once
#include <cstdlib>
#include <cstring>
#include <iostream>

/// <summary>
/// ǥ�� std::string�� �䳻���� Ŭ����.
/// </summary>
class STRING final {
public:
	STRING() = default;
	STRING(const char*);
	STRING(const size_t&);
	STRING(const STRING&);
	STRING(STRING&&);
	~STRING();

	STRING& operator=(const STRING&);
	STRING& operator=(const char* const);
	STRING& operator&&(STRING&&);

	const bool operator==(const STRING&) const;
	const bool operator!=(const STRING&) const;

	const bool operator==(const char* const) const;
	const bool operator!=(const char* const) const;

	STRING operator+(const STRING&) const;
	STRING& operator+=(const STRING&);

	STRING operator+(const char* const) const;
	STRING& operator+=(const char* const);

	const char operator[](const size_t&) const;
	char& operator[](const size_t&);

public:
	const size_t GetSize() const;

	// �ű��� ���۷����� ������ �����ε�
	// friend Ű���带 ���� �޼��带 �ۼ��� �� �ִ�.
	friend STRING operator+(const char* left, const STRING& right);

	// �ݵ�� ��/��� ���۷����ʹ� friend �޼���� ����Ǿ�� �Ѵ�.
	friend std::ostream& operator<<(std::ostream&, const STRING&);

private:
	/// <summary>
	/// ���ڿ��� ������.
	/// </summary>
	size_t size;

	/// <summary>
	/// ������ ���ڿ��� ����Ű�� ������.
	/// </summary>
	char* ptr;

};

