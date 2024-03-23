# Тестовое задание для Intern C++ Programmer

Использованные инструменты:

1. Cmake
2. GTest

Структура проекта:

* \-tasks/: код для заданий
* \-tests/: тесты

## Вопрос 1
Код представлен в [DivisionByTwo.cpp](./tasks/DivisionByTwo.cpp)

Тесты в [DivisionByTwo.cpp](./tests/DivisionByTwoTests.cpp)

## Вопрос 2
### Первая версия
Cделана с использованием массивов.

Код в [CircularBuffArray.cpp](./tasks/CircularBuffArray.cpp)

Тесты в [CircularBuffArrayTests.cpp](./tests/CircularBuffArrayTests.cpp)
### Вторая вресия
Вторая версия сделана с использованием связных списков.

Код в [CircularBuffArray.cpp](./tasks/CircularBuffArray.cpp)

Тесты в [CircularBuffArrayTests.cpp](./tests/CircularBuffArrayTests.cpp)

## Вопрос 3
Одни из самых быстрых версий сортировок - это те которые выполняются за время  O(n * log(n)).
Примеры таких сортировок - quickSort, MergeSort.

На практике на малых значениях сортировки вставкой или пузырьком работают быстрее, чем слиянием или быстрая сортировка.
Но это достигается засчет меньшей сложности алгоритмов. Поэтому можно написать комбинированную сортировку, и посмотреть насколько быстро она
отрабатывает.