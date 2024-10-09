#include <iostream> // Подключение библиотеки для ввода/вывода
#include <fstream> // Подключение библиотеки для работы с файлами
#include <string> // Подключение библиотеки для работы со строками
#include <limits> // Подключение библиотеки для numeric_limits
#include "structure.h" // Подключение заголовочного файла с определениями структур Pipeline и CS

using std::cout; // Использование стандартного пространства имен
using std::cin;

// Объявление функций
void addPipeline(Pipeline& pipeline); // Функция для добавления трубопровода
void redactPipeline(Pipeline& pipeline); // Функция для редактирования трубопровода
void viewPipeline(Pipeline& pipeline); // Функция для просмотра трубопроводов
void addCS(CS& cs); // Функция для добавления CS
void redactCS(CS& cs); // Функция для редактирования CS
void viewCS(CS& cs); // Функция для просмотра CS
void clearInputBuffer(); // Функция для очистки входного буфера
void saveData(const Pipeline& pipeline, const CS& cs);
void loadData(Pipeline& pipeline, CS& cs);

int main()
{
    Pipeline pipe;
    CS cs;
    int choice; // Переменная для хранения выбора пользователя

    do
    {
        // Вывод меню на экран
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Menu:\n"; // Заголовок меню
        cout << "1. Add Pipeline\n"; // Пункт меню для добавления трубопровода
        cout << "2. Redact Pipeline\n"; // Пункт меню для редактирования трубопровода
        cout << "3. Add CS\n"; // Пункт меню для добавления CS
        cout << "4. Redact CS\n"; // Пункт меню для редактирования CS
        cout << "5. View Pipeline\n"; // Пункт меню для просмотра трубопроводов
        cout << "6. View CS\n"; // Пункт меню для просмотра CS
        cout << "7. Save all\n"; // Сохранение всего
        cout << "8. Load all\n"; // Загрузить все
        cout << "9. Exit\n"; // Пункт меню для выхода
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Enter your choice: "; // Запрос выбора от пользователя
        cin >> choice; // Получение выбора от пользователя
        clearInputBuffer(); // Очистка входного буфера

        switch (choice)
        {
        case 1:
            system("cls"); // Очистка консоли
            addPipeline(pipe); // Вызов функции для добавления трубопровода
            break;
        case 2:
            system("cls"); // Очистка консоли
            redactPipeline(pipe); // Вызов функции для редактирования трубопровода
            break;
        case 3:
            system("cls"); // Очистка консоли
            addCS(cs); // Вызов функции для добавления CS
            break;
        case 4:
            system("cls"); // Очистка консоли
            redactCS(cs); // Вызов функции для редактирования CS
            break;
        case 5:
            system("cls"); // Очистка консоли
            viewPipeline(pipe); // Вызов функции для просмотра трубопроводов
            break;
        case 6:
            system("cls"); // Очистка консоли
            viewCS(cs); // Вызов функции для просмотра CS
            break;
        case 7:
            system("cls"); // Очистка консоли
            saveData(pipe, cs); // Вызов функции для просмотра CS
            break;
        case 8:
            system("cls"); // Очистка консоли
            loadData(pipe, cs); // Вызов функции для просмотра CS
            break;
        case 9:
            cout << "Exiting the program.\n"; // Сообщение о выходе из программы
            break;
        default:
            system("cls"); // Очистка консоли
            cout << "Invalid choice. Please try again.\n"; // Сообщение об ошибке при неверном выборе
        }
    } while (choice != 9); // Цикл продолжается, пока пользователь не выберет выход
    return 0; // Завершение программы
}



// Функция для добавления трубопровода
void addPipeline(Pipeline& pipeline)
{
    cout << "Enter Pipeline Name: "; // Запрос имени трубопровода
    getline(cin, pipeline.name); // Считывание имени трубопровода
    // Ввод длины с проверкой на положительное значение
    do {
        cout << "Enter Length (positive value): "; // Запрос длины трубопровода
        while (!(cin >> pipeline.length) || (cin.peek() != '\n') || pipeline.length < 1) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Error. Please enter a valid length: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (pipeline.length <= 0) {
            cout << "Length must be a positive value. Please enter again.\n"; // Сообщение об ошибке
        }
    } while (pipeline.length <= 0);

    // Ввод диаметра с проверкой на положительное значение
    do {
        cout << "Enter Diameter (positive value): "; // Запрос диаметра трубопровода
        while (!(cin >> pipeline.diameter) || pipeline.diameter < 1) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Error. Please enter a valid diameter: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (pipeline.diameter <= 0) {
            cout << "Diameter must be a positive value. Please enter again.\n"; // Сообщение об ошибке
        }
    } while (pipeline.diameter <= 0);

    // Ввод наличия ремонта с проверкой на допустимые значения
    string repairInput; // Переменная для хранения ввода наличия ремонта
    do {
        cout << "Has Repair (1/0 or yes/no): "; // Запрос наличия ремонта
        cin >> repairInput; // Считывание
        if (repairInput != "1" && repairInput != "0" && repairInput != "yes" && repairInput != "no") {
            cout << "Please enter 1/0 or yes/no.\n"; // Сообщение об ошибке
        }
    } while (repairInput != "1" && repairInput != "0" && repairInput != "yes" && repairInput != "no");
    pipeline.hasRepair = (repairInput == "1" || repairInput == "yes"); // Установка значения наличия ремонта
    cout << "Pipeline added successfully.\n"; // Сообщение об успешном добавлении
}



