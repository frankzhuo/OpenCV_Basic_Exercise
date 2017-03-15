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
// ���ã� TrackBarʵ��ͼ��������ں�
// ���ߣ� liangzelang@gmail.com
// ʱ�䣺 2017/02.26
// ���⣺ ��������ͼƬ�Ĵ�С��ͬ�����¸��ĵ�ԭͼ�ˣ��нϴ����� #1
// �޸���Ϣ�� #1 2017/03/15 �޸���ɣ�����һ����ROIͬ����С�ľ��󣬸���ԭͼ��Ϣ���ں�ʱ���¶����ԭͼ�����ںϣ����ᵼ��ͼ����� 
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;
#define WINDOW_NAME "��Newbird����ѧ����"

const int value = 100;
int trackbarValue;
double AlphaValue;
double BetaValue;

Mat imageROI;	
Mat learn;
Mat newbird;
Mat NewbirdLearn;
Mat srcImage_ROI;

void on_Trackbar(int, void *)
{
	AlphaValue = (double)trackbarValue / value;
	BetaValue = 1.0-AlphaValue;
	cout << "�ں�ֵ��" << AlphaValue << " and  " << BetaValue << "\n" << endl;
		
	addWeighted(srcImage_ROI, AlphaValue, newbird, BetaValue, 0.0 ,imageROI);
	//addWeighted(learn, AlphaValue, newbird, BetaValue, 0.0, NewbirdLearn);
	imshow(WINDOW_NAME, learn);
}

int main()
{
	learn = imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\learn.jpg",2|4);
	newbird = imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\logo.png",2|4);

	if( !learn.data || !newbird.data)
	{
		printf("��ȡNewbirdѧ�����Ŀ�����ͼƬ������ȷ��Ŀ¼���Ƿ���ָ��ͼƬ��\n");
		return -1;
	}
	imageROI = learn(Rect(65,560,newbird.cols,newbird.rows));
	//srcImage_ROI.copyTo(imageROI);  //���ø��ƹ��캯�����õ������ԭͼ
	imageROI.copyTo(srcImage_ROI);
	//initialize the slider value to 50;
	trackbarValue = 50;
	namedWindow(WINDOW_NAME,1);
	// create a trackbar
	char TrackbarName[50];
	sprintf(TrackbarName, "͸��ֵ%d:", value);
	createTrackbar( TrackbarName, WINDOW_NAME, &trackbarValue, value, on_Trackbar);
	on_Trackbar(trackbarValue, 0);
	waitKey(0);
	//system("pause");
	return 0;
		
}