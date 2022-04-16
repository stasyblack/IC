// IC.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
int main() {
	cv::Mat image(cv::Size(256, 256), CV_8UC3);
	for (int x = 0; x < image.size().width; ++x) 
	{
		for (int y = 0; y < image.size().height; ++y) {
			image.at < cv::Vec3b >(y, x)[0] = x; // Blue
			image.at < cv::Vec3b >(y, x)[1] = y; // Green
			image.at < cv::Vec3b >(y, x)[2] = (x + y) / 2; // Red
		}
	}

	cv::VideoCapture cam(0);
	while (1) {
		cv::Mat img;
		cam >> img;
		cv::imshow("image", img);
		std::cout << "bjhsvdbhj\n";
		cv::waitKey(1);
	}
	return 0;
}