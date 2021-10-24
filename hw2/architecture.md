## Архитектура
### ТТ
* bool 1
* char 1
* int 4
* float 4
* size_t 8
<details>
  <summary>BaseTransport 16</summary>
  void* __vtbl 8 [0]<br/>
  int m_speed 4 [8]<br/>
  float m_distance 4 [12]
</details>
<details>
  <summary>Plane 24</summary>
  BaseTransport super 16 [0]<br/>
  int m_maxDistance 4 [16]<br/>
  int m_carryingCapacity 4 [20]
</details>
<details>
  <summary>Train 20</summary>
  BaseTransport super 16 [0]<br/>
  int m_carsCount 4 [16]<br/>
</details>
<details>
  <summary>Ship 24</summary>
  BaseTransport super 16 [0]<br/>
  int m_displacement 4 [16]<br/>
  VesselType m_vesselType 4 [20]
</details>
<details>
  <summary>Random 5000</summary>
  std::mt19937 m_rng 5000 [0]
</details>
<details>
  <summary>InputHelper 1</summary>
</details>
<details>
  <summary>Container 80008</summary>
  size_t len 8 [0]<br/>
  std::array<BaseTransport*, 10000> m_data 80000 [8]
</details>

### ГП
Отсутствует, т. к. нет ни глобальных, ни статических переменных.

### ПП
Зависит от условий запуска программы, таких как аргументы запуска.\
Один из примеров (некорректный запуск без параметров):
```
main(...):
int argc: 4 [0] stack
argv: char** 8 [4] stack -> heap (value = ".../program.exe")
quiet: bool 1 [12] stack
randomize: bool 1 [13]
argIndex: int 4 [14]
```