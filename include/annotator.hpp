#pragma once

#include "global.hpp"

class annotator
{
    public:
        annotator(char* I_image);
        ~annotator();
        cv::Mat process_image();
        cv::Mat gray_image(cv::Mat in_image);
        cv::Mat blur_image(cv::Mat in_image);
        cv::Mat canny_image(cv::Mat in_image);
    private:
        cv::Mat origin_image;
        cv::Mat processed_image;
        cv::Mat grayed_image;
        cv::Mat blurred_image;
        cv::Mat cannyed_image;
};