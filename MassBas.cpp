/*
 *MassBas.cpp
 */
#include "MassBas.h"

namespace CorrelationCoefficients {
	MassBas::MassBas(const IDataProvider& dataProvider) : dataProvider(dataProvider) {
		data = dataProvider.GetData();
		MassSignX = new char[data.n];
		MassSignY = new char[data.n];
	}
	MassBas::~MassBas()
	{
		delete[] MassSignX;
		delete[] MassSignY;
	}
	MassBas::MassBas(const MassBas& source) : dataProvider(source.dataProvider)
	{
		data = source.data;
		MassSignX = new char[data.n];
		MassSignY = new char[data.n];
		for (int i = 0; i < data.n;i++)
		{
			MassSignX[i] = source.MassSignX[i];
			MassSignY[i] = source.MassSignY[i];
		}
	}
	float MassBas::AveVal(std::vector<int> Mass) const
	{
		int Summ = 0;
		for (int i = 0; i < data.n;i++)
		{
			Summ += Mass[i];
		}
		return Summ / data.n;
	}
	char *MassBas::DefinitionSign(std::vector<int> Mass, char *MassSign)
	{
		float AveValue = AveVal(Mass);
		for (int i = 0; i < data.n; i++)
		{
			MassSign[i] = (Mass[i] - AveValue > 0) ? '+' : '-';
		}
		return MassSign;
	}
	int MassBas::CountSign()
	{
		nA = 0;
		nB = 0;
		MassSignX = DefinitionSign(data.MassX, MassSignX);
		MassSignY = DefinitionSign(data.MassY, MassSignY);
		for (int i = 0;i < data.n;i++)
		{
			(MassSignX[i] == MassSignY[i] ? nA : nB)++;
		}
		return 0;
	}
	float MassBas::CalculationFehner()
	{
		CountSign();
		/*
		*формуля для вычисления коэффициента
		*/
		Fenh = float(nA - nB) / float(nA + nB);

		return(Fenh);
	}
}