#pragma once

#include "global.hpp"

class annotator
{
    public:
        annotator(char* I_image);
        bool IF_image_exist();
    private:
        cv::Mat image;    
};