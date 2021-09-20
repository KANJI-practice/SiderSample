// Sample.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>
#include <array>
#include <thread>
#include <mutex>
#include <vector>



class Widget1
{
public:
    Widget1(int a):m_a(a){}

    Widget1(Widget1&& original) noexcept
    {
       /// m_a = original.m_a;
    }

    void print() {
        std::cout << m_a << std::endl;
    }

private:
    int m_a;

};

class Widget2
{
public:
    Widget2(int a) :m_a(a) {}

    //テンプレートでムーブコンストラクタを自作した場合
    template<typename T>
    Widget2(const T&& original) noexcept
    {
        /// m_a = original.m_a;
    }

    void print() {
        std::cout << m_a << std::endl;
    }

private:
    int m_a;
};

int main() {

    Widget1 a(1);
    Widget1 b(std::move(a));
    b.print();//正常にmoveされていないので無効値が表示される

    Widget2 c(1);
    Widget2 d(std::move(c));//テンプレートメンバ関数が特殊メンバ関数の生成を抑制することはない
    d.print();//1が表示される
    return 0;
}