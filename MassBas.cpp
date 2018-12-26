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
			Fenh = float(nA - nB) / float(nA + nB);//формуля для вычисления коэффициента
			
			return(Fenh);
		}
}