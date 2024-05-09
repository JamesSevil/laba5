#include "plane_system.h"

void create_plane(map<int, vector<string>>& kal) { // создание самолета
    cout << "Введите номер самолета: ";
    int numplane, numtown;
    while (true) {
        cin >> numplane;
        if(cin.fail()) {
            cout << "Ошибка. Нельзя использовать буквы." << endl;
            cin.clear();
            cin.get();
        } else if (kal.find(numplane) != kal.end()) {
            cout << "Номер самолета " << numplane << " уже занят, выберите другой.";
        } else break;
    }
    cout << "Введите число городов: ";
    while (true) {
        cin >> numtown;
        if (cin.fail()) {
            cout << "Ошибка. Нельзя использовать буквы." << endl;
            cin.clear();
            cin.get();
        } else break;
    }
    string towns;
    vector<string> numplanetown(numtown);
    cout << "Название города: ";
    for (string& x : numplanetown) {
        cin >> x;
    }
    kal[numplane] = numplanetown;
}
void planes_for_town(const map<int, vector<string>>& kal, const string& town) { // вывод самолетов, пролетающих город
    cout << "Самолеты летающие через " << town << ":" << endl;
    bool found = false;
    for (auto pair : kal) {
        const vector<string>& towns = pair.second;
        for (string t : towns) {
            if (t == town) {
                cout << "Самолет " << pair.first << endl;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "Нет пролетающих самолетов " << town << endl;
    }
}
void towns_for_plane(const map<int, vector<string>>& kal, int plane) { // вывод городов, которые пролетает самолет
    if (kal.find(plane) != kal.end()) {
        const vector<string>& towns = kal.at(plane);
        cout << "Города, через которые мы пролетели на самолете " << plane << ":" << endl;
        for (string town : towns) {
            cout << town << endl;
            planes_for_town(kal, town);
        }
    } else {
        cout << "Самолеты " << plane << " не был найден." << endl;
    }
}
void planes(const map<int, vector<string>>& kal) { // вывод информации по самолетам
    for (auto pair : kal) {
        int planeNumber = pair.first;
        cout << "Самолет " << planeNumber << " останавливается в этих городах:" << endl;
        const vector<string>& towns = pair.second;
        for (string town : towns) {
            cout << town << endl;
        }
        cout << endl;
    }
}