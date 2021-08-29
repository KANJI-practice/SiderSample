// Sample.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>


std::vector<bool> f(std::vector<bool>& a) {

	a[5] = 1;

	return a;
}

void function(int a) {

	std::cout << "int\n";
}

void function(void* p) {

	std::cout << "void* pointer\n";
}


int main(void)
{
	function(10);

	function(NULL);

	function(nullptr);
}