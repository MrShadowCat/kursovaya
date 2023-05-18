#include <iostream>
#include <string>
#include <fstream>


using namespace std;

struct ExamsRecords 
{
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
};

struct Student
{
    StudentNode stud;
    struct Student* next;
};

class ListStudent
{
private:
    struct Student* myHead;
    int countItem = 0;
public:
    ListStudent()
    {
        myHead;
        countItem = 0;
    };
    ~ListStudent()
    {
        struct Student* old = NULL;
        struct Student* current = myHead;
        while (current != NULL) {
            old = current;
            current = current->next;
            delete old;
        }
    };

    void addItem(StudentNode _data)
    {
        struct Student* newItem = new Student();
        newItem->stud = _data;
        if (countItem == 0)
            newItem->next = NULL;
        else
            newItem->next = myHead;
        myHead = newItem;
        countItem++;
    }

    void insertItem(int index, StudentNode _data)
    {
        if (not (index >= 0 and index <= countItem and countItem >= 0))
            return;
        if (index == 0)
            addItem(_data);
        else {
            struct Student* current = myHead;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            struct Student* newItem = new Student();
            newItem->stud = _data;
            newItem->next = current->next;
            current->next = newItem;
            countItem++;
        }
    }

    void push_back(StudentNode _data)
    {
        insertItem(countItem, _data);
    }

    int getCount() 
    {
        return countItem;
    }

    StudentNode getItem(int index) 
    {
        StudentNode _data;
        if (index >= 0 and index < countItem and countItem>0) {
            struct Student* current = myHead;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            _data = current->stud;
        }
        return _data;
    }
};

