#include "annotator.hpp"

annotator::annotator(char* I_image)
{
    std::cout << "Annotator object created!\n";
    image = cv::imread(I_image, 1); // Read in RGB mode, ref: https://reurl.cc/mDdaWl
    if (!annotator::IF_image_exist())
    {
      exit(0);
    }
    else
    {
      std::cout << "Image Exist\n";
      exit(0);
    }
}

bool annotator::IF_image_exist()
{
    if ( !image.data )
    {
      printf("No Image Data\n");
      return false;
    }
    else
    {
      return true;
    }
}
