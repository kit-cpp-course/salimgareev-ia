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
	std::ifstream fileIn(_filename);
	if (!fileIn.is_open())
	{
		throw std::logic_error("Could not open file \n");
	}
	Data data;
	fileIn >> data.n; fileIn.ignore();//чтение n
	data.MassX = LineToVector(fileIn);//чтение массива X
	data.MassY = LineToVector(fileIn);//чтение массива Y
	if (data.n != data.MassX.size() || data.n != data.MassY.size())
	{
		throw std::logic_error("The amount of data entered does not correspond to n \n");
	}
	return data;
}
