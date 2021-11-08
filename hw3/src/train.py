'''
train.py - содержит описание поезда
'''

from base_transport import *

# Поезд
class Train(BaseTransport):
    # Инициализация
    def __init__(self, speed, distance, cars_count):
        super().__init__(speed, distance)
        self.cars_count = cars_count

    # Конвертация в строку
    def __str__(self):
        return super().__str__() + f', cars_count = {self.cars_count}'
