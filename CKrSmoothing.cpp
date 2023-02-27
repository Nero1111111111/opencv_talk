#include "KrSmoothing.h"
#include <assert.h>


void CKrSmoothing::Average_Filetering()
{
	Mat image = imread("3.jpg");
	cv::imshow("原图", image);

	int sigma = 3;

	Mat dst;
	blur(image, dst, Size(3, 3), Point(-1, -1));

	// 显示图像
	cv::imshow("3*3核均值滤波", dst);

	blur(image, dst, Size(5, 5), Point(-1, -1));
	cv::imshow("5*5核均值滤波", dst);

	blur(image, dst, Size(12, 12), Point(-1, -1));
	cv::imshow("12*12核均值滤波", dst);

	waitKey(0);
}

void CKrSmoothing::Gauss_Noise()
{
#if WIP
	Mat img = cv::imread("3.jpg");
	if (img.empty())
	{
		cout << "请确认图像文件名称是否正确" << endl;
		assert(false);
	}

#endif	
	// 生成与原图像同尺寸、数据类型和通道数的矩阵
	Mat image = imread("3.jpg");
	Mat img_noise = Mat::zeros(image.rows, image.cols, image.type());
	cv::imshow("原图", image);

	RNG rng(time(NULL));
	rng.fill(img_noise, RNG::NORMAL, 10, 20);

	// smoothing /filter
	Mat out;
	GaussianBlur(image, out, Size(3, 3), 0, 0);
	imshow("3*3的核高斯滤波效果图", out);

	GaussianBlur(image, out, Size(7, 7), 0, 0);
	imshow("5*5的核高斯滤波效果图", out);

	GaussianBlur(image, out, Size(9, 9), 0, 0);
	imshow("9*9的核高斯滤波效果图", out);

	waitKey(0);
}

void CKrSmoothing::Median_Filetering()
{
	Mat image = imread("4.jpg");
	cv::imshow("原图", image);

	Mat imgResult3, imgResult7, imgResult15;
	medianBlur(image, imgResult3, 3); // 3 * 3的核
	imshow("3*3核的中值滤波效果图", imgResult3);

	medianBlur(image, imgResult7, 7); // 7 * 7的核
	imshow("7*7核的中值滤波效果图", imgResult7);

	medianBlur(image, imgResult15, 15);  // 15 * 7的核
	imshow("15*15核的中值滤波效果图", imgResult15);

	waitKey(0);
}

void CKrSmoothing::Bilateral_Filter()
{
	Mat image = imread("4.jpg");
	cv::imshow("原图", image);

	Mat out;
	bilateralFilter(image, out, 50, 50 * 2, 50 / 2);
	imshow("双边滤波效果图", out);

	waitKey(0);
}