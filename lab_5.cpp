#include <iostream>

using namespace std;


// ПУНКТ 1 ------------------------

void function1(int a, int b) // Ищем деление или умножение 2-х чисел
{
    if (a != 0)
    {
        if (b%a == 0)
        {
            cout << "Деление b на a: " << b/a << endl;
        }else{
            if (b != 0)
            {
                if (a%b == 0)
                {
                    cout << "Деление a на b: " << a/b << endl;
                }else
                {
                    cout << "Произведение чисел a и b: " << a*b << endl;
                }
            }else
            {
                cout << "Произведение чисел a и b: " << a*b << endl;
            }
        }
    }else{
        if (b!=0)
        {
            cout << "Деление a на b: " << a/b << endl;
        }else
        {
        cout << "Произведение чисел a и b: " << a*b << endl;
        }
    }
}

void function2(int ch1, int ch2, int ch3) // проверяем равенство 3-х чисел
{
    if ((ch1 == ch2) && (ch2 == ch3))
    {
        cout << "1";
    }
    else{
        cout << "-1";
    }
}

// ПУНКТ 2 ------------------------

void function3(int c, int d) // лаба 1
{
    // создаем переменные для каждого действия над c и d
    int Sum = c + d;

    int Ras_1 = c - d;
    int Ras_2 = d - c;
    int prois = c * d;

    cout << "Сумма чисел (тип - целое): " << Sum << endl;
    cout << "Разность чисел (тип - целое) (1-го и 2-го), (2-го и 1-го): " << Ras_1 << " и " << Ras_2 << endl;
    cout << "Произведение чисел (тип - целое): " << prois << endl;

    /* в делении добаляем float 
    для точного дробного значения*/


    if ((d!=0) && (c!=0))
    {
        float delen_1 = float(c) / d;
        float delen_2 = float(d) / c;
        cout << "Деление чисел (тип - дробное) (1-го на 2-е), (2-го на 1-е): " << delen_1 << " и " << delen_2 << endl;
    }

    else if ((d != 0) && (c == 0))
    {
        float delen_1 = float(c) / d;
        cout << "Деление чисел (тип - дробное) (1-го на 2-е): " << delen_1 << endl;
    }
    else{
        float delen_2 = float(d) / c;
        cout << "Деление чисел (тип - дробное) (2-го на 1-е): " << delen_2 << endl;
    }
    



    // ищем минимальные и максимальные значения для int и float
    cout << "Минимальное значение int: " <<  numeric_limits <int>::min() << endl;
    cout << "Максимальное значение int: " << numeric_limits <int>::max() << endl;

    cout << "Минимальное значение float: " << -numeric_limits <float>::max() << endl;
    cout << "Максимальное значение float: " << numeric_limits <float>::max() << endl;

    // ищем размер в битах
    cout << "Размер int в битах: " << sizeof(int) * 8 << endl;
    cout << "Размер float в битах: " << sizeof(float) * 8 << endl;
}



int main()
{
    int punkt = 0;
    cout << "Пожалуйста, введите номер пункта (1 или 2): ";
    cin >> punkt;

    if (punkt == 1)
    {
        cout << "Пожалуйста, введите 2 или 3 целых числа: ";
        int ch1 = 0;
        int ch2 = 0;
        int ch3 = 0;
        cin >> ch1 >> ch2 >> ch3;

        if ((ch1 != 0) && (ch2 != 0) && (ch3 != 0))
        {
            cout << "Используется фукция определения равенства 3-х чисел" << endl;
            function2(ch1, ch2, ch3);
        }
        else
        {
            cout << "Используется функция деления 2-х кратных чисел / умножения 2-х не кратных чисел" << endl;
            
            if (ch1 == 0)
            {
                cout << "Пусть a = " << ch2 << " и b = " << ch3 << ", тогда:" << endl;
                function1(ch2, ch3);
            }
            else if (ch2 == 0)
            {
                cout << "Пусть a = " << ch1 << " и b = " << ch3 << ", тогда:" << endl;
                function1(ch1, ch3);
            }
            else
            {
                cout << "Пусть a = " << ch1 << " и b = " << ch2 << ", тогда:" << endl;
                function1(ch1, ch2);
            }
            
        }
    }
    
    else{
        cout << "Используется функция   суммы, разности, деления и умножения 2-х чисел" << endl;
        cout << "Пожалуйста,  введите 2 целых числа" << endl;
        int n3 = 0;
        int n4 = 0;
        cin >> n3 >> n4;
        function3(n3, n4);
    }
}
