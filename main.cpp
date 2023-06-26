#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    // Path to the video file
    std::string videoPath = "vid.mp4";

    // Open the video file
    cv::VideoCapture capture(videoPath);
    if (!capture.isOpened()) {
        std::cout << "Failed to open the video file." << std::endl;
        return -1;
    }

    // Create a window to display the video
    cv::namedWindow("Video Player", cv::WINDOW_NORMAL);

    while (true) {
        cv::Mat frame;
        bool success = capture.read(frame);
        if (!success) {
            std::cout << "Failed to read frame from the video file." << std::endl;
            break;
        }

        // Add text overlay in the bottom right corner
        std::string text = "Your Text Overlay";
        int fontFace = cv::FONT_HERSHEY_SIMPLEX;
        double fontScale = 1.0;
        int thickness = 2;
        int baseline = 0;
        cv::Size textSize = cv::getTextSize(text, fontFace, fontScale, thickness, &baseline);
        cv::Point textOrg(frame.cols - textSize.width - 10, frame.rows - 10);
        cv::putText(frame, text, textOrg, fontFace, fontScale, cv::Scalar(0, 255, 0), thickness);

        // Display the frame with the text overlay
        cv::imshow("Video Player", frame);

        // Exit if the 'Esc' key is pressed
        if (cv::waitKey(1) == 27) {
            break;
        }
    }

    // Release the video capture and close the window
    capture.release();
    cv::destroyAllWindows();

    return 0;
}