StudentNode read(int z)
{
    StudentNode st;
    bool adeckvat = false;
    int dd, mm, gggg;
    switch (z)
    {
    case 1:
        adeckvat = false;
        while (adeckvat == false)
        {
            cout << endl << "Введите фамилию" << endl;
            cin >> st.SurName;
            if (st.SurName.length() > 30)
            {
                cout << "Превышение допустимой длины фамилии. Допустимая длина 30 символов. Вы ввели " << st.SurName.length() << " символов" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                for (int i = 0; i < st.SurName.length(); i++)
                {
                    bool gg = true;
                    if (!(((int(st.SurName[i]) + 256 >= 192) && (int(st.SurName[i]) + 256 <= 255)) || (int(st.SurName[i]) + 256 == 168) || (int(st.SurName[i]) + 256 == 184)))
                    {
                        gg = false;
                        cout << "Ошибка. В введённой строке присутствуют символы не из русского алфавита" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        adeckvat = gg;
                        break;
                    }
                    adeckvat = gg;
                }
            }
        }
        return st;
        break;
    case 2:
        adeckvat = false;
        while (adeckvat == false)
        {
            cout << "Введите имя" << endl;
            cin >> st.Name;
            if (st.Name.length() > 30)
            {
                cout << "Превышение допустимой длины имени. Допустимая длина 30 символов. Вы ввели " << st.Name.length() << " символов" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                for (int i = 0; i < st.Name.length(); i++)
                {
                    bool gg = true;
                    if (!(((int(st.Name[i]) + 256 >= 192) && (int(st.Name[i]) + 256 <= 255)) || (int(st.Name[i]) + 256 == 168) || (int(st.Name[i]) + 256 == 184)))
                    {
                        gg = false;
                        cout << "Ошибка. В введённой строке присутствуют символы не из русского алфавита" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        adeckvat = gg;
                        break;
                    }
                    adeckvat = gg;
                }
            }
        }
        return st;
        break;
    case 3:
        adeckvat = false;
        while (adeckvat == false)
        {
            cout << "Введите отчество" << endl;
            cin >> st.middleName;
            if (st.middleName.length() > 30)
            {
                cout << "Превышение допустимой длины отчества. Допустимая длина 30 символов. Вы ввели " << st.middleName.length() << " символов" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                for (int i = 0; i < st.middleName.length(); i++)
                {
                    bool gg = true;
                    if (!(((int(st.middleName[i]) + 256 >= 192) && (int(st.middleName[i]) + 256 <= 255)) || (int(st.middleName[i]) + 256 == 168) || (int(st.middleName[i]) + 256 == 184)))
                    {
                        gg = false;
                        cout << "Ошибка. В введённой строке присутствуют символы не из русского алфавита" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        adeckvat = gg;
                        break;
                    }
                    adeckvat = gg;
                }
            }
        }
        return st;
        break;
    case 4:
        getline(cin, st.facultet);
        adeckvat = false;
        while (adeckvat == false)
        {
            cout << "Введите институт" << endl;
            getline(cin, st.facultet);
            if (st.facultet.length() > 50)
            {
                cout << "Превышение допустимой длины института. Допустимая длина 50 символов. Вы ввели " << st.facultet.length() << " символов" << endl;
                cin.clear();
            }
            else
            {
                for (int i = 0; i < st.facultet.length(); i++)
                {
                    bool gg = true;
                    if (!(((int(st.facultet[i]) + 256 >= 192) && (int(st.facultet[i]) + 256 <= 255)) || (int(st.facultet[i]) + 256 == 168) || (int(st.facultet[i]) + 256 == 184) || (int(st.facultet[i]) == 32)))
                    {
                        gg = false;
                        cout << "Ошибка. В введённой строке присутствуют символы не из русского алфавита" << endl;
                        cin.clear();
                        adeckvat = gg;
                        break;
                    }
                    adeckvat = gg;
                }
            }
        }
        return st;
        break;
    case 5:
        adeckvat = false;
        while (adeckvat == false)
        {
            cout << "Введите кафедру" << endl;
            cin >> st.department;
            if (st.department.length() > 10)
            {
                cout << "Превышение допустимой длины кафедры. Допустимая длина 10 символов. Вы ввели " << st.department.length() << " символов" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                adeckvat = true;
            }
        }
        return st;
        break;
    case 6:
        adeckvat = false;
        while (adeckvat == false)
        {
            cout << "Введите группу" << endl;
            cin >> st.group;
            if (st.group.length() > 10)
            {
                cout << "Превышение допустимой длины группы. Допустимая длина 10 символов. Вы ввели " << st.group.length() << " символов" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                adeckvat = true;
            }
        }
        return st;
        break;
    case 7:
        adeckvat = false;
        while (adeckvat == false)
        {
            cout << "Введите номер студенческого билета" << endl;
            cin >> st.recordCardNumber;
            if (st.recordCardNumber.length() > 10)
            {
                cout << "Превышение допустимой длины номера студенческого билета. Допустимая длина 10 символов. Вы ввели " << st.recordCardNumber.length() << " символов" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                adeckvat = true;
            }
        }
        return st;
        break;
    case 8:
        cout << "Введите дату рождения (ДД.ММ.ГГГГ)" << endl;
        adeckvat = false;
        while (adeckvat == false)
        {
            cout << "ДД: " << endl;
            cin >> dd;
            if (!((dd > 0) && (dd < 32)))
            {
                cout << "Ошибка. Допустимые значения 1-31" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                adeckvat = true;
            }
        }
        adeckvat = false;
        while (adeckvat == false)
        {
            cout << "ММ: " << endl;
            cin >> mm;
            if (!((mm > 0) && (mm < 13)))
            {
                cout << "Ошибка. Допустимые значения 1-12" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                adeckvat = true;
            }
        }
        adeckvat = false;
        while (adeckvat == false)
        {
            cout << "ГГГГ: " << endl;
            cin >> gggg;
            if (!((gggg > 1989) && (gggg < 2006)))
            {
                cout << "Ошибка. Допустимые значения 1990-2005" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                adeckvat = true;
            }
        }
        st.birthDateString = to_string(dd) + "." + to_string(mm) + "." + to_string(gggg);
        cout << st.birthDateString << endl;
        return st;
        break;
    case 9:
        adeckvat = false;
        while (adeckvat == false)
        {
            cout << "Введите пол: М или Ж" << endl;
            cin >> st.pol;
            if (!((st.pol == "ж") || (st.pol == "Ж") || (st.pol == "м") || (st.pol == "М")))
            {
                cout << "Ошибка. Вы ввели " << st.pol << " Допустимые значения М или Ж." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                adeckvat = true;
            }
        }
        return st;
        break;
    case 10:
        adeckvat = false;
        while (adeckvat == false)
        {
            cout << "Введите год поступления" << endl;
            cin >> st.startYear;
            for (int i = 0; i < st.startYear.length(); i++)
            {
                if (int(st.startYear[i]) < 48 || int(st.startYear[i]) > 58)
                {
                    cout << "Ошибка в строке присутствуют знаки отличные от цифр" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                else
                {
                    if ((st.startYear < "1990") || (st.startYear > "2022"))
                    {
                        cout << "Ошибка. Выход из допустимого диапазона (1990-2022)" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    else
                    {
                        adeckvat = true;
                    }
                }
            }
        }
        return st;
        break;
    case 11:
        getline(cin, st.examsRecordsData[0][0].name);
        adeckvat = false;
        while (adeckvat == false)
        {
            cout << "Введите название предмета" << endl;
            cout << "Введите 0 если предметов нет" << endl;
            getline(cin, st.examsRecordsData[0][0].name);
            if (st.examsRecordsData[0][0].name.length() > 31)
            {
                cout << "Превышение допустимой длины предмета. Допустимая длина 30 символов. Вы ввели " << st.examsRecordsData[0][0].name.length() << " символов" << endl;
                cin.clear();
            }
            else
            {
                for (int i = 0; i < st.examsRecordsData[i][0].name.length(); i++)
                {
                    bool gg = true;
                    if (!(((int(st.examsRecordsData[i][0].name[i]) + 256 >= 192) && (int(st.examsRecordsData[i][0].name[i]) + 256 <= 255)) || (int(st.examsRecordsData[i][0].name[i]) + 256 == 168) || (int(st.examsRecordsData[i][0].name[i]) + 256 == 184) || (st.examsRecordsData[i][0].name == "0") || (int(st.examsRecordsData[i][0].name[i]) == 32)))
                    {
                        gg = false;
                        cout << "Ошибка. В введённой строке присутствуют символы не из русского алфавита" << endl;
                        cin.clear();
                        adeckvat = gg;
                        break;
                    }
                    adeckvat = gg;
                }
            }
        }
        if (st.examsRecordsData[0][0].name == "0")
        {
            for (int i = 0; i < 9; i++)
            {
                st.examsRecordsData[i][0].markType = "0";
            }
        }
        return st;
        break;
    case 12:
        adeckvat = false;
        while (adeckvat == false)
        {
            cout << "Введите результат экзаменов за семестр" << endl;
            cout << "Если оценок нет введите 0" << endl;
            cin >> st.examsRecordsData[0][0].markType;
            if (st.examsRecordsData[0][0].markType == "0")
            {
                adeckvat = true;
            }
            else
            {
                if ((st.examsRecordsData[0][0].markType == "2") || (st.examsRecordsData[0][0].markType == "3") || (st.examsRecordsData[0][0].markType == "4") || (st.examsRecordsData[0][0].markType == "5"))
                {
                    adeckvat = true;
                }
                else
                {
                    if ((st.examsRecordsData[0][0].markType == "Зачёт") || (st.examsRecordsData[0][0].markType == "зачёт") || (st.examsRecordsData[0][0].markType == "Зачет") || (st.examsRecordsData[0][0].markType == "зачет"))
                    {
                        adeckvat = true;
                    }
                    else
                    {
                        if ((st.examsRecordsData[0][0].markType == "Незачёт") || (st.examsRecordsData[0][0].markType == "незачёт") || (st.examsRecordsData[0][0].markType == "Незачет") || (st.examsRecordsData[0][0].markType == "незачет"))
                        {
                            adeckvat = true;
                        }
                        else
                        {
                            cout << "Ошибка. Допустимые значения: 2, 3, 4, 5, Зачёт, Незачёт." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                }
            }
        }
        return st;
        break;
    default:
        int i = 0;
        int flagName = 1;
        for (int j = 0; j < 10; j++)
        {
            if (!(flagName == 0))
            {
                getline(cin, st.examsRecordsData[0][j].name);
                adeckvat = false;
                while (adeckvat == false)
                {
                    cout << "Введите название предмета" << endl;
                    cout << "Введите 0 если предметов нет" << endl;
                    getline(cin, st.examsRecordsData[i][j].name);
                    if (st.examsRecordsData[i][j].name.length() > 31)
                    {
                        cout << "Превышение допустимой длины предмета. Допустимая длина 30 символов. Вы ввели " << st.examsRecordsData[i][j].name.length() << " символов" << endl;
                        cin.clear();
                    }
                    else
                    {
                        for (int i = 0; i < st.examsRecordsData[i][j].name.length(); i++)
                        {
                            bool gg = true;
                            if (!(((int(st.examsRecordsData[i][j].name[i]) + 256 >= 192) && (int(st.examsRecordsData[i][j].name[i]) + 256 <= 255)) || (int(st.examsRecordsData[i][j].name[i]) + 256 == 168) || (int(st.examsRecordsData[i][j].name[i]) + 256 == 184) || (st.examsRecordsData[i][j].name == "0") || (int(st.examsRecordsData[i][j].name[i]) == 32)))
                            {
                                gg = false;
                                cout << "Ошибка. В введённой строке присутствуют символы не из русского алфавита" << endl;
                                cin.clear();
                                adeckvat = gg;
                                break;
                            }
                            adeckvat = gg;
                        }
                    }
                }
                if (st.examsRecordsData[i][j].name == "0")
                {
                    flagName = 0;
                    for (int i = 0; i < 9; i++)
                    {
                        st.examsRecordsData[i][j].markType = "0";
                    }
                }
                else
                {
                    int flagMark = 1;
                    for (int i = 0; i < 9; i++)
                    {
                        if (!(flagMark == 0))
                        {
                            adeckvat = false;
                            while (adeckvat == false)
                            {
                                cout << "Введите результат экзаменов за  " << i + 1 << " семестр" << endl;
                                cout << "Если оценок нет введите 0" << endl;
                                cin >> st.examsRecordsData[i][j].markType;
                                if (st.examsRecordsData[i][j].markType == "0")
                                {
                                    adeckvat = true;
                                }
                                else
                                {
                                    if ((st.examsRecordsData[i][j].markType == "2") || (st.examsRecordsData[i][j].markType == "3") || (st.examsRecordsData[i][j].markType == "4") || (st.examsRecordsData[i][j].markType == "5"))
                                    {
                                        adeckvat = true;
                                    }
                                    else
                                    {
                                        if ((st.examsRecordsData[i][j].markType == "Зачёт") || (st.examsRecordsData[i][j].markType == "зачёт") || (st.examsRecordsData[i][j].markType == "Зачет") || (st.examsRecordsData[i][j].markType == "зачет"))
                                        {
                                            adeckvat = true;
                                        }
                                        else
                                        {
                                            if ((st.examsRecordsData[i][j].markType == "Незачёт") || (st.examsRecordsData[i][j].markType == "незачёт") || (st.examsRecordsData[i][j].markType == "Незачет") || (st.examsRecordsData[i][j].markType == "незачет"))
                                            {
                                                adeckvat = true;
                                            }
                                            else
                                            {
                                                cout << "Ошибка. Допустимые значения: 2, 3, 4, 5, Зачёт, Незачёт." << endl;
                                                cin.clear();
                                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            }
                                        }
                                    }
                                }
                            }
                            if (st.examsRecordsData[i][j].markType == "0")
                            {
                                flagMark = 0;
                            }
                        }
                        else
                        {
                            st.examsRecordsData[i][j].markType = "0";
                        }
                    }
                }
            }
            else
            {
                st.examsRecordsData[i][j].name = "0";
                for (int i = 0; i < 9; i++)
                {
                    st.examsRecordsData[i][j].markType = "0";
                }
            }
        }
        return st;
    }
}

void MagicX2_1(int z)
{
    system("cls");
    string surname, name, ExamName;
    int t, q=0;
    StudentNode student, prob;
    ListStudent* st = new ListStudent;
    cout << "Введите Фамилию и Имя студента, данные которого хотите изменить." << endl;
    prob = read(1);
    surname = prob.SurName;
    prob = read(2);
    name = prob.Name;
    string file1 = "База.bin";
    fstream baza(file1, fstream::binary | fstream::in | fstream::out | fstream::app);
    while (!baza.eof())
    {
        baza >> prob.SurName;
        baza >> prob.Name;
        baza >> prob.middleName;
        getline(baza,prob.facultet);
        getline(baza, prob.facultet);
        baza >> prob.department;
        baza >> prob.group;
        baza >> prob.recordCardNumber;
        baza >> prob.birthDateString;
        baza >> prob.pol;
        baza >> prob.startYear;
        int i = 0;
        for (int j = 0; j < 10; j++)
        {
            getline(baza, prob.examsRecordsData[i][j].name);
            getline(baza,prob.examsRecordsData[i][j].name);
            for (int i = 0; i < 9; i++)
            {
                baza >> prob.examsRecordsData[i][j].markType;
            }
        }
        st->push_back(prob);
    }
    baza.close();
    remove("База.bin"); 
    if (z == 11)
    {
        cout << "Введите название предмета, которое вы хотите изменить" << endl;
        getline(cin, ExamName);
        getline(cin, ExamName);
    }
    if (z == 12)
    {
        cout << "Введите название предмета, которое вы хотите изменить" << endl;
        getline(cin, ExamName);
        getline(cin, ExamName);
        cout << "Введите семестр, оценку которого вы хотите изменить" << endl;
        cin >> q;
    }
    prob = read(z);
    t = st->getCount();
    for (int i = 0; i < t; i++)
    {
        student = st->getItem(i);
        if ((student.SurName == surname)&&(student.Name == name))
        {
            switch (z)
            {
            case 1:
                student.SurName = prob.SurName;
                break;
            case 2:
                student.Name = prob.Name;
                break;
            case 3:
                student.middleName = prob.middleName;
                break;
            case 4:
                student.facultet = prob.facultet;
                break;
            case 5:
                student.department = prob.department;
                break;
            case 6:
                student.group = prob.group;
                break;
            case 7:
                student.recordCardNumber = prob.recordCardNumber;
                break;
            case 8:
                student.birthDateString = prob.birthDateString;
                break;
            case 9:
                student.pol = prob.pol;
                break;
            case 10:
                student.startYear = prob.startYear;
                break;
            case 11:
                for (int j = 0; j < 10; j++)
                {
                    if (student.examsRecordsData[0][j].name == ExamName)
                    {
                        student.examsRecordsData[0][j].name = prob.examsRecordsData[0][0].name;
                    }
                }
                break;
            case 12:
                for (int j = 0; j < 10; j++)
                {
                    if (student.examsRecordsData[0][j].name == ExamName)
                    {
                        student.examsRecordsData[q-1][j].markType = prob.examsRecordsData[0][0].markType;
                    }
                }
                break;
            default:
                break;
            }
        }
        fstream baza(file1, fstream::binary | fstream::in | fstream::out | fstream::app);
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
        int p = 0;
        for (int j = 0; j < 10; j++)
        {
            baza << "\n";
            baza << student.examsRecordsData[p][j].name << endl;
            for (int p = 0; p < 9; p++)
            {
                baza << "  ";
                baza << student.examsRecordsData[p][j].markType;
            }
        }
        baza.close();
    }
}

void MagicX2()
{
    int x = -1;
    string oshibka;
    while (!(x == 13))
    {
        x = -1;
        system("cls");

        cout << "1.Изменить фамилию " << endl;
        cout << "2.Изменить имя " << endl;
        cout << "3.Изменить отчество " << endl;
        cout << "4.Изменить институт " << endl;
        cout << "5.Изменить кафедру " << endl;
        cout << "6.Изменить группу " << endl;
        cout << "7.Изменить номер студенческого билета " << endl;
        cout << "8.Изменить дату рождения " << endl;
        cout << "9.Изменить пол " << endl;
        cout << "10.Изменить дату поступления " << endl;
        cout << "11.Изменить название предмета " << endl;
        cout << "12.Изменить оценку за экзамен " << endl;
        cout << "13.Назад " << oshibka << endl;

        cin >> x;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (x == 13)
        {
            system("cls");
        }
        else
        {
            if ((x<13)&&(x>0))
            {
                MagicX2_1(x);
            }
            else
            {
                oshibka = "\nОшибка. Введены неверные данные. Допустимые значения 1-13 ";
            }
        }
    }
}

void MagicX3()
{
    string file1 = "База.bin";
    cout << "Введите Фамилию и Имя студента, данные которого хотите удалить." << endl;
    cout << "Если хотите удалить данные всех студентов введите <Все>" << endl;
    string surname, name;
    int t;
    StudentNode student, prob;
    ListStudent* st = new ListStudent;
    prob = read(1);
    surname = prob.SurName;
    if ((surname == "все") || (surname == "Все") || (surname == "ВСЕ"))
    {
        remove("База.bin");
    }
    else
    {
        prob = read(2);
        name = prob.Name;
        fstream baza(file1, fstream::binary | fstream::in | fstream::out | fstream::app);
        while (!baza.eof())
        {
            baza >> prob.SurName;
            baza >> prob.Name;
            baza >> prob.middleName;
            getline(baza, prob.facultet);
            getline(baza, prob.facultet);
            baza >> prob.department;
            baza >> prob.group;
            baza >> prob.recordCardNumber;
            baza >> prob.birthDateString;
            baza >> prob.pol;
            baza >> prob.startYear;
            int i = 0;
            for (int j = 0; j < 10; j++)
            {
                getline(baza, prob.examsRecordsData[i][j].name);
                getline(baza, prob.examsRecordsData[i][j].name);
                for (int i = 0; i < 9; i++)
                {
                    baza >> prob.examsRecordsData[i][j].markType;
                }
            }
            st->push_back(prob);
        }
        baza.close();
        remove("База.bin");
        t = st->getCount();
        for (int i = 0; i < t; i++)
        {
            student = st->getItem(i);
            if (!((student.SurName == surname)&&(student.Name == name)))
            {
                fstream baza(file1, fstream::binary | fstream::in | fstream::out | fstream::app);
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
                int p = 0;
                for (int j = 0; j < 10; j++)
                {
                    baza << "\n";
                    baza << student.examsRecordsData[p][j].name << endl;
                    for (int p = 0; p < 9; p++)
                    {
                        baza << "  ";
                        baza << student.examsRecordsData[p][j].markType;
                    }
                }
                baza.close();
            }
        }
    }
}

void var73()
{
    system("cls");
    ListStudent* megaxarosh = new ListStudent;
    ListStudent* xarosh = new ListStudent;
    ListStudent* normas = new ListStudent;
    string file1 = "База.bin";
    int t, mark;
    StudentNode student, prob;
    fstream baza(file1, fstream::binary | fstream::in | fstream::out | fstream::app);
    while (!baza.eof())
    {
        mark = 0;
        baza >> prob.SurName;
        baza >> prob.Name;
        baza >> prob.middleName;
        getline(baza, prob.facultet);
        getline(baza, prob.facultet);
        baza >> prob.department;
        baza >> prob.group;
        baza >> prob.recordCardNumber;
        baza >> prob.birthDateString;
        baza >> prob.pol;
        baza >> prob.startYear;
        int i = 0;
        for (int j = 0; j < 10; j++)
        {
            getline(baza, prob.examsRecordsData[i][j].name);
            getline(baza, prob.examsRecordsData[i][j].name);
            for (int i = 0; i < 9; i++)
            {
                baza >> prob.examsRecordsData[i][j].markType;
                if ((prob.examsRecordsData[i][j].markType == "2") || (prob.examsRecordsData[i][j].markType == "3") || (prob.examsRecordsData[i][j].markType == "незачёт") || (prob.examsRecordsData[i][j].markType == "Незачёт") || (prob.examsRecordsData[i][j].markType == "Незачет") || (prob.examsRecordsData[i][j].markType == "незачет"))
                {
                    mark = 3;
                }
                else
                {
                    if (!(mark==3) && (prob.examsRecordsData[i][j].markType == "4"))
                    {
                        mark = 4;
                    }
                    else
                    {
                        if (!(mark == 4) && !(mark == 3) && !(prob.examsRecordsData[i][j].markType == "0"))
                        {
                            mark = 5;
                        }
                    }
                }
            }
        }
        if (mark == 5)
        {
            megaxarosh->push_back(prob);
        }
        if (mark == 4)
        {
            xarosh->push_back(prob);
        }
        if (mark == 3)
        {
            normas->push_back(prob);
        }
    }
    baza.close();
    string len, god1, god2, god;
    cout << "Введите интервал годов рождения через пробел" << endl;
    cin >> god1;
    cin >> god2;
    t = megaxarosh->getCount();
    string* mass = new string[t];
    for (int i = 0; i < t; i++)
    {
        prob = megaxarosh->getItem(i);
        mass[i] = prob.SurName;
    }
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t-1; j++)
        {
            if (mass[j] > mass[j+1])
            {
                len = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = len;
            }
        }
    }
    cout << "\nОтличники: " << endl;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            prob = megaxarosh->getItem(j);
            if (mass[i] == prob.SurName)
            {
                god = prob.birthDateString[prob.birthDateString.length() - 4];
                god = god + prob.birthDateString[prob.birthDateString.length() - 3];
                god = god + prob.birthDateString[prob.birthDateString.length() - 2];
                god = god + prob.birthDateString[prob.birthDateString.length() - 1];
                if ((god >= god1) && (god <= god2))
                {
                    cout << endl;
                    cout << prob.SurName << "  ";
                    cout << prob.Name << "  ";
                    cout << prob.middleName << "  ";
                    cout << prob.group << "  " << endl;
                }
                break;
            }
        }
    }
    delete[] mass;
    t = xarosh->getCount();
    string* mass1 = new string[t];
    for (int i = 0; i < t; i++)
    {
        prob = xarosh->getItem(i);
        mass1[i] = prob.SurName;
    }
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t - 1; j++)
        {
            if (mass1[j] > mass1[j + 1])
            {
                len = mass1[j];
                mass1[j] = mass1[j + 1];
                mass1[j + 1] = len;
            }
        }
    }
    cout << "\nХорошисты: " << endl;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            prob = xarosh->getItem(j);
            if (mass1[i] == prob.SurName)
            {
                god = prob.birthDateString[prob.birthDateString.length() - 4];
                god = god + prob.birthDateString[prob.birthDateString.length() - 3];
                god = god + prob.birthDateString[prob.birthDateString.length() - 2];
                god = god + prob.birthDateString[prob.birthDateString.length() - 1];
                if ((god >= god1) && (god <= god2))
                {
                    cout << endl;
                    cout << prob.SurName << "  ";
                    cout << prob.Name << "  ";
                    cout << prob.middleName << "  ";
                    cout << prob.group << "  " << endl;
                }
                break;
            }
        }
    }
    delete[] mass1;
    t = normas->getCount();
    string* mass2 = new string[t];
    for (int i = 0; i < t; i++)
    {
        prob = normas->getItem(i);
        mass2[i] = prob.SurName;
    }
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t - 1; j++)
        {
            if (mass2[j] > mass2[j + 1])
            {
                len = mass2[j];
                mass2[j] = mass2[j + 1];
                mass2[j + 1] = len;
            }
        }
    }
    cout << "\nТроечники: " << endl;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            prob = normas->getItem(j);
            if (mass2[i] == prob.SurName)
            {
                god = prob.birthDateString[prob.birthDateString.length() - 4];
                god = god + prob.birthDateString[prob.birthDateString.length() - 3];
                god = god + prob.birthDateString[prob.birthDateString.length() - 2];
                god = god + prob.birthDateString[prob.birthDateString.length() - 1];
                if ((god >= god1) && (god <= god2))
                {
                    cout << endl;
                    cout << prob.SurName << "  ";
                    cout << prob.Name << "  ";
                    cout << prob.middleName << "  ";
                    cout << prob.group << "  " << endl;
                }
                break;
            }
        }
    }
    delete[] mass2;
}

