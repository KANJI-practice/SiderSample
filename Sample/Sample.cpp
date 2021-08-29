// Sample.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>
#include <array>

constexpr int pow(int base, int exp) noexcept
{
	return (exp == 0 ? 1 : base * pow(base, exp - 1));//C++11は1行のみ
}

int main(void)
{
	constexpr int base = 2;
	base = 4;//constexprを変更してみる
	constexpr int exp = 3;
	std::array<int, pow(base, exp)> ary;
	std::cout << ary.size() << std::endl; // 8
}