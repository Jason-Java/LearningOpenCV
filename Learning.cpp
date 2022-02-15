//
// Created by Jason on 2022/2/9.
//

#include "Learning.h"

void Learning::myRNG()
{
    cv::RNG rng = cv::theRNG();

    double rngDouble = rng.uniform(0, 100);

    cout << "����� " << rngDouble << endl;
    cout << "����� " << endl;
    Mat mat = Mat::zeros(Size(10, 10), CV_8UC1);
    rng.fill(mat, RNG::UNIFORM, 2, 0);
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cout << mat.at<int>(i, j) << "  ";
        }
        cout << endl;
    }


}

void Learning::_7_1()
{
    RNG rng = theRNG();
    float rngFloat_1 = rng.operator double();
    float rngFloat_2 = rng.operator double();
    float rngFloat_3 = rng.operator double();
    cout << "��������� " << rngFloat_1 << endl;
    cout << "��������� " << rngFloat_2 << endl;
    cout << "��������� " << rngFloat_3 << endl;
    double rngDouble_1 = rng.gaussian(1);
    double rngDouble_2 = rng.gaussian(1);
    double rngDouble_3 = rng.gaussian(1);

    cout << "��̬�ֲ���������� " << rngDouble_1 << endl;
    cout << "��̬�ֲ���������� " << rngDouble_2 << endl;
    cout << "��̬�ֲ���������� " << rngDouble_3 << endl;

    int int_1 = rng.operator()(255);
    int int_2 = rng.operator()(255);
    int int_3 = rng.operator()(255);

    cout << "�޷������������ " << int_1 << endl;
    cout << "�޷������������ " << int_2 << endl;
    cout << "�޷������������ " << int_3 << endl;


}

void Learning::L_7_2()
{
    RNG rng = theRNG();
    Matx<double, 1, 20> matx;
    rng.fill(matx, RNG::UNIFORM, 1.0, 0);

    for (int i = 0; i < 20; ++i)
    {
        cout << " ����� " << matx(0, i);
    }
    cout << endl;


    Matx<double, 1, 20> matx2;
    rng.fill(matx2, RNG::NORMAL, 0, 1.0);

    for (int i = 0; i < 20; ++i)
    {
        cout << " ����� " << matx2(0, i);
    }


    cout << endl;
    Mat mat = Mat::zeros(1, 20, CV_8UC3);

    rng.fill(mat, RNG::UNIFORM, 0, 255);
    cout << mat << endl;
}

void Learning::L_7_3()
{
    RNG rng = theRNG();
    Mat mat1 = Mat::zeros(1, 20, CV_32FC1);
    rng.fill(mat1, RNG::NORMAL, 64, 10);
    Mat mat2 = Mat::zeros(1, 20, CV_32FC1);
    rng.fill(mat2, RNG::NORMAL, 192, 10);
    Mat mat3 = Mat::zeros(1, 20, CV_32FC1);
    rng.fill(mat3, RNG::NORMAL, 128, 2);
    Mat mat = Mat::zeros(1, 20, CV_32FC3);
    Mat matArray[3] = {mat1, mat2, mat3};
    merge(matArray, 3, mat);
    cout << mat << endl;
}

