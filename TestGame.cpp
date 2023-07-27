// TestGame.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <random>
#include <functional>
#include <chrono>
#include <thread>
#include <mutex>
#include <fstream>

using namespace std;


int prize[11]{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int test_number = 0;

mt19937::result_type seed = time(0);
auto dice_rand = bind(uniform_int_distribution<__int64>(0, 10000000000),
    mt19937(seed));

void Play(mutex& mt)
{

    __int64 a[12]{0, 8461775783, 8500000000, 8696509704, 9341857710, 9657585612, 9982328470, 9991766292, 9992773662, 9993788806,9994016324, 10000000000};
    for (int i = 0; i < 10000; i++)
    {
        mt.lock();
        __int64 b = dice_rand();


        if (a[0] <= b && b < a[1]) prize[0]++;
        if (a[1] <= b && b < a[2]) prize[1]++;
        if (a[2] <= b && b < a[3]) prize[2]++;
        if (a[3] <= b && b < a[4]) prize[3]++;
        if (a[4] <= b && b < a[5]) prize[4]++;
        if (a[5] <= b && b < a[6]) prize[5]++;
        if (a[6] <= b && b < a[7]) prize[6]++;
        if (a[7] <= b && b < a[8]) prize[7]++;
        if (a[8] <= b && b < a[9]) prize[8]++;
        if (a[9] <= b && b < a[10]) prize[9]++;
        if (a[10] <= b && b <= a[11]) prize[10]++;

        mt.unlock();
    }
    test_number = test_number + 10000;

}

int main()
{
    mutex mt;
    thread t1(Play, ref(mt));
    thread t2(Play, ref(mt));

    t1.join();
    t2.join();

    cout << test_number << ": ";
    for (int i = 0; i < 11; i++)
    {
        cout << prize[i] << ' ';
    }
    ofstream out;
    out.open("1.txt");
    if (out.is_open())
    {
        out << "Количесвто испытаний:" << test_number << endl;
        for (int i = 0; i < 11; i++)
        {
            out << prize[i] << ' ';
        }

    }

    out.close();
    cout << endl;
    cout << "File has been written" << endl;
}

