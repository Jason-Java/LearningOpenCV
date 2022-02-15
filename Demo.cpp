//
// Created by Jason on 2022/1/24.
//

#include "Demo.h"

void Demo::perspective(Mat &object_image)
{
    vector<KeyPoint> object_keyPoints;
    orb->detect(object_image, object_keyPoints, Mat());
    Mat  object_describe;
    orb->compute(object_image, object_keyPoints, object_describe);

    vector<DMatch> matches;
    bf_matcher->match(template_describe, object_describe, matches, Mat());
    cout<<matches.size()<<endl;
    vector<DMatch>::iterator iter = matches.begin();
    while (iter != matches.end())
    {
        if (iter->distance > 60)
        {
            iter = matches.erase(iter);
            continue;
        }
        iter++;
    }

    if(template_keyPoints .size()<=0)
    {
        cout << "未发现目标" << endl;
        return;
    }
    vector<Point2f> src_points, dst_points;
    for (int i = 0; i < matches.size(); ++i)
    {
        DMatch match = matches[i];
        src_points.push_back(template_keyPoints[match.queryIdx].pt);
        dst_points.push_back(object_keyPoints[match.trainIdx].pt);
    }

    if(src_points.size()<=0||dst_points.size()<=0)
    {
        cout << "未发现目标2" << endl;
        return;
    }

    Mat H = findHomography(dst_points, src_points, RANSAC);
    Mat dst;
    warpPerspective(object_image, dst, H, template_image.size());

    cvtColor(dst,dst,COLOR_BGR2GRAY);
    threshold(dst,dst,0,255,THRESH_BINARY|cv::THRESH_OTSU);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    morphologyEx(dst,dst,MORPH_CLOSE,kernel);
   // namedWindow("结果",WINDOW_FREERATIO);
    imshow("结果", dst);
}
