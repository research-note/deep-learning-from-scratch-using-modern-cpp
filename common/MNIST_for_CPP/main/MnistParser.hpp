#ifndef _MNIST_PARSER_HPP_
#define _MNIST_PARSER_HPP_

class MnistParser {
    public:
        MnistParser();
        ~MnistParser();
        void setFilePath(string filePath);
        void setNumData(int numData);
        void setLenInfo(int lenInfo);
        void setArrN(int arrN);
        void setData(vector<vector<T>> data);
        void loadMnist();
    private: 
        string filtPath;
        int numData;
        int lenInfo;
        int arrN;
        vector<vector<T>> data;
        vector<int> infoArr;

        void readMnist();
}

#include "MnistParser.cc"

#endif