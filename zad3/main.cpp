#include "plane_system.h"
#include "plane_system.cpp"

int main() {
    setlocale(LC_ALL, "Rus");
    
    cout << "Все команды: CREATE_PLANE, PLANES_FOR_TOWN, TOWNS_FOR_PLANE, PLANES, EXIT" << endl;
    string comand;
    string town;
    string plane;
    map<string, vector<string>> kal;
    
    Type comands;
    
    while (true) {
        cout << "Введите команду: ";
        cin >> comand;

        if (comand == "CREATE_PLANE") comands = Type::CREATE_PLANE;
        else if (comand == "PLANES_FOR_TOWN") comands = Type::PLANES_FOR_TOWN;
        else if (comand == "TOWNS_FOR_PLANE") comands = Type::TOWNS_FOR_PLANE;
        else if (comand == "PLANES") comands = Type::PLANES;
        else if (comand == "EXIT") comands = Type::EXIT;
        else comands = Type::OTHERS;

        if (comands == Type::CREATE_PLANE) {
            create_plane(kal);
        } else if (comands == Type::PLANES) {
            planes(kal);
        } else if (comands == Type::PLANES_FOR_TOWN) {
            cout << "Введите название города: ";
            cin >> town;
            planes_for_town(kal, town);
        } else if (comands == Type::TOWNS_FOR_PLANE) {
            cout << "Введите номер самолета: ";
            cin >> plane;
            towns_for_plane(kal, plane);
        } else if (comands == Type::EXIT) {
            exit(0);
        } else {
            cout << "Неверный ввод" << endl;
        }   
    }

    return 0;
}