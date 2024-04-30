#include <iostream>
#include "BMP_Library/BMP_library.h"

int main() {
    BMP_library embedder;
    std::string imagePath = "output_image.bmp";

    std::string extractedText = embedder.extractTextFromImage(imagePath);

    if (!extractedText.empty()) {
        std::cout << "Извлеченный текст: " << extractedText << std::endl;
    } else {
        std::cout << "Не удалось извлечь текст из изображения." << std::endl;
    }

    return 0;
}