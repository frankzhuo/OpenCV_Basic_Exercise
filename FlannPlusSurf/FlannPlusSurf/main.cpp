#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\nonfree\features2d.hpp>
#include <opencv2\features2d\features2d.hpp>
#include <iostream>
using namespace cv;
using namespace std;


int main()
{
	//
	system("color 6f");

	Mat trainImage;
	Mat a= imread("D:\\C++������ϵ�ļ��У���ѡ����ɾ����\\OpenCV_Exercise\\test.jpg",1);
	resize(a, trainImage, Size(640, 480));
	Mat trainGrayImage;
	imshow("src", trainImage);

	//surf ������ȡ����
	cvtColor(trainImage, trainGrayImage, COLOR_BGR2GRAY);
	vector<KeyPoint> trainKeyPoint;
	Mat trainDescriptor;
	SurfFeatureDetector featureDetector(80);
	featureDetector.detect(trainGrayImage, trainKeyPoint);
	SurfDescriptorExtractor featureExtractor;
	featureExtractor.compute(trainGrayImage, trainKeyPoint, trainDescriptor);

	//FLANN ����ƥ��
	FlannBasedMatcher matcher;
	vector<Mat> train_desc_collection(1, trainDescriptor);
	matcher.add(train_desc_collection);
	matcher.train();

	VideoCapture cap(0);
	unsigned int frameCount  = 0;

	while(char(waitKey(1)) != 'q')
	{
		int64 time0 = getTickCount();
		Mat testImage, testGrayImage;
		cap >> testImage;
		if(testImage.empty())
		{
			continue;
		}
		cvtColor(testImage, testGrayImage, COLOR_BGR2GRAY);
		vector<KeyPoint> testKeyPoint;
		Mat testDescriptor;
		featureDetector.detect(testGrayImage, testKeyPoint, Mat());
		featureExtractor.compute(testGrayImage, testKeyPoint, testDescriptor);

		//ƥ��ѵ���Ͳ���������
		vector<vector<DMatch>> matches;   //�����ʲô��
		matcher.knnMatch(testDescriptor, matches,2);


		//������ʽ�㷨 Low's algorithm , �õ������ƥ���
		vector<DMatch> goodMatches;
		for(unsigned int i = 0; i < matches.size(); i++)
		{
			if(matches[i][0].distance < 0.6 * matches[i][1].distance)
				goodMatches.push_back(matches[i][0]);
		}

		//����
		Mat dstImage;
		drawMatches(testImage, testKeyPoint, trainImage, trainKeyPoint, goodMatches, dstImage);
		imshow("dst", dstImage);
		cout << "��ǰ֡��Ϊ�� " << getTickFrequency()/(getTickCount() - time0) << endl;
	
	}
	waitKey();
	return 0;
}