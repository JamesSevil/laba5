#include "plane_system.h"
#include "plane_system.cpp"

int main() {
    setlocale(LC_ALL, "Rus");
    
    cout << "Все команды: CREATE_PLANE, PLANES_FOR_TOWN, TOWNS_FOR_PLANE, PLANES, EXIT" << endl;
    string comands;
    string town;
    int plane;
    map<int, vector<string>> kal;

    while (true) {
        cout << "Введите команду: ";
        cin >> comands;
        if (comands == "CREATE_PLANE") {
            create_plane(kal);
        } else if (comands == "PLANES") {
            planes(kal);
        } else if (comands == "PLANES_FOR_TOWN") {
            cout << "Введите название города: ";
            cin >> town;
            planes_for_town(kal, town);
        } else if (comands == "TOWNS_FOR_PLANE") {
            cout << "Введите номер самолета: ";
            cin >> plane;
            towns_for_plane(kal, plane);
        } else if (comands == "EXIT") {
            exit(0);
        } else {
            cout << "Неверный ввод" << endl;
        }   
    }

    return 0;
}