#include "MassBas.h"

namespace CorrelationCoefficients {
		float MassBas::AveVal(std::vector<int> Mass) const 
		{
			int Summ = 0;
			for (int i = 0; i < data.n;i++)
				Summ += Mass[i];
			return Summ / data.n;
		}
		char *MassBas::DefinitionSign(std::vector<int> Mass, char *MassSign) 
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
		int MassBas::CountSign() 
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
		float MassBas::CalculationFehner()
		{
			CountSign();
			Fenh = float(nA - nB) / float(nA + nB);//формуля для вычисления коэффициента
			return(Fenh);
		}
}
