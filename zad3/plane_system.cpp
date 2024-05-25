#include "plane_system.h"

void create_plane(map<string, vector<string>>& kal) { // создание самолета
    cout << "Введите название самолета: ";
    int numtown;
    string plane;
    while (true) {
        cin >> plane;
        if (kal.find(plane) != kal.end()) {
            cout << "Номер самолета " << plane << " уже занят, выберите другой.";
        } else break;
    }
    cout << "Введите число городов: ";
    while (true) {
        cin >> numtown;
        if (numtown < 2) {
            cout << "Ошибка! Минимум 2 города для ввода." << endl;
            cin.clear();
            cin.get();
        } else if (cin.fail()) {
            cout << "Ошибка. Нельзя использовать буквы." << endl;
            cin.clear();
            cin.get();
        } else break;
    }
    // ввод городов
    string town;
    vector<string> numplanetown;
    bool check = false;
    int iter = 0;
    while (true) {
        if (iter == numtown) {
            break;
        }
        cout << "Введите город: ";
        cin >> town;
        check = false;
        for (auto elem : numplanetown) {
            if (elem == town) {
                check = true;
                break;
            }
        }
        if (check) {
            cout << "Ошибка, город повторяется!" << endl;
        } else {
            numplanetown.push_back(town);
            iter++;
        }
    }
    kal[plane] = numplanetown;
}
void planes_for_town(const map<string, vector<string>>& kal, const string& town) { // вывод самолетов, пролетающих город
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
void towns_for_plane(const map<string, vector<string>>& kal, string plane) { // вывод городов, которые пролетает самолет
    if (kal.find(plane) != kal.end()) {
        const vector<string>& towns = kal.at(plane);
        cout << "Города, через которые мы пролетели на самолете " << plane << ":" << endl;
        for (string town : towns) {
            cout << town << endl;
            cout << "Самолеты летающие через " << town << ":" << endl; //
            bool found = false;
            for (auto pair : kal) {
                const vector<string>& towns = pair.second;
                for (string t : towns) {
                    if (t == town) {
                        if (pair.first != plane) {
                            cout << "Самолет " << pair.first << endl;
                            found = true;
                            break;
                        }
                    }
                }
            }
            if (!found) {
                cout << "Нет пролетающих самолетов " << town << endl;
            }
        }
    } else {
        cout << "Самолеты " << plane << " не был найден." << endl;
    }
}
void planes(const map<string, vector<string>>& kal) { // вывод информации по самолетам
    for (auto pair : kal) {
        string plane = pair.first;
        cout << "Самолет " << plane << " останавливается в этих городах:" << endl;
        const vector<string>& towns = pair.second;
        for (string town : towns) {
            cout << town << endl;
        }
        cout << endl;
    }
}