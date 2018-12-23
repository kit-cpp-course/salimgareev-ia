#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <exception>
#include <iostream>
#include <iterator>
#include <sstream>

struct Data//cтруктура, содержит в себе n(количество X и Y), массивы Y и X
{
	int n{};
	std::vector<int> MassX{};
	std::vector<int> MassY{};
};
class IDataProvider//класс для структуры входных данных
{
public:
	virtual Data GetData() const = 0;
	virtual ~IDataProvider() = default;
};
class FileDataProvider : public IDataProvider//чтение данных из файла
{
private:
	std::string _filename;
	std::vector<int> LineToVector(std::ifstream & fileIn) const;//считывание строки в вектор
public:
	FileDataProvider(const std::string filename)
		: _filename(filename) {};
	Data GetData() const override;//функция для чтения с файла
	
};
