#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <windows.h>

using namespace std;

struct item { // �������
    string name;
    int quantity;
};
class sklad { // �����
private:
    map<string, item> storage;

public:
    void add(string address, string name, int quantity) { // �-�� ���������� ������
        if (storage.count(address) == 0 && quantity <= 10) {
            storage[address] = {name, quantity};
        } else if (storage[address].quantity + quantity <= 10){
            storage[address] = {name, storage[address].quantity+quantity};
        } else {
            cout << "������" << endl;
        }
    }
    void remove(string address, int quantity) { // �-�� �������� ������
        if (storage.count(address) != 0 && storage[address].quantity - quantity >= 0) {
            storage[address].quantity -= quantity;
        } else {
            cout << "������" << endl;
        }
    }
    void info () { // �-�� ������ ����������
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
        cout << "�������� �������: 1 - ��������, 2 - �������, 3 - ������� ����������, 0 - �����: ";
        cin >> comand;
        switch(comand) {

            case 1:
                cout << "������� ������ ������, �������� �������� � ��� ���-��: ";
                cin >> address >> tovar.name >> tovar.quantity;
                warehouse.add(address, tovar.name, tovar.quantity);
                break;

            case 2:
                cout << "������� ������ ������ � ���-�� ������: ";
                cin >> address >> tovar.quantity;
                warehouse.remove(address, tovar.quantity);
                break;

            case 3:
                warehouse.info();
                break;

            case 0:
                cout << "����� �� ���������..." << endl;
                k = false;
                break;

            default:
                cout << "������� ������� �������." << endl;
                break;

        }
    }

    return 0;
}