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
Mat imgGray, monoImgOr, monoImgGr, monoImgWh;
//int hmin = 0, hmax = 100;
int main(){
    
    Mat img = imread("/Users/ratanprakash/Desktop/OpenCV/OpenCV/openCV_task.jpeg");
//    Mat RatImg = imread("/Users/ratanprakash/Desktop/OpenCV/OpenCV/RATAN.jpeg");
    cvtColor(img, imgHSV, COLOR_BGR2HSV);
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(img, imgBlur, Size(9, 9), 5, 0);
    
//    cvtColor(img, monoImg, COLOR_BGR2YUV);
//    namedWindow("Trackbars window");
//    createTrackbar("lower", "Trackbars window", <#int *value#>, <#int count#>);
    
    
    
    Scalar lower(0, 110, 153);    //////////////////////for Orange color //////////////////////////////////
    Scalar upper(19, 240, 255);
    inRange(imgHSV, lower, upper, monoImgOr);
    
    Scalar low(245, 245, 245);    //////////////////////for White color //////////////////////////////////
    Scalar upp(255, 256, 255);
    inRange(img, low, upp, monoImgWh);
    
    Scalar lo(125, 180, 85);    //////////////////////for Green color //////////////////////////////////
    Scalar up(120, 170, 80);
    inRange(img, lo, up, monoImgGr);
    
    
    imshow("photo", img);
    imshow("HSVimage", imgHSV);
//    imshow("grayScale", imgGray);
//    imshow("BlurredImg", imgBlur);
    imshow("Region of Orange color", monoImgOr);
    imshow("Region of White color", monoImgWh);
    imshow("Region of Green color", monoImgGr);
    
    waitKey(0);
    
    cout<< "code ran succesfully" <<endl;

}


