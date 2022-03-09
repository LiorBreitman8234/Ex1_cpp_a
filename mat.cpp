//
// Created by bravo8234 on 03/03/2022.
//
#include "mat.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
namespace ariel {
    std::vector<char> illegal_Symbols{'\n','\t',' ','\r','\0'};
    std::string mat(int length, int height, char symbol1, char symbol2) {
        if((std::find(illegal_Symbols.begin(),illegal_Symbols.end(),symbol1) != illegal_Symbols.end()) || (std::find(illegal_Symbols.begin(),illegal_Symbols.end(),symbol2) != illegal_Symbols.end()))
        {
            throw std::invalid_argument("Illegal symbol");
        }
        if(length %2 == 0 || height %2 == 0){
            throw std::invalid_argument("Mat size is always odd");
        }
        if(length <0 || height < 0)
        {
            throw std::invalid_argument("Mat size is always positive");
        }
        std::vector<std::vector<char>> mat;
        mat.resize(height, std::vector<char>(length));
        int keepHeight = height;
        int keepLength = length;
        int flag = 1;
        int numOfIterations = length < height ? length / 2 + 1 : height / 2 + 1;
        for(int iteration =0; iteration < numOfIterations; iteration++)
        {
            height = keepHeight -2*iteration;
            length = keepLength -2*iteration;
            for (int i = 0; i < length; i++) {
                mat[iteration][i + iteration] = flag == 1 ? symbol1 : symbol2;
            }
            for (int i = 0; i < height; i++) {
                mat[i + iteration][iteration] = flag == 1 ? symbol1 : symbol2;
            }
            for (int i = 0; i < height; i++) {
                mat[i + iteration][iteration + length - 1] = flag == 1 ? symbol1 : symbol2;
            }
            for (int i = 0; i < length; i++) {
                mat[iteration + height - 1][i + iteration] = flag == 1 ? symbol1 : symbol2;
            }
            flag = flag == 1 ? 2 : 1;
        }
        std::string toPrint;
        height = keepHeight;
        length = keepLength;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < length; j++) {
                toPrint.push_back(mat[i][j]);
            }
            toPrint.push_back('\n');
        }
        return toPrint;
    }



}
