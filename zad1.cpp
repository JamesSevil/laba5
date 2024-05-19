#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <windows.h>
#include <algorithm>

using namespace std;

struct item { // продукт
    string name;
    int quantity;
};

class sklad { // склад
private:
    map<string, item> storage; // хранилище
    vector<char> zonees; // список зон
    
public:
    void add(string address, string name, int quantity) { // ф-и€ добавлени€ товара
        if (storage.count(address) != 0) { // проверка есть ли така€ €чейка
            if (storage[address].name != name && storage[address].name != "") { // проверка, зан€ты ли €чейка другим продуктом
                cout << "ќшибка, €чейка зан€та!" << endl;
            } else {
                if (storage[address].quantity + quantity <= 10) { // проверка, превышает ли кол-во продуктов при добавлении число 10
                    storage[address] = {name, storage[address].quantity + quantity};
                } else {
                    cout << "ќшибка, не хватает места в €чейке!" << endl;
                }
            }
        } else { // если нет €чейки, то ошибка
            cout << "ќшибка, нет такой €чейки!" << endl;
        }
    }

    void remove(string address, int quantity) { // ф-и€ удалени€ товара
        if (storage.count(address) != 0) { // проверка есть ли така€ €чейка
            if (storage[address].quantity - quantity == 0) { // проверка, если при удалении продуктов стало 0, то освободим €чейку от продукта
                storage[address] = {"", 0};
            } else if (storage[address].quantity - quantity > 0) { // проверка, если при удалении продуктов их будет > 0, то выполн€ем
                storage[address].quantity -= quantity;
            } else { // если < 0, то продуктов не хватает
                cout << "ќшибка, не хватает продуктов дл€ удалени€!" << endl;
            }
        } else {
            cout << "ќшибка, нет такой €чейки!" << endl;
        }
    }

    void info () { // ф-и€ вызова информации
        cout << "јдресс\t" << "ѕродукт\t" << " ол-во" << endl; // информаци€ по загруженным €чейкам
        float countzanyato = 0.0;
        float countzonezanyato;
        for (auto i : storage) {
            if (i.second.quantity != 0) { // вывод непустых €чеек
                cout << i.first << "\t" << i.second.name << "\t" << i.second.quantity << endl;
                countzanyato++;
            }
        }

        float countvsego = 0.0; // информаци€ по общей загруженности склада
        cout << "«агруженность склада: ";
        for (auto i : storage) { // считаем всего €чеек
            countvsego++;
        }
        float zagrsklad = (countzanyato/countvsego)*100; // высчитываем загруженность склада
        cout << zagrsklad << "%" << endl;

        float countvsegozones = countvsego / zonees.size(); // »нформаци€ по общей загруженности каждой зоны
        vector<float> countzanyatozones(zonees.size());
        cout << "«агруженность каждой зоны:" << endl;
        for (int i = 0; i < zonees.size(); ++i) {
            for (auto j : storage) {
                if(j.first[0] == zonees[i] && j.second.quantity > 0) { // считаем зан€тые зоны
                    countzanyatozones[i]++;
                }
            }
        }
        float zagrzones;
        for (int i = 0; i < countzanyatozones.size(); ++i) {
            cout << "«она " << zonees[i] << ": ";
            zagrzones = (countzanyatozones[i]/countvsegozones) * 100;
            cout << zagrzones << "%" << endl;
        }

        cout << "ѕустые €чейки: "; // информаци€ по пустым €чейкам
        for (auto i : storage) {
            if (i.second.quantity == 0) {
                cout << i.first << " ";
            }
        }
        cout << endl;
    }

    void GenerationAddress() { // формируем адресса склада
        vector<char> zones = {'A', 'B', 'C'};
        zonees = zones;
        for (auto i : zones) {
            for (int polka = 1; polka <= 5; ++polka) { // проходим по каждой полке
                for (int section = 1; section <= 5; ++section) { // проходим по каждой секции
                    for (int stelaj = 1; stelaj <= 3; ++stelaj) { // проходим по каждому стелажу
                        // —оздаем адресса
                        stringstream s;
                        s << i << stelaj << section << polka;
                        storage[s.str()] = {"", 0};
                        
                    }
                }
            }
        }
    }
};

int main(){
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251);

    sklad warehouse;
    item tovar;
    string address;

    warehouse.GenerationAddress(); // формируем склад(зоны A/B/C, 3 стелажа, 5 секций, 5 полок)

    cout << "¬ыберите команду: ADD, REMOVE, INFO, EXIT дл€ выхода: "; // работа с командами
    string command;
    bool k = true;
    while (k == true) {
        cin >> command;
        if (command == "ADD") {
            cin >> address >> tovar.name >> tovar.quantity;
            warehouse.add(address, tovar.name, tovar.quantity);
        } else if (command == "REMOVE") {
            cin >> address >> tovar.quantity;
            warehouse.remove(address, tovar.quantity);
        } else if (command == "EXIT") {
            cout << "¬ыход из программы..." << endl;
            k = false;
        } else if (command == "INFO") {
            warehouse.info();
        } else {
            cout << "ќшибка команды" << endl;
        }
    }

    return 0;
}