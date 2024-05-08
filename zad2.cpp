#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void QueuePeoples(vector<pair<int, int>>& visitors, int numWindows) { // ф-ия формирования очереди
    vector<int> WindowsTimes(numWindows, 0);
    vector<int> WindowsNumbers(numWindows);

    for(int i= 0; i < numWindows; ++i) { // работа с номерами окон
        WindowsNumbers[i] = i + 1;
    }

    for (const auto& people : visitors) {
        
        auto MinWindowIndex = min_element(WindowsTimes.begin(), WindowsTimes.end()) - WindowsTimes.begin(); // находим индекс окна с минимальным временем работы

        cout << ">>> " << "Окно " << WindowsNumbers[MinWindowIndex] << " (" << WindowsTimes[MinWindowIndex] << " минут): "; // вывод информации по очереди
        cout << "T" << people.second;
        WindowsTimes[MinWindowIndex] += people.first; // Увеличиваем время работы окна на время обслуживания посетителя
        cout << endl;
    }
}

int main(){
    setlocale(LC_ALL, "Rus");

    vector<pair<int, int>> Peoples; // вектор пара, в котором будут хранится время и талоны посетителей
    cout << ">>> Введите кол-во рабочих окон:" << endl;
    cout << "<<< ";
    int NumsWindows;
    cin >> NumsWindows;

    cout << ">>> Для получения талона введите: ENQUEUE и время посещения\n\tДля формирования очереди введите: DISTRIBUTE\n\t\tДля выхода введите: EXIT" << endl;
    string command;
    bool k = true; // условие выхода из while
    int time; // время посетителя
    int talon = 100; // талон посетителя
    while (k == true) {
        cout << "<<< ";
        cin >> command;
        if (command == "ENQUEUE") {
            cin >> time;
            talon += 10;
            cout << ">>> T" << talon << endl;
            Peoples.push_back({time, talon});
        } else if (command == "DISTRIBUTE") {
            QueuePeoples(Peoples, NumsWindows); // ф-ия формирования очереди
        } else if (command == "EXIT") {
            cout << ">>> Выход..." << endl;
            k = false;
        } else {
            cout << ">>> Команда введена неверно" << endl;
        }
    }

    return 0;
}