#pragma once
#include <cstdlib>
#include <cstring>
#include <iostream>

/// <summary>
/// 표준 std::string을 흉내내본 클래스.
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

	// 신기한 오퍼레이터 연산자 오버로딩
	// friend 키워드를 통해 메서드를 작성할 수 있다.
	friend STRING operator+(const char* left, const STRING& right);

	// 반드시 입/출력 오퍼레이터는 friend 메서드로 선언되어야 한다.
	friend std::ostream& operator<<(std::ostream&, const STRING&);

private:
	/// <summary>
	/// 문자열의 사이즈.
	/// </summary>
	size_t size;

	/// <summary>
	/// 관리할 문자열을 가리키는 포인터.
	/// </summary>
	char* ptr;

};

