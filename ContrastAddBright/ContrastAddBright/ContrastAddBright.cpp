#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;
static void on_contrastTrackbar(int , void * );
Mat srcImage;
Mat dstImage;
int g_contrastValue;
int g_brightValue;
int main()
{
	srcImage = imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\lena_src.png",1);
	if(!srcImage.data)
	{
		cout << "Sorry Sir, No Element.\n";
		return 0;
	} 
	dstImage = Mat::zeros(srcImage.size(), srcImage.type());
	g_contrastValue = 80;
	g_brightValue = 50;

	
	namedWindow("ԭͼ",1);
	namedWindow("Ч��ͼ",1);
	createTrackbar("�Աȶ� : ", "Ч��ͼ", &g_contrastValue, 300, on_contrastTrackbar);
	createTrackbar("����   : ", "Ч��ͼ", &g_brightValue, 200, on_contrastTrackbar);
	on_contrastTrackbar(g_contrastValue,0);
	on_contrastTrackbar(g_brightValue, 0);

	waitKey();
	return 0;	
}

static void on_contrastTrackbar(int, void*)
{
	for(int i = 0; i< srcImage.rows; i++)
	{
		for(int j = 0; j < srcImage.cols; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				dstImage.at<Vec3b>(i,j)[k] = saturate_cast<uchar>(g_contrastValue*0.01*(srcImage.at<Vec3b>(i,j)[k]) + g_brightValue);
			}
		}
	}
	
	imshow("ԭͼ", srcImage);
	imshow("Ч��ͼ", dstImage);

}