import random
import math
import numpy as np
game_matrix = [
    [2, -3],
    [-1, 2]
]
def calculate_variance(data):
    mean = sum(data) / len(data)
    variance = sum((x - mean) ** 2 for x in data) / len(data)
    return math.sqrt(variance)

def win_stat(mass):
    win_a = 0
    win_b = 0
    money_a = 0
    money_b = 0
    money_a_mass = []
    money_b_mass = []
    for i in mass:
        if i == (0, 0) or i == (1,1):
            win_a += 1
            money_a += 2
            money_a_mass.append(2)
            money_b_mass.append(-2)
            money_b -= 2

        else:
            if i == (0, 1):
                money_b += 3
                money_a -= 3
                money_a_mass.append(-3)
                money_b_mass.append(3)
            else:
                money_b += 1
                money_a -= 1
                money_a_mass.append(-1)
                money_b_mass.append(1)
            win_b += 1
    return [win_a, win_b], [money_a, money_b], money_a_mass, money_b_mass


def generate_random_number(p):
    generated_number = random.randint(0,100)
    return 0 if generated_number < p else 1

def test(mass, veroyat, N):
    wins, moneys, money_a_mass, money_b_mass = win_stat(mass)
    middle_moneys_a = moneys[0] / N
    middle_moneys_b = moneys[1] / N
    print(wins, moneys, middle_moneys_a, middle_moneys_b)
    veroyat_mat = len(game_matrix) * len(game_matrix[0])
    mat_waits_on_table = 0
    for i in game_matrix:
        for j in i:
            mat_waits_on_table += j * veroyat_mat
    print(f'Количество выигрышей игрока А: {wins[0]}')
    print(f'Количество денег игрока А: {moneys[0]}')
    print(f'Среднее количество денег игрока А за 1 игру: {middle_moneys_a}')
    print(f'Количество выигрышей игрока B: {wins[1]}')
    print(f'Количество денег игрока B: {moneys[1]}')
    print(f'Среднее количество денег игрока B за 1 игру: {middle_moneys_b}')
    print(f'Математическое ожидание по таблице: {mat_waits_on_table}')

    std_a = calculate_variance(money_a_mass)
    std_b = calculate_variance(money_b_mass)
    print(f'Среднее квадратичное отклонение от экспериментального среднего для А: {std_a}')
    print(f'Среднее квадратичное отклонение от экспериментального среднего для B: {std_b}')
    game_matrix2 = np.array(game_matrix)
    variance = np.sum(veroyat/100 * (game_matrix2 - mat_waits_on_table) ** 2)
    standard_deviation = np.sqrt(variance)
    print(f'Дисперсия: {variance}')
    print(f'Стандартное отклонение: {standard_deviation}')


def main():


#равномерное распределение
    mass = []
    veroyat = 50
    N = 100
    count_1 = 0
    count_0 = 0
    for i in range(N):
        mass.append((generate_random_number(veroyat), generate_random_number(veroyat)))
    print(mass)
    for i in mass:
        for j in i:
            if j == 1:
                count_1 += 1
            else:
                count_0 += 1
    print(count_1, count_0)
    test(mass, veroyat, N)
    print()
#когда первый игрок выбирает числа последовательно а второй выбирает синий столбец в 3 раза чаще
    mass = []
    veroyat = 33
    N = 100
    for i in range(N//2):
        mass.append((0, generate_random_number(veroyat)))
        mass.append((1, generate_random_number(veroyat)))
    test(mass, veroyat, N)


main()
