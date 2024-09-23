#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>

using namespace cv;
using namespace std;

// 生成椒盐噪声
void addSaltPepperNoise(Mat &img, int n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distRow(0, img.rows - 1);
    std::uniform_int_distribution<> distCol(0, img.cols - 1);

    for (int k = 0; k < n; k++)
    {
        int i = distRow(gen);
        int j = distCol(gen);
        img.at<Vec3b>(i, j) = Vec3b(0, 0, 255); // 红色噪声
    }
}

int main()
{
    // 1. 创建一个黑色背景的图片
    Mat img = Mat::zeros(500, 500, CV_8UC3);

    // 2. 绘制一个黄色的菱形
    Point points[1][4];
    points[0][0] = Point(250, 100);
    points[0][1] = Point(400, 250);
    points[0][2] = Point(250, 400);
    points[0][3] = Point(100, 250);

    const Point *ppt[1] = {points[0]};
    int npt[] = {4};
    fillPoly(img, ppt, npt, 1, Scalar(0, 255, 255), 8);

    // 3. 添加红色椒盐噪声
    addSaltPepperNoise(img, 1000);

    // 保存图片
    imwrite("mango.png", img);
    cout << "Image saved as mango.png" << endl;

    // 显示原始图片
    imshow("Original Image", img);
    waitKey(0);

    // 4. 读取图片
    Mat mango = imread("mango.png");
    if (mango.empty())
    {
        cout << "Could not read the image." << endl;
        return 1;
    }

    // 5. 二值化处理 (黄色的范围)
    Mat binary;
    inRange(mango, Scalar(0, 200, 200), Scalar(0, 255, 255), binary);
    imshow("Binary Image", binary);
    waitKey(0);

    // 6. 高斯滤波
    Mat blurred;
    GaussianBlur(binary, blurred, Size(5, 5), 0);
    imshow("Gaussian Blur", blurred);
    waitKey(0);

    // 7. 膨胀与腐蚀
    Mat morph;  
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
    dilate(blurred, morph, kernel);
    erode(morph, morph, kernel);
    imshow("Morphological Transformation", morph);
    waitKey(0);

    // 8. 寻找轮廓
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(morph, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    // 绘制轮廓和外接矩形框
    Mat contourOutput = mango.clone();
    for (size_t i = 0; i < contours.size(); i++)
    {
        drawContours(contourOutput, contours, (int)i, Scalar(0, 255, 0), 2, LINE_8, hierarchy, 0);
        Rect boundingBox = boundingRect(contours[i]);
        rectangle(contourOutput, boundingBox, Scalar(255, 0, 0), 2);
    }

    // 输出轮廓数量
    cout << "Number of contours found: " << contours.size() << endl;

    // 显示结果
    imshow("Contours", contourOutput);
    waitKey(0);

    return 0;
}
