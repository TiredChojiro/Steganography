//
// Created by muzsa on 4/30/2024.
//

#ifndef BMP_LSB_H
#define BMP_LSB_H

#include <string>

class BMP_LSB {
public:
    static void embedTextInImage(const std::string& imagePath, const std::string& message, const std::string& outputImagePath);
    static std::string extractTextFromImage(const std::string& imagePath);
};



#endif //BMP_LSB_H
