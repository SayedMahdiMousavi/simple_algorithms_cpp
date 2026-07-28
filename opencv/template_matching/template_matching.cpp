#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main(){
    cv::Mat template_image = cv::imread("./images/template.png", cv::IMREAD_GRAYSCALE);
    cv::Mat search_image = cv::imread("./images/search.png");

    cv::Mat search_image_gray;
    cv::cvtColor(search_image, search_image_gray, cv::COLOR_BGR2GRAY);


    if (template_image.empty()) {
        std::cerr << "Failed to load template_image\n";
        return -1;
    }
    if (search_image.empty()) {
        std::cerr << "Failed to load search_image\n";
        return -1;
    }
    
    cv::Mat result;
    
    cv::matchTemplate(search_image_gray, template_image, result, cv::TM_CCOEFF_NORMED);

    double min_val, max_val;
    cv::Point min_loc, max_loc;
    cv::minMaxLoc(result, &min_val, &max_val, &min_loc, &max_loc);

    int template_width = template_image.cols;
    int template_height = template_image.rows;

    cv::Point pt2(max_loc.x + template_width, max_loc.y + template_height);

    cv::putText(search_image, "Max_Value" + std::to_string(max_val), cv::Point(max_loc.x, max_loc.y-5), 1, 1, cv::Scalar(0,255,0), 2);
    cv::rectangle(search_image, max_loc, pt2, cv::Scalar(0,255,0), 2);
    
    
    cv::imwrite("./outputs/cpp_output.jpg", search_image);
    cv::imshow("Outpout", search_image);
    cv::waitKey(0);

    return 0;
}