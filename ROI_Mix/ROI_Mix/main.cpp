////////////////////////////////////////////////////////////////////
//                          _ooOoo_                               //
//                         o8888888o                              //
//                         88" . "88                              //
//                         (| ^_^ |)                              //
//                         O\  =  /O                              //
//                      ____/`---'\____                           //
//                    .'  \\|     |//  `.                         //
//                   /  \\|||  :  |||//  \                        //
//                  /  _||||| -:- |||||-  \                       //
//                  |   | \\\  -  /// |   |                       //
//                  | \_|  ''\---/''  |   |                       //
//                  \  .-\__  `-`  ___/-. /                       //
//                ___`. .'  /--.--\  `. . ___                     //
//              ."" '<  `.___\_<|>_/___.'  >'"".                  //
//            | | :  `- \`.;`\ _ /`;.`/ - ` : | |                 //
//            \  \ `-.   \_ __\ /__ _/   .-` /  /                 //
//      ========`-.____`-.___\_____/___.-`____.-'========         //
//                           `=---='                              //
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^        //
//         ���汣��       ����BUG     �����޸�                    //
////////////////////////////////////////////////////////////////////
// ���ã� ����ͼ���ں�(��Trackbar����ʵ�Ѿ�ʵ����)
// ���ߣ� liangzelang@gmail.com
// ʱ�䣺 2017/03.15 
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;
const double AlphaValue = 0.4;
const double BetaValue = 1 - AlphaValue;
bool ROI_AddImage();
bool LinearBlending();
bool ROI_LinearBlending();

int main()
{
	system("color 5E");
	if( ROI_AddImage() && LinearBlending() && ROI_LinearBlending())
	{
		cout << endl << " ���гɹ����ó�������Ҫ��ͼ��.\n" << endl;
	}

	waitKey();
   	return 0;
}

bool ROI_AddImage()
{
	Mat srcImage = imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\learn.jpg",1);
	Mat logoImage = imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\logo.png",1);
	if((!srcImage.data) && (!logoImage.data))
	{
		cout << "����ͼƬʧ��.\n";
		return false;
	}
	Mat ImageROI = srcImage(Rect(65, 560, logoImage.cols, logoImage.rows));

	//������ģ
	Mat mask = imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\logo.png", 0);  //Ϊʲô�����ǻҶ�ͼ

	//����ģ���Ƶ�ROI
	logoImage.copyTo(ImageROI, mask);

	namedWindow("ROI_examples");
	imshow("ROI_examples", srcImage);
	return true;
}
bool LinearBlending()
{
	Mat srcImage1 = imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\lena.png");
	Mat srcImage2 = imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\lena_src.png");
	if(!srcImage1.data && !srcImage2.data)
	{
		cout << "����ͼƬʧ��.\n";
		return false;
	}
	Mat dstImage;
	addWeighted(srcImage1, AlphaValue, srcImage2, BetaValue, 0.0, dstImage);

	namedWindow("srcImage");
	imshow("srcImage",srcImage2);

	namedWindow("dstImage");
	imshow("dstImage", dstImage);

	return true;
}
bool ROI_LinearBlending()
{
	Mat srcImage = imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\learn.jpg",1);
	Mat logoImage = imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\logo.png",1);
	if((!srcImage.data) && (!logoImage.data))
	{
		cout << "����ͼƬʧ��.\n";
		return false;
	}
	Mat ImageROI = srcImage(Rect(65, 560, logoImage.cols, logoImage.rows));

	addWeighted(ImageROI, AlphaValue, logoImage, BetaValue, 0.0, ImageROI);


	namedWindow("ROI_LB_examples");
	imshow("ROI_LB_examples", srcImage);
	return true;
}
