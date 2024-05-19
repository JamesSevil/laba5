#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <windows.h>
#include <algorithm>

using namespace std;

struct item { // �������
    string name;
    int quantity;
};

class sklad { // �����
private:
    map<string, item> storage; // ���������
    vector<char> zonees; // ������ ���
    
public:
    void add(string address, string name, int quantity) { // �-�� ���������� ������
        if (storage.count(address) != 0) { // �������� ���� �� ����� ������
            if (storage[address].name != name && storage[address].name != "") { // ��������, ������ �� ������ ������ ���������
                cout << "������, ������ ������!" << endl;
            } else {
                if (storage[address].quantity + quantity <= 10) { // ��������, ��������� �� ���-�� ��������� ��� ���������� ����� 10
                    storage[address] = {name, storage[address].quantity + quantity};
                } else {
                    cout << "������, �� ������� ����� � ������!" << endl;
                }
            }
        } else { // ���� ��� ������, �� ������
            cout << "������, ��� ����� ������!" << endl;
        }
    }

    void remove(string address, int quantity) { // �-�� �������� ������
        if (storage.count(address) != 0) { // �������� ���� �� ����� ������
            if (storage[address].quantity - quantity == 0) { // ��������, ���� ��� �������� ��������� ����� 0, �� ��������� ������ �� ��������
                storage[address] = {"", 0};
            } else if (storage[address].quantity - quantity > 0) { // ��������, ���� ��� �������� ��������� �� ����� > 0, �� ���������
                storage[address].quantity -= quantity;
            } else { // ���� < 0, �� ��������� �� �������
                cout << "������, �� ������� ��������� ��� ��������!" << endl;
            }
        } else {
            cout << "������, ��� ����� ������!" << endl;
        }
    }

    void info () { // �-�� ������ ����������
        cout << "������\t" << "�������\t" << "���-��" << endl; // ���������� �� ����������� �������
        float countzanyato = 0.0;
        float countzonezanyato;
        for (auto i : storage) {
            if (i.second.quantity != 0) { // ����� �������� �����
                cout << i.first << "\t" << i.second.name << "\t" << i.second.quantity << endl;
                countzanyato++;
            }
        }

        float countvsego = 0.0; // ���������� �� ����� ������������� ������
        cout << "������������� ������: ";
        for (auto i : storage) { // ������� ����� �����
            countvsego++;
        }
        float zagrsklad = (countzanyato/countvsego)*100; // ����������� ������������� ������
        cout << zagrsklad << "%" << endl;

        float countvsegozones = countvsego / zonees.size(); // ���������� �� ����� ������������� ������ ����
        vector<float> countzanyatozones(zonees.size());
        cout << "������������� ������ ����:" << endl;
        for (int i = 0; i < zonees.size(); ++i) {
            for (auto j : storage) {
                if(j.first[0] == zonees[i] && j.second.quantity > 0) { // ������� ������� ����
                    countzanyatozones[i]++;
                }
            }
        }
        float zagrzones;
        for (int i = 0; i < countzanyatozones.size(); ++i) {
            cout << "���� " << zonees[i] << ": ";
            zagrzones = (countzanyatozones[i]/countvsegozones) * 100;
            cout << zagrzones << "%" << endl;
        }

        cout << "������ ������: "; // ���������� �� ������ �������
        for (auto i : storage) {
            if (i.second.quantity == 0) {
                cout << i.first << " ";
            }
        }
        cout << endl;
    }

    void GenerationAddress() { // ��������� ������� ������
        vector<char> zones = {'A', 'B', 'C'};
        zonees = zones;
        for (auto i : zones) {
            for (int polka = 1; polka <= 5; ++polka) { // �������� �� ������ �����
                for (int section = 1; section <= 5; ++section) { // �������� �� ������ ������
                    for (int stelaj = 1; stelaj <= 3; ++stelaj) { // �������� �� ������� �������
                        // ������� �������
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

    warehouse.GenerationAddress(); // ��������� �����(���� A/B/C, 3 �������, 5 ������, 5 �����)

    cout << "�������� �������: ADD, REMOVE, INFO, EXIT ��� ������: "; // ������ � ���������
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
            cout << "����� �� ���������..." << endl;
            k = false;
        } else if (command == "INFO") {
            warehouse.info();
        } else {
            cout << "������ �������" << endl;
        }
    }

    return 0;
}