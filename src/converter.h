#ifndef CONVERTER_H
#define CONVERTER_H

// STL Includes
#include <string>

// opencv Includes
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

// Project Includes
#include "converter-types.h"

/*-----------------------------------------------------------------------------
Description  : Top level class used primarily to convert an image into an ascii
                 representation of that image.
-----------------------------------------------------------------------------*/
namespace I2A
{
    class Converter
    {
        public:
            explicit Converter(std::string path);
            virtual ~Converter();

            bool image_is_valid() const noexcept;

            void print_image() const noexcept;
            void display_image() const noexcept;

            void set_square_size(const UInt32 square) noexcept;

        private:
            void convert_image() noexcept;
            UInt8 calculate_average(UInt32 row, UInt32 col) const noexcept;
            std::string average_to_ascii(UInt8 average) const noexcept;

            std::string image_path;
            cv::Mat image;
            UInt32 square_size;
            std::string ascii_image;
    };
};

#endif