#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;

class ExamsRecords 
{
public:
    string name;
    string markType;
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
        cout << "Введите институт" << endl;
        cin >> facultet;
        cout << "Введите кафедру" << endl;
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

        int i = 0;
        int flagName = 1;
        for (int j = 0; j < 10; j++)
        {
            if (!(flagName == 0))
            {
                cout << "Введите название предмета" << endl;
                cout << "Введите 0 если предметов нет" << endl;
                cin >> examsRecordsData[i][j].name;
                if (examsRecordsData[i][j].name == "0")
                {
                    flagName = 0;
                    for (int i = 0; i < 9; i++)
                    {
                        examsRecordsData[i][j].markType = "0";
                    }
                }
                else
                {
                    int flagMark = 1;
                    for (int i = 0; i < 9; i++)
                    {
                        if (!(flagMark == 0))
                        {
                            cout << "Введите результат экзаменов за  " << i + 1 << " семестр" << endl;
                                cout << "Если оценок нет введите 0" << endl;
                                cin >> examsRecordsData[i][j].markType;
                                if (examsRecordsData[i][j].markType == "0")
                                {
                                    flagMark = 0;
                                }
                        }
                        else
                        {
                            examsRecordsData[i][j].markType = "0";
                        }
                    }
                }
            }
            else
            {
                examsRecordsData[i][j].name = "0";
                for (int i = 0; i < 9; i++)
                {
                    examsRecordsData[i][j].markType = "0";
                }
            }
        }
    }
};

void FCKMagic()
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
        remove("База.bin");
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
            int i = 0;
            for (int j = 0; j < 10; j++)
            {
                baza >> student.examsRecordsData[i][j].name;
                for (int i = 0; i < 9; i++)
                {
                    baza >> student.examsRecordsData[i][j].markType;
                }
            }
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
            for (int p = 0; p < ochko; p++)
            {
                baza >> mass[p].SurName;
                baza >> mass[p].Name;
                baza >> mass[p].middleName;
                baza >> mass[p].facultet;
                baza >> mass[p].department;
                baza >> mass[p].group;
                baza >> mass[p].recordCardNumber;
                baza >> mass[p].birthDateString;
                baza >> mass[p].pol;
                baza >> mass[p].startYear;
                int i = 0;
                for (int j = 0; j < 10; j++)
                {
                    baza >> mass[p].examsRecordsData[i][j].name;
                    for (int i = 0; i < 9; i++)
                    {
                        baza >> mass[p].examsRecordsData[i][j].markType;
                    }
                }
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
                for (int p = 0; p < ochko; p++)
                {
                    if (!((mass[p].SurName == student1.SurName)&&(mass[p].Name == student1.Name)))
                    {
                        baza << endl << mass[p].SurName << endl;
                        baza << mass[p].Name << endl;
                        baza << mass[p].middleName << endl;
                        baza << mass[p].facultet << endl;
                        baza << mass[p].department << endl;
                        baza << mass[p].group << endl;
                        baza << mass[p].recordCardNumber << endl;
                        baza << mass[p].birthDateString << endl;
                        baza << mass[p].pol << endl;
                        baza << mass[p].startYear;
                        int i = 0;
                        for (int j = 0; j < 10; j++)
                        {
                            baza << "\n";
                            baza << mass[p].examsRecordsData[i][j].name;
                            for (int i = 0; i < 9; i++)
                            {
                                baza << "  ";
                                baza << mass[p].examsRecordsData[i][j].markType;
                            }
                        }
                        
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
            int i = 0;
            for (int j = 0; j < 10; j++)
            {
                baza << "\n";
                baza << student.examsRecordsData[i][j].name;
                for (int i = 0; i < 9; i++)
                {
                    baza << "  ";
                    baza << student.examsRecordsData[i][j].markType;
                }
            }
            baza.close();
        }
        if (x == 3)
        {
            baza.close();
            FCKMagic();
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
                int i = 0;
                for (int j = 0; j < 10; j++)
                {
                    baza >> student.examsRecordsData[i][j].name;
                    for (int i = 0; i < 9; i++)
                    {
                        baza >> student.examsRecordsData[i][j].markType;
                    }
                }

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
                int i = 0;
                for (int j = 0; j < 10; j++)
                {
                    baza >> student.examsRecordsData[i][j].name;
                    for (int i = 0; i < 9; i++)
                    {
                        baza >> student.examsRecordsData[i][j].markType;
                    }
                }

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
                    int i = 0;
                    for (int j = 0; j < 10; j++)
                    {
                        if (!(student.examsRecordsData[i][j].name == "0"))
                        {
                            cout << student.examsRecordsData[i][j].name << endl;
                            for (int i = 0; i < 9; i++)
                            {
                                if (!(student.examsRecordsData[i][j].markType == "0"))
                                {
                                    cout << student.examsRecordsData[i][j].markType << "  ";
                                }

                            }
                        }
                    }
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
    system("chcp 1251 > nul");              

    menuGlav();
}