#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <exception>
#include <iostream>

struct Data//c��������, �������� � ���� n(���������� X � Y), ������� Y � X
{
	int n{};
	std::vector<int> MassX{};
	std::vector<int> MassY{};
};

class IDataProvider//����� ��� ��������� ������� ������
{
public:
	virtual Data GetData() const = 0;
	virtual ~IDataProvider() = default;
};

class FileDataProvider : public IDataProvider//������ ������ �� �����
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
		fileIn >> data.n; fileIn.ignore();//������ n
		for (int i = 0; i < data.n; i++)//������ ������� X
		{
			int temp;
			fileIn >> temp;
			data.MassX.push_back(temp);
		}
		fileIn.ignore();
		for (int i = 0; i < data.n; i++)//������ ������� Y
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