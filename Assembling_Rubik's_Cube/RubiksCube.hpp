#pragma once

#include <vector>
#include <string>

#define SWAP2(type, el1, el2) {type t = el1; el1 = el2; el2 = t;}

// RC - rubik's cube (кубик-рубика)

#define COUNT_SIDE_RC 6		/* Число сторон кубика-рубика*/
#define COUNT_EL_RC 3		/* Число элементов в столбце и строке стороны кубика-рубика */

// Перечисление цветов кубика-рубика
typedef enum
{
	noneColor = 0,
	white = 1,
	orange = 2,
	green = 3,
	red = 4,
	blue = 5,
	yellow = 6
}
t_ColorsRC;

// Перечисление сторон кубика-рубика с индексом стороны
typedef enum
{
	up = 0,
	left = 1,
	front = 2,
	right = 3,
	back = 4,
	down = 5,
	noneSide = 6
}
t_SideRotateRC;

// СД типа "элемент кубика-рубика"
typedef t_ColorsRC t_ElRC;

// СД типа "столбец стороны кубика-рубика"
typedef std::vector<t_ElRC> t_ColumnSideRC;

// СД типа "сторона кубика-рубика"
typedef std::vector<t_ColumnSideRC> t_SideRC;

// СД типа "кубик-рубика"
typedef std::vector<t_SideRC> t_RC;

// Нотация кубика-рубика
typedef std::vector<std::string> t_NotationRC;

// Элемент нотации кубика-рубика
typedef std::string t_ElNotationRC;

// Создание кубика-рубика
t_RC CreateRC(void);

// Удаление кубика-рубика
void DoneRC(t_RC &RC);

// Вывод состояния кубика-рубика на экран
void WriteRC(const t_RC &RC);

// Разборка кубика-рубика
void DisassemblyRC(t_RC &RC, const t_NotationRC &notation);

// Разборка (случайная) кубика-рубика
void DisassemblyRandomRC(t_RC &RC);

// Чтение нотации кубика-рубика
t_NotationRC ReadNotationRC(void);

// Вывод нотации кубика-рубика
void WriteNotationRC(const t_NotationRC &notation);

// Приведение кубика-рубика в собранное состояние
void AssembledStateRC(t_RC &RC);

// Повороты граней кубика-рубика на 90 градусов по часовой стрелке

void RotateSideClockwiseRC(t_SideRC &sideRC);
void RotateLClockwiseRC(t_RC &RC);
void RotateRClockwiseRC(t_RC &RC);
void RotateUClockwiseRC(t_RC &RC);
void RotateBClockwiseRC(t_RC &RC);
void RotateFClockwiseRC(t_RC &RC);
void RotateDClockwiseRC(t_RC &RC);

// Повороты граней кубика-рубика на 90 градусов против часовой стрелке

void RotateSideCounterClockwiseRC(t_SideRC &sideRC);
void RotateLCounterClockwiseRC(t_RC &RC);
void RotateRCounterClockwiseRC(t_RC &RC);
void RotateUCounterClockwiseRC(t_RC &RC);
void RotateBCounterClockwiseRC(t_RC &RC);
void RotateFCounterClockwiseRC(t_RC &RC);
void RotateDCounterClockwiseRC(t_RC &RC);


// Повороты граней кубика-рубика на 180 градусов

void RotateSideDoubleTurnRC(t_SideRC &sideRC);
void RotateLDoubleTurnRC(t_RC &RC);
void RotateRDoubleTurnRC(t_RC &RC);
void RotateUDoubleTurnRC(t_RC &RC);
void RotateBDoubleTurnRC(t_RC &RC);
void RotateFDoubleTurnRC(t_RC &RC);
void RotateDDoubleTurnRC(t_RC &RC);