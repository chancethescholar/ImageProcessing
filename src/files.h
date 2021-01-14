//
// Created by Chance Onyiorah on 3/24/20.
//
#include <iostream>
using namespace std;
#ifndef FILES_H
#define FILES_H

class files
{
    public:

            char  idLength;
            char  colorMapType;
            char  dataTypeCode;
            short colorMapOrigin;
            short colorMapLength;
            char  colorMapDepth;
            short xOrigin;
            short yOrigin;
            short width;
            short height;
            char  bitsPerPixel;
            char  imageDescriptor;


    int size;
    unsigned char* pixelData;
    files(string);
    unsigned char* getPixels();
    int getSize();
    int getHeight();
    int getWidth();
    void displayFile(string fileName, unsigned char* pixels);
};
#endif //UNTITLED4_FILES_H
