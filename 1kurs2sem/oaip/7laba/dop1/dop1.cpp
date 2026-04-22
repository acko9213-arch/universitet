#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#define MAX_SIZE 10
using namespace std;

static int countUniversity = 0;

void addUniversityInfo(struct directory university[]);
void showUniversityInfo(struct directory university[], int choice);
void deleteUniversityInfo(struct directory university[]);
void showUniversityInfoByName(struct directory university[]);
void addInfoToFile(struct directory university[]);
void showInfoFromFile(struct directory university[]);

struct directory {
    string nameOfUniversity;
    string adress;
    string specialties[MAX_SIZE];
    int points[MAX_SIZE] = { 0 };
    int cost;
};

void choose(struct directory university[]) {
    while (true) {
        cout << "---   MENU   ---" << endl;
        cout << "1) Добавить информацию вуз: " << endl;
        cout << "2) Показать всю информацию о вузе: " << endl;
        cout << "3) Удалить вуз из списка: " << endl;
        cout << "4) Вывести информацию по названию вуза: " << endl;
        cout << "5) Сохранить справочник в файл: " << endl;
        cout << "6) Вывести текущую информацию из файла: " << endl;
        bool flag = true;
        int choice;
        if (!(cin >> choice)) {
            cout << "Неверный ввод";
            cin.clear();
            cin.ignore(10000, '\n');
            choose(university);
        }
        switch (choice) {
        case 1: {
            addUniversityInfo(university);
            break;
        }
        case 2: {
            if (countUniversity == 0) {
                cout << "Список вузов пуст." << endl;
                break;
            }
            cout << "Информацию о каком университете вы хотите увидеть? " << endl;
            for (int i = 0; i < countUniversity; i++) {
                cout << i + 1 << ") " << university[i].nameOfUniversity << endl;
            }
            int choice; cin >> choice;
            choice -= 1;
            showUniversityInfo(university, choice);
            break;
        }
        case 3: {
            deleteUniversityInfo(university);
            break;
        }
        case 4: {
            showUniversityInfoByName(university);
            break;
        }
        case 5: {
            addInfoToFile(university);
            break;
        }
        case 6: {
            showInfoFromFile(university);
            break;
        }
        default: {
            cout << "Неверный ввод, повторите попытку " << endl;
            flag = false;
            break;
        }
        }
        if (flag) {
            cout << "Хотите продолжить? " << endl;
            cout << "1) Да" << endl;
            cout << "2) Нет" << endl;
            cin >> choice;
            switch (choice) {
            case 1: break;;
            case 2: return;
            default: break;;
            }
        }

    }

}

