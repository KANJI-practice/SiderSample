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

class Widget {
public:
	//デフォルトのコンストラクタはない状態
	Widget(int arg) :w(arg) {};
	int w;



private:
	int x{ 0 };
	int y = 0;
	int z(0);//ビルドエラー
	
};

class Widget2 
{
public:
	Widget2() {};


	Widget2(double arg)
	{
		std::cout << "double constructer";
	};


	std::vector<int>v;
	Widget2(std::initializer_list<int> list)
	{
		std::cout << "initializer_list";
		for (auto i : list) {
			v.push_back(i);
		}

	}

};

int main(void)
{
	//精度が落ちる変換の初期化
	double x = 1.0;
	double y = 1.0;
	int sum{ x + y };//｛｝ならビルドエラー。精度落ち許容しない
	int sum2( x + y );//（）は精度低下許容



	//デフォルトのコンストラクタは存在しない時に()で初期化
	Widget w1(1);
	Widget w2();//関数定義になってしまっている。デフォルトのコンストラクタは存在しない。ビルドエラーなし
	Widget w3{};//ビルドエラーになる
	Widget w4{1};//OK

	//{}初期化ではinitialize_listが優先的に呼び出される
	Widget2 w5(10.0); //()では型のマッチが優先される
	Widget2 w6{ 10.0 }; //{}ではinitializer_listが優先され,精度落ちでビルドエラー
	Widget2 w7({});//空のinitializer_listを渡す
	Widget2 w8{ {} };//空のinitializer_listを渡す
	std::vector<int> a(10, 20);//値20が10個
	std::vector<int> b{ 10,20 };//initializer_listにより{10，20}が生成.std::vectorのコンストラクタ設計がいけてない

	std::unique_ptr<int[]> p1 = std::make_unique<int[]>(3);//要素3つ
	std::unique_ptr<int[]> p2 = std::make_unique<int[]>{ 3 };//()でしか初期化できないようになっている。ビルドエラー
	std::shared_ptr<int[]> p3 = std::make_shared<int[]>( 3 );
	std::shared_ptr<int[]> p4 = std::make_shared<int[]>{ 3 };//()でしか初期化できないようになっている。ビルドエラー
}