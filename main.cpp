#include <iostream>
#include "KrSmoothing.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "KrAnimeGAN.h"

using namespace cv;






int main()
{

	CKrSmoothing* pt = new CKrSmoothing();
	//pt->Gauss_Noise();
	//pt->Average_Filetering();
	//pt->Median_Filetering();
	pt->Bilateral_Filter();



	return 0;
}
