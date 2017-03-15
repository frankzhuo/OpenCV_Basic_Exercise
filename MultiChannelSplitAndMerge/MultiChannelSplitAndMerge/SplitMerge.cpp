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
// ���ã� ������ɫͨ������ͨ��ͼ����
// ���ߣ� liangzelang@gmail.com
// ʱ�䣺 2017/03.15 
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
const double AlphaValue = 0.3;
const double BetaValue = 1 - AlphaValue;
bool MultiChannelBlending()
{
	Mat srcImage = imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\learn.jpg",1);
	Mat logoImage = imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\logo.png",0);
	if((!srcImage.data) && (!logoImage.data))
	{
		cout << "����ͼƬʧ��.\n";
		return false;
	}
	imshow("logoԭͼ", logoImage);
	Mat imageBlueChannel;
	vector<Mat> Channels;

	split(srcImage, Channels);

	imageBlueChannel = Channels.at(1);

	addWeighted(imageBlueChannel(Rect(65, 560, logoImage.cols, logoImage.rows)), AlphaValue, logoImage, BetaValue, 0.0, imageBlueChannel(Rect(65, 560, logoImage.cols, logoImage.rows)));

	merge(Channels, srcImage);

	namedWindow("��ɫͨ��");
	imshow("��ɫͨ��", srcImage);
	return true;
}

int main()
{
	system("color 5E");
	if(MultiChannelBlending())
	{
		cout << endl << "���гɹ��� �õ���Ҫ��ͼ��.\n" << endl;
	}
	waitKey();
	return 0;
}
