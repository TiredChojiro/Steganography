#include "BMP_LSB.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void BMP_LSB::embedTextInImage(const string& imagePath, const string& message, const string& outputImagePath) {
    Mat image = imread(imagePath);

    if (image.empty()) {
        cout << "Не удалось загрузить изображение." << endl;
        return;
    }

    // Преобразование текста в бинарный формат
    string binaryMessage = "";
    for (char c : message) {
        for (int i = 0; i < 8; ++i) {
            binaryMessage += ((c >> i) & 1) ? '1' : '0';
        }
    }

    int index = 0;
    for (int y = 0; y < image.rows; ++y) {
        for (int x = 0; x < image.cols; ++x) {
            Vec3b& pixel = image.at<Vec3b>(y, x);
            for (int i = 0; i < 3; ++i) {
                if (index < binaryMessage.length()) {
                    pixel.val[i] = (pixel.val[i] & 0xFE) | (binaryMessage[index++] - '0');
                } else {
                    goto end;
                }
            }
        }
    }
    end:

    imwrite(outputImagePath, image);
    cout << "Текст успешно внедрен в изображение." << endl;
}

std::string BMP_LSB::extractTextFromImage(const std::string& imagePath) {
    Mat image = imread(imagePath);

    if (image.empty()) {
        cout << "Не удалось загрузить изображение." << endl;
        return "";
    }

    string binaryMessage = "";
    for (int y = 0; y < image.rows; ++y) {
        for (int x = 0; x < image.cols; ++x) {
            Vec3b pixel = image.at<Vec3b>(y, x);
            for (int i = 0; i < 3; ++i) {
                binaryMessage += (pixel.val[i] & 1) ? '1' : '0';
            }
        }
    }

    string text = "";
    for (size_t i = 0; i < binaryMessage.length(); i += 8) {
        char c = 0;
        for (int j = 0; j < 8; ++j) {
            c = (c << 1) | (binaryMessage[i + j] - '0');
        }
        text += c;
    }

    return text;
}