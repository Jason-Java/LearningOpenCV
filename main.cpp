#include <iostream>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Demo.h"
#include "Learning.h"

using namespace cv;
using namespace std;

int main()
{

    Learning learning;
    learning.L_8_5();

    waitKey();
    destroyAllWindows();
    return 0;
}
