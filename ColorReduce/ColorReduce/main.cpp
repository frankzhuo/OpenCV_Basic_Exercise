#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;
const int DIV = 32;
void colorReduce(Mat & inputImage, Mat & outputImage, int div);

int main()
{
	Mat srcImage = imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\lena.png");
	imshow("[ԭʼͼ��]",srcImage);
	
	Mat dstImage;
	dstImage.create(srcImage.rows, srcImage.cols, srcImage.type());  //����һ�ź�ԭͼͬ��С�����͵�ͼƬ

	double time1 = static_cast<double>(getTickCount());
	colorReduce(srcImage, dstImage, DIV);
	time1 = ((double)getTickCount() - time1) / getTickFrequency();
	cout << "Running time: " << time1 << " sec.\n" << endl;

	imshow("[Ч��ͼ]", dstImage);
	waitKey(0);
	return 0;
}

void colorReduce(Mat & inputImage, Mat & outputImage, int div)
{
	outputImage = inputImage.clone();
	int rowNumber = outputImage.rows;
	int colNumber = outputImage.cols * outputImage.channels();

	for(int i = 0; i < rowNumber; i++)
	{
		uchar * data = outputImage.ptr<uchar>(i);
		for(int j = 0; j < colNumber; j++)
		{
			data[j] = data[j]/div*div;
		}
	}
}

/*
void colorReduce(Mat & inputImage, Mat & outputImage, int div)
{
	outputImage = inputImage.clone();
	Mat_<Vec3b>::iterator it = outputImage.begin<Vec3b>();   //begin��ģ�庯��
	Mat_<Vec3b>::iterator itend = outputImage.end<Vec3b>();
	for(; it != itend; ++it)
	{
		(*it)[0] = (*it)[0] / div * div;
		(*it)[1] = (*it)[1] / div * div;
		(*it)[2] = (*it)[2] / div * div;
	}
}
*/
/*
void colorReduce(Mat & inputImage, Mat & outputImage, int div)
{
	outputImage = inputImage.clone();
	int rowNumber = outputImage.rows;
	int colNumber = outputImage.cols;

	for(int i = 0; i < rowNumber; i++)
	{
		for(int j = 0; j < colNumber; j++)
		{
			outputImage.at<Vec3b>(i,j)[0] = outputImage.at<Vec3b>(i, j)[0] / div * div;
			outputImage.at<Vec3b>(i,j)[1] = outputImage.at<Vec3b>(i, j)[1] / div * div;
			outputImage.at<Vec3b>(i,j)[2] = outputImage.at<Vec3b>(i, j)[2] / div * div;
		}
	}
}*/