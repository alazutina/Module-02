### Проект - оптимальное управление Work-Stealing деками в двухуровневой памяти ###

#### Описание проекта ####
Рассмотрена модель для оптимального управления Work-Stealing деком в двухуровневой памяти. Работа выполнена в рамках гранта РФФИ. Опубликована статья.

#### Постановка задачи #####
Рассматривается классический последовательный циклический метод представления дека в двухуровневой памяти. Известны размер быстрой памяти и вероятностные характеристики работы с деком. Задача вычислить оптимальное математическое ожидение времени и среднее время работы деков до перераспределения памяти.

#### Реализация #####
Построены математическая и имитационные модели, описывающие работу деков. Разработаны алгоритм и программы вычисления вычисления оптимального математического ожидания и среднего времени работы дека.

#### Описание работы дека ####
Рассматривается классический последовательный циклический метод представления дека в двухуровневой памяти. 
После перераспределения дека в быстрой памяти остается основание дека, из которого элементы только исключаются как в FIFO-очереди, и вершинная часть дека, которая работает как LIFO-стек. В эту часть дека элементы включаются и исключаются. В процессе перераспределения памяти  дек переходит в такое состояние, когда вершина дека может догнать FIFO-часть, из которой происходят только исключения. Для этого надо меньшую по количеству элементов часть дека переписать в обратном порядке так, чтобы обе части дека касались друг друга сторонами, с которыми не происходят операции. Работа тогда происходит до тех пор, пока память не переполнится или одна из частей дека не станет пустой.  Затем происходит новое перераспределение дека между быстрой и медленной памятью или заканчивается работа программы.
Рассмотрен вариант задачи, когда в качестве критерия оптимальности рассмотрено максимальное среднее время до перераспределения памяти. Такой критерий оптимальности минимизирует среднее число перераспределений  памяти.


#### Математическая модель ####
Построена математическая модель, описывающая поведение дека в двухуровневой памяти, в виде случайного блуждания по целочисленной пирамиде с отражающими и поглощающими экранами. Доказана теорема в виде матрицы переходных вероятностей поглащающей цепи Маркова. Разработаны алгоритм и программы вычисления математического ожидания.

#### Имитационная модель ####
Реализована имитационную модель по методу Монте-Карло. Входные параметры модели: размер быстрой памяти m, вероятности работы с деком q1, p1, q2, q12, pq12, и r. Отрезок от 0 до 1 делится в соответствии с вероятностями. С помощью датчика случайных определяется вероятность и то, какая операция произошла. Считается время до перераспределения. Количество экспериментов 1 000 000. Вычисляеется среднее время до перераспределения. 

#### Стек технологий ####
C, компилятор gcc
