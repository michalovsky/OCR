#pragma once

#include <string>
#include <tesseract/baseapi.h>
#include <memory>

class TextRecognizer
{
public:
    TextRecognizer(const std::string& language);
    ~TextRecognizer();

    std::string recognizeTextFromImage(const std::string& imagePath);

private:
    std::unique_ptr<tesseract::TessBaseAPI> tesseractApi;
};