#pragma once
#include <iostream>
#include "IDataProvider.h"
#include <vector>

namespace CorrelationCoefficients{
	class MassBas {
		const IDataProvider& dataProvider;
		Data data = dataProvider.GetData();
		float Fenh;//�����������
		int nA, nB;//�������� ��� ����������� ���������� ������(A- ���������, B - �� ���������)
		char *MassSignX = new char[data.n];//������ �� ������� X
		char *MassSignY = new char[data.n];//������ �� ������� X
		float AveVal(std::vector<int> Mass) const; //������� ��������
		char *DefinitionSign(std::vector<int> Mass, char *MassSign);//����������� �����, ������� ������� �� ���������� �������� ��������
		int CountSign(); //����������� ��������� ����������� � ������������� ������
	public:
		MassBas(const IDataProvider& dataProvider): dataProvider(dataProvider) {}
		~MassBas() = default;
		float CalculationFehner();//���������� ������������			
	};
}