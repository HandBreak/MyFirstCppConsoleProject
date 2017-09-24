#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print (string word);
void print (float word);
void print (string word, float a);
float devide (float del, float div);
inline float multiplex (float mux1, float mux2);

//  Точка входа в программу. Входными аргументами являются:
//  argc    - Количество переданных аргументов через командную строку, где 1-м аргументом является название самой программы
//  **argv  - Указатель на массив строк, содержащий аргументы командной строки

int main(int argc, char **argv) {

    // Поприветствуем Мир
    cout << "Hello, world!" << endl;

    // Сообщим количество полученных аргументов через командную строку
    cout << "Input arguments: " << argc << endl;

    // Выведем поочередно сами аргументы командной строки
    for (int i = 0; i < argc; i++) {
        cout << "Command line argument N" << i << ": " << argv[i] << endl;
    }

    // Запросим номер аргумента командной строки, который необходимо отобразить
    int i;
    cout << "Input argument number for print: ";
    cin >> i;
    if (i >= argc) {
        cout << "Error!  Inputed argument number too big." << endl;
        return 1;
    }
    cout << "Argument N" << i << " have value: " << argv[i] << endl;
    
    // Создадим одномерный массив целых чисел
    int iarray[5] = {11, 37, 54, 7, 1};
    
    // Создадим двухмерный массив дробных числе
    float farray[3][2] = {{23.52,1.275}, {7.1,5.9993}, {4.3,9.0}};
    
    // Отобразим элементы массивов
    cout << iarray[2] << endl;
    cout << farray[0][1] << endl;
    
    // Выполним вывод последовательности чисел в цикле for
    cout << " for loop: \n";
    for (float z = 1000; z >= 10; z /= 2) {
        cout << z << endl;
    }
    // Выполним вывод последовательности чисел через цикл while (Исполняется только если условие выполняется)
    cout << " while loop: \n";
    int y = 7;
    while (y > 0){
        y--;
        cout << y << endl;
    }
    
    // Выполним вывод последовательности чисел через цикл do while (Первый раз исполняется в любом случае)
    cout << " do - while loop: \n";
    int j = 5;
    do {
        j--;
        cout << j << endl;
    } while (j > 5);
    cout << "j=" << j << endl;
    
    // Попробуем использовать тип данных "СТРОКА", для этого надо подключить библиотеку string.  Странно, но работает и без неё !!!
    string newText = "Hello Dolly!";
    string nexText = " Let's Go!";
    cout << newText + nexText << endl;
    
    // Попробуем использовать "ВЕКТОР". Это подобие массива, но его можно дополнять
    vector <float> vect(10, 255);                               // Создаём вектор из 10 дробных чисел, установленных равными 255
    vect.insert(vect.begin(), iarray, iarray+3);                // Копируем в его начала три элемента массива iarray
    vect.insert(vect.begin(), 3.14159);                         // Затем вставляем в начала дробное число (остальные элементы смещаются и вектор растёт совокупно на 4 элемента
    cout << vect.at(2) << endl;                                 // Выводим значение второго элемента в векторе (отсчет с 0) = 37 (до этой операции был равен 54)
    cout << vect.front() << endl;                               // Выводим значение первого элемента вектора (после предыдущей вставки = 3.14159)
    cout << vect.back() << endl;                                // Выводим значение последнего элемента вектора (остался равным 255 после инициализации)
    cout << vect.size() << endl;                                // Выводим результирующую размерность вектора (была 10, стала 14)
   
    // Попробуем использовать созданную нами ранее функцию "print"
    print( "My function is work!" );
    float res = devide(5,2);
    print(res);
    // Или запишем всё в кучу
    print(devide(7,4));
    // Выведем значение с текстом
    print( "5 : 2 =", devide(5,2) );
    
    // Вычислим размеры типов переменных
    print( "Type 'short    int'(byte): ", sizeof(short int) );
    print( "Type '         int'(byte): ", sizeof(int) );
    print( "Type 'unsigned int'(byte): ", sizeof(unsigned int) );
    print( "Type 'long     int'(byte): ", sizeof(long int) );
    print( "Type 'float'       (byte): ", sizeof(float) );
    print( "Type 'double'      (byte): ", sizeof(double) );
    print( "Type 'char'        (byte): ", sizeof(char) );
    print( "Type 'bool'        (byte): ", sizeof(bool) );
    
    // Перечисляемые константы
    enum color {RED, GREEN, BLUE, YELLOW, WHITE, BLACK = 100, MAGENTA};
    cout << RED << GREEN << BLUE << YELLOW << WHITE << BLACK << MAGENTA << endl;
    
    // Старый метод (C) определения константы
    #define maximusAge 13;
    int maxBirthday = 2017 - maximusAge;
    cout << maxBirthday << endl;
    
    // Вывод остатка от деления. Выведет остаток от деления 12 / 10 = 1 и 2 в остатке
    cout << 12%10 << endl;
    
    // Варианты операций
    i = j = 1 + 1;
    int inc_v1 = i++;
    cout << inc_v1 << endl;
    int inc_v2 = ++i;
    cout << inc_v2 << endl;
    cout << inc_v1 * inc_v2 << endl;
    inc_v1 += 2; // (inc_v1 = inc_v1 + 2)
    inc_v2 /= 3; // (inc_v2 = inc_v2 / 3)
    
    // Проверка деления нацело
    if ((inc_v1 % inc_v2) == 0) // Без остатка ?
        print("without");
    else
        print("with");
    
    // Встраиваемая функция (inline)
    cout << multiplex(5, 5) << endl;
     
    // Ессть даже цикл goto !!!
    int count = 0;
    prnloop:
        cout << "Counter=" << count << endl;
        count++;
        if (count < 11) goto prnloop;
        
    // whitle loop with break & continue
    int a, b, c = 0;
    cout << "Input a: ";
    cin >> a;
    cout << "Input b: ";
    cin >> b;
    while (c < 64) {
        c++;
        if (a > b) {
            cout << "a > b - Exit !!!" << endl;
            break;
        }
        if (a == b) {
            cout << "Inputed a = b" << endl;
            b--;
            continue;
        }
        a++;
        cout << "a=" << a << " , b=" << b << endl;
    }
    
    // Цикл for в одну строку
    for (int j = 0; j < 10; cout << "j=" << j++ << endl);

    // Логические операторы:
    // && = AND(И)   выражение1 && выражение2
    // || = OR (ИЛИ) выражение1 || выражение2
    // !  = NOT(НЕ) !выражение
    
    
    // Завершим программу с кодом ошибки 0
    return 0;
}

/* Конец основного тела программы
 * начало области функций
 * упражняемся с созданием новых функций
 */

// Создадим свою функцию 'print'
void print (string word) {
    cout << word << endl;
}

// Воспользуемся перегрузкой функции и сделаем вариант для печати 'float' значения
void print (float word) {   
    cout << word << endl;
}

// И до кучи с двумя параметрами
void print (string word, float a) {
    cout << word << " " << a << endl;
}


// Создадим функцию деления 'devide'
float devide (float del, float div) {
    if (div == 0)
        return 0;
    else
        return del / div;
}

// Создадим встраиваемую функцию умножения 'multiplex' будет встраиваться в каждой точке вызова  - замена #define из C
inline float multiplex (float mux1, float mux2) {
    return mux1 * mux2;
}
