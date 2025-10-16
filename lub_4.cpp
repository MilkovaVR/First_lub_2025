#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "Russian");
    int massiv[6];
    cout << "Пожалуйста, введите 6 элементов массива" << endl;

    for (int l = 0; l < 6; ++l)
    {
        cout << l + 1 << " элемент: ";
        cin >> massiv[l];
    }


    // ПУНКТ 1

    int pov = 0; //переменная для повторяющихся элементов

    for (int g = 0; g < 5; ++g)
    {
        if (massiv[g] == massiv[g+1])
        {
            pov+=1;
        }
    }

    if (pov == 0)
    {
        cout << "Нет пар повторяющихся элементов, Ваш массив: ";
    }else
    {
        for (int i =0; i < 5; ++i)
        { 
            for(int j = i+1; j < 6; ++j)
            {
                if (massiv[i] > massiv[j])
                {
                    swap(massiv[i], massiv[j]);
                }
            }
        }
    }

        cout << "Есть пары повторяющихся элементов, сортировка по возрастанию: ";

    for (int h = 0; h < 6; ++h)
    {
        cout << massiv[h] << " ";
    }
    
    cout << endl;
    cout << endl;

    // ПУНКТ 2

    int strk = 3;
    int stolb = 4;

    vector < vector<int> > matrix(strk, vector<int>(stolb));

    cout << "Введите элементы матрицы " << endl;
    for (int y = 0; y < strk; ++y)
    {
        for (int x = 0; x < stolb; ++x)
        {
            cin >> matrix[y][x];
        }
        cout << endl;
    }
    
    int Maxi = -1;
    int sum;
    int number = -1; //номер строки с наиб. суммой

    for (int y = 0; y < strk; ++y)
    {
        sum = 0;
        for (int x = 0; x < stolb; ++x)
        {
            sum += abs(matrix[y][x]);
        }
        if (sum > Maxi){
                Maxi = sum;
                number = y;
        }
    }

    cout << "Наибольшая сумма модулей в строке № " << number+1 << ", сумма: " << Maxi << endl;
    cout << endl;

    if (number != -1)
    {
    for (int x = 0; x < stolb; ++x)
    {
        matrix[number][x] = 0;
    }

    cout << "Ваша новая матрица:" << endl;

    for (int y = 0; y < strk; ++y)
    {
        for (int x = 0; x < stolb; ++x)
        {
            cout << matrix[y][x];
        }
        cout << endl;
    }
    }

    return 0;
}
