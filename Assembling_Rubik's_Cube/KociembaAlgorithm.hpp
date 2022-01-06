#pragma once

#include "RubiksCube.hpp"

// Проверка на нахождении кубика-рубика в первом состоянии
bool CheckFirstStateRC(const t_RC RC);

// Проверка на нахождении кубика-рубика во втором состоянии
bool CheckSecondStateRC(const t_RC RC);

// Проверка на нахождении кубика-рубика в собранном состоянии
bool CheckAssembledStateRC(const t_RC RC);

/* 
 * Алгоритм Коцембы для сборки кубика-рубика
 * Использовать:
 *   Алгоритм: IDA*
 *   СД: очередь с приоритетом
 */
t_NotationRC KociembaAlgorithm(t_RC RC);