void Learning::L_8_1()
{

    Mat src = imread("C:\\Users\\Jason\\Desktop\\VersionImage\\master.jpg", IMREAD_UNCHANGED);
    Mat gray;
    if (src.empty())
    {
        cout << "ͼƬ��ȡʧ��" << endl;
        return;
    }


    imshow("ԭͼƬ", src);
    cvtColor(src, gray, COLOR_BGR2GRAY);
    imshow("�Ҷ�ͼ��", gray);
    Mat dst;
    Canny(gray, dst, 50, 100);
    namedWindow("��Ե���", WINDOW_FREERATIO);
    imshow("��Ե���", dst);

    Mat result = Mat::zeros(src.rows, src.cols * 3, src.type());

    cvtColor(gray, gray, COLOR_GRAY2BGR);
    cvtColor(dst, dst, COLOR_GRAY2BGR);

    for (int i = 0; i < result.rows; ++i)
    {
        for (int j = 0; j < src.cols; ++j)
        {
            result.at<Vec3b>(i, j) = src.at<Vec3b>(i, j);
        }
    }
    for (int i = 0; i < result.rows; ++i)
    {
        for (int j = 0; j < src.cols; ++j)
        {
            result.at<Vec3b>(i, src.cols * 1 + j) = gray.at<Vec3b>(i, j);
        }
    }
    for (int i = 0; i < result.rows; ++i)
    {
        for (int j = 0; j < src.cols; ++j)
        {
            result.at<Vec3b>(i, src.cols * 2 + j) = dst.at<Vec3b>(i, j);
        }
    }
    imshow("���", result);
}

void my_mouse_callback(int event, int x, int y, int flags, void *userdata)
{
    Mat src1 = *((Mat *) userdata);
    Mat dra_image;
    src1.copyTo(dra_image);
    if (src1.empty())
    {

        printf("���ǿ�����\n");
        return;
    }

    if (event == EVENT_LBUTTONDOWN)
    {
        Vec3b vec3B = src1.at<Vec3b>(x, y);
        printf("BGR [ %d %d %d ]\n", vec3B[0], vec3B[1], vec3B[2]);
        putText(dra_image, "[ " + to_string(vec3B[0]) + " " + to_string(vec3B[1]) + " " + to_string(vec3B[2]) + " ]",
                Point(x, y), FONT_HERSHEY_SIMPLEX, 1, Scalar::all(0));

        imshow("����ͼƬ", dra_image);
    }
}


void Learning::L_8_2()
{

    static Mat src = imread("C:\\Users\\Jason\\Desktop\\VersionImage\\master.jpg", IMREAD_UNCHANGED);

    if (src.empty())
    {
        cout << "ͼƬ��ȡʧ��" << endl;
        return;
    }
    waitKey(1);
    namedWindow("����ͼƬ", WINDOW_FREERATIO);
    imshow("����ͼƬ", src);
    setMouseCallback("����ͼƬ", my_mouse_callback, &src);

}

Point2f startPoint(-1, -1);
Point2f endPoint(-1, -1);

void statistic(int value, int array[])
{
    if (value >= 0 && value <= 31)
    {
        array[0]++;
    } else if (value >= 32 & value <= 63)
    {
        array[1]++;
    } else if (value >= 64 & value <= 95)
    {
        array[2]++;
    } else if (value >= 96 & value <= 127)
    {
        array[3]++;
    } else if (value >= 128 & value <= 159)
    {
        array[4]++;
    } else if (value >= 160 & value <= 191)
    {
        array[5]++;
    } else if (value >= 192 & value <= 223)
    {
        array[6]++;
    } else
    {
        array[7]++;
    }
}

void mouse_callback_8_3(int event, int x, int y, int flags, void *userdata)
{
    Mat src = *(Mat *) userdata;
    Mat drawable_image;
    src.copyTo(drawable_image);

    Rect rect;
    if (event == EVENT_LBUTTONDOWN)
    {
        cout << "1" << endl;
        startPoint.x = x;
        startPoint.y = y;
    }
    if (event == CV_EVENT_MOUSEMOVE)
    {
        if (startPoint.x == -1)
        {
            return;
        }
        endPoint.x = x;
        endPoint.y = y;
        rect.x = startPoint.x;
        rect.y = startPoint.y;
        rect.width = endPoint.x - startPoint.x;
        rect.height = endPoint.y - startPoint.y;
        rectangle(drawable_image, rect, Scalar(255, 0, 0), 2, LINE_AA);
        imshow("����ͼƬ", drawable_image);
    }
    if (event == EVENT_LBUTTONUP)
    {

        rect.x = startPoint.x;
        rect.y = startPoint.y;
        rect.width = endPoint.x - startPoint.x;
        rect.height = endPoint.y - startPoint.y;

        Mat result = src(rect);

        imshow("���", result);
        startPoint.x = -1;
        int BArray[8] = {0};
        int GArray[8] = {0};
        int RArray[8] = {0};
        for (int i = 0; i < result.rows; ++i)
        {
            for (int j = 0; j < result.cols; ++j)
            {
                Vec3b vec3B = result.at<Vec3b>(i, j);

                statistic(vec3B[0], BArray);
                statistic(vec3B[1], GArray);
                statistic(vec3B[2], RArray);
            }
        }

        Mat histo = Mat::zeros(Size(15000, 255), CV_8UC3);

        for (int i = 0; i < 8; ++i)
        {
            printf("%d\t", BArray[i]);
        }
        cout << endl;
        for (int i = 0; i < 8; ++i)
        {
            printf("%d\t", GArray[i]);
        }
        cout << endl;
        for (int i = 0; i < 8; ++i)
        {
            printf("%d\t", GArray[i]);
        }
    }


}

