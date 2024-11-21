// C++���� C ����� ����ϰ� �ʹٸ� c~�� �����ϰ�, .h�� ������ �ʴ� ���̺귯���� �������.
#include "STRING.h"

bool shouldDebug{ false }; // ����׿� �÷���.

STRING::STRING(const char* s) 
	: size{ std::strlen(s) }
{
	ptr = new char[size];
	std::memcpy(ptr, s, size);

	if (shouldDebug) {
		std::cout << "������(const char*) - " << size << ", �ּ� - " << this << std::endl;
	}
}

STRING::STRING(const size_t& length) 
	: size{ length }
{
	ptr = new char[size];
	if (shouldDebug) {
		std::cout << "������(size_t) - " << size << ", �ּ� - " << this << std::endl;
	}
}

STRING::STRING(const STRING& other)
	: size{ other.size }
{
	ptr = new char[size];
	std::memcpy(ptr, other.ptr, size);
	// this = *other; <-- ��ü ����!

	if (shouldDebug) {
		std::cout << "���� ������ - " << size << ", �ּ� - " << this << std::endl;
	}
}

STRING::~STRING() 
{
	if (shouldDebug) {
		std::cout << "�Ҹ��� - " << size << ", �ּ� - " << this << std::endl;
	}

	delete[] ptr;
}

STRING& STRING::operator=(const STRING& other) 
{
	if (this == &other) {
		return *this;
	}

	delete[] ptr;
	size	= other.size;
	ptr = new char[size];
	std::memcpy(ptr, other.ptr, size);

	if (shouldDebug) {
		std::cout << "�̵� �Ҵ� ������ - " << size << ", �ּ� - " << this << std::endl;
	}

	return *this;
}

STRING& STRING::operator=(const char* const s) 
{
	if (std::strcmp(ptr, s)) {
		return *this;
	}

	delete[] ptr;
	size = strlen(s);
	ptr = new char[size];
	std::memcpy(ptr, s, size);

	return *this;
}

STRING& STRING::operator&&(STRING&& other)
{
	if (this == &other) {
		return *this;
	}

	size	= other.size;
	ptr		= other.ptr;

	other.size	= 0;
	other.ptr	= nullptr;

	if (shouldDebug) {
		std::cout << "�̵� �Ҵ� ������ - " << size << ", �ּ� - " << this << std::endl;
	}
}

STRING::STRING(STRING&& other)
	: size(other.size), ptr(other.ptr)
{
	other.size	= 0;
	other.ptr	= nullptr;

	if (shouldDebug) {
		std::cout << "�̵� ������ - " << size << ", �ּ� - " << this << std::endl;
	}
}

const bool STRING::operator==(const STRING& other) const
{
	return std::strcmp(ptr, other.ptr);
}

const bool STRING::operator!=(const STRING& other) const
{
	return not(*this == other);
}

const bool STRING::operator==(const char* const s) const
{
	return std::strcmp(ptr, s);
}

const bool STRING::operator!=(const char* const s) const
{
	return not(*this == s);
}

STRING STRING::operator+(const STRING& other) const
{
	STRING temp{ size + other.size };

	std::memcpy(temp.ptr, ptr, size);
	std::memcpy(temp.ptr + size, other.ptr, other.size);

	return temp;
}

STRING& STRING::operator+=(const STRING& other) 
{
	return *this += other;
}

STRING STRING::operator+(const char* const s) const
{
	// ���� �������� �ǿ����� 2���� ���� �ִ� ���ڸ� ���� �� �ִ� �ӽ� ��ü�� �����Ѵ�.
	STRING temp{ size + std::strlen(s) };

	std::memcpy(temp.ptr, ptr, size);
	std::memcpy(temp.ptr + size, s, strlen(s));

	return temp;
}

STRING& STRING::operator+=(const char* const s) 
{
	return *this += s;
}

const char STRING::operator[](const size_t& index) const
{
	return ptr[index];
}

char& STRING::operator[](const size_t& index)
{
	return ptr[index];
}

const size_t STRING::GetSize() const 
{
	return size;
}

STRING operator+(const char* left, const STRING& right) 
{
	size_t length{ std::strlen(left) };
	STRING temp{ length + right.size };
	std::memcpy(temp.ptr, left, length);
	std::memcpy(temp.ptr + length, right.ptr, right.size);

	return temp;
}

std::ostream& operator<<(std::ostream& os, const STRING& next) 
{
	const char* const begin{ next.ptr };
	const char* const end{ next.ptr + next.size };
	
	for (const char* ch = begin; ch != end; ++ch) {
		os << *ch;
	}

	return os;
}
