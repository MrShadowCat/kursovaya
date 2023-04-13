#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct StudentNode
{
    string SurName;
    string Name;
    string middleName;
    string facultet;
    string department;
    string group;
    string recordCardNumber;
    string birthDateString;
    bool pol; // true - Мальчик // false - девочка 
    int startYear;

    void print()
    {
        cout << endl << "Фамилия\t" << "Имя\t" <<  "Группа";
        cout << endl << SurName << "\t" << Name << "\t"  << group;
    }

    void read()
    {
        cout << endl << "Введите фамилию" << endl;
        cin >> SurName;
        cout << "Введите имя" << endl;
        cin >> Name;
        cout << "Введите группу" << endl;
        cin >> group;
    }
};



int main()
{
    setlocale(LC_ALL, "ru");

    string file1 = "База.bin", file2 = "База_коп.bin";

    menu:
    cout << endl<< "\tМеню" << endl << "1.Изменить значения" << endl << "2.Вывести значения" << endl << "3.Закрыть программу" << endl;
    char a=0;
    cin >> a;

    // Модуль меню
    switch (a)
    {
    case '1':
        cin.clear();
        break;

    case '2':
        cin.clear();
        goto output;
        break;

    case '3':
        cin.clear();
        return 0;
        break;
    default:
        cout << endl << "Введены неверные данные" << endl;
        cin.clear();
        goto menu;
        break;
    }

    // Модуль вывода значений
    output:
    fstream baza;
    baza.open(file1, fstream::in | fstream::out | fstream::app);
    if (!baza.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
    }
    else
    {
        short b=0;
        cout << endl << "1.Ввод" << endl << "2.Вывод" << endl;
        cin >> b;

        if (b == 1)
        {
            StudentNode student;
            student.read();
            cin.clear();
        }

        if (b == 2)
        {
            StudentNode student;
            while (baza.read((char*)&student, sizeof(StudentNode)))
            {
                student.print();
            }
            cin.clear();
        }
    }
    baza.close();
    goto menu;
}