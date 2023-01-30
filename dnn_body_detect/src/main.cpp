#include "body_detect.h"

int main()
{
	std::cout<<"---------------- BODY DETECT ---------------"<<std::endl;

	body_detect::BodyDetection detect;

	cv::Mat image = cv::imread("/home/sunrise/workstation/dnn_body_detect/test_data/1.jpg");

	cv::resize( image, image, cv::Size( 960, 544 ) );

	cv::imshow( "test", image );
	cv::waitKey(0);

	detect.imageProcess( image );

	detect.displayResults( image );
	cv::imshow( "ret", image );
	cv::waitKey(0);

	return 0;
}
