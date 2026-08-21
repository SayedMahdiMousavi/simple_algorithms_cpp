#include <iostream>
#include <chrono>
#include <opencv2/opencv.hpp>

// #include <iomanip>
#include <sstream>


using namespace std;
using namespace cv;


int main(int argc, char* argv[]) {
    int counter = 0;
    int template_width, template_height;

    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " Video path" << std::endl;
        std::cerr << "Usage: " << argv[1] << " Show Template(yes|no)" << std::endl;
        std::cerr << "Usage: " << argv[2] << " Threshold(float)" << std::endl;

        return 1;
    }

    std::string video_path = argv[1];
    std::string show_template = argv[2];
    std::string threshold = argv[3];


    VideoCapture cap(video_path);
    
    cv::namedWindow("Frame", cv::WINDOW_NORMAL);
    cv::setWindowProperty("Frame", cv::WND_PROP_FULLSCREEN, cv::WINDOW_FULLSCREEN);

    cv::Mat template_image, template_image_gray;
    cv::Mat result;

    double min_val, max_val;
    cv::Point min_loc, max_loc;

    // Check if camera opened successfully
    if(!cap.isOpened()){
        cout << "Error opening video stream or file" << endl;
        return -1;
    }
    cv::Mat frame, frame_gray;

    while(1){
        
        auto start = std::chrono::steady_clock::now();
        
        cap >> frame;

        cv::Mat frame_copy = frame.clone();
        cv::cvtColor(frame, frame_gray, cv::COLOR_BGR2GRAY);


        if (counter == 0){
            cv::namedWindow("Select Template", cv::WINDOW_NORMAL);
            cv::setWindowProperty("Select Template", cv::WND_PROP_FULLSCREEN, cv::WINDOW_FULLSCREEN);
            // xmin, ymin, boxw, boxh = cv::selectROI("Select Template", frame);
            cv::Rect roi = cv::selectROI("Select Template", frame, false);

            template_image = frame_copy(roi);
            cvtColor(template_image, template_image_gray, cv::COLOR_BGR2GRAY);

            cv::destroyWindow("Select Template");
        }
        

        cv::matchTemplate(frame_gray, template_image_gray, result, cv::TM_CCOEFF_NORMED);
        
        cv::minMaxLoc(result, &min_val, &max_val, &min_loc, &max_loc);    
        
        if(max_val < std::stof(threshold)){
            std::cerr << " xxx Object Loss xxx " << std::endl;
            return 1;
        }

        template_width = template_image.cols;
        template_height = template_image.rows;
        
        // Update Template
        if (counter != 0 && counter % 3 == 0){
            std::cout << "Update Template" << std::endl;
            cv::Mat template_image_temp = frame_copy(cv::Rect(max_loc.x, max_loc.y,
                                                     template_width, template_height));

            if(show_template=="yes"){
                cv::imshow("Template Image", template_image_temp);
            }

            cvtColor(template_image_temp, template_image_gray, cv::COLOR_BGR2GRAY);
        }
        
        auto end = std::chrono::steady_clock::now();
        float fps = 1000 / (std::chrono::duration<double, std::milli>(end - start).count());

        cv::Point pt2(max_loc.x + template_width, max_loc.y + template_height);

        // FPS
        cv::putText(frame, "FPS: " + std::to_string((int)fps), cv::Point(20, 40), cv::FONT_HERSHEY_DUPLEX, 0.7, cv::Scalar(0,0,0), 2, cv::LINE_AA);
        cv::putText(frame, "FPS: " + std::to_string((int)fps), cv::Point(20+2, 40-2), cv::FONT_HERSHEY_DUPLEX, 0.7, cv::Scalar(255,255,255), 2, cv::LINE_AA);
        
        // Max Value
        stringstream ss;
        ss << fixed << setprecision(2) << max_val;

        cv::putText(frame, "Max_Value: " + ss.str(), cv::Point(max_loc.x, max_loc.y-5), cv::FONT_HERSHEY_DUPLEX, 0.75, cv::Scalar(0,0,0), 2, cv::LINE_AA);
        cv::putText(frame, "Max_Value: " + ss.str(), cv::Point(max_loc.x+1, max_loc.y-6), cv::FONT_HERSHEY_DUPLEX, 0.75, cv::Scalar(255,255,255), 2, cv::LINE_AA);

        cv::rectangle(frame, max_loc, pt2, cv::Scalar(0,255,0), 2);
    
        if (frame.empty())
            break;

        cv::imshow( "Frame", frame );
    
        
        // Press ESC on keyboard to exit
        char c = (char)waitKey(1);
        if (c == 27)
            break;
        counter += 1;
    }
    
    cap.release();
    destroyAllWindows();
    
    return 0;
}
