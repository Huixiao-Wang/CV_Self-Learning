#include "windmill.hpp"
#include "ceres/ceres.h"

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
        src = wm.getMat((double)t.count()); // Is here wrong? (why to divide 1000?) Still, it can run well. But it is unreasonal.
        /*code*/
        // starttime
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
        int R_id = -1, hammer_id = -1;
        for (size_t i = 0; i < contours.size(); i++)
        {
            if (R_id != -1 && hammer_id != -1)
            {
                break;
            }
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
                    hammer_id = hierarchy[i][2];
                    continue;
                }
            }
        }

        // locate & draw
        Moments M_R = moments(contours[R_id]);
        Point R_xy(int(M_R.m10 / M_R.m00), int(M_R.m01 / M_R.m00));
        // circle(src, R_xy, 4, Scalar(255, 0, 0), -1); // draw

        Moments M_ham = moments(contours[hammer_id]);
        Point ham_xy(int(M_ham.m10 / M_ham.m00), int(M_ham.m01 / M_ham.m00));
        // circle(src, ham_xy, 4, Scalar(255, 0, 0), -1); // draw

        // calculate vector RH & cos(angle_now)
        Point RH = ham_xy - R_xy;
        Point2d RHi = Point2d(RH) / norm(RH);

        // ceres

        // endtime
        int64 end_time = getTickCount();
        double t = (end_time - start_time) / getTickFrequency();
        // cout << t << endl;
        /*code*/
        imshow("windmill", src);
        waitKey(1);
    }
}