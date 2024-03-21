/**
 * Description: 使用Opencv，画出astar的最短路径
 * Time:2024-03-20
 * Author: Jimmy Nie
 * E-Mail: nieshihua@126.com
*/

#include <unistd.h>
#include <iostream>
#include <vector>
#include <string>
#include "astar/astar.h"
#include "read_map/read_map.h"
#include "display/display.h"

using namespace std;

int main() {
    string mapPath = "/astar_map.txt";   ///记得修改路径
    Point2D startPos {1, 4};
    Point2D targetPos {26, 18};
    float weightA = 1.0;                  //权重a
    float weightB = 1.0;                  //权重b

    ///处理当前的文件路径
    char dir[128] = {0};
    if(!getcwd(dir, sizeof(dir))) {
        std::cout << "getcwd failed!\n";
        return 0;
    }
    mapPath = dir + mapPath;

    ///地图数据
    vector<vector<int>> mapData(MapData(mapPath));
    if(mapData.empty())
        return 0;

    ///寻找路径
    ASTAR::Astar astar(mapData);
    auto path = astar.FindPath(startPos, targetPos);
    if(path.empty()) {
        std::cout << "A* 算法未找到路径 !!!" << std::endl;
        return 0;
    }

    std::cout << "\n[" << startPos.x << "," << startPos.y << "] -> ["
                << targetPos.x << "," << targetPos.y << "]的 A* 算法找到的最短路径如下：" << std::endl;
    for(auto& point : path) {
        std::cout << "[" << point.x << "," << point.y << "] ";
    }
    std::cout << std::endl;

    ///显示地图 & 路径
    Display(path, mapData, startPos, targetPos, "Astar");

    return 0;
}
