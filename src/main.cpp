#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "configuration.h"

using namespace cv;

/*-----------------------------------------------------------------------------
Return Value : 
Description  : 
-----------------------------------------------------------------------------*/
void display_image(Mat& image)
{
    String windowName = "Gray Scale"; //Name of the window

    namedWindow(windowName); // Create a window

    imshow(windowName, image); // Show our image inside the created window.

    waitKey(0); // Wait for any keystroke in the window

    destroyWindow(windowName); //destroy the created window
}


/*-----------------------------------------------------------------------------
Return Value : 
Description  : 
-----------------------------------------------------------------------------*/
UInt8 calculate_average(Mat& image, UInt32 row, UInt32 col, UInt32 square_size)
{
    UInt32 sum = 0UL;

    for (UInt32 i = 0UL; i < square_size; ++i)
    {
        for(UInt32 j = 0UL; j < square_size; ++j)
        {
            // Print_Out("Famous last words...? " << col + j << " " << row + i << " ");
            sum += static_cast<UInt32>(image.at<UInt8>(row + i, col + j));
            // Print_Out("Nope");
        }
    }

    return (sum) / (square_size * square_size);
}


/*-----------------------------------------------------------------------------
Return Value : 
Description  : 
-----------------------------------------------------------------------------*/
std::string average_to_ascii(UInt8 average)
{
    std::string character = "";

    // Characters to include from here: http://paulbourke.net/dataformats/asciiart/

    if(average <= 31)
    {
        character += "@";
    }
    else if(average <= 56)
    {
        character += "%";
    }
    else if(average <= 81)
    {
        character += "#";
    }
    else if(average <= 106)
    {
        character += "*";
    }
    else if(average <= 131)
    {
        character += "+";
    }
    else if(average <= 156)
    {
        character += "=";
    }
    else if(average <= 181)
    {
        character += "-";
    }
    else if(average <= 206)
    {
        character += ":";
    }
    else if(average <= 231)
    {
        character += ".";
    }
    else
    {
        character += " ";
    }

    return character;
}




/*-----------------------------------------------------------------------------
Return Value : 
Description  : 
-----------------------------------------------------------------------------*/
void iterate_over_image(Mat& image)
{
    // TODO: Currently confusing columns and rows
    std::string ascii_image = "";

    Print_Out(image.rows << " " << image.cols);

    UInt32 row_count = image.rows - (image.rows % 6UL);
    UInt32 col_count = image.cols - (image.cols % 6UL);

    for (Int32 row = 0UL; row < row_count; row += 6UL)
    {
        for(Int32 col = 0UL; col < col_count; col += 6UL)
        {
            ascii_image += average_to_ascii(calculate_average(image, row, col, 6UL));
        }

        ascii_image += "\n";
    }

    Print_Out(ascii_image);
}


/*-----------------------------------------------------------------------------
Return Value : 
Description  : 
-----------------------------------------------------------------------------*/
int main()
{
    Mat image = imread("/Users/ianrigg/Desktop/half-dome.jpg", IMREAD_GRAYSCALE);

    if (image.empty())
    {
        std::cout << "bad image" << std::endl;
        return -1L;
    }


    //display_image(image);
    iterate_over_image(image);

    return 0L;
}