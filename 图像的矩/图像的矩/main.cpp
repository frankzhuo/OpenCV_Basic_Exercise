#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat g_srcImage, g_grayImage, g_dstImage;
int g_nTreshValue = 10;
vector<vector<Point>> contours;
vector<Vec4i> hierarchy;
static void on_ChangeThresh(int, void *);

int main()
{
	system("color 1E");

	g_srcImage = imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\58.bmp", 1);
	cvtColor(g_srcImage, g_grayImage, COLOR_BGR2GRAY);
	blur(g_grayImage, g_grayImage, Size(3, 3));  //��ֵ�˲�

	namedWindow("ԭͼ", 1);
	imshow("ԭͼ", g_srcImage);

	createTrackbar("TreshValue","ԭͼ", &g_nTreshValue, 255, on_ChangeThresh);
	on_ChangeThresh(0, 0);

	waitKey(0);
	return 0;
}

static void on_ChangeThresh(int, void *)
{
	
	Canny(g_grayImage, g_dstImage, g_nTreshValue, g_nTreshValue*2, 3, false);
	findContours(g_dstImage, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
	//�����
	vector<Moments> mu(contours.size());
	for(int i = 0; i < contours.size(); i++)
	{
		mu[i] = moments(contours[i], false);  //�ڶ�����Ϊ�Ƿ�Ϊ��ֵ��ͼ��
	}
	//�������ľ�
	vector<Point2f> mc(contours.size());
	for(int i = 0; i < contours.size(); i++)
	{
		mc[i] = Point2f(static_cast<float>(mu[i].m10/mu[i].m00), static_cast<float>(mu[i].m01/mu[i].m00));
	}
	//��������
	Mat drawing = Mat::zeros( g_dstImage.size(), CV_8UC3);
	for(int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rand()&255, rand()&255, rand()&255);
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point(0, 0));
		circle(drawing, mc[i], 4, color, 1, 8, 0);
	}

	imshow("Ч��ͼ", drawing);

//	cout << "������ݣ� �������������" << endl;

//	for(int i = 0; i < contours.size(); i++)
//	{
		//cout << "ͨ��m00�������������� ��M_00�� = "<< mu[i].m00 << "OpenCV�⺯������õ��������Ϊ�� " << contourArea(contours[i]) << "����Ϊ�� " << arcLength(contours[i], true) << endl;
		//Scalar color = Scalar(rand()&255, rand()&255, rand()&255);
		//drawContours(drawing, contours, i, color, 1, 8, hierarchy, 0, Point(0, 0));
		//circle(drawing, mc[i], 4, color, -1, 8, 0);
//	}
}