void doSomeMagic(int x, int y)
{
    system("cls");
    string file1 = "База.bin";
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
            student1 = read(1);
            student.SurName = student1.SurName;
            student1 = read(2);
            student.Name = student1.Name;
            student1 = read(3);
            student.middleName = student1.middleName;
            student1 = read(4);
            student.facultet = student1.facultet;
            student1 = read(5);
            student.department = student1.department;
            student1 = read(6);
            student.group = student1.group;
            student1 = read(7);
            student.recordCardNumber = student1.recordCardNumber;
            student1 = read(8);
            student.birthDateString = student1.birthDateString;
            student1 = read(9);
            student.pol = student1.pol;
            student1 = read(10);
            student.startYear = student1.startYear;
            student1 = read(0);
            int i = 0;
            for (int j = 0; j < 10; j++)
            {
                student.examsRecordsData[i][j].name = student1.examsRecordsData[i][j].name;
                for (int i = 0; i < 9; i++)
                {
                    student.examsRecordsData[i][j].markType = student1.examsRecordsData[i][j].markType;
                }
            }
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
            i = 0;
            for (int j = 0; j < 10; j++)
            {
                baza << "\n";
                baza << student.examsRecordsData[i][j].name << endl;
                for (int i = 0; i < 9; i++)
                {
                    baza << "  ";
                    baza << student.examsRecordsData[i][j].markType;
                }
            }
            baza.close();
        }
        if (x == 2)
        {
            baza.close();
            MagicX2();
        }
        if (x == 3)
        {
            baza.close();
            MagicX3();
        }
        if (y == 1)
        {
            while (!baza.eof())
            {
                baza >> student.SurName;
                baza >> student.Name;
                baza >> student.middleName;
                getline(baza, student.facultet);
                getline(baza,student.facultet);
                baza >> student.department;
                baza >> student.group;
                baza >> student.recordCardNumber;
                baza >> student.birthDateString;
                baza >> student.pol;
                baza >> student.startYear;
                int i = 0;
                for (int j = 0; j < 10; j++)
                {
                    getline(baza, student.examsRecordsData[i][j].name);
                    getline(baza,student.examsRecordsData[i][j].name);
                    for (int i = 0; i < 9; i++)
                    {
                        baza >> student.examsRecordsData[i][j].markType;
                    }
                }
                cout << "Фамилия: " << " ";
                cout << student.SurName << "  ";
                cout << "Имя: " << " ";
                cout << student.Name << "  ";
                cout << "Отчество: " << " ";
                cout << student.middleName << "  ";
                cout << "Группа: " << " ";
                cout << student.group << "  " << endl;
            }
            baza.close();
        }
        if (y == 2)
        {
            cout << "Введите фамилию и имя студента, информацию которого хотите увидеть:" << endl;
            cin >> student1.SurName;
            cin >> student1.Name;
            cout << endl;
            while (!baza.eof())
            {
                baza >> student.SurName;
                baza >> student.Name;
                baza >> student.middleName;
                getline(baza, student.facultet);
                getline(baza, student.facultet);
                baza >> student.department;
                baza >> student.group;
                baza >> student.recordCardNumber;
                baza >> student.birthDateString;
                baza >> student.pol;
                baza >> student.startYear;
                int i = 0;
                for (int j = 0; j < 10; j++)
                {
                    getline(baza, student.examsRecordsData[i][j].name);
                    getline(baza, student.examsRecordsData[i][j].name);
                    for (int i = 0; i < 9; i++)
                    {
                        baza >> student.examsRecordsData[i][j].markType;
                    }
                }

                if ((student.SurName == student1.SurName)&&(student.Name == student1.Name))
                {
                    cout << "Фамилия: " << " ";
                    cout << student.SurName << "  ";
                    cout << "Имя: " << " ";
                    cout << student.Name << "  ";
                    cout << "Отчество: " << " ";
                    cout << student.middleName << endl;
                    cout << "Институт: " << " ";
                    cout << student.facultet << endl;
                    cout << "Кафедра: " << " ";
                    cout << student.department << endl;
                    cout << "Группа: " << " ";
                    cout << student.group << endl;
                    cout << "Номер студенческого билета: " << " ";
                    cout << student.recordCardNumber << endl;
                    cout << "Дата рождения: " << " ";
                    cout << student.birthDateString << endl;
                    cout << "Пол: " << " ";
                    cout << student.pol << endl;
                    cout << "Год поступления: " << " ";
                    cout << student.startYear << endl;
                    int i = 0;
                    for (int j = 0; j < 10; j++)
                    {
                        if (!(student.examsRecordsData[i][j].name == "0"))
                        {
                            cout << "Предмет: " << " ";
                            cout << student.examsRecordsData[i][j].name << endl;
                            for (int i = 0; i < 9; i++)
                            {
                                if (!(student.examsRecordsData[i][j].markType == "0"))
                                {
                                    cout << "Семестр" << i+1 <<": " << " ";
                                    cout << student.examsRecordsData[i][j].markType << "  ";
                                }
                            }
                            cout << endl;
                        }
                    }
                }
            }
            baza.close();
        }
        if (y == 3)
        {
            baza.close();
            var73();
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
        case 2:
            system("cls");
            doSomeMagic(a, 0);
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
        cout << "3.Вывести индивидуальное задание" << endl;
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
        case 3:
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

void Crypt()
{
    srand(time(NULL));
    char* pass = new char[64];
    for (int i = 0; i < 64; ++i) {
        switch (rand() % 3) {
        case 0:
            pass[i] = rand() % 10 + '0';
            break;
        case 1:
            pass[i] = rand() % 26 + 'A';
            break;
        case 2:
            pass[i] = rand() % 26 + 'a';
        }
    }
    string command = "OpenSSL\\bin\\openssl.exe enc -aes-256-cbc -salt -in База.bin -out База.bin.enc -pass pass:";
    command = command + pass;
    system(command.c_str());
    if (remove("База.bin") != 0) 
    {
        cout << "[ERROR] - deleting file" << endl;
    }
    ofstream file;
    file.open("key.txt", ios::binary);
    file << pass;
    file.close();
    command = "OpenSSL\\bin\\openssl.exe rsautl -encrypt -inkey rsa.public -pubin -in key.txt -out key.txt.enc";
    system(command.c_str());
    if (remove("key.txt") != 0) 
    {
        cout << "[ERROR] - deleting file" << endl;
    }
}

void Decrypt()
{
    string command = "OpenSSL\\bin\\openssl.exe rsautl -decrypt -inkey rsa.private -in key.txt.enc -out key.txt";
    system(command.c_str());
    if (remove("key.txt.enc") != 0) 
    {
        cout << "[ERROR] - deleting file" << endl;
    }
    char* pass = new char[64];
    ifstream file;
    file.open("key.txt", ios::binary);
    file >> pass;
    file.close();
    if (remove("key.txt") != 0) 
    {
        cout << "[ERROR] - deleting file" << endl;
    }
    command = "OpenSSL\\bin\\openssl.exe enc -aes-256-cbc -d -in База.bin.enc -out База.bin -pass pass:";
    command = command + pass;
    system(command.c_str());
    if (remove("База.bin.enc") != 0) 
    {
        cout << "[ERROR] - deleting file" << endl;
    }
}

int main()
{
    system("chcp 1251 > nul");
    Decrypt();
    menuGlav();
    Crypt();
}
