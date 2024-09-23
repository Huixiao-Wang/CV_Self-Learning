#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    // 创建一个3x3的矩阵，并显示在终端
    cv::Mat mat = (cv::Mat_<double>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
    std::cout << "Matrix: " << std::endl
              << mat << std::endl;

    return 0;
}

// g++ main.cpp -o test `pkg-config --cflags --libs opencv4`
// ./test