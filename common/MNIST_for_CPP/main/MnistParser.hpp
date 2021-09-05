#ifndef _MNIST_PARSER_HPP_
#define _MNIST_PARSER_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define SIZE 784 // 28*28
#define NUM_TEST 10000

class MnistParser {
    public:
        MnistParser();
        ~MnistParser();
        void loadMnist();
        double test_image[NUM_TEST][SIZE];
    private: 
        void readMnistImage(char *file_path, int num_data, int len_info, int arr_n, unsigned char data_char[][SIZE], int info_arr[]);
        void readMnistLabel(char *file_path, int num_data, int len_info, int arr_n, unsigned char data_char[][1], int info_arr[]);
        void flipLong(unsigned char * ptr);
        void imageChar2Double(int num_data, unsigned char data_image_char[][SIZE], double data_image[][SIZE]);
        void labelChar2Int(int num_data, unsigned char data_label_char[][1], int data_label[]);
        void printMnistPixel(double data_image[][SIZE], int num_data);
        void print_mnist_label(int data_label[], int num_data);
        void saveImage(int n, char name[]);
        void saveMnistPgm(double data_image[][SIZE], int index);
};

#include "MnistParser.cc"

#endif