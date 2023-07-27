// TestGame.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <random>
#include <functional>
#include <chrono>

using namespace std;


int prize[11]{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

mt19937::result_type seed = time(0);
auto dice_rand = bind(uniform_int_distribution<__int64>(0, 10000000000),
    mt19937(seed));

void Play()
{
    __int64 a[12]{0, 8461775783, 8500000000, 8696509704, 9341857710, 9657585612, 9982328470, 9991766292, 9992773662, 9993788806,9994016324, 10000000000};
    for (int i = 0; i < 10000; i++)
    {

        cout << dice_rand() << endl;
        if (a[0] <= dice_rand() && dice_rand() < a[1]) prize[0]++;
        if (a[1] <= dice_rand() && dice_rand() < a[2]) prize[1]++;
        if (a[2] <= dice_rand() && dice_rand() < a[3]) prize[2]++;
        if (a[3] <= dice_rand() && dice_rand() < a[4]) prize[3]++;
        if (a[4] <= dice_rand() && dice_rand() < a[5]) prize[4]++;
        if (a[5] <= dice_rand() && dice_rand() < a[6]) prize[5]++;
        if (a[6] <= dice_rand() && dice_rand() < a[7]) prize[6]++;
        if (a[7] <= dice_rand() && dice_rand() < a[8]) prize[7]++;
        if (a[8] <= dice_rand() && dice_rand() < a[9]) prize[8]++;
        if (a[9] <= dice_rand() && dice_rand() < a[10]) prize[9]++;
        if (a[10] <= dice_rand() && dice_rand() <= a[11]) prize[10]++;
    }


}

int main()
{

    //cout << dice_rand() << endl ;
    //winning w;
    //w.Print();
    Play();
    for (int i = 0; i < 11; i++)
    {
        cout << prize[i] << ' ';
    }


}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
