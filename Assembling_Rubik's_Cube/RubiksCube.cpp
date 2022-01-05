#include "RubiksCube.h"
#include <vector>
#include <string>

// RC - rubik's cube (кубик-рубика)

// Перечисление цветов кубика-рубика
typedef enum ColorsRC {none, white, orange, green, red, blue, yellow};

// СД типа "кубик-рубика"
typedef std::vector<std::vector<ColorsRC>> t_RC;

// Создание кубика-рубика
t_RC CreateRC(void);

// Удаление кубика-рубика
void DoneRC(t_RC *RC);

// Сборка кубика-рубика
void AssemblyRC(t_RC *RC);

// Разборка кубика-рубика
void DisassemblyRC(t_RC *RC);

// Разборка (случайная) кубика-рубика
void DisassemblyRandomRC(t_RC RC);

// Чтение нотации кубика-рубика
std::string ReadNotationRC(void);

// Вывод нотации кубика-рубика
std::string WriteNotationRC(void);

// Приведение кубика-рубика в собранное состояние
void AssembledStateRC(t_RC* RC);


// Повороты граней кубика-рубика на 90 градусов по часовой стрелке

void RotateLClockwiseRC(t_RC *RC);
void RotateRClockwiseRC(t_RC* RC);
void RotateUClockwiseRC(t_RC* RC);
void RotateBClockwiseRC(t_RC* RC);
void RotateFClockwiseRC(t_RC* RC);
void RotateDClockwiseRC(t_RC* RC);

// Повороты граней кубика-рубика на 90 градусов против часовой стрелке

void RotateLCounterClockwiseRC(t_RC* RC);
void RotateRCounterClockwiseRC(t_RC* RC);
void RotateUCounterClockwiseRC(t_RC* RC);
void RotateBCounterClockwiseRC(t_RC* RC);
void RotateFCounterClockwiseRC(t_RC* RC);
void RotateDCounterClockwiseRC(t_RC* RC);


// Повороты граней кубика-рубика на 180 градусов

void RotateLDoubleTurnRC(t_RC* RC);
void RotateRDoubleTurnRC(t_RC* RC);
void RotateUDoubleTurnRC(t_RC* RC);
void RotateBDoubleTurnRC(t_RC* RC);
void RotateFDoubleTurnRC(t_RC* RC);
void RotateDDoubleTurnRC(t_RC* RC);