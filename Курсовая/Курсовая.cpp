#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;

struct ExamsRecords {
    string name;
    list <string> markType = { "Fail", "Pass", "5", "4", "3", "2" };
    bool isEmpty;
};

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
    string pol;
    int startYear;
    ExamsRecords examsRecordsData[9][10];

    void read()
    {
        system("cls");
        cout << endl << "Введите фамилию" << endl;
        cin >> SurName;
        cout << "Введите имя" << endl;
        cin >> Name;
        cout << "Введите отчество" << endl;
        cin >> middleName;
        cout << "Введите факультет" << endl;
        cin >> facultet;
        cout << "Введите департамент" << endl;
        cin >> department;
        cout << "Введите группу" << endl;
        cin >> group;
        cout << "Введите номер студенческого билета" << endl;
        cin >> recordCardNumber;
        cout << "Введите дату рождения" << endl;
        cin >> birthDateString;
        cout << "Введите пол: М или Ж" << endl;
        cin >> pol;
        cout << "Введите дату поступления" << endl;
        cin >> startYear;
    }
};

void doSomeMagic(int x, int y)
{
    system("cls");
    string file1 = "База.bin", file2 = "База_коп.bin";
    fstream baza(file1, fstream::binary | fstream::in | fstream::out | fstream::app);
    if (!(baza.is_open()))
    {
        cout << "Ошибка открытия файла" << endl;
    }
    else
    {
        baza.imbue(locale(".1251"));
        StudentNode student;
        if (x == 1)
        {
            student.read();
            baza << endl << student.SurName << endl;
            baza << student.Name << endl;
            baza << student.middleName << endl;
            baza << student.facultet << endl;
            baza << student.department << endl;
            baza << student.group << endl;
            baza << student.recordCardNumber << endl;
            baza << student.birthDateString << endl;
            baza << student.pol << endl;
            baza << student.startYear;
        }
        if (y == 1)                                   //Вывод(дописать)
        {
            /*
            int size = 10;                            //Размер изменить
            StudentNode *mass = new StudentNode[size];  
            delete[] mass;
            */
            while (!baza.eof())
            {
                baza >> student.SurName;
                baza >> student.Name;
                baza >> student.middleName;
                baza >> student.facultet;
                baza >> student.department;
                baza >> student.group;
                baza >> student.recordCardNumber;
                baza >> student.birthDateString;
                baza >> student.pol;
                baza >> student.startYear;

                cout << student.SurName << endl;
                cout << student.Name << endl;
                cout << student.middleName << endl;
                cout << student.group << endl << endl;
            }
        }
    }
    baza.close();
}

void menuinput()
{
    int a = 0;
    string falsee;
    while (!(a == 4))
    {
        system("cls");
        a = 0;
        cout << endl;
        cout << "1.Ввести данные о студенте" << endl;
        cout << "2.Изменить данные о студенте" << endl;
        cout << "3.Удалить данные о студенте" << endl;
        cout << "4.Назад" << falsee << endl;
        falsee = "";
        cin >> a;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (a)
        {
        case 1:
            system("cls");
            doSomeMagic(a,0);
            break;

        case 4:
            system("cls");
            break;

        default:
            system("cls");
            falsee = "\nОшибка, допустимые значения 1, 2, 3, 4";
            break;
        }
    }
}

void menuoutput()
{
    int a = 0;
    string falsee;
    while (!(a == 4))
    {
        a = 0;
        cout << endl;
        cout << "1.Вывести краткие данные о студентах" << endl;
        cout << "2.Вывести полные данные о студенте" << endl;
        cout << "3.Вывести вариант 73" << endl;
        cout << "4.Назад" << falsee << endl;
        falsee = "";
        cin >> a;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (a)
        {
        case 1:
            system("cls");
            doSomeMagic(0,a);
            break;
        case 4:
            system("cls");
            break;
        default:
            system("cls");
            falsee = "\nОшибка, допустимые значения 1, 2, 3, 4";
            break;
        }
    }
}

void menuGlav()
{
    int a = 0;
    string falsee;
    while (!(a==3))
    {
        cout << endl << "\tМеню" << endl;
        cout << "1.Изменить значения" << endl;
        cout << "2.Вывести значения" << endl;
        cout << "3.Закрыть программу" << falsee << endl;
        falsee = "";
        cin >> a;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (a)
        {

        case 1:
            system("cls");
            menuinput();
            break;

        case 2:
            system("cls");
            menuoutput();
            break;

        case 3:
            system("cls");
            break;
        default:
            system("cls");
            falsee = "\nОшибка, допустимые значения 1, 2, 3";
            break;
        }
    }
}


int main()
{
    system("chcp 1251 > nul");              //&БАННЫЙ РОТ ЭТОГО КАЗИНО, БЛ@ТЬ!!!

    menuGlav();
}