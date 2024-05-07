#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <windows.h>

using namespace std;

struct item { // продукт
    string name;
    int quantity;
};
class sklad { // склад
private:
    map<string, item> storage;

public:
    void add(string address, string name, int quantity) { // ф-ия добавления товара
        if (storage.count(address) == 0 && quantity <= 10) {
            storage[address] = {name, quantity};
        } else if (storage[address].quantity + quantity <= 10){
            storage[address] = {name, storage[address].quantity+quantity};
        } else {
            cout << "Ошибка" << endl;
        }
    }
    void remove(string address, int quantity) { // ф-ия удаления товара
        if (storage.count(address) != 0 && storage[address].quantity - quantity >= 0) {
            storage[address].quantity -= quantity;
        } else {
            cout << "Ошибка" << endl;
        }
    }
    void info () { // ф-ия вызова информации
        cout << "Address\t" << "Name\t" << "Quantity" << endl;
        for (auto i : storage) {
            cout << i.first << "\t" << i.second.name << "\t" << i.second.quantity << endl;
        }
    }
};

int main(){
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251);

    sklad warehouse;
    item tovar;
    string address;

    bool k = true;
    while (k == true) {
        int comand;
        cout << "Выберите команду: 1 - добавить, 2 - удалить, 3 - вывести информацию, 0 - выйти: ";
        cin >> comand;
        switch(comand) {

            case 1:
                cout << "Введите адресс ячейки, название продукта и его кол-во: ";
                cin >> address >> tovar.name >> tovar.quantity;
                warehouse.add(address, tovar.name, tovar.quantity);
                break;

            case 2:
                cout << "Введите адресс ячейки и кол-во товара: ";
                cin >> address >> tovar.quantity;
                warehouse.remove(address, tovar.quantity);
                break;

            case 3:
                warehouse.info();
                break;

            case 0:
                cout << "Выход из программы..." << endl;
                k = false;
                break;

            default:
                cout << "Команда введена неверно." << endl;
                break;

        }
    }

    return 0;
}