#include <opencv2\opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	/*����1��ʹ��Mat�������캯��*/
	Mat M(2, 2, CV_8UC3, Scalar(0,0,255));
	cout << "M = " << endl << " " << M << endl;

	//way2 û��̫�����������Ƕ�ά�����飬ʹ��cout����
	int sz[3] = {2, 2, 2};
	Mat L(3, sz, CV_8UC3, Scalar::all(0));
	
	//way3 ΪIplImage������Ϣͷ
	IplImage* img = cvLoadImage("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\learn.jpg",1);
	Mat mtx(img);
	
	//namedWindow("��ѧ��ֹ����",1);
	//imshow("��ѧ��ֹ����", mtx);

	//way4 ʹ��Create()����
	Mat K;
	K.create(4,4,CV_8UC(2));
	cout << "K = " << endl << " " << K << endl << endl;
	//way5 Matlab�󷨺�
	Mat E = Mat::eye(4,4,CV_64F);
	cout << "E = " << endl << " " << E << endl << endl;

	Mat O = Mat::ones(2,2,CV_32F);
	cout << "O = " << endl << " " << O << endl << endl;

	Mat Z = Mat::zeros(3,3,CV_8UC1);
	cout << "Z = " << endl << " " << Z << endl << endl;

	//way6 
	Mat C = (Mat_<double>(3,3) << 0, -1, 2, -1, 5, -1, 0, -1, 0);
	cout << "C = " << endl << " " << C << endl << endl;

	//way7 Ϊ�Ѵ��ڵĶ��󴴽��µ���Ϣͷ
	Mat RowClone = C.row(0).clone();
	cout << "RowClone = " << endl << " " << RowClone << endl << endl;

	system("pause");
	return 0;
}