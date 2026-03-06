#include "kiss_fft.h"
#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>



/*
Input : some image that contains a binary line drawn shape, line will be white and black background

step 1 : start at theta = 0, then go out to the nearest white point, then we will go counter clockwise around the shape
step 2 : each time we get to the new point we plot its x,y cordinates as complex, and we have an iterator for our fourier transform period



return : I want to return a vector of complex numbers 
*/


std::vector<std::pair<float,float>> parametrized_line(cv::Mat binary) {

    // Find contours
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(binary, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);


    //WE ARE JUST GOING TO TAKE THE VERY FIRST CONTOUR WE SEE
    //WE DONT CARE ABOUT HIREARCHY VECTOR YET


    std::cout << "Found " << contours.size() << " contour(s)\n";
    std::cout << "Points in Contour is : " << contours[0].size() << "\n";


    // FOR DEBUGGING PURPOSES
    // // Draw the first contour on a new image for visualization
    // cv::Mat contourImg = cv::Mat::zeros(binary.size(), CV_8UC3);
    // if (!contours.empty()) {
    //     cv::drawContours(contourImg, contours, 0, cv::Scalar(0, 255, 0), 1); // green contour
    // }

    // // Display the contour
    // cv::imshow("Contour", contourImg);
    // cv::waitKey(0);

    // // Print out the contour points
    // if (!contours.empty()) {
    //     std::cout << "Contour points:\n";
    //     for (auto& p : contours[0]) {
    //         std::cout << "(" << p.x << ", " << p.y << ")\n";
    //     }
    // }

    int N = contours[0].size();

    std::vector<std::pair<float, float>> floatPoints;
    floatPoints.reserve(N);

    float cx = binary.cols / 2.0f;
    float cy = binary.rows / 2.0f;

    float max_radius = std::max(cx, cy); // to normalize by the largest extent

    for (const auto& p : contours[0]) {
        float x = (p.x - cx) / max_radius; // now in roughly [-1, 1]
        float y = -(p.y - cy) / max_radius; // now in roughly [-1, 1] //flip y?
        //flipping y results in ensuring the smallest coeffs are first in order?
        floatPoints.emplace_back(x, y);
    }

    //we have to carefully get the size of our image here and then ensure that our grid is actually of radius 1 all around,
    //This is because currently we have pixel location values at like 400,500, which results in the coeffs blowing up


    return floatPoints;

}





//////Lol monke, opencv has an fft implementation you didnt have to use kiss_fftt
std::vector<std::complex<float>> dft(std::vector<std::pair<float,float>> path) {
    int N = path.size();

    std::vector<kiss_fft_cpx> in(N);
    std::vector<kiss_fft_cpx> out(N);

    // Fill input with some example data
    for (int i = 0; i < N; ++i) {
        in[i].r = path[i].first;   // real part
        in[i].i = path[i].second;   // imaginary part
    }

    // Create FFT configuration
    kiss_fft_cfg cfg = kiss_fft_alloc(N, 0, nullptr, nullptr); // 0 = forward FFT

    // Compute FFT
    kiss_fft(cfg, in.data(), out.data());

    // // Print output
    // std::cout << "FFT result:" << std::endl;
    // for (int i = 0; i < N; ++i) {
    //     std::cout << "Bin " << i << ": " << out[i].r << " + " << out[i].i << "i\n";
    // }

    // Free configuration
    free(cfg);

    std::vector<std::complex<float>> std_out;
    std_out.reserve(out.size());

    for (int i = 0; i < N; ++i) {
        // **Orthogonal scaling**
        std_out.emplace_back(out[i].r / N, out[i].i / N);
    }

    return std_out;

}









