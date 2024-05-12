class Item:
    def __init__(self, name='', quantity=0):
        self.name = name
        self.quantity = quantity

class Sklad:
    def __init__(self):
        self.storage = {}
        self.zones = []

    def add(self, address, name, quantity):
        if address in self.storage:
            if self.storage[address].quantity + quantity <= 10:
                self.storage[address] = Item(name, self.storage[address].quantity + quantity)
            else:
                print("Ошибка, не хватает места для продуктов")
        else:
            print("Такого адреса не существует")

    def remove(self, address, quantity):
        if address in self.storage:
            if self.storage[address].quantity - quantity >= 0:
                self.storage[address].quantity -= quantity
            else:
                print("Нет стольки продуктов для удаления")
        else:
            print("Такого адреса не существует")

    def info(self):
        print("Адресс\tПродукт\tКол-во")
        count_occupied = 0.0
        for address, item in self.storage.items():
            if item.quantity != 0:
                print(f"{address}\t{item.name}\t{item.quantity}")
                count_occupied += 1

        total_count = len(self.storage)
        print("Загруженность склада: {:.2f}%".format((count_occupied / total_count) * 100))

        total_zones = total_count / len(self.zones)
        occupied_zones = [0.0] * len(self.zones)
        print("Загруженность каждой зоны:")
        for i, zone in enumerate(self.zones):
            for address, item in self.storage.items():
                if address[0] == zone and item.quantity > 0:
                    occupied_zones[i] += 1
            print("Зона {}: {:.2f}%".format(zone, (occupied_zones[i] / total_zones) * 100))

        print("Пустые ячейки: ", end='')
        for address, item in self.storage.items():
            if item.quantity == 0:
                print(address, end=' ')
        print()

    def generate_addresses(self):
        zones = ['A', 'B', 'C']
        self.zones = zones
        for zone in zones:
            for shelf in range(1, 6):
                for section in range(1, 6):
                    for rack in range(1, 4):
                        address = f"{zone}{rack}{section}{shelf}"
                        self.storage[address] = Item()

warehouse = Sklad()
warehouse.generate_addresses()

print("Выберите команду: ADD, REMOVE, INFO, EXIT для выхода:")
k = True
while k:
    command = input()
    if command == "ADD":
        address, name, quantity = input().split()
        quantity = int(quantity)
        warehouse.add(address, name, quantity)
    elif command == "REMOVE":
        address, quantity = input().split()
        quantity = int(quantity)
        warehouse.remove(address, quantity)
    elif command == "EXIT":
        print("Выход из программы...")
        k = False
    elif command == "INFO":
        warehouse.info()
    else:
        print("Ошибка команды")