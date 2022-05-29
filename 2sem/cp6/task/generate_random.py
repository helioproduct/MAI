from random import choice, randint

male_surnames = ['Петров', 'Иванов', 'Терешков', 'Попов', 'Дремков']
letters = 'КЕНЕНГЗХФВАПРОЛДЖЭЯЧСМИТ'


def generate_random_line(marks_amount):
    surname = choice(male_surnames)
    initials = choice(letters) + choice(letters)

    gender = choice(('M', 'F'))
    if gender == 'F':
        surname += 'а'
    
    institute = str(randint(1, 12))
    group_number = str(randint(101, 120))
    year = str(randint(10, 21))
    group = 'М' + institute + 'О' + '-' + group_number + '-' + year + choice(('Б', 'М'))
    marks = [randint(2, 5) for _ in range(marks_amount)]
    result = surname + ' ' + initials + ' ' + gender + ' ' + group
    
    for i in range(len(marks)):
        result += ' ' + str(marks[i])
    
    return result


def generate_text_db(file, lines_amount):
    file = open(file, 'w')
    
    for _ in range(lines_amount):
        file.write(generate_random_line(4) + '\n')

    file.close()


if __name__ == '__main__':
    file = input('Введите путь до файла: ')
    n = int(input('Введите кол-во строк: '))
    generate_text_db(file, n)