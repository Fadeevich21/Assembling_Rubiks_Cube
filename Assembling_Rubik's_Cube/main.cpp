#include <iostream>
#include <Windows.h>
#include "RubiksCube.hpp"
#include "KociembaAlgorithm.hpp"

using namespace std;

int main()
{
	SetConsoleCP(1251);				// Устанавливает кодировку ввода из консоли и из редактора кода
	SetConsoleOutputCP(1251);		// Устанавливает кодировку вывода на консоль

	t_RC RC = CreateRC();

	
	cout << "Введите нотацию кубика-рубика:" << endl;
	t_NotationRC notationRC = ReadNotationRC();

	cout << "Нотация кубика-рубика:" << endl;
	WriteNotationRC(notationRC);

	DisassemblyRC(RC, notationRC);
	

	/*
	int n = 6;
	for (int i = 0; i < n; i++)
	{
		RotateRClockwiseRC(RC);
		RotateUClockwiseRC(RC);
		RotateRCounterClockwiseRC(RC);
		RotateUCounterClockwiseRC(RC);
	}
	*/

	cout << endl << "Вид кубика-рубика" << endl;
	WriteRC(RC);
	
	DoneRC(RC);

	cout << "Привет, мир!" << endl;

	return 0;
}