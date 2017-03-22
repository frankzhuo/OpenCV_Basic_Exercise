#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat g_srcImage, g_grayImage, g_dstImage;
int g_nTreshValue = 20;
RNG g_rng(12345);

static void on_ChangeValue(int, void *);

int main()
{
	g_srcImage = imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\lena_src.png", 1);
	cvtColor(g_srcImage, g_grayImage, COLOR_BGR2GRAY);
	blur(g_grayImage, g_grayImage, Size(3,3));

	namedWindow("ԭͼ", 1);
	imshow("ԭͼ", g_srcImage);

	createTrackbar("Treshold", "ԭͼ", &g_nTreshValue, 255, on_ChangeValue);
	on_ChangeValue(g_nTreshValue, 0);
	
	waitKey(0);
	return 0;
}

static void on_ChangeValue(int, void *)
{
	Mat thresholdOut;
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;  //��������ĺ���û��̫����
	//��ֵ��
	threshold(g_grayImage, thresholdOut, g_nTreshValue, 255, THRESH_BINARY);
	//����
	findContours(thresholdOut, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
	//��Χ
	// �����   ����   Բ��
	vector<vector<Point>> contours_Poly(contours.size());
	vector<Rect> boundRect(contours.size());  //contours.size()��ʾ���������ĸ���
	vector<Point2f> center(contours.size());
	vector<float> radius(contours.size());

	for(int i = 0; i < contours.size(); i++)
	{
		approxPolyDP(Mat(contours[i]), contours_Poly[i], 3, true); //ʹ��ָ�����ȶ���αƽ�����
		boundRect[i] = boundingRect(contours_Poly[i]);
		minEnclosingCircle(contours_Poly[i], center[i], radius[i]);
	}
	//����
	Mat drawing = Mat::zeros(thresholdOut.size(), CV_8UC3);
	for(int i = 0; i < contours.size(); i ++)
	{
		Scalar color = Scalar(g_rng.uniform(0,255), g_rng.uniform(0,255), g_rng.uniform(0,255));
		drawContours(drawing, contours_Poly, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
		rectangle(drawing, boundRect[i].tl(), boundRect[i].br(), color, 1, 8, 0);
		circle(drawing, center[i], radius[i], color, 1, 8, 0);
	}

	namedWindow("Ч��ͼ", 1);
	imshow("Ч��ͼ", drawing);
}