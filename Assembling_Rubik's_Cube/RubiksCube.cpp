#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include "RubiksCube.hpp"

t_RC CreateRC(void)
{
	t_RC RC(COUNT_SIDE_RC, t_SideRC(COUNT_EL_RC, t_ColumnSideRC(COUNT_EL_RC, t_ColorsRC::noneColor)));
	AssembledStateRC(RC);

	return RC;
}

void DoneRC(t_RC &RC)
{
	for (int i = 0; i < COUNT_SIDE_RC; i++)
	{
		for (int j = 0; j < COUNT_EL_RC; j++)
			RC[i][j].clear();
		
		RC[i].clear();
	}
}

void WriteElRC(const t_ElRC &elRC)
{
	switch (elRC)
	{
		case white:
			std::cout << "w ";
			break;
		case orange:
			std::cout << "o ";
			break;
		case green:
			std::cout << "g ";
			break;
		case red:
			std::cout << "r ";
			break;
		case blue:
			std::cout << "b ";
			break;
		case yellow:
			std::cout << "y ";
			break;
		default:
			assert(elRC == noneColor && "Ошибка: нет данного элемента!");
			break;
	}
}

void WriteRC(const t_RC &RC)
{
	for (int i = 0; i < COUNT_EL_RC; i++)
	{
		for (int j = 0; j < COUNT_EL_RC; j++)
			std::cout << "  ";

		for (int j = 0; j < COUNT_EL_RC; j++)
			WriteElRC(RC[0][i][j]);

		std::cout << std::endl;
	}

	int cntElWrite = COUNT_EL_RC * (COUNT_SIDE_RC - 2);
	for (int i = 0; i < COUNT_EL_RC; i++)
	{
		for (int j = 0, sideRC = 1; j < cntElWrite; j++, sideRC = (int) (j / COUNT_EL_RC) + 1)
			WriteElRC(RC[sideRC][i][j % 3]);

		std::cout << std::endl;
	}

	for (int i = 0; i < COUNT_EL_RC; i++)
	{
		for (int j = 0; j < COUNT_EL_RC; j++)
			std::cout << "  ";

		for (int j = 0; j < COUNT_EL_RC; j++)
			WriteElRC(RC[COUNT_SIDE_RC - 1][i][j]);

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

t_ColorsRC GetColorRC(const int &num)
{
	t_ColorsRC colorRC = t_ColorsRC::noneColor;
	switch (num)
	{
		case 0:
			colorRC = t_ColorsRC::noneColor;
			break;
		case 1:
			colorRC = t_ColorsRC::white;
			break;
		case 2:
			colorRC = t_ColorsRC::orange;
			break;
		case 3:
			colorRC = t_ColorsRC::green;
			break;
		case 4:
			colorRC = t_ColorsRC::red;
			break;
		case 5:
			colorRC = t_ColorsRC::blue;
			break;
		case 6:
			colorRC = t_ColorsRC::yellow;
			break;
		default:
			assert(1 && "Ошибка: не существует данного цвета!");
			break;
	}

	return colorRC;
}

void AssembledStateRC(t_RC &RC)
{
	for (int i = 0; i < COUNT_SIDE_RC; i++)
		for (int j = 0; j < COUNT_EL_RC; j++)
			for (int k = 0; k < COUNT_EL_RC; k++)
				RC[i][j][k] = GetColorRC(i + 1);
}

t_NotationRC ReadNotationRC(void)
{
	t_NotationRC notationRC;

	int index = -1;
	char ch;
	std::cin.get(ch);
	while (ch != '\n')
	{
		if (ch != ' ')
		{
			if (index == -1)
			{
				notationRC.push_back("");
				index++;
			}

			notationRC[index].push_back(ch);
		}
		else
		{
			notationRC.push_back("");
			index++;
		}

		std::cin.get(ch);
	}

	return notationRC;
}

void WriteNotationRC(const t_NotationRC &notation)
{
	for (uint8_t i = 0; i < notation.size(); i++)
		std::cout << notation[i] << ' ';

	std::cout << std::endl;
}

/*
void DisassemblyRC(t_RC &RC, const t_NotationRC &notation)
{
	for (t_ElNotationRC elNotation : notation)
	{
		if (elNotation == "L")
			RotateLClockwiseRC(RC);
		else if (elNotation == "L'")
			RotateLCounterClockwiseRC(RC);
		else if (elNotation == "L2")
			RotateLDoubleTurnRC(RC);

		else if (elNotation == "R")
			RotateRClockwiseRC(RC);
		else if (elNotation == "R'")
			RotateRCounterClockwiseRC(RC);
		else if (elNotation == "R2")
			RotateRDoubleTurnRC(RC);

		else if (elNotation == "U")
			RotateUClockwiseRC(RC);
		else if (elNotation == "U'")
			RotateUCounterClockwiseRC(RC);
		else if (elNotation == "U2")
			RotateUDoubleTurnRC(RC);

		else if (elNotation == "D")
			RotateDClockwiseRC(RC);
		else if (elNotation == "D'")
			RotateDCounterClockwiseRC(RC);
		else if (elNotation == "D2")
			RotateDDoubleTurnRC(RC);

		else if (elNotation == "F")
			RotateFClockwiseRC(RC);
		else if (elNotation == "F'")
			RotateFCounterClockwiseRC(RC);
		else if (elNotation == "F2")
			RotateFDoubleTurnRC(RC);

		else if (elNotation == "B")
			RotateBClockwiseRC(RC);
		else if (elNotation == "B'")
			RotateBCounterClockwiseRC(RC);
		else if (elNotation == "B2")
			RotateBDoubleTurnRC(RC);
	}
}
*/

void RotateSideClockwiseRC(t_SideRC &sideRC)
{
	// Повороты углов стороны
	SWAP2(t_ElRC, sideRC[0][0], sideRC[COUNT_EL_RC - 1][0]);
	SWAP2(t_ElRC, sideRC[COUNT_EL_RC - 1][0], sideRC[COUNT_EL_RC - 1][COUNT_EL_RC - 1]);
	SWAP2(t_ElRC, sideRC[COUNT_EL_RC - 1][COUNT_EL_RC - 1], sideRC[0][COUNT_EL_RC - 1]);

	// Повороты рёбер стороны
	SWAP2(t_ElRC, sideRC[0][1], sideRC[1][COUNT_EL_RC - 1]);
	SWAP2(t_ElRC, sideRC[0][1], sideRC[1][0]);
	SWAP2(t_ElRC, sideRC[1][0], sideRC[COUNT_EL_RC - 1][1]);
}

void SwapRowsRC(t_SideRC &side1RC, const int &numRowSide1RC, t_SideRC &side2RC, const int &numRowSide2RC)
{
	t_ElRC t;
	for (int i = 0; i < COUNT_EL_RC; i++)
	{
		t = side1RC[numRowSide1RC][i];
		side1RC[numRowSide1RC][i] = side2RC[numRowSide2RC][i];
		side2RC[numRowSide2RC][i] = t;
	}
}

void SwapColumnsRC(t_SideRC &side1RC, const int &numColumnSide1RC, t_SideRC &side2RC, const int &numColumnSide2RC)
{
	t_ElRC t;
	for (int i = 0; i < COUNT_EL_RC; i++)
	{
		t = side1RC[i][numColumnSide1RC];
		side1RC[i][numColumnSide1RC] = side2RC[i][numColumnSide2RC];
		side2RC[i][numColumnSide2RC] = t;
	}
}


void SwapRowAndColumnsRC(t_SideRC &sideRowRC, const int &numSideRowRC, t_SideRC &sideColumnRC, const int &numSideColumnRC)
{
	t_ElRC t;
	for (int i = 0; i < COUNT_EL_RC; i++)
	{
		t = sideRowRC[numSideRowRC][i];
		sideRowRC[numSideRowRC][i] = sideColumnRC[i][numSideColumnRC];
		sideColumnRC[i][numSideColumnRC] = t;
	}
}


void RotateLClockwiseRC(t_RC &RC)
{
	RotateSideClockwiseRC(RC[t_SideRotateRC::left]);
	
	std::reverse(RC[t_SideRotateRC::back].begin(), RC[t_SideRotateRC::back].end());
	std::reverse(RC[t_SideRotateRC::down].begin(), RC[t_SideRotateRC::down].end());
	SwapColumnsRC(RC[t_SideRotateRC::up], 0, RC[t_SideRotateRC::front], 0);
	SwapColumnsRC(RC[t_SideRotateRC::up], 0, RC[t_SideRotateRC::back], 0);
	SwapColumnsRC(RC[t_SideRotateRC::back], 0, RC[t_SideRotateRC::down], 0);
}

void RotateRClockwiseRC(t_RC &RC)
{
	RotateSideClockwiseRC(RC[t_SideRotateRC::right]);

	std::reverse(RC[t_SideRotateRC::back].begin(), RC[t_SideRotateRC::back].end());
	std::reverse(RC[t_SideRotateRC::up].begin(), RC[t_SideRotateRC::up].end());
	SwapColumnsRC(RC[t_SideRotateRC::up], COUNT_EL_RC - 1, RC[t_SideRotateRC::front], COUNT_EL_RC - 1);
	SwapColumnsRC(RC[t_SideRotateRC::front], COUNT_EL_RC - 1, RC[t_SideRotateRC::down], COUNT_EL_RC - 1);
	SwapColumnsRC(RC[t_SideRotateRC::back], COUNT_EL_RC - 1, RC[t_SideRotateRC::down], COUNT_EL_RC - 1);
}

void RotateUClockwiseRC(t_RC &RC)
{
	RotateSideClockwiseRC(RC[t_SideRotateRC::up]);

	SwapRowsRC(RC[t_SideRotateRC::front], 0, RC[t_SideRotateRC::right], 0);
	SwapRowsRC(RC[t_SideRotateRC::right], 0, RC[t_SideRotateRC::back], 0);
	SwapRowsRC(RC[t_SideRotateRC::back], 0, RC[t_SideRotateRC::left], 0);
}

void RotateDClockwiseRC(t_RC &RC)
{
	RotateSideClockwiseRC(RC[t_SideRotateRC::down]);

	SwapRowsRC(RC[t_SideRotateRC::front], COUNT_EL_RC - 1, RC[t_SideRotateRC::right], COUNT_EL_RC - 1);
	SwapRowsRC(RC[t_SideRotateRC::front], COUNT_EL_RC - 1, RC[t_SideRotateRC::left], COUNT_EL_RC - 1);
	SwapRowsRC(RC[t_SideRotateRC::back], COUNT_EL_RC - 1, RC[t_SideRotateRC::left], COUNT_EL_RC - 1);
}

void RotateFClockwiseRC(t_RC &RC)
{
	RotateSideClockwiseRC(RC[t_SideRotateRC::front]);

	std::reverse(RC[t_SideRotateRC::left].begin(), RC[t_SideRotateRC::left].end());
	std::reverse(RC[t_SideRotateRC::right].begin(), RC[t_SideRotateRC::right].end());
	SwapRowAndColumnsRC(RC[t_SideRotateRC::up], COUNT_EL_RC - 1, RC[t_SideRotateRC::right], 0);
	SwapRowAndColumnsRC(RC[t_SideRotateRC::up], COUNT_EL_RC - 1, RC[t_SideRotateRC::left], COUNT_EL_RC - 1);
	SwapRowAndColumnsRC(RC[t_SideRotateRC::down], 0, RC[t_SideRotateRC::left], COUNT_EL_RC - 1);
}

void RotateBClockwiseRC(t_RC &RC)
{
	RotateSideClockwiseRC(RC[t_SideRotateRC::back]);

	std::reverse(RC[t_SideRotateRC::left].begin(), RC[t_SideRotateRC::left].end());
	std::reverse(RC[t_SideRotateRC::right].begin(), RC[t_SideRotateRC::right].end());
	SwapRowAndColumnsRC(RC[t_SideRotateRC::up], 0, RC[t_SideRotateRC::right], COUNT_EL_RC - 1);
	SwapRowAndColumnsRC(RC[t_SideRotateRC::down], COUNT_EL_RC - 1, RC[t_SideRotateRC::right], COUNT_EL_RC - 1);
	SwapRowAndColumnsRC(RC[t_SideRotateRC::down], COUNT_EL_RC - 1, RC[t_SideRotateRC::left], 0);
}


void RotateSideCounterClockwiseRC(t_SideRC &sideRC)
{
	// Повороты углов стороны
	SWAP2(t_ElRC, sideRC[0][0], sideRC[COUNT_EL_RC - 1][0]);
	SWAP2(t_ElRC, sideRC[0][0], sideRC[0][COUNT_EL_RC - 1]);
	SWAP2(t_ElRC, sideRC[COUNT_EL_RC - 1][COUNT_EL_RC - 1], sideRC[0][COUNT_EL_RC - 1]);

	// Повороты рёбер стороны
	SWAP2(t_ElRC, sideRC[0][1], sideRC[1][COUNT_EL_RC - 1]);
	SWAP2(t_ElRC, sideRC[1][COUNT_EL_RC - 1], sideRC[COUNT_EL_RC - 1][1]);
	SWAP2(t_ElRC, sideRC[1][0], sideRC[COUNT_EL_RC - 1][1]);
}

void RotateLCounterClockwiseRC(t_RC &RC)
{
	RotateSideCounterClockwiseRC(RC[t_SideRotateRC::left]);

	std::reverse(RC[t_SideRotateRC::back].begin(), RC[t_SideRotateRC::back].end());
	std::reverse(RC[t_SideRotateRC::up].begin(), RC[t_SideRotateRC::up].end());
	SwapColumnsRC(RC[t_SideRotateRC::up], 0, RC[t_SideRotateRC::front], 0);
	SwapColumnsRC(RC[t_SideRotateRC::front], 0, RC[t_SideRotateRC::down], 0);
	SwapColumnsRC(RC[t_SideRotateRC::back], 0, RC[t_SideRotateRC::down], 0);
}

void RotateRCounterClockwiseRC(t_RC &RC)
{
	RotateSideCounterClockwiseRC(RC[t_SideRotateRC::right]);

	std::reverse(RC[t_SideRotateRC::back].begin(), RC[t_SideRotateRC::back].end());
	std::reverse(RC[t_SideRotateRC::down].begin(), RC[t_SideRotateRC::down].end());
	SwapColumnsRC(RC[t_SideRotateRC::up], COUNT_EL_RC - 1, RC[t_SideRotateRC::front], COUNT_EL_RC - 1);
	SwapColumnsRC(RC[t_SideRotateRC::up], COUNT_EL_RC - 1, RC[t_SideRotateRC::back], COUNT_EL_RC - 1);
	SwapColumnsRC(RC[t_SideRotateRC::back], COUNT_EL_RC - 1, RC[t_SideRotateRC::down], COUNT_EL_RC - 1);
}

void RotateUCounterClockwiseRC(t_RC &RC)
{
	RotateSideCounterClockwiseRC(RC[t_SideRotateRC::up]);

	SwapRowsRC(RC[t_SideRotateRC::front], 0, RC[t_SideRotateRC::right], 0);
	SwapRowsRC(RC[t_SideRotateRC::front], 0, RC[t_SideRotateRC::left], 0);
	SwapRowsRC(RC[t_SideRotateRC::back], 0, RC[t_SideRotateRC::left], 0);
}

void RotateDCounterClockwiseRC(t_RC &RC)
{
	RotateSideCounterClockwiseRC(RC[t_SideRotateRC::down]);

	SwapRowsRC(RC[t_SideRotateRC::front], COUNT_EL_RC - 1, RC[t_SideRotateRC::right], COUNT_EL_RC - 1);
	SwapRowsRC(RC[t_SideRotateRC::right], COUNT_EL_RC - 1, RC[t_SideRotateRC::back], COUNT_EL_RC - 1);
	SwapRowsRC(RC[t_SideRotateRC::back], COUNT_EL_RC - 1, RC[t_SideRotateRC::left], COUNT_EL_RC - 1);
}

void RotateFCounterClockwiseRC(t_RC &RC)
{
	RotateSideCounterClockwiseRC(RC[t_SideRotateRC::front]);

	std::reverse(RC[t_SideRotateRC::left].begin(), RC[t_SideRotateRC::left].end());
	std::reverse(RC[t_SideRotateRC::right].begin(), RC[t_SideRotateRC::right].end());
	SwapRowAndColumnsRC(RC[t_SideRotateRC::up], COUNT_EL_RC - 1, RC[t_SideRotateRC::right], 0);
	SwapRowAndColumnsRC(RC[t_SideRotateRC::down], 0, RC[t_SideRotateRC::right], 0);
	SwapRowAndColumnsRC(RC[t_SideRotateRC::down], 0, RC[t_SideRotateRC::left], COUNT_EL_RC - 1);
}

void RotateBCounterClockwiseRC(t_RC &RC)
{
	RotateSideCounterClockwiseRC(RC[t_SideRotateRC::back]);

	std::reverse(RC[t_SideRotateRC::left].begin(), RC[t_SideRotateRC::left].end());
	std::reverse(RC[t_SideRotateRC::right].begin(), RC[t_SideRotateRC::right].end());
	SwapRowAndColumnsRC(RC[t_SideRotateRC::up], 0, RC[t_SideRotateRC::right], COUNT_EL_RC - 1);
	SwapRowAndColumnsRC(RC[t_SideRotateRC::up], 0, RC[t_SideRotateRC::left], 0);
	SwapRowAndColumnsRC(RC[t_SideRotateRC::down], COUNT_EL_RC - 1, RC[t_SideRotateRC::left], 0);
}


void RotateSideDoubleTurnRC(t_SideRC &sideRC)
{
	// Повороты углов стороны
	SWAP2(t_ElRC, sideRC[0][0], sideRC[COUNT_EL_RC - 1][COUNT_EL_RC - 1]);
	SWAP2(t_ElRC, sideRC[0][COUNT_EL_RC - 1], sideRC[COUNT_EL_RC - 1][0]);

	// Повороты рёбер стороны
	SWAP2(t_ElRC, sideRC[0][1], sideRC[COUNT_EL_RC - 1][1]);
	SWAP2(t_ElRC, sideRC[1][0], sideRC[1][COUNT_EL_RC - 1]);
}

void RotateLDoubleTurnRC(t_RC &RC)
{
	RotateSideDoubleTurnRC(RC[t_SideRotateRC::left]);

}

void RotateRDoubleTurnRC(t_RC &RC)
{
	RotateSideDoubleTurnRC(RC[t_SideRotateRC::right]);

}

void RotateUDoubleTurnRC(t_RC &RC)
{
	RotateSideDoubleTurnRC(RC[t_SideRotateRC::up]);

}

void RotateDDoubleTurnRC(t_RC &RC)
{
	RotateSideDoubleTurnRC(RC[t_SideRotateRC::down]);

}

void RotateFDoubleTurnRC(t_RC &RC)
{
	RotateSideDoubleTurnRC(RC[t_SideRotateRC::front]);

}

void RotateBDoubleTurnRC(t_RC &RC)
{
	RotateSideDoubleTurnRC(RC[t_SideRotateRC::back]);

}