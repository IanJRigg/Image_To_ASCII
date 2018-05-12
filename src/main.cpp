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

UInt8 calculate_average(Mat& image, UInt32 row, UInt32 col, UInt32 square_size)
{
    UInt32 sum = 0UL;

    for (UInt32 i = 0UL; i < square_size; ++i)
    {
        for(UInt32 j = 0UL; j < square_size; ++j)
        {
            //Print_Out("Is it failing here? " << image.cols << " " << (col + j) << " " << image.rows << " " << (row + i));
            sum += static_cast<UInt32>(image.at<UInt8>(col + j, row + i));
            //Print_Out("Nope");
        }
    }

    Print_Out((sum) / (square_size * square_size));

    return 0U;
}


void iterate_over_image(Mat& image)
{
    Print_Out(image.rows << " " << image.cols);

    for (Int32 row = 0UL; row < image.rows; row += 12UL)
    {
        for(Int32 col = 0UL; col < image.cols; col += 12UL)
        {
            calculate_average(image, row, col, 12UL);
        }
    }
}


int main()
{
    Mat image = imread("/Users/ianrigg/Desktop/half-dome.jpg", IMREAD_GRAYSCALE);

    if (image.empty())
    {
        std::cout << "bad image" << std::endl;
        return -1L;
    }

    display_image(image);
    iterate_over_image(image);

    return 0L;
}