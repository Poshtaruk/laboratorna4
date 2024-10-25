#include <iostream>
#include <string>
#include <windows.h> 
using namespace std;

struct Zodiak {
    string surnameName;
    string zodiakSign;
    int birthDate[3];
};

void sortByYear(Zodiak zodiacs[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (zodiacs[i].birthDate[2] > zodiacs[j].birthDate[2]) {
                Zodiak temp = zodiacs[i];
                zodiacs[i] = zodiacs[j];
                zodiacs[j] = temp;
            }
        }
    }
}

void findPersonBySurname(Zodiak zodiacs[], int size, const string& surname) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (zodiacs[i].surnameName.find(surname) != string::npos) {
            cout << "Прізвище та ім’я: " << zodiacs[i].surnameName
                << ", Знак Зодіаку: " << zodiacs[i].zodiakSign
                << ", Дата народження: " << zodiacs[i].birthDate[0] << "."
                << zodiacs[i].birthDate[1] << "." << zodiacs[i].birthDate[2] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Запис з прізвищем '" << surname << "' не знайдено.\n";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int size = 3;
    Zodiak zodiacs[size];

    for (int i = 0; i < size; i++) {
        cout << "Введіть дані для людини " << i + 1 << ":\n";
        cout << "Прізвище та ім’я: ";
        cin.ignore();
        getline(cin, zodiacs[i].surnameName);
        cout << "Знак Зодіаку: ";
        getline(cin, zodiacs[i].zodiakSign);
        cout << "Дата народження (день, місяць, рік): ";
        cin >> zodiacs[i].birthDate[0] >> zodiacs[i].birthDate[1] >> zodiacs[i].birthDate[2];
        cout << endl;
    }

    sortByYear(zodiacs, size);

    cout << "\nВідсортований список за роком народження:\n";
    for (int i = 0; i < size; i++) {
        cout << "Прізвище та ім’я: " << zodiacs[i].surnameName
            << ", Знак Зодіаку: " << zodiacs[i].zodiakSign
            << ", Дата народження: " << zodiacs[i].birthDate[0] << "."
            << zodiacs[i].birthDate[1] << "." << zodiacs[i].birthDate[2] << endl;
    }

    string searchSurname;
    cout << "\nВведіть прізвище для пошуку: ";
    cin.ignore();
    getline(cin, searchSurname);
    findPersonBySurname(zodiacs, size, searchSurname);

    return 0;
}