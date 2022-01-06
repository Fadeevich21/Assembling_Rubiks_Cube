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

	WriteRC(RC);

	DoneRC(RC);

	cout << "Привет, мир!" << endl;

	return 0;
}