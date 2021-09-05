#include "MnistParser.hpp"

// set appropriate path for data
#define TEST_IMAGE "./data/t10k-images.idx3-ubyte"
#define TEST_LABEL "./data/t10k-labels.idx1-ubyte"

// #define SIZE 784 // 28*28
// #define NUM_TEST 10000
#define LEN_INFO_IMAGE 4
#define LEN_INFO_LABEL 2

#define MAX_IMAGESIZE 1280
#define MAX_NUM_OF_IMAGES 1

unsigned char image[MAX_NUM_OF_IMAGES][MAX_IMAGESIZE][MAX_IMAGESIZE];
int width[MAX_NUM_OF_IMAGES], height[MAX_NUM_OF_IMAGES];

int info_image[LEN_INFO_IMAGE];
int info_label[LEN_INFO_LABEL];

unsigned char test_image_char[NUM_TEST][SIZE];
unsigned char test_label_char[NUM_TEST][1];

double test_image[NUM_TEST][SIZE];
int test_label[NUM_TEST];

MnistParser::MnistParser() {

}

MnistParser::~MnistParser() {

}

void MnistParser::loadMnist()
{
    readMnistImage(TEST_IMAGE, NUM_TEST, LEN_INFO_IMAGE, SIZE, test_image_char, info_image);
    imageChar2Double(NUM_TEST, test_image_char, test_image);
    
    readMnistLabel(TEST_LABEL, NUM_TEST, LEN_INFO_LABEL, 1, test_label_char, info_label);
    labelChar2Int(NUM_TEST, test_label_char, test_label);
}

void MnistParser::readMnistImage(char *file_path, int num_data, int len_info, int arr_n, unsigned char data_char[][SIZE], int info_arr[])
{
    int i, fd;
    unsigned char *ptr;

    if ((fd = open(file_path, O_RDONLY)) == -1) {
        fprintf(stderr, "couldn't open image file");
        exit(-1);
    }
    
    // read-in mnist numbers (pixels|labels)
    for (i=0; i<num_data; i++) {
        pread(fd, data_char[i], arr_n * sizeof(unsigned char), len_info * sizeof(int));
    }

    close(fd);
}

void MnistParser::imageChar2Double(int num_data, unsigned char data_image_char[][SIZE], double data_image[][SIZE])
{
    int i, j;
    for (i=0; i<num_data; i++)
        for (j=0; j<SIZE; j++)
            data_image[i][j]  = (double)data_image_char[i][j] / 255.0;
}

void MnistParser::readMnistLabel(char *file_path, int num_data, int len_info, int arr_n, unsigned char data_char[][1], int info_arr[])
{
    int i, fd;
    unsigned char *ptr;

    if ((fd = open(file_path, O_RDONLY)) == -1) {
        fprintf(stderr, "couldn't open image file");
        exit(-1);
    }
    
    // read-in mnist numbers (pixels|labels)
    for (i=0; i<num_data; i++) {
        pread(fd, data_char[i], arr_n * sizeof(unsigned char), len_info * sizeof(int));
    }

    close(fd);
}

void MnistParser::labelChar2Int(int num_data, unsigned char data_label_char[][1], int data_label[])
{
    int i;
    for (i=0; i<num_data; i++)
        data_label[i]  = (int)data_label_char[i][0];
}