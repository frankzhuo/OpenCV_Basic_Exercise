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
// ���ã� ��֤imwrite����
// ���ߣ� liangzelang@gmail.com
// ʱ�䣺 2017/02.26

#include <opencv2\opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

void createAlphaMat(Mat &mat)
{
	for(int i = 0; i < mat.rows; ++i) {
		for(int j = 0; j < mat.cols; ++j) {
			Vec4b & rgba = mat.at<Vec4b>(i,j); //Vec4b = Vec<uchar,4> �򵥿�����vector����
			rgba[0] = UCHAR_MAX;  //0xff
			rgba[1] = saturate_cast<uchar>((float(mat.cols -j))/((float)mat.cols)*UCHAR_MAX);
			rgba[2] = saturate_cast<uchar>((float(mat.rows - i))/((float)mat.rows) *UCHAR_MAX);
			rgba[3] = saturate_cast<uchar>(0.5 * (rgba[1] + rgba[2]));
		}
	}
}

int main()
{
	Mat mat(480,640, CV_8UC4);
	createAlphaMat(mat);

	vector<int> compression_params;
	compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);

	try {
		imwrite("͸����Alphaֵͼ.png", mat, compression_params);
		imshow("���ɵ�PNGͼ", mat);
		fprintf(stdout, "PNGͼƬ�ļ���alpha���ݱ������\n �����ڹ���Ŀ¼�²鿴��IMwrite�������ɵ�ͼƬ \n");
		waitKey(0);
	}
	catch(runtime_error & ex) {
		cout << "ͼƬת����PNG��ʽ���ִ���\n" << ex.what() << endl;
		return 1;
	}
	return 0;
}