# # ТУРНАЕВА ВЕРА 747
# Практическая работа №3

## Односвязные списки
Необходимо используя  функции реализовать программу которая:
1. считать количество элементов ∈ N≤ 2147483647;
2.  создать пустой список, считать n элементов a, |a| ≤2147483647 и занести их в список;
3.  вывести содержимое списка используя функцию print;
4.  считать k1, k2, k3 |k| ≤ 2147483647 и вывести ‘1’ если в списке существует элемент с таким значением. ‘0’ если нет, перейти на новую строку.
5.  считать m, |m| ≤ 2147483647 и вставить его в конец списка;
6.  вывести содержимое списка используя функцию print;
7.  считать t, |t| ≤ 2147483647 и вставить его в начало списка;
8.  вывести содержимое списка используя функцию print;
9.  считать j, 0 < j ≤ 2147483647 и x, |x| ≤ 2147483647 и вставить значение x после j-ого элемента списка;
10. вывести содержимое списка используя функцию print;
11.  считать z, |z| ≤ 2147483647 и удалить первый элемент хранящий значение z из списка;
12. вывести содержимое списка используя функцию print;
13.  очистить список.


## Ход работы
С помощью текстового блокнота **nano** были созданы исходный код программы. Код был скомпилирован и проверен на заданных примерах.
|  input   | output         |
|----------|----------------|
| 5        | 1 2 3 2 4      |
|1 2 3 2 4 | 1 0 1          |
|2 5 1     | 1 2 3 2 4 5    |
|5         | 7 1 2 3 2 4 5  |
|7         | 7 1 2 0 3 2 4 5|
|3 0       | 7 1 0 3 2 4 5  |
|2         |                |

Результат выполнения программы:


![enter image description here](https://pp.userapi.com/c852024/v852024596/dc388/9T-iFibKOcs.jpg)

## Список используемых источников

 - [ Структурный тип данных](https://younglinux.info/c/structure)
 - [ Односвязный список на Си](https://codedream.me/2016/10/12/%D0%BE%D0%B4%D0%BD%D0%BE%D1%81%D0%B2%D1%8F%D0%B7%D0%BD%D1%8B%D0%B9-%D1%81%D0%BF%D0%B8%D1%81%D0%BE%D0%BA/)
 - [ Односвязный линейный список](https://prog-cpp.ru/data-ols/)
