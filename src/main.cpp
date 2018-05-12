#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "configuration.h"

using namespace cv;

void display_image(Mat& image)
{
    String windowName = "Gray Scale"; //Name of the window

    namedWindow(windowName); // Create a window

    imshow(windowName, image); // Show our image inside the created window.

    waitKey(0); // Wait for any keystroke in the window

    destroyWindow(windowName); //destroy the created window
}

Uint8 calculate_average(Mat& image, Uint32 row, Uint32 col, Uint32 square_size)
{
    Vec3b intensity = image.at<Vec3b>(col, row);

    UInt32 blue  = static_cast<UInt32>(intensity.val[0UL]);
    UInt32 green = static_cast<UInt32>(intensity.val[1UL]);
    UInt32 red   = static_cast<UInt32>(intensity.val[2UL]);

    Print_Out((blue + green + red) / 3);
}


void iterate_over_image(Mat& image)
{
    Mat grayscale_image;
    cv::cvtColor(image, grayscale_image, cv::COLOR_BGR2GRAY);

    for (Int32 row = 0UL; row < image.rows; ++row)
    {
        for(Int32 col = 0UL; col < image.cols; ++col)
        {
            calculate_average(image, row, col, 12UL);
        }
    }
}


int main()
{
    Mat image = imread("/Users/ianrigg/Desktop/half-dome.jpg");

    if (image.empty())
    {
        std::cout << "bad image" << std::endl;
        return -1L;
    }

    display_image(image);
    iterate_over_image(image);

    return 0L;
}