#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;

struct ExamsRecords {
    string name;
    list <string> markType = { "Fail", "Pass", "5", "4", "3", "2" };
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
    string startYear;
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

void FCKDRM()
{
    StudentNode student1, student;
    string file1 = "База.bin";
    fstream baza(file1, fstream::binary | fstream::in | fstream::out | fstream::app);
    cout << "Введите Фамилию и Имя студента, данные которого хотите удалить." << endl;
    cout << "Если хотите удалить данные всех студентов введите <Все>" << endl;
    cin >> student1.SurName;

    if ((student1.SurName == "все") || (student1.SurName == "Все") || (student1.SurName == "ВСЕ"))
    {
        baza.close();
        ofstream baza;
        baza.open(file1, ofstream::out);
        baza.close();
    }
    else
    {
        cin >> student1.Name;
        int ochko = 0;
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
            ochko = ochko + 1;
        }
        StudentNode* mass = new StudentNode[ochko];
        baza.close();
        fstream baza(file1, fstream::binary | fstream::in | fstream::out | fstream::app);
        if (!(baza.is_open()))
        {
            cout << "Ошибка открытия файла" << endl;
        }
        else
        {
            for (int i = 0; i < ochko; i++)
            {
                baza >> mass[i].SurName;
                baza >> mass[i].Name;
                baza >> mass[i].middleName;
                baza >> mass[i].facultet;
                baza >> mass[i].department;
                baza >> mass[i].group;
                baza >> mass[i].recordCardNumber;
                baza >> mass[i].birthDateString;
                baza >> mass[i].pol;
                baza >> mass[i].startYear;
            }
            baza.close();
            remove("База.bin");
            fstream baza(file1, fstream::binary | fstream::in | fstream::out | fstream::app);
            if (!(baza.is_open()))
            {
                cout << "Ошибка открытия файла" << endl;
            }
            else
            {
                for (int i = 0; i < ochko; i++)
                {
                    if (!((mass[i].SurName == student1.SurName)&&(mass[i].Name == student1.Name)))
                    {
                        baza << endl << mass[i].SurName << endl;
                        baza << mass[i].Name << endl;
                        baza << mass[i].middleName << endl;
                        baza << mass[i].facultet << endl;
                        baza << mass[i].department << endl;
                        baza << mass[i].group << endl;
                        baza << mass[i].recordCardNumber << endl;
                        baza << mass[i].birthDateString << endl;
                        baza << mass[i].pol << endl;
                        baza << mass[i].startYear;
                        
                    }
                }
                baza.close();
            }
        }
        delete[] mass;
    }
}

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
        StudentNode student, student1;
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
            baza.close();
        }
        if (x == 3)
        {
            baza.close();
            FCKDRM();
        }
        if (y == 1)
        {
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

                cout << student.SurName << "  ";
                cout << student.Name << "  ";
                cout << student.middleName << "  ";
                cout << student.group << "  " << endl;
            }
            baza.close();
        }
        if (y == 2)
        {
            cout << "Введите фамилию и имя сдудента, информацию которого хотите увидеть:" << endl;
            cin >> student1.SurName;
            cin >> student1.Name;
            cout << endl;
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

                if ((student.SurName == student1.SurName)&&(student.Name == student1.Name))
                {
                    cout << student.SurName << "  ";
                    cout << student.Name << "  ";
                    cout << student.middleName << endl;
                    cout << student.facultet << endl;
                    cout << student.department << endl;
                    cout << student.group << endl;
                    cout << student.recordCardNumber << endl;
                    cout << student.birthDateString << endl;
                    cout << student.pol << endl;
                    cout << student.startYear << endl;
                    break;
                }
            }
            baza.close();
        }
    }
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
        case 3:
            system("cls");
            doSomeMagic(a, 0);
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
            doSomeMagic(0, a);
            break;
        case 2:
            system("cls");
            doSomeMagic(0, a);
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