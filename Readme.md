﻿# Тестовое задание для Intern C++ Programmer

Использованные инструменты:

1. Cmake
2. GTest
3. Visual Studio 2022

Структура проекта:

* \-tasks/: код для заданий
* \-tests/: тесты

## Вопрос 1
Код представлен в [DivisionByTwo.cpp](./tasks/DivisionByTwo.cpp) и [DivisionByTwo.h](./tasks/DivisionByTwo.h)

Тесты в [DivisionByTwo.cpp](./tests/DivisionByTwoTests.cpp).

Ниже привидена таблица с достоинствами и недостатками каждой реализации
<table style="border-collapse:collapse;border-spacing:0" class="tg"><thead><tr><th style="background-color:#dae8fc;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;font-weight:bold;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Реализация</th><th style="background-color:#dae8fc;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;font-weight:normal;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal"></th><th style="background-color:#dae8fc;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;font-weight:normal;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal"></th><th style="background-color:#dae8fc;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;font-weight:normal;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal"></th></tr></thead><tbody><tr><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal" rowspan="2">Пример (IsEven)</td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Плюсы</td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Быстро</td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Интуитивная реализация</td></tr><tr><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Минусы</td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">-</td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal"></td></tr><tr><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal" rowspan="2">IsEvenBit</td><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Плюсы</td><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Быстро</td><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Понятный код</td></tr><tr><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Минусы</td><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">-</td><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal"></td></tr><tr><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal" rowspan="2">IsEvenShift</td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Плюсы</td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Быстро</td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal"></td></tr><tr><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Минусы</td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Не самая очевидная реализация</td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal"></td></tr><tr><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal" rowspan="2">IsEvenTemplate</td><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Плюсы</td><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Работает во время компиляции</td><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Быстро</td></tr><tr><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Минусы</td><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal"></td><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal"></td></tr><tr><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal" rowspan="2">IsEvenRandomJoke</td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Плюсы</td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Понятный код</td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Работает молниеносно</td></tr><tr><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Минусы</td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Работает в 50% случаев</td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Глаз дергается</td></tr><tr><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal" rowspan="2">IsEvenArryayJoke</td><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Плюсы</td><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal"></td><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal"></td></tr><tr><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Минусы</td><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Усложненный код</td><td style="background-color:#ecf4ff;border-color:inherit;border-style:solid;border-width:1px;font-family:Verdana, Geneva, sans-serif !important;font-size:14px;overflow:hidden;padding:10px 5px;text-align:center;vertical-align:top;word-break:normal">Медленно работает</td></tr></tbody></table>

## Вопрос 2

### Первая версия
Cделана с использованием массивов.

Код в [CircularBuffArray.h](./tasks/CircularBuffArray.h)

Тесты в [CircularBuffArrayTests.cpp](./tests/CircularBuffArrayTests.cpp)
### Вторая вресия
Вторая версия сделана с использованием связных списков.

Код в [CircularBuffArray.h](./tasks/CircularBuffArray.h)

Тесты в [CircularBuffArrayTests.cpp](./tests/CircularBuffArrayTests.cpp)

## Вопрос 3
Одни из самых быстрых версий сортировок - это те которые выполняются за время  _O(n * log(n)_).
Примеры таких сортировок - quickSort, MergeSort.

На практике на малых значениях сортировки вставкой или пузырьком работают быстрее, чем слиянием или быстрая сортировка.
Но это достигается засчет меньшей сложности алгоритмов. Поэтому можно написать комбинированную сортировку, и посмотреть насколько быстро она
отрабатывает.

Также ускорение при больших объемах массива (N > 100'000) дает распаралелливание сортировки
на несколько потоков, что можно реализовать через std::thread.

Код приведен в [Sort.h](./tasks/Sort.h).
С тестами алгоритмо можно ознакомиться в [MixedSortTests.cpp](./tests/MixedSortTests.cpp).

С результатами прогонов на моей машине можно ознакомится в таблице ниже, а также самостоятельно
запустив [MixedSortBenchmark.cpp](./tests/MixedSortBenchmark.cpp).

| Размер массива | Сортировка Вставкой | Сортировка слиянием | Сортировка слиянием (2 потока) | Сортировка слиянием (макс. потоков) |
|:--------------:|---------------------|---------------------|--------------------------------|-------------------------------------|
|       64       | 2.00 (мкс)          | 6.00 (мкс)          | 2.87 (мс)                      | 54.15 (мс)                          |
|      1'000     | 0.64 (мс)           | 0.06 (мс)           | 5.13 (мс)                      | 244.03 (мс)                         |
|     10'000     | 45.74 (мс)          | 0.56 (мс)           | 2.05 (мс)                      | 197.49 (мс)                         |
|     100'000    | 7.34 (с)            | 5.99 (мс)           | 4.72 (мс)                      | 192.50 (мс)                         |
|   10'000'000   | -                   | 734.31 (мс)         | 406.81 (мс)                    | 394.88 (мс)                         |
|   100'000'000  | -                   | 8.04 (с)            | 4.36 (с)                       | 1.73 (с)                            |