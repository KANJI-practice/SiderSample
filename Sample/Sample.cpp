﻿// Sample.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>
#include <tuple>

class Base {
public:
	virtual void mf1() const;
	virtual void mf2(int x);
	virtual void mf3()&;
	void mf4() const;
};
class Derived : public Base {
public:
	virtual void mf1();
	virtual void mf2(unsigned int x);
	virtual void mf3()&&;
	void mf4() const;
};


int main(void)
{
	
}