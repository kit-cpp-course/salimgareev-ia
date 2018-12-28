/*
 *MassBas.h
 */
#pragma once
#include <iostream>
#include "IDataProvider.h"
#include <vector>

namespace CorrelationCoefficients{
	/*
	 *Класс для вычисления коэффициента Фехнера
	 */
	class MassBas {
		/*
		 *Ссылка на экземпляр класса IdataProvider
		 */
		const IDataProvider& dataProvider;
		/*
		 *Структура содержащая входные данные
		 */
		Data data;
		/*
		 *Коэффициент Фехнера
		 */
		float Fenh;
		/*
		 *Счетчики для определения совпадений знаков(nA- совпадают, nB - не совпадают)
		 */
		int nA, nB;
		/*
		 *массив со знаками отклонения X
		 */
		char *MassSignX;
		/*
		 *массив со знаками отклонения Y
		 */
		char *MassSignY;
		/*
		 *Функция для получения среднего значения
		 */
		float AveVal(std::vector<int> Mass) const;
		/*
		 *Функция для определения знака отклонения от среднего значения
		 */
		char *DefinitionSign(std::vector<int> Mass, char *MassSign);
		/*
		 *Функция для определения nA(количество совпавших знаков) и nB(количества несовпавщих знаков)
		 */
		int CountSign();
	public:
		/*
		 *Конструктор принимает ссылка на экземпляр класса IdataProvider
		 */
		MassBas(const IDataProvider& dataProvider);
		/*
		 *Деструктор
		 */
		~MassBas();
		/*
		*Конструктор копирования 
		*/
		MassBas(const MassBas& source);
		/*
		 *Функция для вычисления коэффициента Фехнера
		 */
		float CalculationFehner();		
	};
}