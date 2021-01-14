//
// Created by Chance Onyiorah on 3/24/20.
//

#include"files.h"
#include<string>
#include<fstream>
#include<iostream>

files::files(string name) {
    //getting data
    ifstream image(name, ios_base::binary);
    image.read(&idLength, 1);
    image.read(&colorMapType, 1);
    image.read(&dataTypeCode, 1);
    image.read((char*)&colorMapOrigin, 2);
    image.read((char*)&colorMapLength, 2);
    image.read(&colorMapDepth, 1);
    image.read((char*)&xOrigin, 2);
    image.read((char*)&yOrigin, 2);
    image.read((char*)&width, 2);
    image.read((char*)&height, 2);
    image.read(&bitsPerPixel, 1);
    image.read(&imageDescriptor, 1);
    //each pixel has 3 values associated with it R,G,B
    size = 3 * width * height;
    pixelData = new unsigned char[size];
    //first component is blue,green,red
    for (int i = 0; i < size; i++) {
        image.read((char*)&pixelData[i], 1);
    }

}
unsigned char* files::getPixels() {
    return pixelData;
}
int files::getSize() {
    return size;
}
int files::getHeight() {
    return height;
}
int files::getWidth() {
    return width;
}
void files::displayFile(string fileName, unsigned char* pixels) {
    ofstream file(fileName + ".tga", ios_base::binary);
    file.write((char*)&idLength, 1);
    file.write((char*)&colorMapType, 1);
    file.write((char*)&dataTypeCode, 1);
    file.write((char*)&colorMapOrigin, 2);
    file.write((char*)&colorMapLength, 2);
    file.write((char*)&colorMapDepth, 1);
    file.write((char*)&xOrigin, 2);
    file.write((char*)&yOrigin, 2);
    file.write((char*)&width, 2);
    file.write((char*)&height, 2);
    file.write((char*)&bitsPerPixel, 1);
    file.write((char*)&imageDescriptor, 1);
    for (int i = 0; i < size; i++) {
        file.write((char*)&pixels[i], 1);
    }
}
