schedule = []
    
N = int(input("Введите число N: "))
    
for _ in range(N):
    operation = input("Введите операцию: ")
        
    if operation == "CLASS":
        day, discipline = input("Введите номер дня и название предмета: ").split()
        day = int(day)
        schedule.append((day, discipline))
    elif operation == "NEXT":
        schedule = [(27 if 28 <= day <= 31 else day + 1, discipline) for day, discipline in schedule]
        print("Переход на следующий месяц выполнен.")
    elif operation == "VIEW":
        day = int(input("Введите номер дня: "))
        classes = [discipline for d, discipline in schedule if d == day]
            
        if classes:
            print(f"В {day} день занятия в университете: {', '.join(classes)}")
        else:
            print("У нас свободный день!")