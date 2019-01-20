//
// Created by Emila on 2019-01-19.
//
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void task1()
{
    while(true) {
       // cout << " czesc tutaj task 1 z Polska" << endl;
        this_thread::sleep_for(chrono::seconds(2));
    }
}
void task2()
{   while(true) {
       // cout << " czesc here task 2 z Sidney" << endl;
        this_thread::sleep_for(chrono::seconds(2));
    }
}
int main()
{
    cout << "Hello World!" << endl;

    thread t1 (task1);
    thread t2 (task2);

    string a;
    while(true) {
        cin >> a;
        cout << a << endl;
    }


}
