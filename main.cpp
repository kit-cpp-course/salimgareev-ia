/*
*main.cpp
*/
#include <iostream>
#include "MassBas.h"
#include "IDataProvider.h"
#include "FileNameProvider.h"

using namespace std;
using namespace  CorrelationCoefficients;

int main(int argc, char* argv[])
{
	FileNameProvider FileName = FileNameProvider(argc, argv);
	IDataProvider & dataProvider = FileDataProvider(FileName.GetInputFileName(), FileName.GetOutputFileName());
	try
	{
		MassBas A{dataProvider};
		dataProvider.PutData(A.CalculationFehner());
	}
	catch (const exception& ex)
	{
		std::cerr << ex.what();
	}
	system("pause");
	return 0;
}