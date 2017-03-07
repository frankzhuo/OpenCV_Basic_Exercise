#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>

using namespace cv;

int main()
{
	//ͼ�����������ʾ
	Mat learn = imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\learn.jpg",2|4);
	namedWindow("ѧ�����Ŀ�����");
	imshow("ѧ�����Ŀ�����",learn);

	Mat newbird = imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\logo.png",1);
	namedWindow("Newbird.cn");
	imshow("Newbird.cn",newbird);

	//ͼ���ں�
	Mat imageROI;
	
	imageROI = learn(Rect(65,560,newbird.cols,newbird.rows));

	addWeighted(imageROI, 0.5,newbird,0.3, 0. ,imageROI);

	namedWindow("Newbird should learn");

	imshow("Newbird should learn", learn);
	
	//ͼ�����
	imwrite("Neverstop2learn.jpg",learn);

	waitKey();

	return 0 ;
}