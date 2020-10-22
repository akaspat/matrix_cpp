#include <iostream>

/*
В целочисленной матрице А размером N*M заменить
элементы побочной диагонали и расположенные выше нее
на значение 4 (числа N и М задаются с клавиатуры в
диапазоне от 3 до 10). Первоначальное заполнение массива
А осуществить при помощи датчика случайных чисел в
диапазоне от -5 до 15. Исходную и видоизмененную
матрицы вывести на экран.
*/

int main(int argc, char* argv[]){
    int n = 0, m; // rows
    m = 0; // cols

    while ( !((m >= 3 && m <= 10) && (n >= 3 && n <= 10)) ) {
        std::cout << "Please input matrix size. 3 <= m, n <= 10" << std::endl;
        std::cout << "Input n (rows): ";
        std::cin >> m;
        std::cout << "Input m (cols): ";
        std::cin >> n;
    }

    // allocate memory
    int **matrix;
    matrix = new int*[n];
    for (int i=0; i < n; i++){
        matrix[i] = new int[m];
    }

    srand(time(NULL));
    // random value for matrix
    for (int row = 0; row < n; row++){
        for (int col = 0; col < m; col++){
            matrix[row][col] = -5 + rand() % + 21;
        }
    }

    // print matrix
    std::cout << "________Matrix________" << std::endl;
    for (int row = 0; row < n; row++){
        for (int col = 0; col < m; col++){
            std::cout << matrix[row][col] << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << "______________________" << std::endl;

    // numbers above secondary diagonal
    // are changed on value - 4
    for (int row = 0; row < n; row++){
        for (int col = 0; col < m; col++){
            if (row + col + 1 < n) {
                matrix[row][col] = 4;
            }
        }
    }

    // print matrix
    std::cout << "________Matrix________" << std::endl;
    for (int row = 0; row < n; row++){
        for (int col = 0; col < m; col++){
            std::cout << matrix[row][col] << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << "______________________" << std::endl;

    // deallocate memory
    for (int i=0; i < n; i++){
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
