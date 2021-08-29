// Sample.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>
#include <tuple>

enum Color 
{
	black,
	white,
	red
};


enum class Color2
{
	black,
	white,
	red
};


void func(double d) {

}


enum UserInfoFields { uiName, uiEmail, uiReputation };

template<typename E> // C++14
constexpr std::underlying_type_t<E>
toUType(E enumerator) noexcept
{
	return static_cast<std::underlying_type_t<E>>(enumerator);
}


int main(void)
{
	auto white = false;//本書と異なりビルド可能。ビルド時にワーニングは表示されている
	func(white);//暗黙の型変換発生

	//Color  c = white;

	Color2  c2 = Color2::white;
	func(c2);//暗黙の型変換は発生しない。キャスト必要。

	using UserInfo = // type alias; see Item 9
		std::tuple<std::string, // name
		std::string, // email
		std::size_t>;

	UserInfo uInfo;
	auto val = std::get<uiName>(uInfo);//UserInfoFieldsからstd::size_tへの暗黙の変換のおかげ




}