FROM gcc

WORKDIR /OCR
COPY ./ ./

RUN apt-get update -y && \
    apt-get install --no-install-recommends -y cmake libboost-all-dev tesseract-ocr libtesseract-dev

RUN mkdir build && cd build && cmake .. && make -j $(nproc)

CMD ["build/OCR"]