// Функция для редактирования трубопровода
void redactPipeline(Pipeline& pipeline)
{
    // Вывод текущего состояния трубопровода
    cout << "Pipeline Name: " << pipeline.name << "\n"; // Вывод имени
    cout << "Length: " << pipeline.length << "\n"; // Вывод длины
    cout << "Diameter: " << pipeline.diameter << "\n"; // Вывод диаметра
    cout << "Has Repair: " << (pipeline.hasRepair ? "Yes" : "No") << "\n"; // Вывод информации о ремонте

    // Редактирование наличия ремонта
    int option;
    cout << "1. Stay\n2. Redact Has Repair\n"; // Предложение действий
    cout << "Choose an option for Has Repair: "; // Запрос выбора от пользователя
    cin >> option; // Получение выбора
    clearInputBuffer(); // Очистка входного буфера
    if (option == 2)
    {
        string repairInput; // Переменная для хранения ввода наличия ремонта
        do {
            cout << "Has Repair (1 for Yes, 0 for No, yes/no): "; // Запрос наличия ремонта
            cin >> repairInput; // Считывание
            if (repairInput != "1" && repairInput != "0" && repairInput != "yes" && repairInput != "no") {
                cout << "Please enter 1 for Yes, 0 for No, or yes/no.\n"; // Сообщение об ошибке
            }
        } while (repairInput != "1" && repairInput != "0" && repairInput != "yes" && repairInput != "no");
        pipeline.hasRepair = (repairInput == "1" || repairInput == "yes"); // Установка нового значения наличия ремонта
    }
    system("cls"); // Очистка консоли

    cout << "Pipeline updated successfully.\n"; // Сообщение об успешном обновлении
}



// Функция для просмотра трубопроводов
void viewPipeline(Pipeline& pipeline)
{
    if (pipeline.name != "none")
    {
        // Вывод информации о трубопроводе
        cout << "Pipeline Name: " << pipeline.name << "\n"
            << "Length: " << pipeline.length << "\n"
            << "Diameter: " << pipeline.diameter << "\n"
            << "Has Repair: " << (pipeline.hasRepair ? "Yes" : "No") << "\n\n";
    }
}



// Функция для добавления CS
void addCS(CS& cs)
{
    // Запрос данных о CS
    cout << "Enter CS Name: "; // Запрос имени CS
    getline(cin, cs.name); // Считывание имени CS

    // Ввод общего количества отделов с проверкой на положительное значение
    do {
        cout << "Enter Mount of Departments (positive value): "; // Запрос общего количества отделов
        while (!(cin >> cs.mountOfDepartments) || cs.mountOfDepartments < 1) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Error. Please enter a valid Mount of Departments: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (cs.mountOfDepartments <= 0) {
            cout << "Mount of Departments must be a positive value. Please enter again.\n"; // Сообщение об ошибке
        }
    } while (cs.mountOfDepartments <= 0);

    // Ввод рабочих отделов с проверкой на допустимые значения
    do {
        cout << "Enter Working Departments (must be positive and less than Mount of Departments): "; // Запрос рабочих отделов
        while (!(cin >> cs.workingDepartments) || cs.workingDepartments < 1) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Error. Please enter a valid Working Departments: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (cs.workingDepartments <= 0 || cs.workingDepartments > cs.mountOfDepartments) {
            cout << "Working Departments must be positive and cannot exceed Mount of Departments. Please enter again.\n"; // Сообщение об ошибке
        }
    } while (cs.workingDepartments <= 0 || cs.workingDepartments > cs.mountOfDepartments);

    // Рассчитываем коэффициент эффективности
    cs.coefficientEfficiency = static_cast<double>(cs.workingDepartments) / cs.mountOfDepartments * 100; // Рассчитываем процент
    cout << "CS added successfully. Coefficient Efficiency: " << cs.coefficientEfficiency << "%\n"; // Сообщение об успешном добавлении и вывод коэффициента
}



