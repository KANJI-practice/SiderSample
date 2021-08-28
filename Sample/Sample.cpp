// Sample.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>


std::vector<bool> f(std::vector<bool>& a) {

	a[5] = 1;

	return a;
}


int main(void)
{
	std::vector<bool> a;
	a.resize(10);

	std::cout << a[5];

	auto c = f(a)[5];

	std::cout << c;
}