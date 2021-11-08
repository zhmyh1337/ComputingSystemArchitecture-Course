'''
base_transport.py - содержит описание обобщенного транспорта
'''

import input_helper
import random

# Обобщенный транспорт
class BaseTransport:
    # Инициализация транспорта
    def __init__(self, speed, distance):
        self.speed = speed
        self.distance = distance

    # Идеальное время прохождения пути
    def get_ideal_time(self):
        return self.distance / self.speed

    # Конвертация в строку
    def __str__(self):
        return f'{type(self).__name__}: speed = {self.speed}, distance = {self.distance}, ideal time = {self.get_ideal_time()}'

from plane import *
from train import *
from ship import *
# Создание транспорта из строки
@staticmethod
def create(s):
    splitted = s.split()
    try:
        speed = int(splitted[1])
        distance = float(splitted[2])
        if splitted[0] == 'plane':
            max_distance = int(splitted[3])
            carrying_capacity = int(splitted[4])
            return Plane(speed, distance, max_distance, carrying_capacity)
        elif splitted[0] == 'train':
            cars_count = int(splitted[3])
            return Train(speed, distance, cars_count)
        elif splitted[0] == 'ship':
            displacement = int(splitted[3])
            vessel_type = Ship.VesselType[splitted[4]]
            return Ship(speed, distance, displacement, vessel_type)
        else:
            raise Exception()
    except Exception:
        input_helper.invalid_input()
BaseTransport.create = create
del create

# Создание транспорта (случайно)
@staticmethod
def create_rnd():
    speed = random.randint(1, 1000)
    distance = random.uniform(0, 5000)
    transport_type = random.randint(1, 3)
    if transport_type == 1:
        return Plane(speed, distance, random.randint(0, 30000), random.randint(0, 1000))
    elif transport_type == 2:
        return Train(speed, distance, random.randint(0, 40))
    else:
        return Ship(speed, distance, random.randint(0, 30000), random.choice(list(Ship.VesselType)))
BaseTransport.create_rnd = create_rnd
del create_rnd
