#include <iostream>

#include "GetProjectPath.h"
#include "TextRecognizer.h"

int main()
{
    TextRecognizer textRecognizer{"eng"};
    auto recognizedText = textRecognizer.recognizeTextFromImage(utils::getProjectPath("OCR") + "/resources/example_image.jpeg");
    std::cout<< recognizedText;
    return 0;
}