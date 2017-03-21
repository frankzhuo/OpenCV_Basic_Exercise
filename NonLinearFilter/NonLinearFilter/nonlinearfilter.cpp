#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat g_srcImage, g_MedianBlurdstImage, g_BilateralFilterdstImage;
int g_nMedianBlurValue = 10;
int g_nBilateralFilterValue = 10;

static void on_MedianBlur(int, void * );
static void on_BilateralFilter(int, void *);

int main()
{
	g_srcImage = imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\lena_src.png",1);
	g_MedianBlurdstImage = g_srcImage.clone();
	g_BilateralFilterdstImage = g_srcImage.clone();

	namedWindow("ԭͼ", 1);
	imshow("ԭͼ", g_srcImage);
	
	//��ֵ�˲�
	namedWindow("��ֵ�˲�", 1);
	createTrackbar("Kernal", "��ֵ�˲�", &g_nMedianBlurValue, 40, on_MedianBlur);
	on_MedianBlur(g_nMedianBlurValue, 0);
	//˫���˲�
	namedWindow("˫���˲�",1);
	createTrackbar("Kernal", "˫���˲�", &g_nBilateralFilterValue, 40, on_BilateralFilter);
	on_BilateralFilter(g_nBilateralFilterValue, 0);
	
	cout << "����TrackBar���鿴��ͬ�˲�Ч��\n" << endl;

	waitKey();
	return 0;
}

static void on_MedianBlur(int, void *)
{
	medianBlur(g_srcImage, g_MedianBlurdstImage,g_nMedianBlurValue*2+1);
	imshow("��ֵ�˲�", g_MedianBlurdstImage);
}

static void on_BilateralFilter(int, void *)
{
	bilateralFilter(g_srcImage, g_BilateralFilterdstImage, g_nBilateralFilterValue, g_nBilateralFilterValue*2, g_nBilateralFilterValue/2);
	imshow("˫���˲�", g_BilateralFilterdstImage);
}