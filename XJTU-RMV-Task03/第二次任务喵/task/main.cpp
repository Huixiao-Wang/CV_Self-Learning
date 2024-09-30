#include "windmill.hpp"

using namespace std;
using namespace cv;

int main()
{
    std::chrono::milliseconds t = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    WINDMILL::WindMill wm(t.count());
    Mat src;
    while (1)
    {
        t = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
        src = wm.getMat((double)t.count() / 1000);
        /*code*/
        int64 start_time = getTickCount();

        // 1. draw circles
        // gray
        Mat highlightGray;
        cvtColor(src, highlightGray, COLOR_BGR2GRAY);

        // binary
        Mat binary;
        threshold(highlightGray, binary, 50, 255, THRESH_BINARY);

        /* // findcontours way 1
        vector<vector<Point>> contours;
        findContours(binary, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        // find hammer & R
        int R_id, hammer_id;
        for (size_t i = 0; i < contours.size(); i++)
        {
            double area = contourArea(contours[i]);
            if (area < 5000)
            {
                if (area < 200)
                {
                    R_id = i;
                    continue;
                }
                hammer_id = i;
                continue;
            }
        } */

        // findcontours way 2
        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;
        findContours(binary, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
        int R_id, hammer_id, innnerhammer_id;
        for (size_t i = 0; i < contours.size(); i++)
        {
            if (hierarchy[i][3] == -1)
            {
                double area = contourArea(contours[i]);
                if (area < 5000)
                {
                    if (area < 200)
                    {
                        R_id = i;
                        continue;
                    }
                    innnerhammer_id = hierarchy[i][2];
                    continue;
                }
            }
        }

        // locate
        Moments M_R = moments(contours[R_id]);
        int R_x = int(M_R.m10 / M_R.m00);
        int R_y = int(M_R.m01 / M_R.m00);
        circle(src, Point(R_x, R_y), 4, Scalar(255, 0, 0), -1);

        Moments M_ham = moments(contours[innnerhammer_id]);
        int innerham_x = int(M_ham.m10 / M_ham.m00);
        int innerham_y = int(M_ham.m01 / M_ham.m00);
        circle(src, Point(innerham_x, innerham_y), 4, Scalar(255, 0, 0), -1);

        int64 end_time = getTickCount();
        double t = (end_time - start_time) / getTickFrequency();
        cout << t << endl;
        /*code*/
        imshow("windmill", src);
        waitKey(1);
    }
}