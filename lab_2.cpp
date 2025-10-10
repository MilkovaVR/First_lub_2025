
#include <iostream>
#include <bitset>



using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    // Вводим значения
    short A;
    int i;

    cout << "Введите число А: ";
    cin >> A;

    cout << "Введите количество битов i (от 0 до 7):";
    cin >> i;

    //Проверяем на корректность записи i
    if (i < 0 || i > 7) {
        cout << "Число не соответсвует заявленным критериям! Нужно число от 0 до 7" << endl;
        cin >> i;
        return 1;
    }
    // Переводим в двоичную си и находим бит
    bitset<16> b1 = (A);
    cout << A << " = " << b1 << endl;
    short bit = (A >> i) & 1;
    cout << "Значение " << i << " бита:" << bit << endl;


    //Пункт 1:
    if (bit != 0) {
        int a, b;
        cout << "Введите 2 числа: ";
        cin >> a >> b;

        if (a % b == 0) {
            bitset<16> b2 = (a/b);
            cout << "Результат деления: " << a / b << " = " << b2 << endl;
        }
        else {
            bitset<16> b3 = (a*b);
            cout << "Произведение: " << a * b << " = " << b3 << endl;
        }
    }
    else { // i != 0, меняем биты на противоположные
        A ^= (1 << (i + 1));
        A ^= (1 << (i - 1));

        bitset<16> b4 = (A);
        cout << "Измененное число: " << A << " = " << b4 << endl;
    }

    // Пункт 2

    int N;
    cout << "Введите число N: ";
    cin >> N;

    switch (N) {
    case 1: cout << "Ошибка: Неисправность ЭБУ впрыска" << endl; break;
    case 2: cout << "Ошибка: Неисправность ДУТ" << endl; break;
    case 4: cout << "Ошибка: Повышенное напряжение" << endl; break;
    case 8: cout << "Ошибка: Пониженное напряжение" << endl; break;
    case 13: cout << "Ошибка: Отсутствует сигнал датчика кислорода" << endl; break;
    case 51: cout << "Ошибка: Неисправность работы ПЗУ" << endl; break;
    case 52: cout << "Ошибка: Неисправность работы ОЗУ" << endl; break;
    case 55: cout << "Ошибка: Слишком бедная смесь" << endl; break;
    case 61: cout << "Ошибка: Проблемы в работе датчика кислорода" << endl; break;
    }
    return 0;
}


