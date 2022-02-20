//  main.cpp
//  OpenCV
//
//  Created by Ratan Prakash on 09/02/22.
//


#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

Mat imgHSV, imgBlur;
Mat imgGray, monoImg;
//int hmin = 0, hmax = 100;
int main(){
    
    Mat img = imread("/Users/ratanprakash/Desktop/OpenCV/OpenCV/openCV_task.jpeg");
    cvtColor(img, imgHSV, COLOR_BGR2HSV);
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(img, imgBlur, Size(9, 9), 5, 0);
//    cvtColor(img, monoImg, COLOR_BGR2YUV);
    
    namedWindow("Trackbars window");
//    createTrackbar("lower", "Trackbars window", <#int *value#>, <#int count#>);
    
    Scalar lower(255, 0, 100);
    Scalar upper(0, 0, 100);
    
    inRange(imgHSV, lower, upper, monoImg);
    
    imshow("photo", img);
    imshow("HSVimage", imgHSV);
    imshow("grayScale", imgGray);
    imshow("BlurredImg", imgBlur);
    imshow("monoIMAGE", monoImg);
    
    waitKey(0);
    
    cout<< "code ran succesfully" <<endl;

}


