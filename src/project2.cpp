#include <iostream>
#include <fstream>
#include "files.h"

using namespace std;

bool checkImages (files check, files example)
{
            if (check.idLength != example.idLength)
                return false;
            
            if (check.colorMapType != example.colorMapType)
                return false;
            
            if (check.dataTypeCode != example.dataTypeCode) 
                return false;
                        
            if (check.colorMapOrigin != example.colorMapOrigin) 
                return false;
            
            if (check.colorMapLength != example.colorMapLength) 
                return false;
            
            if (check.colorMapDepth != example.colorMapDepth)
                return false;
            
            if (check.xOrigin != example.xOrigin) 
                return false;
            
            if (check.yOrigin != example.yOrigin) 
                return false;
                                                
            if (check.width != example.width) 
                return false;
                                                    
            if (check.height != example.height) 
                return false;
                                                        
            if (check.bitsPerPixel != example.bitsPerPixel)
                return false;
                                                
            if (check.imageDescriptor != example.imageDescriptor) 
                return false;

            return true;
        }

int main()
{
    unsigned char* pictureOnePixels;
    unsigned char* pictureTwoPixels;
    unsigned char* pictureThreePixels;
    unsigned char* totalPixels;
    int size;
    bool checkImages (files check, files example);

    files layer1("input/layer1.tga");
    files pattern1("input/pattern1.tga");

    size = layer1.getSize();
    pictureOnePixels = layer1.getPixels();
    pictureTwoPixels = pattern1.getPixels();
    totalPixels = pictureTwoPixels;
    int i = 0;
    while (i < size) 
    {
        float pixel1 = (float)pictureOnePixels[i];
        float pixel2 = (float)pictureTwoPixels[i];
        pixel1 = pixel1/255;
        pixel2 = pixel2/255;
        float pixelCombo = (pixel1 * pixel2 * 255) + 0.5f;
        totalPixels[i] = (unsigned char)pixelCombo;
        i++;
    }
    layer1.displayFile("output/part1", totalPixels);

    files layer2("input/layer2.tga");
    files car1("input/car.tga");

    size = layer2.getSize();
    pictureOnePixels = layer2.getPixels();
    totalPixels = pictureOnePixels;
    pictureTwoPixels = car1.getPixels();

    i = 0;
    while (i < size) 
    {
        int pixel1 = (int)pictureOnePixels[i];
        int pixel2 = (int)pictureTwoPixels[i];
        int pixelCombo = pixel2 - pixel1;
        
        if (pixelCombo > 255) 
        {
		    pixelCombo = 255;
	    }
	    else if (pixelCombo < 0) 
        {
		    pixelCombo = 0;
	    }
	    else 
        {
		    pixelCombo = pixelCombo;
	    }

        totalPixels[i] = (unsigned char)pixelCombo;
        i++;
    }
    layer2.displayFile("output/part2", totalPixels);

    files layer12("input/layer1.tga");
    files pattern2("input/pattern2.tga");
    files text("input/text.tga");
    size = pattern2.getSize();
    
    pictureOnePixels = layer12.getPixels();
    pictureTwoPixels = pattern2.getPixels();
    i = 0;
    while (i < size) 
    {        
        float pixel1 = (float)pictureOnePixels[i];
        float pixel2 = (float)pictureTwoPixels[i];
        pixel1 = pixel1/255;
        pixel2 = pixel2/255;
        float pixelCombo = (pixel1 * pixel2 * 255) + 0.5f;
        totalPixels[i] = (unsigned char)pixelCombo;
        i++;
    }

    pictureThreePixels = text.getPixels();
    i = 0;
    while (i < size) 
    {
        float pixel1 = (float)totalPixels[i];
        float pixel2 = (float)pictureThreePixels[i];
        pixel1 = pixel1/255;
        pixel2 = pixel2/255;
        float pixelCombo = ((1 - (1 - pixel1) * (1 - pixel2)) * 255) + 0.5f;
        totalPixels[i] = (unsigned char)pixelCombo;
        i++;
    }
    text.displayFile("output/part3", totalPixels);

    files layer22("input/layer2.tga");
    files circles("input/circles.tga");
    files pattern22("input/pattern2.tga");
    size = circles.getSize();
    
    pictureOnePixels = layer22.getPixels();
    pictureTwoPixels = circles.getPixels();
    i = 0;
    while (i < size) 
    {
        float pixel1 = (float)pictureOnePixels[i];
        float pixel2 = (float)pictureTwoPixels[i];
        pixel1 = pixel1/255;
        pixel2 = pixel2/255;
        float pixelCombo = (pixel1 * pixel2 * 255) + 0.5f;
        totalPixels[i] = (unsigned char)pixelCombo;
        i++;
    }

    pictureThreePixels = pattern22.getPixels();
    i = 0;
    while (i < size) 
    {        
        float pixel1 = (float)totalPixels[i];
        float pixel2 = (float)pictureThreePixels[i];
        int pixelCombo = pixel1 - pixel2;
        if (pixelCombo > 255) 
        {
		    pixelCombo = 255;
	    }
	    else if (pixelCombo < 0) 
        {
		    pixelCombo = 0;
	    }
	    else 
        {
		    pixelCombo = pixelCombo;
	    }
        totalPixels[i] = (unsigned char)pixelCombo;
        i++;
    }
    pattern22.displayFile("output/part4", totalPixels);
    files layer13("input/layer1.tga");
    files pattern12("input/pattern1.tga");
    size = pattern12.getSize();
    
    pictureOnePixels = layer13.getPixels();
    pictureTwoPixels = pattern12.getPixels();

    float pixelCombo;
    i = 0;
    while (i < size) {
        float pixel1 = (float)pictureOnePixels[i];
        float pixel2 = (float)pictureTwoPixels[i];
        pixel1 = pixel1/255;
        pixel2 = pixel2/255;
        if (pixel2 <= 0.5) 
        {
            pixelCombo = (2 * pixel1 * pixel2 * 255) + 0.5f;
        
            if (pixelCombo > 255) 
            {
                pixelCombo = 255;
            }
            
            else if (pixelCombo < 0) 
            {
                pixelCombo = 0;
            }
            
            else 
            {
                pixelCombo = pixelCombo;
            }
                totalPixels[i] = (unsigned char)pixelCombo;
        }

        else 
        {
            pixelCombo = 1 - 2 * (1 - pixel1) * (1 - pixel2);
            pixelCombo = pixelCombo * 255;
            pixelCombo = pixelCombo + 0.5f;
            if (pixelCombo > 255) 
            {
		        pixelCombo = 255;
	        }
            else if (pixelCombo < 0) 
            {
                pixelCombo = 0;
            }
            else 
            {
                pixelCombo = pixelCombo;
            }
                totalPixels[i] = (unsigned char)pixelCombo;
        }
            i++;
    }
    layer13.displayFile("output/part5", totalPixels);

    files car2("input/car.tga");
    size = car2.getSize();
    pictureOnePixels = car2.getPixels();
    for (int i = 0; i < size; i++) 
    {
        totalPixels[i] = pictureOnePixels[i];
    }
    for (int i = 1; i < size; i += 3) 
    {
        int pixel =pictureOnePixels[i];
        pixel = pixel + 200;
        
        
        if (pixel > 255) 
        {
		    pixel = 255;
	    }
	    else if (pixel < 0) 
        {
		    pixel = 0;
	    }
	    else 
        {
		    pixel = pixel;
	    }        
        totalPixels[i] = pixel;
    }
    car2.displayFile("output/part6", totalPixels);

    files car3("input/car.tga");
    pictureOnePixels = car3.getPixels();

    for (int i = 0; i < size; i++) 
    {
        totalPixels[i] = pictureOnePixels[i];
    }
    for (int i = 2; i < size; i += 3) 
    {
        int pixel = pictureOnePixels[i];
        pixel *= 4;
        if (pixel > 255) 
        {
		    pixel = 255;
	    }
	    else if (pixel < 0) 
        {
		    pixel = 0;
	    }
	    else 
        {
		    pixel = pixel;
	    }       
        totalPixels[i] = pixel;
    }

    for (int i = 0; i < size; i += 3) 
    {
        int pixel = totalPixels[i];
        pixel *= 0;
        if (pixel > 255) 
        {
		    pixel = 255;
	    }
	    else if (pixel < 0) 
        {
		    pixel = 0;
	    }
	    else 
        {
		    pixel = pixel;
	    }       
        totalPixels[i] = pixel;
    }
    car3.displayFile("output/part7", totalPixels);

    files car4("input/car.tga");
    pictureOnePixels = car3.getPixels();
    unsigned char* pixel = new unsigned char[car4.getSize()];
    int index = 0;
    for (unsigned int i = 0; i < car4.getSize(); i += 3) 
    {
        pixel[index] = pictureOnePixels[i];
        pixel[index + 1] = pictureOnePixels[i];
        pixel[index + 2] = pictureOnePixels[i];
        index += 3;
    }
    car4.displayFile("output/part8_b", pixel);
    index = 0;
    for (unsigned int i = 1; i < car4.getSize(); i += 3) 
    {
        pixel[index] = pictureOnePixels[i];
        pixel[index + 1] = pictureOnePixels[i];
        pixel[index + 2] = pictureOnePixels[i];
        index += 3;
    }
    car4.displayFile("output/part8_g", pixel);
    index = 0;
    for (unsigned int i = 2; i < car4.getSize(); i += 3) 
    {
        pixel[index] = pictureOnePixels[i];
        pixel[index + 1] = pictureOnePixels[i];
        pixel[index + 2] = pictureOnePixels[i];
        index += 3;
    }
    car4.displayFile("output/part8_r", pixel);

    files layer_red("input/layer_red.tga");
    files layer_green("input/layer_green.tga");
    files layer_blue("input/layer_blue.tga");
    pictureOnePixels = layer_red.getPixels();
    pictureTwoPixels = layer_green.getPixels();
    pictureThreePixels = layer_blue.getPixels();

    for (unsigned int i = 0; i < layer_red.getSize(); i += 3) 
    {
        totalPixels[i] = pictureThreePixels[i];
    }
    for (unsigned int i = 1; i < layer_red.getSize(); i += 3) 
    {
        totalPixels[i] = pictureTwoPixels[i];
    }
    for (unsigned int i = 2; i < layer_red.getSize(); i += 3) 
    {
        totalPixels[i] = pictureOnePixels[i];
    }
    layer_red.displayFile("output/part9", totalPixels);


    files text2("input/text2.tga");
    pictureOnePixels = text2.getPixels();
    index = 0;
    for (int i = text2.getSize() - 1; i >= 0; i--) 
    {
        totalPixels[i] = pictureOnePixels[index];
        index++;
    }
    text2.displayFile("output/part10", totalPixels);

    unsigned char* pixel1;
	unsigned char* pixel2;
	string name1;
	string name2;
	bool complete = false;
	for (int i = 1; i < 8; i++) 
    {
		name1 = "output/part" + to_string(i) + ".tga";
		files check(name1);
		name1 = "examples/EXAMPLE_part" + to_string(i) + ".tga";
		files example(name1);
		pixel1 = check.getPixels();
		pixel2 = example.getPixels();

        complete = checkImages(check, example);
		
		for (int i = 0; i < check.getSize(); i++) {
			if (pixel1[i] == pixel2[i]) {
				complete = true;
			}
			else {
				complete = false;
				break;
			}
		}

		if (complete) 
        {
			cout << "This part is complete\n";
		}
		else
			cout << "Something went wrong\n";
		complete = false;
		cout << "\n";
	}

    for (int i = 0; i < 3; i++) 
    {
        if (i == 1) {
            name1 = "output/part8_r.tga";
            name2 = "examples/EXAMPLE_part8_r.tga";
        }
        else if (i == 2) {
            name1 = "output/part8_g.tga";
            name2 = "examples/EXAMPLE_part8_g.tga";
        }
        else {
            name1 = "output/part8_b.tga";
            name2 = "examples/EXAMPLE_part8_b.tga";
        }
        files check(name1);
        files example(name2);
        pixel1 = check.getPixels();
        pixel2 = example.getPixels();
        
        complete = checkImages (check, example);

        for (int i = 0; i < check.getSize(); i++) 
        {
            if (pixel1[i] == pixel2[i]) 
            {
                complete = true;
            }
            else 
            {
                complete = false;
                break;
            }
        }
        if (complete) 
        {
            cout << "This part is complete\n";
        }

        else
        {
            cout << "Something went wrong\n";
        }

        complete = false;
        cout << endl;
    }

    for (int i = 9; i < 11; i++) 
    {
        name1 = "output/part" + to_string(i) + ".tga";
        files check(name1);
        name1 = "examples/EXAMPLE_part" + to_string(i) + ".tga";
        files example(name1);
        pixel1 = check.getPixels();
        pixel2 = example.getPixels();

        complete = checkImages(check, example);

        i = 0;
        while (complete != false && i < check.getSize()) 
        {
            if (pixel1[i] == pixel2[i]) 
            {
                complete = true;
            }
            else 
            {
                complete = false;
            }
            i++;
        }

        if (complete) 
        {
            cout << "This part is complete\n";
        }

        else
        {
            cout << "Something went wrong\n";
        }
    }

    return 0;
}