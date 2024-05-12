#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    vector<pair<int, string>> schedule;

    int N;
    cout << "Введите число N: ";
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string operation;
        cout << "Введите операцию: ";
        cin >> operation;

        if (operation == "CLASS") {
            string discipline;
            int day;
            cout << "Введите номер дня и название предмета: ";
            cin >> day >> discipline;
            schedule.push_back(make_pair(day, discipline)); // Добавляем занятие в расписание
        } else if (operation == "NEXT") {
            // Переносим пары на предпоследний день текущего месяца при смене месяца
            for (auto& cls : schedule) {
                if (cls.first == 28 || cls.first == 29 || cls.first == 30 || cls.first == 31) {
                    cls.first = 27;
                } else {
                    ++cls.first;
                }
            }
            cout << "Переход на следующий месяц выполнен." << endl;
        } else if (operation == "VIEW") {
            int day;
            cout << "Введите номер дня: ";
            cin >> day;

            // Используем алгоритм find_if для поиска первого занятия на указанный день
            auto it = find_if(schedule.begin(), schedule.end(), [day](const pair<int, string>& cls) {
                return cls.first == day;
            });

            cout << "В " << day << " день ";
            if (it != schedule.end()) { // Если занятия нашлись на указанный день
                cout << "1 занятие в университете: " << it->second;
                ++it;
                while (it != schedule.end() && it->first == day) { // Выводим все занятия на этот день
                    cout << ", " << it->second;
                    ++it;
                }
            } else {
                cout << "У нас свободный день!" << endl; // Если занятий нет на указанный день
            }
        }
    }
}