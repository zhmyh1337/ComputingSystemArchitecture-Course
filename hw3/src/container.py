'''
container.py - содержит тип данных, представляющий простейший контейнер
'''

import input_helper
import random
from base_transport import *

# Простейший контейнер на основе одномерного списка
class Container:
    MAX_LENGTH = 10000

    # Инициализация контейнера
    def __init__(self):
        self.len = 0
        self.data = [None] * self.MAX_LENGTH

    # Ввод содержимого контейнера
    def inp(self, file):
        for line in file:
            self.data[self.len] = BaseTransport.create(line)
            self.len += 1

    # Случайный ввод содержимого контейнера
    def inp_rnd(self, file):
        try:
            splitted = file.readline().split()
            count = int(splitted[0])
            seed = int(splitted[0])
            if count < 0 or count > self.MAX_LENGTH:
                raise Exception()
            random.seed(seed)
            self.len = count
            for i in range(count):
                self.data[i] = BaseTransport.create_rnd()
        except Exception:
            input_helper.invalid_input()

    # Вывод в список строк
    def out(self):
        return [str(self.data[i]) for i in range(self.len)]

    # Сортировка контейнера методом Straight Insertion
    def sort(self):
        for i in range(1, self.len):
            key = self.data[i]
            j = i - 1
            while j >= 0 and self.data[j].get_ideal_time() > key.get_ideal_time():
                self.data[j + 1] = self.data[j]
                j = j - 1
            self.data[j + 1] = key
