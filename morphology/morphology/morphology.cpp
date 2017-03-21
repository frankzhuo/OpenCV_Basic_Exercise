#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat g_srcImage, g_dstImage;
int g_Mode = 0;
// 0: ��ʴ 1�� ���� 2�� ������ 3�������� 4����ñ 5�� ��ñ
int g_nValue = 10;
static void on_ChangeMode(int , void *);
static void on_ChangeValue(int, void *);
void process();
int main()
{
	g_srcImage = imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\learn.jpg",1);
	if(!g_srcImage.data)
	{
		cout << "Sorry Sir, No element.\n" << endl;
		return 0;
	}
	namedWindow("ԭͼ",1);
	imshow("ԭͼ", g_srcImage);
	namedWindow("Ч��ͼ", 1);
	//ģʽѡ��TrackBar
	createTrackbar("Mode", "Ч��ͼ", &g_Mode, 5, on_ChangeMode);
	on_ChangeMode(g_Mode, 0);
	//�˴�С
	createTrackbar("Value", "Ч��ͼ", &g_nValue, 40, on_ChangeValue);
	on_ChangeValue(g_nValue, 0);

	cout << "please choose what you want.\n" << endl;
	waitKey();
	return 0;
}

static void on_ChangeMode(int, void *)
{
	process();
}

static void on_ChangeValue(int , void *)
{
	process();
}

void process()
{
	switch(g_Mode)
	{
	case 0: //��ʴ
		{
			Mat element = getStructuringElement(MORPH_RECT, Size(g_nValue*2+1,g_nValue*2+1));
			erode(g_srcImage,g_dstImage, element);
			imshow("Ч��ͼ", g_dstImage);
			break;
		}
	case 1: //����
		{
			Mat element = getStructuringElement(MORPH_RECT, Size(g_nValue*2+1,g_nValue*2+1));
			dilate(g_srcImage,g_dstImage, element);
			imshow("Ч��ͼ", g_dstImage);
			break;
		}
	case 2: //������
		{
			Mat element = getStructuringElement(MORPH_RECT, Size(g_nValue*2+1,g_nValue*2+1));
			morphologyEx(g_srcImage, g_dstImage, MORPH_OPEN, element);
			imshow("Ч��ͼ", g_dstImage);
			break;
		}
		
	case 3: //������
		{
			Mat element = getStructuringElement(MORPH_RECT, Size(g_nValue*2+1,g_nValue*2+1));
			morphologyEx(g_srcImage, g_dstImage, MORPH_CLOSE, element);
			imshow("Ч��ͼ", g_dstImage);
			break;
		}
	case 4: //��ñ
		{
			Mat element = getStructuringElement(MORPH_RECT, Size(g_nValue*2+1, g_nValue*2+1));
			morphologyEx(g_srcImage, g_dstImage, MORPH_TOPHAT, element);
			imshow("Ч��ͼ", g_dstImage);
			break;
		}
	case 5: //��ñ
		{
			Mat element = getStructuringElement(MORPH_RECT, Size(g_nValue*2+1, g_nValue*2+1));
			morphologyEx(g_srcImage, g_dstImage, MORPH_BLACKHAT, element);
			imshow("Ч��ͼ", g_dstImage);
			break;
		}
	default:
		cout << "Sorry Sir, NO This Mode" << endl;
		break;
	}
}