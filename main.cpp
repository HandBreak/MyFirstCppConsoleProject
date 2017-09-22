#include <iostream>

using namespace std;

//  Точка входа в программу. Входными аргументами являются:
//  argc    - Количество переданных аргументов через командную строку, где 1-м аргументом является название самой программы
//  **argv  - Указатель на массив строк, содержащий аргументы командной строки

int main(int argc, char **argv) {

    // Поприветствуем Мир
    cout << "Hello, world!" << endl;

    // Сообщим количество полученных аргументов через командную строку
    cout << "Получено аргументов: " << argc << endl;

    // Выведем поочередно сами аргументы командной строки
    for (int i = 0; i < argc; i++) {
        cout << "Аргумент командной строки №" << i << ": " << argv[i] << endl;
    }

    // Завершим программу с кодом ошибки 0
    return 0;
}
