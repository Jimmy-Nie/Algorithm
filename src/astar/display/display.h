/**
 * Description: Display the astar path with opencv
 * Time:2024-03-20
 * Author: Jimmy Nie
 * E-Mail: nieshihua@126.com
*/

#pragma once
#include <vector>
#include <string>

#include "astar/astar.h"

void Display(const std::vector<Point2D>& pathPoint,
             const std::vector<std::vector<int>>& mapData,
             const Point2D& startPos, const Point2D& targetPos,
             std::string pictureName, bool saveFlag = true);
