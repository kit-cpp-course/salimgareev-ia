/*
*IDataProvider.cpp
*/
#include "IDataProvider.h"

std::vector<int> FileDataProvider::LineToVector(std::ifstream & fileIn) const
{
	std::string line;
	std::getline(fileIn, line);
	std::istringstream stream(line);
	return std::vector<int> { std::istream_iterator<int>(stream), std::istream_iterator<int>{} };
}
Data FileDataProvider::GetData() const
{
	std::ifstream fileIn(_InputFilename);
	if (!fileIn.is_open())
	{
		throw std::logic_error("Could not open file \n");
	}
	Data data;
	fileIn >> data.n; fileIn.ignore();//������ n
	data.MassX = LineToVector(fileIn);//������ ������� X
	data.MassY = LineToVector(fileIn);//������ ������� Y
	if (data.n != data.MassX.size() || data.n != data.MassY.size())
	{
		throw std::logic_error("The amount of data entered does not correspond to n \n");
	}
	return data;
}
void FileDataProvider::PutData(float Fenh)
{
	std::ofstream fileIn(_OutputFilename);
	if (!fileIn.is_open())
	{
		throw std::logic_error("Could not open file \n");
	}
	fileIn << Fenh;
}