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

		float AveVal(std::vector<int> Mass) const //������� ��������
		{
			int Summ = 0;
			for (int i = 0; i < data.n;i++)
				Summ += Mass[i];
			return Summ / data.n;
		}

		char *DefinitionSign(std::vector<int> Mass, char *MassSign) //����������� �����, ������� ������� �� ���������� �������� ��������
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

		int CountSign() //����������� ��������� ����������� � ������������� ������
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

		float CalculationFehner()//���������� ������������ 
		{
			CountSign();
			Fenh = float(nA - nB) / float(nA + nB);//������� ��� ���������� ������������
			return(Fenh);
		}		
	};
}