void Learning::L_8_3()
{
    static Mat src = imread("C:\\Users\\Jason\\Desktop\\VersionImage\\master.jpg", IMREAD_UNCHANGED);

    if (src.empty())
    {
        cout << "ͼƬ��ȡʧ��" << endl;
        return;
    }
    namedWindow("����ͼƬ", WINDOW_FREERATIO);
    //imshow("����ͼƬ", src);
    setMouseCallback("����ͼƬ", mouse_callback_8_3, &src);

}

void tracBar_speed_8_4(int pos, void *userdata)
{
    VideoCapture videoCapture = *(VideoCapture *) userdata;
    Mat frame;
    videoCapture.set(CAP_PROP_POS_FRAMES, pos);

}

bool stop = true;

void tracBar_stop_8_4(int pos, void *userdata)
{
    if (pos == 1)
    {
        stop = false;
    } else
    {
        stop = true;
    }

}


void Learning::L_8_4()
{
    static VideoCapture videoCapture;
    videoCapture.open("F:\\Opencv\\opencv\\sources\\samples\\data\\vtest.avi");

    int frameCount = videoCapture.get(CAP_PROP_FRAME_COUNT);
    Mat frame;
    if (!videoCapture.isOpened())
    {
        printf("��Ƶ��ʧ��\n");
        return;
    }

    namedWindow("��Ƶ����", WINDOW_FREERATIO);
    createTrackbar("����", "��Ƶ����", 0, frameCount, tracBar_speed_8_4, &videoCapture);
    int value = 2;
    createTrackbar("��ͣ", "��Ƶ����", &value, 1, tracBar_stop_8_4, &videoCapture);
    char c;
    while (true)
    {
        c = waitKey(100);

        if (stop)
        {
            videoCapture.read(frame);
        }

        if (frame.empty())
        {
            printf("��Ƶ�������\n");
            break;
        }

        imshow("��Ƶ����", frame);

        if (c == 27)
        {
            break;
        }
    }
}

void tracBar_8_5(int pos, void *userdata)
{
    if (pos % 2 == 0)
    {
        return;
    }
    Mat src = *(Mat *) userdata;
    Mat scharr_x,scharr_y;

    addWeighted(scharr_x, 1.0, scharr_y, 1.0, 0.0, src);

    imshow("����������", src);
}
void Learning::L_8_5()
{
   static  Mat src = imread("C:\\Users\\Jason\\Desktop\\VersionImage\\IMG_0002.jpg", IMREAD_UNCHANGED);
    Mat binary, result,gray;
    if (src.empty())
    {
        cout << "ͼƬ��ȡʧ��" << endl;
        return;
    }
    cvtColor(src, src, COLOR_BGR2GRAY);
    threshold(src, binary, 0, 255, THRESH_BINARY_INV | cv::THRESH_OTSU);
    imshow("��ֵ��", binary);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
    erode(binary, result, kernel);
    imshow("��ʴ", result);
}



