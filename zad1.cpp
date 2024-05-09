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
    void add(string address, string name, int quantity) { // ф-ия добавления товара
        if (storage.count(address) != 0) {
            if (storage[address].quantity + quantity <= 10) {
                storage[address] = {name, storage[address].quantity + quantity};
            } else {
                cout << "Ошибка, не хватает места для продуктов" << endl;
            }
        } else {
            cout << "Такого адреса не существует" << endl;
        }
    }
    void remove(string address, int quantity) { // ф-ия удаления товара
        if (storage.count(address) != 0) {
            if (storage[address].quantity - quantity >= 0) {
                storage[address].quantity -= quantity; 
            } else {
                cout << "Нет стольки продуктов для удаления" << endl;
            }
        } else {
            cout << "Такого адреса не существует" << endl;
        }
    }
    void info () { // ф-ия вызова информации
        cout << "Адресс\t" << "Продукт\t" << "Кол-во" << endl; // информация по загруженным ячейкам
        float countzanyato = 0.0;
        float countzonezanyato;
        for (auto i : storage) {
            if (i.second.quantity != 0) {
                cout << i.first << "\t" << i.second.name << "\t" << i.second.quantity << endl;
                countzanyato++;
            }
        }

        float countvsego = 0.0; // информация по общей загруженности склада
        cout << "Загруженность склада: ";
        for (auto i : storage) {
            countvsego++;
        }
        float zagrsklad = (countzanyato/countvsego)*100;
        cout << zagrsklad << "%" << endl;

        float countvsegozones = countvsego / zonees.size(); // Информация по общей загруженности каждой зоны
        vector<float> countzanyatozones(zonees.size());
        cout << "Загруженность каждой зоны:" << endl;
        for (int i = 0; i < zonees.size(); ++i) {
            for (auto j : storage) {
                if(j.first[0] == zonees[i] && j.second.quantity > 0) {
                    countzanyatozones[i]++;
                }
            }
        }
        float zagrzones;
        for (int i = 0; i < countzanyatozones.size(); ++i) {
            cout << "Зона " << zonees[i] << ": ";
            zagrzones = (countzanyatozones[i]/countvsegozones) * 100;
            cout << zagrzones << "%" << endl;
        }

        cout << "Пустые ячейки: "; // информация по пустым ячейкам
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
                        // Создаем адресса
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

    cout << "Выберите команду: ADD, REMOVE, INFO, EXIT для выхода: "; // работа с командами
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
            cout << "Выход из программы..." << endl;
            k = false;
        } else if (command == "INFO") {
            warehouse.info();
        } else {
            cout << "Ошибка команды" << endl;
        }
    }

    return 0;
}