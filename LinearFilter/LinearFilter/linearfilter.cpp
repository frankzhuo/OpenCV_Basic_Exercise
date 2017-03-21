#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int g_nBoxFilterValue = 10;
int g_nMeanBlurValue = 10;
int g_nGaussianBlurValue = 10;
Mat g_srcImage, g_BoxFilterdstImage, g_MeanBlurdstImage, g_GaussianBlurdstImage;

static void on_BoxFilter(int , void *);
static void on_MeanBlur(int, void *);
static void on_GaussianBlur(int, void *);

int main()
{
	system("color5E");
	g_srcImage = imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\lena_src.png",1);
	g_BoxFilterdstImage = g_srcImage.clone();
	g_MeanBlurdstImage = g_srcImage.clone();
	g_GaussianBlurdstImage = g_srcImage.clone();

	namedWindow("ԭͼ",1);
	imshow("ԭͼ", g_srcImage);

	//�����˲�
	namedWindow("�����˲�", 1);
	createTrackbar("��" ,"�����˲�", &g_nBoxFilterValue, 40, on_BoxFilter);
	on_BoxFilter(g_nBoxFilterValue, 0);
	//��ֵ�˲�
	namedWindow("��ֵ�˲�", 1);
	createTrackbar("��", "��ֵ�˲�", &g_nMeanBlurValue, 40, on_MeanBlur);
	on_MeanBlur(g_nMeanBlurValue, 0);
	//��˹�˲�
	namedWindow("��˹�˲�", 1);
	createTrackbar("��", "��˹�˲�", &g_nGaussianBlurValue, 40, on_GaussianBlur);
	on_GaussianBlur(g_nGaussianBlurValue, 0);

	cout << "�������������Բ鿴��ͬ�ں˴�С���˲�Ч��" << endl;

	waitKey(0);
	return 0;
}

static void on_BoxFilter(int, void *)
{
	boxFilter(g_srcImage, g_BoxFilterdstImage, -1, Size(g_nBoxFilterValue + 1, g_nBoxFilterValue + 1), Point(-1, -1),true, 4);
	imshow("�����˲�", g_BoxFilterdstImage);

}
static void on_MeanBlur(int, void *)
{
	blur(g_srcImage, g_MeanBlurdstImage, Size(g_nMeanBlurValue +1, g_nMeanBlurValue + 1));
	imshow("��ֵ�˲�", g_MeanBlurdstImage);
}
static void on_GaussianBlur(int, void *)
{
	GaussianBlur(g_srcImage, g_GaussianBlurdstImage, Size(g_nGaussianBlurValue*2 + 1, g_nGaussianBlurValue*2 + 1),0,0);  //the kernal of GaussianBlur should be odd and positive
	imshow("��˹�˲�", g_GaussianBlurdstImage);
}