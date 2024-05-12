def queue_peoples(visitors, num_windows):
    windows_times = [0] * num_windows
    windows_numbers = list(range(1, num_windows + 1))

    for people in visitors:
        min_window_index = windows_times.index(min(windows_times))
        print(f">>> Окно {windows_numbers[min_window_index]} ({windows_times[min_window_index]} минут): T{people[1]}")
        windows_times[min_window_index] += people[0]
        

peoples = []
print(">>> Введите кол-во рабочих окон:")
num_windows = int(input("<<< "))

print(">>> Для получения талона введите: ENQUEUE и время посещения\n\tДля формирования очереди введите: DISTRIBUTE\n\t\tДля выхода введите: EXIT")
k = True
talon = 100
while k:
    command = input("<<< ")
    if command == "ENQUEUE":
        time = int(input())
        talon += 10
        print(f">>> T{talon}")
        peoples.append((time, talon))
    elif command == "DISTRIBUTE":
        queue_peoples(peoples, num_windows)
    elif command == "EXIT":
        print(">>> Выход...")
        k = False
    else:
        print(">>> Команда введена неверно")