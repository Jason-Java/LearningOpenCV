//
// Created by Jason on 2022/1/24.
//

#ifndef LEARNINGOPENCV_DEMO_H
#define LEARNINGOPENCV_DEMO_H
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace cv;
using namespace std;

class Demo
{
public :  Ptr<ORB> orb;
public :  Ptr<BFMatcher> bf_matcher;
public :  vector<KeyPoint> template_keyPoints;;
public :  Mat template_describe;
public :Mat template_image;

public:  Demo(){

        //读取图片
        template_image = imread("C:\\Users\\Jason\\Desktop\\VersionImage\\37.png");
        orb = ORB::create(2000);
        orb->detect(template_image, template_keyPoints, Mat());

        orb->compute(template_image, template_keyPoints, template_describe);
        bf_matcher = BFMatcher::create(NORM_HAMMING, false);
    }

public :
    void perspective( Mat &object_image);
};


#endif //LEARNINGOPENCV_DEMO_H
