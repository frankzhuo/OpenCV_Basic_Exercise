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
// ���ã� �������ص����� setMouseCallback()
// ���ߣ� liangzelang@gmail.com
// ʱ�䣺 2017/02.26

#include <opencv2\opencv.hpp>
using namespace cv;

#define WINDOW_NAME "������ˣ������"

void on_MouseHandle(int event, int x, int y, int flags, void * param);
void DrawRectangle(cv::Mat& img, cv::Rect box);

Rect l_rectangle;
bool l_drawingbox = false;
RNG l_rng(12345);

int main()
{
	l_rectangle = Rect(-1,-1,0,0);
	Mat srcImage(600, 800, CV_8UC3), tempImage;
	srcImage.copyTo(tempImage);
	srcImage = Scalar::all(100);

	namedWindow( WINDOW_NAME);
	setMouseCallback(WINDOW_NAME, on_MouseHandle, (void *)&srcImage);

	while(1)
	{
		srcImage.copyTo(tempImage);
		if(l_drawingbox)
			DrawRectangle(tempImage, l_rectangle);
		imshow( WINDOW_NAME, tempImage);
		if( waitKey(10) == 27 )
			break;
	}
	return 0;
}

void on_MouseHandle(int event, int x, int y, int flags, void * param)
{
	Mat & image = *(cv::Mat *) param;  //Mat���͵����ã�ָ��ǿ��ת��ΪMat����ָ�룬�ڽ����ַ���õ�Mat�͵�ͼ�����ݡ�
	switch( event)
	{
	case EVENT_MOUSEMOVE:
		{
			if(l_drawingbox)
			{
				l_rectangle.width = x - l_rectangle.x;
				l_rectangle.height = y - l_rectangle.y;
			}
		}
		break;
	case EVENT_LBUTTONDOWN:
		{
			l_drawingbox = true;
			l_rectangle = Rect(x, y, 0, 0);
		}
		break;
	case EVENT_LBUTTONUP:
		{
			l_drawingbox = false;
			if( l_rectangle.width < 0)
			{
				l_rectangle.x += l_rectangle.width;
				l_rectangle.width *= -1;
			}
			if( l_rectangle.height < 0)
			{
				l_rectangle.y += l_rectangle.height;
				l_rectangle.height *= -1;
			}
			DrawRectangle( image, l_rectangle);
		}
		break;
	}
}

void DrawRectangle(cv::Mat& img, cv::Rect box)
{
	rectangle(img, box.tl(), box.br(), Scalar(l_rng.uniform(0,255),l_rng.uniform(0,255),l_rng.uniform(0,255)));
}