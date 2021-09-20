// Sample.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>
#include <array>
#include <thread>
#include <mutex>
#include <vector>
std::mutex m;

void ThreadFuncInt(int thread,int* num) {
     m.lock();
    std::cout << "ThreadFuncInt " << thread << std::endl;
    *num *= 10;
    std::cout << *num << std::endl;
    m.unlock();

}

void ThreadFuncVector(int thread, std::vector<int> v) {
    m.lock();
    std::cout << "ThreadFuncVector " << thread << std::endl;
    v[2] *= 10;
    std::cout << v[2] << std::endl;
    m.unlock();

}

void func(int thread, std::vector<int> v) {
    m.lock();
    std::cout << "ThreadFuncVector " << thread << std::endl;
    v[2] *= 10;
    std::cout << v[2] << std::endl;
    m.unlock();

}

class Smple 
{
public:
    Smple(bool bFlag) :bCashed(bFlag) {};

    void Calc() const{
       // std::lock_guard<std::mutex> guard(m);
        if (!bCashed) 
        {
            std::cout << "bCashed False " << std::endl;
            bCashed = true;
        }
        else {
            std::cout << "bCashed true " << std::endl;
        }

        return;
    }

    void Calc2() const 
    {
        std::lock_guard<std::mutex> guard(m);
        if (!bCashed)
        {
            std::cout << "bCashed False " << std::endl;
            bCashed = true;
        }
        else {
            std::cout << "bCashed true " << std::endl;
        }
    }
private:
    mutable bool bCashed;
    mutable std::mutex m;
};

int main() {

    Smple p(false);


    int i = 10;
    std::vector<int> v(3,10);

    std::thread th1(ThreadFuncVector, 1, v);//vectorのoperator[]はスレッドセーフ　std::vector<bool>除く
    std::thread th2(ThreadFuncInt, 2, &i);//書き込み競合

    std::thread th3(ThreadFuncVector, 3, v);//vectorのoperator[]はスレッドセーフ　std::vector<bool>除く
    std::thread th4(ThreadFuncInt, 4, &i);//書き込み競合

    std::thread th5([&p]() {p.Calc(); });//書き込み競合の可能性
    std::thread th6([&p]() {p.Calc(); });//書き込み競合の可能性
    std::thread th7([&p]() {p.Calc2(); });

    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();
    th7.join();

    return 0;
}