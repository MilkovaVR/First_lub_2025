#include <iostream>
#include <cstdlib> 

using namespace std;

// Функция поиска столбцов с нулевыми элементами
int* poisk_nol(int** matrix, int strok, int stolb, int& nol_stolb_count) 
{
    int* nol_stolb = (int*)malloc(stolb * sizeof(int)); // Временный массив для индексов
    nol_stolb_count = 0;

    for (int j = 0; j < stolb; j++) 
    {
        for (int i = 0; i < strok; i++) 
        {
            if (matrix[i][j] == 0) 
            {
                nol_stolb[nol_stolb_count++] = j; // индекс столбца
                break; 
            }
        }
    }
    return nol_stolb;
}


// Функция удаления столбцов из матрицы
int** delit_stolb(int** matrix, int strok, int& stolb, int* nol_stolb, int nol_stolb_count) 
{
    if (nol_stolb_count == 0) return matrix;

    // Создаем новую матрицу с уменьшенным количеством столбцов
    int new_stolb = stolb - nol_stolb_count;
    int** newMatrix = (int**)malloc(strok * sizeof(int*));
    
    for (int i = 0; i < strok; i++) 
    {
        newMatrix[i] = (int*)malloc(new_stolb * sizeof(int));
        int newJ = 0;
        for (int j = 0; j <  stolb; j++) 
        {
            bool isnol_stolb = false;
            for (int k = 0; k < nol_stolb_count; k++) 
            {
                if (j == nol_stolb[k]) 
                {
                    isnol_stolb = true;
                    break;
                }
            }
            if (!isnol_stolb) 
            {
                newMatrix[i][newJ++] = matrix[i][j];
            }
        }
    }

    // Освобождаем старую матрицу
    for (int i = 0; i < strok; i++) free(matrix[i]);
    free(matrix);

    stolb = new_stolb; // Обновляем количество столбцов
    return newMatrix;
}


int main() 
{
    // ПУНКТ 1 -------------------------------
    int** matrix = (int**)malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++) 
    {
        matrix[i] = (int*)malloc(2 * sizeof(int));
    }

    int A, B, C, D;
    cout << "Введите A, B, C, D для матрицы 2x2, где A и B != 0:\n";

    do 
    {
        cout << "A: "; 
        cin >> A;
        if (A < 0) cout << "Ошибка! A не может быть отрицательным.\n";
    } while (A < 0);

    do 
    {
        cout << "B: "; 
        cin >> B;
        if (B < 0) cout << "Ошибка! B не может быть отрицательным.\n";
    } while (B < 0);

    cout << "C: "; cin >> C;
    cout << "D: "; cin >> D;

    matrix[0][0] = A;
    matrix[0][1] = B;
    matrix[1][0] = C;
    matrix[1][1] = D;

    // Новая матртца
    int new_str = 2 + A;
    int new_stolb = 2 + B;
    matrix = (int**)realloc(matrix, new_str * sizeof(int*));
    for (int i = 0; i < new_str; i++) 
    {
        matrix[i] = (int*)realloc(matrix[i], new_stolb * sizeof(int));
    }

    // Заполняем новые ячейки 
    for (int i = 0; i < new_str; i++) 
    {
        for (int j = 0; j < new_stolb; j++) 
        {
            if (i < 2 && j < 2) continue; // Пропускаем изначальные ячейки
            matrix[i][j] = (i - 1) * C + (j - 2) * D; 
        }
    }

    // Выводим расширенную матрицу
    cout << "\nРасширенная матрица:\n";
    for (int i = 0; i < new_str; i++) {
        for (int j = 0; j < new_stolb; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Ищем столбцы с нулями
    int nol_stolb_count;
    int* nol_stolb = poisk_nol(matrix, new_str, new_stolb, nol_stolb_count);

    // Удаляем нулевые столбцы
    matrix = delit_stolb(matrix, new_str, new_stolb, nol_stolb, nol_stolb_count);

    // Выводим результат
    cout << "\nМатрица после удаления столбцов с нулями:\n";
    for (int i = 0; i < new_str; i++) {
        for (int j = 0; j < new_stolb; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Освобождаем память
    free(nol_stolb);
    for (int i = 0; i < new_str; i++) free(matrix[i]);
    free(matrix);

    // ПУНКТ 2 -------------------------------
    
    double a, b;

    // Ввод значений
    cout << "Введите вещественное число a: ";
    cin >> a;
    cout << "Введите вещественное число b: ";
    cin >> b;

    // Создаем указатели
    double* uk_A = &a;
    double* uk_B = &b;

    // Увеличиваем a в 3 раза через указатель
    *uk_A *= 3;
    cout << "Увеличиваем a в 3 раза: a = " << a << endl;

    // Меняем местами a и b через указатели
    double temp = *uk_A;
    *uk_A = *uk_B;
    *uk_B = temp;

    cout << "После замемены переменных: a = " << a << ", b = " << b << endl;


    return 0;
}

