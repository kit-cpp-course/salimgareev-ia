#pragma once
#include <iostream>
#include "IDataProvider.h"
#include <vector>

namespace CorrelationCoefficients{
	class MassBas {
		const IDataProvider& dataProvider;
		Data data = dataProvider.GetData();
		float Fenh;//коэффициент
		int nA, nB;//счетчики для определения совпадений знаков(A- совпадают, B - не совпадают)
		char *MassSignX = new char[data.n];//массив со знаками X
		char *MassSignY = new char[data.n];//массив со знаками X

		float AveVal(std::vector<int> Mass) const //среднее значение
		{
			int Summ = 0;
			for (int i = 0; i < data.n;i++)
				Summ += Mass[i];
			return Summ / data.n;
		}

		char *DefinitionSign(std::vector<int> Mass, char *MassSign) //Определение знака, который зависит от отклонения среднего значения
		{
			float AveValue = AveVal(Mass);
			for (int i = 0; i < data.n; i++)
			{
				if (Mass[i] - AveValue > 0)
					MassSign[i] = '+';
				else
					MassSign[i] = '-';
			}
			return MassSign;
		}

		int CountSign() //определение количесва совпадающих и различающихся знаков
		{
			nA = 0;
			nB = 0;
			MassSignX = DefinitionSign(data.MassX, MassSignX);
			MassSignY = DefinitionSign(data.MassY, MassSignY);
			for (int i = 0;i < data.n;i++) 
			{
				if (MassSignX[i] == MassSignY[i])
					nA++;
				else
					nB++;
			}
			return 0;
		}

		
	public:
		MassBas(const IDataProvider& dataProvider): dataProvider(dataProvider) {}

		~MassBas() = default;

		float CalculationFehner()//вычисление коэффициента 
		{
			CountSign();
			Fenh = float(nA - nB) / float(nA + nB);//формуля для вычисления коэффициента
			return(Fenh);
		}		
	};
}