'''
plane.py - содержит описание самолета
'''

from base_transport import *

# Самолет
class Plane(BaseTransport):
    # Инициализация
    def __init__(self, speed, distance, max_distance, carrying_capacity):
        super().__init__(speed, distance)
        self.max_distance = max_distance
        self.carrying_capacity = carrying_capacity

    # Конвертация в строку
    def __str__(self):
        return super().__str__() + f', max_distance = {self.max_distance}, carrying_capacity = {self.carrying_capacity}'
