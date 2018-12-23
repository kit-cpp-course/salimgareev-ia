#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <exception>
#include <iostream>

struct Data//cтруктура, содержит в себе n(количество X и Y), массивы Y и X
{
	int n{};
	std::vector<int> MassX{};
	std::vector<int> MassY{};
};

class IDataProvider//класс дл€ структуры входных данных
{
public:
	virtual Data GetData() const = 0;
	virtual ~IDataProvider() = default;
};

class FileDataProvider : public IDataProvider//чтение данных из файла
{
private:
	std::string _filename;
public:
	FileDataProvider(const std::string filename)
		: _filename(filename) {};

	Data GetData() const override
	{
		std::ifstream fileIn(_filename);
		if (fileIn.is_open)
		{
			throw logic_error("Could not open file");
		}
		Data data;
		fileIn >> data.n; fileIn.ignore();//чтение n
		for (int i = 0; i < data.n; i++)//чтение массива X
		{
			int temp;
			fileIn >> temp;
			data.MassX.push_back(temp);
		}
		fileIn.ignore();
		for (int i = 0; i < data.n; i++)//чтение массива Y
		{
			int temp;
			fileIn >> temp;
			data.MassY.push_back(temp);
		}
		fileIn.ignore();
		if(data.n != data.MassX.size() && data.n != data.MassY.size())
		{
			throw logic_error("The amount of data entered does not correspond to n");
		}
		return data;
	}
};