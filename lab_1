#include <iostream>
#include <limits>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите первое число:";
    int a;
    cin >> a;

    cout << "Введите второе число:";
    int b;
    cin >> b;

    // создаем переменные для каждого действия над a и b
    int Sum = a + b;

    int Ras_1 = a - b;
    int Ras_2 = b - a;

    int prois = a * b;

    /* в делении добаляем float 
    для точного дробного значения*/

    float delen_1 = float(a) / b;
    float delen_2 = float(b) / a;

    cout << "Сумма чисел (тип - целое): " << Sum << endl;
    cout << "Разность чисел (тип - целое): " << Ras_1 << " и " << Ras_2 << endl;
    cout << "Произведение чисел (тип - целое): " << prois << endl;
    cout << "Деление чисел (тип - дробное): " << delen_1 << " и " << delen_2 << endl;

    // ищем минимальные и максимальные значения для int и float
    cout << "Минимальное значение int: " <<  numeric_limits <int>::min() << endl;
    cout << "Максимальное значение int: " << numeric_limits <int>::max() << endl;

    cout << "Минимальное значение float: " << -numeric_limits <float>::max() << endl;
    cout << "Максимальное значение float: " << numeric_limits <float>::max() << endl;

    // ищем размер в битах
    cout << "Размер int в битах: " << sizeof(int) * 8 << endl;
    cout << "Размер float в битах: " << sizeof(float) * 8 << endl;

    return 0;
}
