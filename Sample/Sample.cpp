// Sample.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>


std::vector<bool> f(std::vector<bool>& a) {

	a[5] = 1;

	return a;
}

void function(int&) {

}

int main(void)
{
	//未初期化
	auto a;

	//左辺値に右辺値を入れてみる
	function(10);

	//プロクシクラスに推論され、文末でライフタイムが切れて未定義な場合
	std::vector<bool> a;
	a.resize(10);
	auto c = f(a)[5];
	std::cout << c;

}