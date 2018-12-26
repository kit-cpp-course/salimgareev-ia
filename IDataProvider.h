/*
*IDataProvider.h
*/
#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <exception>
#include <iostream>
#include <iterator>
#include <sstream>
/*
*Структура содержащая входные данные (n(количество X и Y) и векторы Y и X)
*/
struct Data
{
	/*
	*Количество X и Y(количество признаков)
	*/
	int n{};
	/*
	*Вектор для первых признаков(X)
	*/
	std::vector<int> MassX{};
	/*
	*Вектор для вторых признаков(Y)
	*/
	std::vector<int> MassY{};
};
/*
*Интерфейс кототрый осуществляет получение и запись данных
*/
class IDataProvider
{
public:
	/*
	*Функция для чтения данных из файла
	*/
	virtual Data GetData() const = 0;
	/*
	*Функция для записи данных в файл
	*/
	virtual void PutData(float Fenh) = 0;
};
class FileDataProvider : public IDataProvider//чтение данных из файла
{
private:
	/*
	*Имя входного файла
	*/
	std::string _InputFilename;
	/*
	*Имя выходного файла 
	*/
	std::string _OutputFilename;
	/*
	*Вектор для записи данных из строки
	*/
	std::vector<int> LineToVector(std::ifstream & fileIn) const;
public:
	/*
	*Конструктор принимает название входного и выходного файла
	*/
	FileDataProvider(const std::string& InputFilename, const std::string& OutputFilename)
		: _InputFilename(InputFilename), _OutputFilename(OutputFilename) {};
	/*
	*Функция для чтения данных из файла
	*/
	Data GetData() const override;
	/*
	*Функция для записи данных в файл
	*/
	void PutData(float Fenh);
};
