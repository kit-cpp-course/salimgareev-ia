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
		char *MassSignY = new char[data.n];//массив со знаками Y
		float AveVal(std::vector<int> Mass) const;//среднее значение
		char *DefinitionSign(std::vector<int> Mass, char *MassSign);//Определение знака, который зависит от отклонения среднего значения
		int CountSign();//определение количесва совпадающих и различающихся знаков
	public:
		MassBas(const IDataProvider& dataProvider): dataProvider(dataProvider) {}
		~MassBas() = default;
		float CalculationFehner();//вычисление коэффициента					
	};
}
