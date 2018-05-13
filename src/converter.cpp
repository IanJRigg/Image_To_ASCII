#include "converter.h"

using namespace I2A;

/*-----------------------------------------------------------------------------
Return Value : Nothing
Description  : Single argument constructor for the converter class
-----------------------------------------------------------------------------*/
Converter::Converter(std::string path) :
    image_path(path),
    square_size(10UL),
    ascii_image("")
{
    image = imread(image_path, cv::IMREAD_GRAYSCALE);

    if (image_is_valid())
    {
        convert_image();
    }
}


/*-----------------------------------------------------------------------------
Return Value : 
Description  : 
-----------------------------------------------------------------------------*/
Converter::~Converter()
{

}


/*-----------------------------------------------------------------------------
Return Value : 
Description  : 
-----------------------------------------------------------------------------*/
bool Converter::image_is_valid() const noexcept
{
    return !image.empty();
}


/*-----------------------------------------------------------------------------
Return Value : 
Description  : 
-----------------------------------------------------------------------------*/
void Converter::print_image() const noexcept
{
    std::cout << ascii_image << std::endl;
}


/*-----------------------------------------------------------------------------
Return Value : 
Description  : 
-----------------------------------------------------------------------------*/
void Converter::display_image() const noexcept
{
    cv::namedWindow(image_path);
    cv::imshow(image_path, image);

    cv::waitKey(0); // Wait for any keystroke in the window

    cv::destroyWindow(image_path);
}


/*-----------------------------------------------------------------------------
Return Value : 
Description  : 
-----------------------------------------------------------------------------*/
void Converter::set_square_size(const UInt32 square) noexcept
{
    square_size = square;
}


/*-----------------------------------------------------------------------------
Return Value : Nothing
Description  : 
-----------------------------------------------------------------------------*/
void Converter::convert_image() noexcept
{
    ascii_image.clear();

    UInt32 row_count = image.rows - (image.rows % square_size);
    UInt32 col_count = image.cols - (image.cols % square_size);

    UInt8 average = 0UL;

    for (UInt32 row = 0UL; row < row_count; row += square_size)
    {
        for(UInt32 col = 0UL; col < col_count; col += square_size)
        {
            average = calculate_average(row, col);
            ascii_image += average_to_ascii(average);
            average = 0UL;
        }

        ascii_image += "\n";
    }
}


/*-----------------------------------------------------------------------------
Return Value : 
Description  : 
-----------------------------------------------------------------------------*/
UInt8 Converter::calculate_average(UInt32 row, UInt32 col) const noexcept
{
    UInt32 sum = 0UL;

    for (UInt32 i = 0UL; i < square_size; ++i)
    {
        for(UInt32 j = 0UL; j < square_size; ++j)
        {
            sum += static_cast<UInt32>(image.at<UInt8>(row + i, col + j));
        }
    }

    return (sum) / (square_size * square_size);
}


/*-----------------------------------------------------------------------------
Return Value : 
Description  : 
Note         : Characters here: http://paulbourke.net/dataformats/asciiart/
-----------------------------------------------------------------------------*/
std::string Converter::average_to_ascii(UInt8 average) const noexcept
{
    std::string character = "";

    if(average <= 31UL)
    {
        character += "@";
    }
    else if(average <= 56UL)
    {
        character += "%";
    }
    else if(average <= 81UL)
    {
        character += "#";
    }
    else if(average <= 106UL)
    {
        character += "*";
    }
    else if(average <= 131UL)
    {
        character += "+";
    }
    else if(average <= 156UL)
    {
        character += "=";
    }
    else if(average <= 181UL)
    {
        character += "-";
    }
    else if(average <= 206UL)
    {
        character += ":";
    }
    else if(average <= 231UL)
    {
        character += ".";
    }
    else
    {
        character += " ";
    }

    return character;
}
