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
*��������� ���������� ������� ������ (n(���������� X � Y) � ������� Y � X)
*/
struct Data
{
	/*
	*���������� X � Y(���������� ���������)
	*/
	int n{};
	/*
	*������ ��� ������ ���������(X)
	*/
	std::vector<int> MassX{};
	/*
	*������ ��� ������ ���������(Y)
	*/
	std::vector<int> MassY{};
};
/*
*��������� �������� ������������ ��������� � ������ ������
*/
class IDataProvider
{
public:
	/*
	*������� ��� ������ ������ �� �����
	*/
	virtual Data GetData() const = 0;
	/*
	*������� ��� ������ ������ � ����
	*/
	virtual void PutData(float Fenh) = 0;
};
class FileDataProvider : public IDataProvider//������ ������ �� �����
{
private:
	/*
	*��� �������� �����
	*/
	std::string _InputFilename;
	/*
	*��� ��������� ����� 
	*/
	std::string _OutputFilename;
	/*
	*������ ��� ������ ������ �� ������
	*/
	std::vector<int> LineToVector(std::ifstream & fileIn) const;
public:
	/*
	*����������� ��������� �������� �������� � ��������� �����
	*/
	FileDataProvider(const std::string& InputFilename, const std::string& OutputFilename)
		: _InputFilename(InputFilename), _OutputFilename(OutputFilename) {};
	/*
	*������� ��� ������ ������ �� �����
	*/
	Data GetData() const override;
	/*
	*������� ��� ������ ������ � ����
	*/
	void PutData(float Fenh);
};
