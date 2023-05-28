#include "annotator.hpp"

annotator::annotator(char* I_image)
{
    std::cout << "Annotator object created!\n";
    origin_image = cv::imread(I_image, 1); // Read in RGB mode, ref: https://reurl.cc/mDdaWl
    
    if ( !origin_image.data )
    {
      printf("No Image Data!\n");
      exit(0);
    }
}

annotator::~annotator()
{
    std::cout << "Annotator object deleted!\n";
    origin_image.release();
    processed_image.release();
    grayed_image.release();
    blurred_image.release();
    cannyed_image.release();
}

cv::Mat annotator::image_processing()
{
    grayed_image = gray_image(origin_image);
    blurred_image = blur_image(grayed_image);
    cannyed_image = canny_image(blurred_image);
    return cannyed_image;
}

cv::Mat annotator::gray_image(cv::Mat in_image)
{
  cv::Mat temp_grayed_image;
  cv::cvtColor(in_image, temp_grayed_image, cv::COLOR_BGR2GRAY);
  return temp_grayed_image;
}

cv::Mat annotator::blur_image(cv::Mat in_image)
{
  cv::Mat temp_blurred_image;
  cv::GaussianBlur(in_image, temp_blurred_image, cv::Size(3,3), 0, 0);
  return temp_blurred_image;
}

cv::Mat annotator::canny_image(cv::Mat in_image)
{
  cv::Mat temp_cannyed_image;
  cv::Canny(in_image, temp_cannyed_image, 50, 150, 3);
  return temp_cannyed_image;
}

void annotator::save_image()
{
  if (!std::filesystem::is_directory("./test"))
  {
    std::filesystem::create_directory("./test");
  }
  cv::imwrite("./test/gray.jpg", grayed_image);
  cv::imwrite("./test/blur.jpg", blurred_image);
  cv::imwrite("./test/canny.jpg", cannyed_image);
}