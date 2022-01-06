#pragma once

#include <vector>
#include <string>

#define COUNT_SIDE_RC 6
#define COUNT_EL_RC 3

// RC - rubik's cube (кубик-рубика)

typedef std::vector<std::string> t_NotationRC;
typedef std::string t_ElNotationRC;

// Перечисление цветов кубика-рубика
typedef enum
{
	none = 0,
	white = 1,
	orange = 2,
	green = 3,
	red = 4,
	blue = 5,
	yellow = 6
}
t_ColorsRC;

// СД типа "кубик-рубика"
typedef t_ColorsRC t_ElRC;
typedef std::vector<t_ElRC> t_ColumnSideRC;
typedef std::vector<t_ColumnSideRC> t_SideRC;
typedef std::vector<t_SideRC> t_RC;

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

/*
// Повороты граней кубика-рубика на 90 градусов по часовой стрелке

void RotateLClockwiseRC(t_RC &RC);
void RotateRClockwiseRC(t_RC &RC);
void RotateUClockwiseRC(t_RC &RC);
void RotateBClockwiseRC(t_RC &RC);
void RotateFClockwiseRC(t_RC &RC);
void RotateDClockwiseRC(t_RC &RC);

// Повороты граней кубика-рубика на 90 градусов против часовой стрелке

void RotateLCounterClockwiseRC(t_RC &RC);
void RotateRCounterClockwiseRC(t_RC &RC);
void RotateUCounterClockwiseRC(t_RC &RC);
void RotateBCounterClockwiseRC(t_RC &RC);
void RotateFCounterClockwiseRC(t_RC &RC);
void RotateDCounterClockwiseRC(t_RC &RC);


// Повороты граней кубика-рубика на 180 градусов

void RotateLDoubleTurnRC(t_RC &RC);
void RotateRDoubleTurnRC(t_RC &RC);
void RotateUDoubleTurnRC(t_RC &RC);
void RotateBDoubleTurnRC(t_RC &RC);
void RotateFDoubleTurnRC(t_RC &RC);
void RotateDDoubleTurnRC(t_RC &RC);
*/