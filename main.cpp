#include <iostream>
#include "MassBas.h"
#include "IDataProvider.h"

using namespace std;
using namespace  CorrelationCoefficients;


int main()
{
	IDataProvider & dataProvider = FileDataProvider("1.txt");



	MassBas A{dataProvider};
	try
	{
		cout << "The value of the coefficient Fechner: " << A.CalculationFehner() << endl;
	}
	catch (const exception& ex)
	{
		std::cerr << ex.what();
	}
		
	

	
	system("pause");
	return 0;
}