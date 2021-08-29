// Sample.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>

class Widget {
public:
	using DataType = std::vector<double>; 
		
	//*thisが左辺値の場合に使用可能
	DataType& data() &
	{
		std::cout << "左辺値参照";
		return values;
	}

	//*thisが右辺値の場合に使用可能
	//DataType data() &&
	//{
	//	std::cout << "右辺値参照";
	//	return std::move(values);
	//}

private:
	DataType values;
};

class Base {
public:
	virtual void mf1() const;
	virtual void mf2(int x);
	virtual void mf3()&;
	virtual void mf4() const;
	virtual void mf5()&&;
};
class Derived : public Base {
public:
	virtual void mf1()const override;
	virtual void mf2(int x) override;

	virtual void mf3() & override
	{

	};

	virtual void mf4() const override;

	virtual void mf5() && override {

	};
};

Widget makeWidget() {

	Widget* tmp = new Widget;

	return *tmp;
}

int main(void)
{
	Widget w;

	auto vals1 = w.data();

	auto vals2 = makeWidget().data(); //makeWidgetでは右辺値が返ってくるので左辺値参照の.data()は使えない
}