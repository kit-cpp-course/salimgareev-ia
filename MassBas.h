/*
 *MassBas.h
 */
#pragma once
#include <iostream>
#include "IDataProvider.h"
#include <vector>

namespace CorrelationCoefficients{
	/*
	 *����� ��� ���������� ������������ �������
	 */
	class MassBas {
		/*
		 *������ �� ��������� ������ IdataProvider
		 */
		const IDataProvider& dataProvider;
		/*
		 *��������� ���������� ������� ������
		 */
		Data data;
		/*
		 *����������� �������
		 */
		float Fenh;
		/*
		 *�������� ��� ����������� ���������� ������(nA- ���������, nB - �� ���������)
		 */
		int nA, nB;
		/*
		 *������ �� ������� ���������� X
		 */
		char *MassSignX;
		/*
		 *������ �� ������� ���������� Y
		 */
		char *MassSignY;
		/*
		 *������� ��� ��������� �������� ��������
		 */
		float AveVal(std::vector<int> Mass) const;
		/*
		 *������� ��� ����������� ����� ���������� �� �������� ��������
		 */
		char *DefinitionSign(std::vector<int> Mass, char *MassSign);
		/*
		 *������� ��� ����������� nA(���������� ��������� ������) � nB(���������� ����������� ������)
		 */
		int CountSign();
	public:
		/*
		 *����������� ��������� ������ �� ��������� ������ IdataProvider
		 */
		MassBas(const IDataProvider& dataProvider);
		/*
		 *����������
		 */
		~MassBas();
		/*
		*����������� ����������� 
		*/
		MassBas(const MassBas& source);
		/*
		 *������� ��� ���������� ������������ �������
		 */
		float CalculationFehner();		
	};
}