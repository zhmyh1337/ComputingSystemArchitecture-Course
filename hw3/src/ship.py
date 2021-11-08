'''
ship.py - содержит описание корабля
'''

from enum import Enum
from base_transport import *

# Корабль
class Ship(BaseTransport):
    # Тип судна
    class VesselType(Enum):
        liner = 1 # лайнер
        tow = 2 # буксир
        tanker = 3 # танкер

        def __str__(self):
            return self.name

    # Инициализация
    def __init__(self, speed, distance, displacement, vessel_type):
        super().__init__(speed, distance)
        self.displacement = displacement
        self.vessel_type = vessel_type

    # Конвертация в строку
    def __str__(self):
        return super().__str__() + f', displacement = {self.displacement}, vessel_type = {self.vessel_type}'
