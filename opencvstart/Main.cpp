#include<iostream>
//#include "opencv2/core/core.hpp"
//#include "opencv2/flann/miniflann.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/photo/photo.hpp"
//#include "opencv2/video/video.hpp"
//#include "opencv2/features2d/features2d.hpp"
//#include "opencv2/objdetect/objdetect.hpp"
//#include "opencv2/calib3d/calib3d.hpp"
//#include "opencv2/ml/ml.hpp"
//#include "opencv2/contrib/contrib.hpp"
//#include "opencv2/core/core_c.h"
//#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;
void imageloader();
bool videoloader();
bool camera();
void main()
{
	camera();
}
///Function to get and image and display it using open CV
void imageloader()
{
	Mat img = imread("wallpaper.JPG", CV_LOAD_IMAGE_UNCHANGED); //read the image data in the file "MyPic.JPG" and store it in 'img'
	if (img.empty()) //check whether the image is loaded or not
	{
		cout << "Error : Image cannot be loaded..!!" << endl;
		//system("pause"); //wait for a key press
	}
	namedWindow("[DM]Shami", CV_WINDOW_AUTOSIZE); //create a window with the name "[DM]Shami"
	imshow("[DM]Shami", img);   //display the image which is stored in the 'img' in the "[DM]Shami" window
	waitKey(0); //wait infinite time for a keypress
	destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"
}

/////Function to get a video and play it
bool videoloader()
{
	VideoCapture capture("jamil.avi");    /////Open file for reading video
	if (!capture.isOpened())
	{
		cout << "\nSorry video cannot be loaded";
		return false;
	}
	double fps = capture.get(CV_CAP_PROP_FPS);    ////IT gets the frame per second of the video
	cout << "MY frames per second are "<<fps << endl;    /////Cout frame per seconds
	namedWindow("[DM]Shami", CV_WINDOW_AUTOSIZE);
	while (1)
	{
		Mat frame;
		bool bsucess = capture.read(frame);
		if (!bsucess)
		{
			cout << "The frames are un readble"<<endl;
			return false;
		}
		imshow("[DM]Shami",frame);           ////The function to show the capture frames
		if (waitKey(30) == 27)
		{
			cout << "GOODBYE";
			return true;
		}

	}
	return true;
}

////Capturing video camera
bool camera()
{
	VideoCapture capture(0);
	if (!capture.isOpened())
	{
		cout << "\nSome kind of problem with camera";
		return false;
	}
	double width = capture.get(CV_CAP_PROP_FRAME_WIDTH);   ////capture the width of video streaming
	double height = capture.get(CV_CAP_PROP_FRAME_HEIGHT);  ////capture the height of stream
	cout << "\n" << "Width = " << width << "Height = " << height << endl;
	namedWindow("[DM]Shami",CV_WINDOW_AUTOSIZE);
	while (1)
	{
		Mat frame;
		bool bsucess = capture.read(frame);
		if (!bsucess)
		{
			cout << "\nCannot read the Video stream";
			return false;
		}
		imshow("[DM]Shami",frame);
		if (waitKey(30) == 27)
		{
			cout << "\nGood Bye";
			return true;
		}
	}
	return true;
}