#include <iostream>
#include <vector>
#include <opencv2\opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Point2f p(6,2);
	cout << "[��ά��] p = " << p << endl;

	Point3f l(1,2,3);
	cout << "[��ά��] l = " << l << endl;

	vector<float> v;
	v.push_back(3);
	v.push_back(5);
	v.push_back(4);
	cout << "[����Mat��Vector] v = " << Mat(v) << endl;

	vector<Point2f> points(20);
	for(size_t i = 0; i < points.size(); ++i)
	{
		points[i] = Point2f((float)(i*5),(float)(i%7));
	}
	cout << "[��ά������] points = " << points << ";";

	system("pause");
	return 0;
}