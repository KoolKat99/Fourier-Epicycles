#include "draw.cpp"
#include "dft.cpp"
#include <algorithm>


/*
main.cpp will take the picture that the circles and various shapes that we have
Then will call parametrize.cpp which will go along the line of points and parametrize them from the center
giving it a complex value, real for x axis, imaginary for y axis.

Then we call dft.cpp which will take those complex values and perform a discrete fourier transform on them
to get frequency components.

Finally, we call draw.cpp which will use those frequency components to reconstruct the original shape using rotating circles (epicycles).
*/

std::vector<std::complex<float>> keepLargestM(const std::vector<std::complex<float>>& fft, int M);



int main() {


    std::string imagePath = "";

    // Read the image (in color by default)
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_GRAYSCALE);

    // Check if image loaded successfully
    if (image.empty()) {
        std::cerr << "Could not open or find the image: " << imagePath << std::endl;
        return -1;
    }


    //we get some image file or something then send it to be parametrized,
    std::vector<std::pair<float,float>> path = parametrized_line(image);


    //then calculate the dft
    std::vector<std::complex<float>> path_transformed = dft(path);

    //then sort
    int M = 1000; // keep only top 100 coefficients
    std::vector<std::complex<float>> filteredFFT = keepLargestM(path_transformed, M);

    // Optional: print the first few
    for (int i = 0; i < 10; ++i) {
        std::cout << "Bin " << i << ": " << filteredFFT[i] << "\n";
    }



    //then send to draw the epicycles
    draw_epicycles(filteredFFT);



    // draw_rotating_circle();
   

    return 0;
}








std::vector<std::complex<float>> keepLargestM(const std::vector<std::complex<float>>& fft, int M) {
    int N = fft.size();
    std::vector<std::complex<float>> filtered(fft); // start with a copy

    // Compute magnitudes with indices
    struct MagnitudeIndex {
        float mag;
        int idx;
    };

    std::vector<MagnitudeIndex> mags;
    mags.reserve(N);
    for (int i = 0; i < N; ++i) {
        mags.push_back({std::abs(fft[i]), i});
    }

    // Partial sort to find the M largest magnitudes
    if (M < N) {
        std::nth_element(mags.begin(), mags.begin() + M, mags.end(),
                         [](const MagnitudeIndex &a, const MagnitudeIndex &b) {
                             return a.mag > b.mag; // descending
                         });

        // Create a set of indices to keep
        std::vector<bool> keep(N, false);
        for (int i = 0; i < M; ++i) {
            keep[mags[i].idx] = true;
        }

        // Zero out all coefficients not in the top M
        for (int i = 0; i < N; ++i) {
            if (!keep[i]) filtered[i] = {0.0f, 0.0f};
        }
    }

    return filtered;
}