// Функция для редактирования CS
void redactCS(CS& cs)
{
    // Вывод текущего состояния CS
    cout << "CS Name: " << cs.name << "\n"; // Вывод имени CS
    cout << "Mount of Departments: " << cs.mountOfDepartments << "\n"; // Вывод общего количества отделов
    cout << "Working Departments: " << cs.workingDepartments << "\n"; // Вывод рабочих отделов
    cout << "Coefficient Efficiency: " << cs.coefficientEfficiency << "%\n"; // Вывод коэффициента эффективности

    // Редактирование рабочих отделов с проверкой на допустимые значения
    int option;
    cout << "1. Stay\n2. Redact Working Departments\n"; // Предложение действий
    cout << "Choose an option for Working Departments: "; // Запрос выбора от пользователя
    cin >> option; // Получение выбора
    clearInputBuffer(); // Очистка входного буфера
    if (option == 2)
    {
        do {
            cout << "Enter Working Departments (must be positive and less than Mount of Departments): "; // Запрос рабочих отделов
            cin >> cs.workingDepartments; // Считывание рабочих отделов
            // Проверка на корректность ввода
            if (cs.workingDepartments <= 0 || cs.workingDepartments > cs.mountOfDepartments) {
                cout << "Working Departments must be positive and cannot exceed Mount of Departments. Please enter again.\n"; // Сообщение об ошибке
            }
        } while (cs.workingDepartments <= 0 || cs.workingDepartments > cs.mountOfDepartments);

        // Рассчитываем коэффициент эффективности
        cs.coefficientEfficiency = static_cast<double>(cs.workingDepartments) / cs.mountOfDepartments * 100; // Рассчитываем процент
    }
    system("cls"); // Очистка консоли
    cout << "CS updated successfully. Coefficient Efficiency: " << cs.coefficientEfficiency << "%\n"; // Сообщение об успешном обновлении и вывод коэффициента
}



// Функция для просмотра CS
void viewCS(CS& cs)
{
    if (cs.name != "none")
    {
        cout << "CS Name: " << cs.name << "\n"
            << "Mount of Departments: " << cs.mountOfDepartments << "\n"
            << "Working Departments: " << cs.workingDepartments << "\n"
            << "Coefficient Efficiency: " << cs.coefficientEfficiency << "%\n\n";
    }
}



// Функция для очистки входного буфера
void clearInputBuffer() {
    cin.clear(); // Сброс флагов ошибок
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорирование остатка строки
}




void saveData(const Pipeline& pipeline, const CS& cs)
{
    if (pipeline.name != "none" || cs.name != "none")
    {
        ofstream file("data.txt");
        if (file.is_open()) {

            if (pipeline.name != "none")
            {
                file << "@pipeline@\n"
                    << pipeline.name << std::endl
                    << pipeline.length << std::endl
                    << pipeline.diameter << std::endl
                    << pipeline.hasRepair << std::endl;
            }

            if (cs.name != "none") {
                file << "@cs@\n"
                    << cs.name << std::endl
                    << cs.mountOfDepartments << std::endl
                    << cs.workingDepartments << std::endl
                    << cs.coefficientEfficiency << std::endl;
            }

            file.close();
            cout << "Data saved successfully.\n";
        }
        else {
            cout << "Error opening file for loading.\n";
        }
    }
}

void loadData(Pipeline& pipeline, CS& cs)
{
    string filename = "data.txt";
    ifstream file("data.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;

        return;
    }

    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Error: File " << filename << " is empty." << std::endl;
        file.close();
        return;
    }

    std::string line;
    bool pipeline_loaded = false;
    bool cs_loaded = false;

    while (std::getline(file, line)) {
        if (line == "@pipeline@") {
            std::getline(file, pipeline.name);
            if (pipeline.name.empty()) {
                std::cerr << "Error: Invalid pipeline name in file." << std::endl;
                continue;
            }

            if (!(file >> pipeline.length) || pipeline.length <= 0) {
                std::cerr << "Error: Invalid pipeline length in file." << std::endl;
                continue;
            }

            if (!(file >> pipeline.diameter) || pipeline.diameter <= 0) {
                std::cerr << "Error: Invalid pipeline diameter in file." << std::endl;
                continue;
            }

            if (!(file >> pipeline.hasRepair) || (pipeline.hasRepair != 0 && pipeline.hasRepair != 1)) {
                std::cerr << "Error: Invalid repair indicator in file. Must be 0 or 1." << std::endl;
                continue;
            }

            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            pipeline_loaded = true;
        }


        else if (line == "@cs@") {
            std::getline(file, cs.name);
            if (cs.name.empty()) {
                std::cerr << "Error: Invalid CS name in file." << std::endl;
                continue;
            }

            if (!(file >> cs.mountOfDepartments) || cs.mountOfDepartments <= 0) {
                std::cerr << "Error: Invalid number of workshops in file." << std::endl;
                continue;
            }

            if (!(file >> cs.workingDepartments) || cs.workingDepartments < 0 || cs.workingDepartments > cs.workingDepartments) {
                std::cerr << "Error: Invalid number of workshops in work in file." << std::endl;
                continue;
            }

            if (!(file >> cs.coefficientEfficiency) || cs.coefficientEfficiency < 0 || cs.coefficientEfficiency > 100) {
                std::cerr << "Error: Invalid CS efficiency in file. Must be between 0 and 100." << std::endl;
                continue;
            }

            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cs_loaded = true;
        }

    }

    file.close();

    if (!pipeline_loaded)
    {
        pipeline.name = "none";
    }
    if (!cs_loaded)
    {
        cs.name = "none";
    }

    if (!pipeline_loaded && !cs_loaded) {
        std::cerr << "Error: No valid pipeline or CS data found in the file." << std::endl;
    }

}