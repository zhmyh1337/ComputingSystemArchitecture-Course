## Титульник
БПИ201 Зубко Александр Вариант 6

Задание:

Задача о курильщиках. Есть три процесса-курильщика и один процесспосредник. Курильщик непрерывно скручивает сигареты и курит их. Чтобы скрутить сигарету, нужны табак, бумага и спички. У одного процессакурильщика есть табак, у второго – бумага, а у третьего – спички. Посредник кладет на стол по два разных случайных компонента. Тот процесс курильщик, у которого есть третий компонент, забирает компоненты со стола, скручивает сигарету и курит. Посредник дожидается, пока курильщик закончит, затем процесс повторяется. Создать многопоточное приложение, моделирующее поведение курильщиков и посредника. При решении задачи использовать семафоры.
## Модель вычислений
Используется модель "производители и потребители". Поток `producerThread` выступает в качестве производителя, потоки `smokerThreads` в качестве потребителей. `producerThread` генерирует (случайно) два компонента сигареты, эти компоненты читают `smokerThreads`. Для того, чтобы избежать ситуаций неуправляемого изменения одних и тех же общих данных несколькими потоками, используется два семафора: `s_produceSemaphore` и `s_consumeSemaphore`. `s_produceSemaphore` является бинарным, его получает производитель для производства компонент, а освобождает потребитель, когда употребил компоненты. `s_consumeSemaphore` имеет максимальную нагрузку 3 (по количеству потребителей), его получает потребитель для попытки употребления компонент, а освобождает производитель после производства компонент.
## Работа с данными
Единственные входные данные - количество итераций, передаются единственным параметром запуска как целочисленное число. Пример: `program.exe 5`. Вывод осуществляется в стандартный поток вывода.
