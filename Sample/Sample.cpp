// Sample.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>
#include <tuple>


class Widget
{

public:
	Widget() {};
	Widget(const Widget&) = delete;
	Widget& operator=(const Widget&) = delete;
};

class Widget2
{
public:
	Widget2() {};

private:
	Widget2(const Widget2&) = delete;
	Widget2& operator=(const Widget2&) = delete;
};


template<typename T>
void processPointer(T* ptr) {};

template<>
void processPointer<double>(double*) = delete;

int main(void)
{
	//deleteをpublicに
	Widget tmp;
	Widget tmp2 = tmp;//「削除された関数を参照」というワーニングで分かりやすい

	//deleteをprivateに
	Widget2 tmp3;
	Widget2 tmp4 = tmp3;//「アクセスできません」というワーニングで分かりにくい

	int a = 10;
	processPointer<int>(&a);

	double b = 1.0;
	processPointer<char>(&b);
}