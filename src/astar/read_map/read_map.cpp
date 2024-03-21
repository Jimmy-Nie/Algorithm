/**
 * Description: 读取地图数据，转化为对应的格式
 * Time:2024-03-20
 * Author: Jimmy Nie
 * E-Mail: nieshihua@126.com
*/

#include<fstream>
#include<sstream>
#include <vector>
#include <string>
#include <iostream>
#include <sys/stat.h>
#include <string.h>
#include "read_map.h"

using namespace std;

vector<vector<int>> MapData(const string& mapPath) {
    ///判断map文件是否存在
    struct stat info;
    if(stat(mapPath.c_str(), &info) != 0) {
        std::cout << "The file " << mapPath << " : " << strerror(errno) << std::endl;
        return {};
    }

    ifstream f;
    f.open(mapPath);

    int tmp;
    string str;
    vector<int> tmp_vec;
    vector<vector<int>> mapData;

    while (getline(f, str)) {   //读取1行并将它赋值给字符串str
        tmp = 0;
        tmp_vec.clear();
        istringstream input(str);

        while (input >> tmp)          //通过input将第一行的数据一个一个的输入给a
            tmp_vec.push_back(tmp);

        mapData.push_back(tmp_vec);
    }

    if(!mapData.empty())
        std::cout << "Read map data ok ! W:" << mapData[5].size() << " `, H:" << mapData.size() << std::endl;

    return mapData;
}
