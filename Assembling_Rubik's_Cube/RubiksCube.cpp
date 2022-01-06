#include <iostream>
#include "RubiksCube.hpp"
#include <cassert>

t_RC CreateRC(void)
{
	t_RC RC(COUNT_SIDE_RC, t_SideRC(COUNT_EL_RC, t_ColumnSideRC(COUNT_EL_RC, none)));
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
			assert(elRC == none && "Ошибка: нет данного элемента!");
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
	t_ColorsRC colorRC = none;
	switch (num)
	{
		case 0:
			colorRC = none;
			break;
		case 1:
			colorRC = white;
			break;
		case 2:
			colorRC = orange;
			break;
		case 3:
			colorRC = green;
			break;
		case 4:
			colorRC = red;
			break;
		case 5:
			colorRC = blue;
			break;
		case 6:
			colorRC = yellow;
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