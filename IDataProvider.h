#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <exception>
#include <iostream>
#include <iterator>
#include <sstream>

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
	std::vector<int> LineToVector(std::ifstream & fileIn) const;//���������� ������ � ������
public:
	FileDataProvider(const std::string filename)
		: _filename(filename) {};
	Data GetData() const override;//������� ��� ������ � �����
	
};