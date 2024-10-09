#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <string> // Подключение библиотеки для работы со строками
using namespace std; // Использование стандартного пространства имен
// Структура для представления трубопровода
struct Pipeline {
    string name = "none"; // Имя трубопровода
    int length; // Длина трубопровода
    int diameter; // Диаметр трубопровода
    bool hasRepair; // Наличие ремонта (да/нет)
};
// Структура для представления CS
struct CS {
    string name = "none"; // Имя CS
    int mountOfDepartments; // Общее количество отделов
    int workingDepartments; // Количество рабочих отделов
    double coefficientEfficiency; // Коэффициент эффективности
};
#endif // STRUCTURE_H
