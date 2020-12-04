// Task07.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <cstdio>

#define N 256


int ifpalindrom(char a[N], int begin, int end)
{
    if (end <= begin)
        return 1;
    if (a[end] == a[begin])
        return (ifpalindrom(a, begin + 1, end - 1));
    else return 0;

}

int binary_search(int start, int finish, int el, int arr[], int mid) {
    mid = (int)abs(finish - start) / 2;
    if (arr[start + mid] == el) {
        return mid + start;
    }
    if (mid == 0)
    {
        if (arr[start + mid + 1] == el)
        {
            return mid + start + 1;
        }
    }
    else if ((finish - start) == 1 && arr[start + mid] != el)
        return -1;
    else if (arr[start + mid] > el)
        binary_search(start, mid + start, el, arr, 0);
    else binary_search(mid + start, finish, el, arr, 0);
}


int* unite(int arr[], int arr1[], int n, int m) {
    int* answer = (int*)malloc((n + m) * sizeof(int));


    int time = 0;
    int i = 0; int j = 0; int l = 0;

    while (i < n && j < m) {
        if (arr[i] <= arr1[j]) {
            answer[l] = arr[i];
            i++;
        }
        else if (arr1[j] < arr[i])
        {
            answer[l] = arr1[j];
            j++;
        }

        l++;

    }

    if (i == n) {
        for (int k = j; k < m; k++)
        {
            answer[l] = arr1[k];
            l++;
        }
    }
    else if (j == m) {
        for (int k = i; k < n; k++)
        {
            answer[l] = arr[k];
            l++;
        }
    }
    return answer;
}

void task07_01() {
    int n1;
    printf("Введите колличество элементов массива n\n");
    scanf_s("%d", &n1);

    int* arr = (int*)malloc(n1 * sizeof(int));
    int s = 0;
    int ch = 0;

    for (int i = 0; i < n1; i++) {
        printf("arr[%i] = ", i);
        scanf_s("%i", &arr[i]);
    }

    printf("\nМассив n\n");

    for (int i = 1; i < n1; i++) {
        if (arr[i] * arr[i - 1] < 0)
            s++;
        if (arr[i] == arr[i - 1])
            ch++;
    }

    printf("\nЗнак в массиве меняется %d раз", s);
    printf("\nв массиве %d различных элементов", n1 - ch);

}

//********

void task07_02(){
    int n;


    printf("Введите колличество элементов массива n\n");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    int s = 0;
    int max = 0;
    int prevmax = 0;

    for (int i = 0; i < n; i++) {
        printf("arr[%i] = ", i);
        scanf_s("%i", &arr[i]);
    }


    int i = 0;
    while (i < n)
    {
        while (arr[i] % 2 != 0 && i < n)
        {
            max++;
            i++;
        }

        if (max > prevmax) {
            prevmax = max;
            max = 0;
        }
        i++;
    }

    printf("\nсамая длинная цепочка нечетных элементов %d", prevmax);

}

void task07_03() {
    int n; 


    printf("Введите колличество элементов массива n\n");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    int s = 0;
    int max = 0;
    int prevmax = 0;

    for (int i = 0; i < n; i++) {
        printf("arr[%i] = ", i);
        scanf_s("%i", &arr[i]);
    }
    int j = 0;
    int m = 0;


    for (int i = 0; i < n - 1; i++) {
        while (arr[i] == arr[i + 1] && arr[i] != 0)
        {

            j = i + 1;
            m++;
            while (j < n - m) {
                arr[j] = arr[j + 1];
                j++;
            }


            arr[n - m] = 0;

        }

    }
    int k = 0;
    m = 0;

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("arr[%i] = %d\n", i, arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j] && arr[i] != 0)
            {
                k = j;
                m++;
                while (k < n - m) {
                    arr[k] = arr[k + 1];
                    k++;
                }

                arr[n - m] = 0;

            }
        }
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("arr[%i] = %d\n", i, arr[i]);
    }

}


void task07_05() {

    int el = 0;
    int answ;

    int n;
    printf("Введите колличество элементов массива n\n");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));


    for (int i = 0; i < n; i++) {
        printf("arr[%i] = ", i);
        scanf_s("%i", &arr[i]);
    }

    printf("\nВведите искомый элемент\n");
    scanf_s("%d", &el);


    answ = binary_search(0, n - 1, el, arr, 0);
    if (answ >= 0)
        printf("Заданный элемент находится на месте %d ", answ);
    else printf("в массиве нет искомого элемента\n");

}

void task07_04() {

    int n;


    printf("Введите колличество элементов массива n\n");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));


    for (int i = 0; i < n; i++) {
        printf("arr[%i] = ", i);
        scanf_s("%i", &arr[i]);
    }

    int max = arr[0];
    int max2 = arr[1];

    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > max2&& arr[i] < max)
            max2 = arr[i];
    }

    printf("\nвторой наибольшый элемент массива равен %d\n", max2);

}

void task07_06() {
    int n;
    int m;
    printf("Введите колличество элементов массива n\n");
    scanf_s("%d", &n);



    int* arr = (int*)malloc(n * sizeof(int));



    for (int i = 0; i < n; i++) {
        printf("arr[%i] = ", i);
        scanf_s("%i", &arr[i]);
    }


    printf("\nВведите колличество элементов массива m\n");
    scanf_s("%d", &m);

    int* arr1 = (int*)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        printf("arr1[%i] = ", i);
        scanf_s("%i", &arr1[i]);
    }

    printf("\nНовый массив:\n");

    arr = unite(arr, arr1, n, m);

    for (int i = 0; i < n + m; i++) {
        printf("\n%d", arr[i]);
    }


}


int main()
{
    setlocale(LC_ALL, "Russian");

    int n = 5;

    while (n != 0) {
        printf("\nВведите номер задания\n");
        scanf_s("%d", &n);
    
        switch (n) {
        case 1:
            task07_01();

            break;

        case 2:
            task07_02();
            break;

        case 3:
            task07_03();
            break;

        case 4:
            task07_04();
            break;

        case 5:
            task07_05();
            break;

        case 6:
            task07_06();
            break;
        }
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
