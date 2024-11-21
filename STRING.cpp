// C++에서 C 헤더를 사용하고 싶다면 c~로 시작하고, .h로 끝나지 않는 라이브러리를 사용하자.
#include "STRING.h"

bool shouldDebug{ false }; // 디버그용 플래그.

STRING::STRING(const char* s) 
	: size{ std::strlen(s) }
{
	ptr = new char[size];
	std::memcpy(ptr, s, size);

	if (shouldDebug) {
		std::cout << "생성자(const char*) - " << size << ", 주소 - " << this << std::endl;
	}
}

STRING::STRING(const size_t& length) 
	: size{ length }
{
	ptr = new char[size];
	if (shouldDebug) {
		std::cout << "생성자(size_t) - " << size << ", 주소 - " << this << std::endl;
	}
}

STRING::STRING(const STRING& other)
	: size{ other.size }
{
	ptr = new char[size];
	std::memcpy(ptr, other.ptr, size);
	// this = *other; <-- 대체 가능!

	if (shouldDebug) {
		std::cout << "복사 생성자 - " << size << ", 주소 - " << this << std::endl;
	}
}

STRING::~STRING() 
{
	if (shouldDebug) {
		std::cout << "소멸자 - " << size << ", 주소 - " << this << std::endl;
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
		std::cout << "이동 할당 연산자 - " << size << ", 주소 - " << this << std::endl;
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
		std::cout << "이동 할당 연산자 - " << size << ", 주소 - " << this << std::endl;
	}
}

STRING::STRING(STRING&& other)
	: size(other.size), ptr(other.ptr)
{
	other.size	= 0;
	other.ptr	= nullptr;

	if (shouldDebug) {
		std::cout << "이동 생성자 - " << size << ", 주소 - " << this << std::endl;
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
	// 이항 연산자의 피연산자 2개가 갖고 있는 글자를 담을 수 있는 임시 객체를 생성한다.
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
