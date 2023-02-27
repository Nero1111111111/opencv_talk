#include "KrSmoothing.h"
#include <assert.h>


void CKrSmoothing::Average_Filetering()
{
	Mat image = imread("3.jpg");
	cv::imshow("ԭͼ", image);

	int sigma = 3;

	Mat dst;
	blur(image, dst, Size(3, 3), Point(-1, -1));

	// ��ʾͼ��
	cv::imshow("3*3�˾�ֵ�˲�", dst);

	blur(image, dst, Size(5, 5), Point(-1, -1));
	cv::imshow("5*5�˾�ֵ�˲�", dst);

	blur(image, dst, Size(12, 12), Point(-1, -1));
	cv::imshow("12*12�˾�ֵ�˲�", dst);

	waitKey(0);
}

void CKrSmoothing::Gauss_Noise()
{
#if WIP
	Mat img = cv::imread("3.jpg");
	if (img.empty())
	{
		cout << "��ȷ��ͼ���ļ������Ƿ���ȷ" << endl;
		assert(false);
	}

#endif	
	// ������ԭͼ��ͬ�ߴ硢�������ͺ�ͨ�����ľ���
	Mat image = imread("3.jpg");
	Mat img_noise = Mat::zeros(image.rows, image.cols, image.type());
	cv::imshow("ԭͼ", image);

	RNG rng(time(NULL));
	rng.fill(img_noise, RNG::NORMAL, 10, 20);

	// smoothing /filter
	Mat out;
	GaussianBlur(image, out, Size(3, 3), 0, 0);
	imshow("3*3�ĺ˸�˹�˲�Ч��ͼ", out);

	GaussianBlur(image, out, Size(7, 7), 0, 0);
	imshow("5*5�ĺ˸�˹�˲�Ч��ͼ", out);

	GaussianBlur(image, out, Size(9, 9), 0, 0);
	imshow("9*9�ĺ˸�˹�˲�Ч��ͼ", out);

	waitKey(0);
}

void CKrSmoothing::Median_Filetering()
{
	Mat image = imread("4.jpg");
	cv::imshow("ԭͼ", image);

	Mat imgResult3, imgResult7, imgResult15;
	medianBlur(image, imgResult3, 3); // 3 * 3�ĺ�
	imshow("3*3�˵���ֵ�˲�Ч��ͼ", imgResult3);

	medianBlur(image, imgResult7, 7); // 7 * 7�ĺ�
	imshow("7*7�˵���ֵ�˲�Ч��ͼ", imgResult7);

	medianBlur(image, imgResult15, 15);  // 15 * 7�ĺ�
	imshow("15*15�˵���ֵ�˲�Ч��ͼ", imgResult15);

	waitKey(0);
}

void CKrSmoothing::Bilateral_Filter()
{
	Mat image = imread("4.jpg");
	cv::imshow("ԭͼ", image);

	Mat out;
	bilateralFilter(image, out, 50, 50 * 2, 50 / 2);
	imshow("˫���˲�Ч��ͼ", out);

	waitKey(0);
}