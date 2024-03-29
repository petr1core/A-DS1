# **Лабораторная работа 1 "Алгебра полиномов"**
## **Участники команды**
- Варфоломеев Григорий - <a href="https://github.com/petr1core?tab=repositories">petr1core</a>
- Цацын Александр - <a href="https://github.com/KAPUSHA228">kapusha</a>
- Кондрашин Виктор - <a href="https://github.com/Paradox644">paradox</a>
___
Введение
Проект представляет собой программу, позволяющую совершать операции над полиномами.
## **Техническое задание**
## **Требования к реализации таблицы**
- (❗) Полиномы хранятся в виде списка 
- (❗) Полиномы хранятся во всех таблицах одновременно. Ключом является имя 
- (❗) Реализованы 6 видов таблиц 
  - линейная на массиве
  - линейная на списке
  - упорядоченная на массиве
  - дерево (АВЛ или красно-черное)
  - две хэш-таблицы 
- (❗) Операции над таблицами 
  - добавление полинома, удаление полинома поиск (во всех сразу) (только в активной таблице, выполняется в процессе вычисления выражений, составленных из имен полиномов) 
- (❗) Активная (выбранная пользователем) таблица должна выводиться на экран в формате, как минимум, двух столбцов: имя полинома, 2) строковое представление полинома 
- (♦) Реализация Google tests 

## **Требования к реализации полинома**
- (❗) Операции над отдельным полиномом 
  - вычисление в точке
  - умножение на константу
  - (♦) производная 
  - (♦) интеграл 
- (❗) Операции в выражениях из полиномов 
  - сложение, вычитание, умножение на константу
  - (♦) умножение полиномов, деление полиномов (Операции должны выполняться, используя постфиксную форму)
___
###### * ❗ - Обязательное задание, ♦ - Дополнительное задание.*
___
## **Используемые для создания проекта инструменты**
• Система контроля версий Git
• IDE Microsoft Visual Studio 2022
• Система сборки проектов CMake
