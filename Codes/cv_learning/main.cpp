#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void onChange(int pos, void *ptr)
{
    Mat image = *((Mat *)(ptr));
    Mat stp = Mat::zeros(image.size(), image.type());
    Mat chg = Mat::zeros(image.size(), image.type());
    Mat chg2 = Mat::zeros(image.size(), image.type());
    stp = Scalar(pos, pos, pos);
    add(image, stp, chg);
    subtract(chg, Scalar(127,127,127), chg2);
    imshow("changing", chg2);
}

int main()
{
    Mat m1 = imread("../images/92C63DCC3F6FE88B50A5AC92E502F1D0.JPG");
    imshow("Spike", m1);
    waitKey(1000);
    Mat m2 = m1; // m2 和 m1 指向同一地址，未创建新内存
    Mat m3 = m1.clone();
    m3 = Scalar(256, 0, 0);
    imshow("Blue", m3);
    waitKey(1000);

    Mat m4 = Mat::zeros(Size(256, 256), CV_8UC3); // 三通道，8UC1 单通道灰度图
    imshow("Black", m4);

    Mat m5;
    m1.copyTo(m5);
    int r = m5.rows, c = m5.cols, ch = m5.channels();
    cout << "rows: " << r << " columns: " << c << " channels: " << ch << endl;

    for (int i = 0; i < r; i++) // 数组下标遍历
    {
        for (int j = 0; j < c; j++)
        {
            if (ch == 3)
            {
                Vec3b pt = m5.at<Vec3b>(i, j);
                m5.at<Vec3b>(i, j)[2] = 256 - pt[2];
            }
        }
    }
    imshow("rvs", m5);
    waitKey(1000);

    for (int i = 0; i < r; i++) // 指针遍历
    {
        uchar *nptr = m5.ptr<uchar>(i);
        for (int j = 0; j < c; j++)
        {
            if (ch == 3) // 三通道 +3，单通道 +1
            {
                nptr += 2;
                *nptr = 256 - *nptr;
                nptr++;
            }
        }
    }
    imshow("rvs again", m5);
    waitKey(1000);

    Mat m6 = Mat::zeros(m1.size(), m1.type());
    m6.at<Vec3b>(0, 0)[0] = saturate_cast<uchar>(m1.at<Vec3b>(0, 0)[0]); // 防止越界， (<0)--0, (>255)--255
    Mat sc = Mat::zeros(m6.size(), m6.type());
    sc = Scalar(100, 100, 100);
    // 运算
    add(m1, sc, m6);
    imshow("add", m6);
    waitKey(1000);
    subtract(m1, sc, m6);
    imshow("sub", m6);
    waitKey(1000);
    multiply(m1, sc, m6);
    imshow("mul", m6);
    waitKey(1000);
    divide(m1, sc, m6);
    imshow("div", m6);
    waitKey(1000);

    namedWindow("changing", WINDOW_AUTOSIZE);
    int step = 20, maxv = 255;
    Mat m7 = imread("../images/92C63DCC3F6FE88B50A5AC92E502F1D0.JPG");
    imshow("changing", m7);
    createTrackbar("adjust", "changing", NULL, maxv, onChange, (void *)(&m7)); // 每当 Trackbar 变动，就会触发 onChange ，执行 onChange 中函数内容， (void*) 指针类型是通用指针，可以强制转化 (cast) 为任何类型的指针，故可以传递任何类型的数据
    waitKey(0);
}