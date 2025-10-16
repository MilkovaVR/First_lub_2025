#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int N;
    cout << "Введите количество чисел последовательности: ";
    cin >> N;

    double sum = 0.0; //сумма чисел последовательности
    double Maxi = -0.36; //максимальное число
    int Maxi_nomer = 0; //номер макс числа
    int count = 0; //количество чисел, попавших в последовательность


    // ПУНКТ 1

    /*for (int i = 1; i <= N; ++i){
        double num = 0;
        cout << "Введите число " << i << ": ";
        cin >> num;

        if (-0.36 < num <= 10.1) {
            sum += num;
            count+=1;

            if (num > Maxi) {
                Maxi = num;
                Maxi_nomer = count;
            }
        }
    }
    if (count != 0){
        cout << "Сумма чисел последовательности, вошедших в интервал (-0.36;10.1]): " << sum << endl;
        cout << "Максмальное число последовательности: " << Maxi << ", его номер: " << Maxi_nomer << endl;
    }
    if (count == 0){
        cout << "Нет чисел, входящих в интервал (-0.36;10.1])" << endl;

    } */

    for (int i = 1; i <= N; ++i){
        double num = 0;
        cout << "Введите число " << i << ": ";
        cin >> num;

        if ((-0.36 >= num) || (num > 10.1)) {
            continue;
        }

        count += 1;
        sum += num;
        if (num > Maxi) {
            Maxi = num;
            Maxi_nomer = count;
        } 
    }

    if (count != 0){
        cout << "Сумма чисел последовательности, вошедших в интервал (-0.36;10.1]): " << sum << endl;
        cout << "Максмальное число последовательности: " << Maxi << ", его номер: " << Maxi_nomer << endl;
    }
    if (count == 0){
        cout << "Нет чисел, входящих в интервал (-0.36;10.1])" << endl;

    }

    // ПУНКТ 2
    int x;
    cout << "Введите целое число из интервала (-1000;1000): ";
    cin >> x;

    while (abs(x) >= 1000) {
        cout << "Число не входит в интервал, попробуйтк снова: " ;
        cin >> x;
        if (abs(x) < 1000){
            break;
        }
    }   

    int ans = 1; //конечное число, которое получится
    int x1 = abs(x);
    
    if (x == 0){
        cout << "Произведение цифр: 0" << endl;
    } else {
        while (x1 > 0){
            ans = ans*(x1 % 10);
            x1 = x1/10;
        }
    }
    cout << "Произведение цифр вашего числа: " << ans << endl;
    return 0;
}
