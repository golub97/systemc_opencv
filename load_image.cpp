#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <systemc>

SC_MODULE(hello)
{
	SC_CTOR(hello)
	{
		std::cout << "Hello" << std::endl;	
	}
};

int sc_main(int argc, char** argv) 
{
    hello h("hello");
    // Check if the user provided an image path
    if (argc != 2) {
        std::cout << "Usage: <executable_name> <image_path>" << std::endl;
        return -1;
    }

    // Read the image file
    cv::Mat image = cv::imread(argv[1], cv::IMREAD_COLOR);

    // Check for an empty image
    if (image.empty()) 
    {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    // Create a window to display the image
    cv::namedWindow("Display Window", cv::WINDOW_AUTOSIZE);

    // Show the image in the window
    cv::imshow("Display Window", image);

    // Wait for a key press and close the window
    cv::waitKey(0);

    return 0;
}