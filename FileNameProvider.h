/*
 *FileNameProvider.h
 */
#pragma once
#include <vector>
#include <string>
/*
 *Класс для работы с аргументами командной строки
 */
class FileNameProvider
{
private:
	/*
	 *Вектор в котором хранятся аргументы из командной строки
	 */
	std::vector<std::string> _args;
public:
	/*
	 *Конструктор принимает аргументы командной строки
	 */
	FileNameProvider(int argc, char * argv[])
		: _args(argv, argv + argc) {}
	/*
	 *Функция которая возвращает название входного файла
	 */
	std::string GetInputFileName() const;
	/*
	 *Функция которая возвращает название выходного файла
	 */
	std::string GetOutputFileName() const;
};
