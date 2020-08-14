#include "TextRecognizer.h"

#include <iostream>
#include <leptonica/allheaders.h>

TextRecognizer::TextRecognizer(const std::string& language) : tesseractApi{std::make_unique<tesseract::TessBaseAPI>()}
{
    if (tesseractApi->Init(nullptr, language.c_str(), tesseract::OEM_LSTM_ONLY))
    {
        std::cerr << "Could not initialize tesseract.\n";
        tesseractApi = nullptr;
    }
}

TextRecognizer::~TextRecognizer()
{
    if (tesseractApi)
    {
        tesseractApi->End();
    }
}

std::string TextRecognizer::recognizeTextFromImage(const std::string& imagePath)
{
    if (not tesseractApi)
    {
        std::cerr << "Tesseract is not initialized.\n";
        return {};
    }

    std::string recognizedText;
    char *outText;

    Pix *image = pixRead(imagePath.c_str());
    tesseractApi->SetImage(image);
    outText = tesseractApi->GetUTF8Text();
    recognizedText = outText;

    delete [] outText;
    pixDestroy(&image);

    return recognizedText;
}
