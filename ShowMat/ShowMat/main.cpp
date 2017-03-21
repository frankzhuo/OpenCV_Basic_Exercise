#include <opencv2\opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	system("color 5E");
	Mat r = Mat(3, 3, CV_8UC3);
	randu(r, Scalar::all(0), Scalar::all(255));
	//OpenCV��ʽ�����
	//way1 OpencvĬ�������ʽ
	cout << "r Ĭ�������ʽ: " << endl << r << endl;

	//way2 python���˼�ܴ�
	cout << "r Python���: " << endl << format(r, "python") << endl;

	//way3 CSV���
	cout << "r CSV���: "  << endl << format(r, "csv") << endl;

	//way4 Numpy���
	cout << "r Numpy���: " << endl << format(r, "numpy") << endl;

	//way5 C style
	cout << "r C style: " << endl << format(r, "C") << endl;

	//waitKey(27);
	system("pause");
	return 0;

}