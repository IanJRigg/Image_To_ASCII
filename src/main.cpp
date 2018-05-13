#include "converter.h"

using namespace I2A;

/*-----------------------------------------------------------------------------
Return Value : A return code. Currently hard set to 0
Description  : Main entry point for the application
-----------------------------------------------------------------------------*/
int main()
{
    Converter converter("/Users/ianrigg/Desktop/half-dome.jpg");

    if (converter.image_is_valid())
    {
        converter.print_image();
        converter.display_image();
    }

    return 0L;
}