int main() {
    setlocale(LC_CTYPE, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    struct directory university[MAX_SIZE];
    choose(university);

    return 0;
}


void addUniversityInfo(struct directory university[]) {
    if (countUniversity >= MAX_SIZE) {
        cout << "Достигнут максимальный размер списка." << endl;
        return;
    }
    int k;
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Добавьте название вуза: "; getline(cin, university[countUniversity].nameOfUniversity);
    cout << "Добавьте адресс вуза: "; getline(cin, university[countUniversity].adress);
    cout << "Количество специальностей?: "; cin >> k;
    if (k > MAX_SIZE) k = MAX_SIZE;
    cin.clear();
    cin.ignore(10000, '\n');
    for (int i = 0; i < k; i++) {
        cout << "Добавьте название специальности вуза: ";
        getline(cin, university[countUniversity].specialties[i]);
    }

    for (int i = 0; i < k; i++) {
        cout << "Добавьте прошлогодние проходные баллы вуза: ";
        cin >> university[countUniversity].points[i];
    }
    cout << "Добавьте цену платного обучения в вузе: ";
    cin >> university[countUniversity].cost;

    countUniversity++;
}

void showUniversityInfo(struct directory university[], int choice) {
    cout << "Название: " << university[choice].nameOfUniversity << endl;
    cout << "Адрес: " << university[choice].adress << endl;
    cout << "Специальности: " << endl;
    int specCount = 0;
    for (int i = 0; i < MAX_SIZE && !(university[choice].specialties[i].empty()); i++) {
        cout << "\t" << i + 1 << ") " << university[choice].specialties[i] << endl;
        specCount++;
    }

    cout << "Баллы соответственно: " << endl;
    for (int i = 0; i < specCount; i++) {
        cout << "\t" << i + 1 << ") " << university[choice].points[i] << endl;
    }

    cout << "Цена за платное обучение: " << university[choice].cost << endl;
}

void deleteUniversityInfo(struct directory university[]) {
    if (countUniversity == 0) {
        cout << "Список вузов пуст." << endl;
        return;
    }

    cout << "Выберите вуз для удаления:" << endl;
    for (int i = 0; i < countUniversity; i++) {
        cout << i + 1 << ") " << university[i].nameOfUniversity << endl;
    }

    int choice;
    cout << "Введите номер (1-" << countUniversity << "): ";
    cin >> choice;

    if (choice < 1 || choice > countUniversity) {
        cout << "Неверный номер." << endl;
        return;
    }

    for (int i = choice - 1; i < countUniversity - 1; i++) {
        university[i].nameOfUniversity = university[i + 1].nameOfUniversity;
        university[i].adress = university[i + 1].adress;
        university[i].cost = university[i + 1].cost;

        for (int j = 0; j < MAX_SIZE; j++) {
            university[i].specialties[j] = university[i + 1].specialties[j];
            university[i].points[j] = university[i + 1].points[j];
        }
    }

    university[countUniversity - 1].nameOfUniversity = "";
    university[countUniversity - 1].adress = "";
    university[countUniversity - 1].cost = 0;
    for (int j = 0; j < MAX_SIZE; j++) {
        university[countUniversity - 1].specialties[j] = "";
        university[countUniversity - 1].points[j] = 0;
    }

    countUniversity--;
    cout << "Удалено!\n";
}

void showUniversityInfoByName(struct directory university[]) {
    cin.clear();
    cin.ignore(10000, '\n');
    string buff;
    cout << "Введите название университета: "; getline(cin, buff);
    bool found = false;
    for (int i = 0; i < countUniversity; i++) {
        if (university[i].nameOfUniversity == buff) {
            showUniversityInfo(university, i);
            found = true;
        }
    }
    if (!found) {
        cout << "Университет с таким названием не найден." << endl;
    }
}

void addInfoToFile(struct directory university[]) {
    if (countUniversity == 0) {
        cout << "Нет данных для сохранения." << endl;
        return;
    }

    ofstream file("university.txt");
    if (!file.is_open()) {
        cout << "Не удалось открыть файл для записи." << endl;
        return;
    }

    file << countUniversity << "\n";

    for (int i = 0; i < countUniversity; i++) {
        int specCount = 0;
        for (int j = 0; j < MAX_SIZE && !university[i].specialties[j].empty(); j++) {
            specCount++;
        }

        file << university[i].nameOfUniversity << "\n";
        file << university[i].adress << "\n";
        file << specCount << "\n";

        for (int j = 0; j < specCount; j++) {
            file << university[i].specialties[j] << "\n";
        }
        for (int j = 0; j < specCount; j++) {
            file << university[i].points[j] << "\n";
        }

        file << university[i].cost << "\n";
    }

    file.close();
    cout << "Данные успешно сохранены в файл university.txt" << endl;
}

void showInfoFromFile(struct directory university[]) {
    ifstream file("university.txt");
    if (!file.is_open()) {
        cout << "Файл не найден. Сначала сохраните данные (пункт 5)." << endl;
        return;
    }

    int count;
    file >> count;
    file.ignore(10000, '\n');

    if (count == 0) {
        cout << "Файл пуст." << endl;
        file.close();
        return;
    }

    cout << "=== Данные из файла ===" << endl;

    for (int i = 0; i < count; i++) {
        string name, adress;
        int specCount, cost;

        getline(file, name);
        getline(file, adress);
        file >> specCount;
        file.ignore(10000, '\n');

        string specialties[MAX_SIZE];
        int points[MAX_SIZE] = { 0 };

        for (int j = 0; j < specCount; j++) {
            getline(file, specialties[j]);
        }
        for (int j = 0; j < specCount; j++) {
            file >> points[j];
        }
        file >> cost;
        file.ignore(10000, '\n');

        cout << "\n[" << i + 1 << "] Название: " << name << endl;
        cout << "    Адрес: " << adress << endl;
        cout << "    Специальности:" << endl;
        for (int j = 0; j < specCount; j++) {
            cout << "\t" << j + 1 << ") " << specialties[j]
                << " — баллы: " << points[j] << endl;
        }
        cout << "    Цена платного обучения: " << cost << endl;
    }

    file.close();
}