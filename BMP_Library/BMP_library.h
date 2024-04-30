#ifndef BMP_LIBRARY_H
#define BMP_LIBRARY_H



class BMP_library {
public:
    void embedTextInImage(const std::string& imagePath, const std::string& message, const std::string& outputImagePath);
    std::string extractTextFromImage(const std::string& imagePath);
};



#endif //BMP_LIBRARY_H
