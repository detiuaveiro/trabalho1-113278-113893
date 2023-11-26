#include <assert.h>
#include <errno.h>
#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image8bit.h"
#include "instrumentation.h"

void LocateImageBestCase(int argc, char *argv[])
{
    if (argc != 5)
    {
        printf("Usage: %s <small image> <medium image> <big image> <smaller image>\n", argv[0]);
        exit(1);
    }

    ImageInit();
    printf("---------------------LocateImage Best Case---------------------\n");

    Image small = ImageLoad(argv[1]);
    if (small == NULL)
    {
        printf("Error loading image %s\n", argv[1]);
        exit(1);
    }
    Image medium = ImageLoad(argv[2]);
    if (medium == NULL)
    {
        printf("Error loading image %s\n", argv[2]);
        exit(1);
    }
    Image big = ImageLoad(argv[3]);
    if (big == NULL)
    {
        printf("Error loading image %s\n", argv[3]);
        exit(1);
    }

    Image smaller = ImageLoad(argv[4]);
    if (smaller == NULL)
    {
        printf("Error loading image %s\n", argv[4]);
        exit(1);
    }

    ImagePaste(big, 0, 0, smaller);
    ImagePaste(medium, 0, 0, smaller);
    ImagePaste(small, 0, 0, smaller);

    int px, py;

    // Test if the smaller image is in the small image
    InstrReset();
    printf("Small image: \n");
    if (ImageLocateSubImage(small, &px, &py, smaller))
    {
        printf("Image found at (%d, %d)\n", px, py);
    }
    else
    {
        printf("Image not found\n");
    }
    InstrPrint();

    // Test if the smaller image is in the medium image
    InstrReset();
    printf("Medium image: \n");
    if (ImageLocateSubImage(medium, &px, &py, smaller))
    {
        printf("Image found at (%d, %d)\n", px, py);
    }
    else
    {
        printf("Image not found\n");
    }

    InstrPrint();

    // Test if the smaller image is in the big image
    InstrReset();
    printf("Big image: \n");
    if (ImageLocateSubImage(big, &px, &py, smaller))
    {
        printf("Image found at (%d, %d)\n", px, py);
    }
    else
    {
        printf("Image not found\n");
    }

    InstrPrint();
    
    printf("---------------------------------------------------------------\n");

    ImageDestroy(&small);
    ImageDestroy(&medium);
    ImageDestroy(&big);
    ImageDestroy(&smaller);
}



void LocateImageAverageCase(int argc, char *argv[])
{
    if (argc != 5)
    {
        printf("Usage: %s <small image> <medium image> <big image> <smaller image>\n", argv[0]);
        exit(1);
    }

    ImageInit();
    printf("-------------------LocateImage Average Case--------------------\n");

    Image small = ImageLoad(argv[1]);
    if (small == NULL)
    {
        printf("Error loading image %s\n", argv[1]);
        exit(1);
    }
    Image medium = ImageLoad(argv[2]);
    if (medium == NULL)
    {
        printf("Error loading image %s\n", argv[2]);
        exit(1);
    }
    Image big = ImageLoad(argv[3]);
    if (big == NULL)
    {
        printf("Error loading image %s\n", argv[3]);
        exit(1);
    }

    Image smaller = ImageLoad(argv[4]);
    if (smaller == NULL)
    {
        printf("Error loading image %s\n", argv[4]);
        exit(1);
    }

    ImagePaste(big, (ImageWidth(big) - ImageWidth(smaller)) / 2, (ImageHeight(big) - ImageHeight(smaller)) / 2, smaller);
    ImagePaste(medium, (ImageWidth(medium) - ImageWidth(smaller)) / 2, (ImageHeight(medium) - ImageHeight(smaller)) / 2, smaller);
    ImagePaste(small, (ImageWidth(small) - ImageWidth(smaller)) / 2, (ImageHeight(small) - ImageHeight(smaller)) / 2, smaller);

    int px, py;

    // Test if the smaller image is in the small image
    InstrReset();
    printf("Small image: \n");
    if (ImageLocateSubImage(small, &px, &py, smaller))
    {
        printf("Image found at (%d, %d)\n", px, py);
    }
    else
    {
        printf("Image not found\n");
    }
    InstrPrint();

    // Test if the smaller image is in the medium image
    InstrReset();
    printf("Medium image: \n");
    if (ImageLocateSubImage(medium, &px, &py, smaller))
    {
        printf("Image found at (%d, %d)\n", px, py);
    }
    else
    {
        printf("Image not found\n");
    }

    InstrPrint();

    // Test if the smaller image is in the big image
    InstrReset();
    printf("Big image: \n");
    if (ImageLocateSubImage(big, &px, &py, smaller))
    {
        printf("Image found at (%d, %d)\n", px, py);
    }
    else
    {
        printf("Image not found\n");
    }

    InstrPrint();
    
    printf("---------------------------------------------------------------\n");

    ImageDestroy(&small);
    ImageDestroy(&medium);
    ImageDestroy(&big);
    ImageDestroy(&smaller);
}



void LocateImageWorstCase(int argc, char *argv[])
{
    if (argc != 5)
    {
        printf("Usage: %s <small image> <medium image> <big image> <smaller image>\n", argv[0]);
        exit(1);
    }

    ImageInit();
    printf("--------------------LocateImage Worst Case---------------------\n");

    Image small = ImageLoad(argv[1]);
    if (small == NULL)
    {
        printf("Error loading image %s\n", argv[1]);
        exit(1);
    }
    Image medium = ImageLoad(argv[2]);
    if (medium == NULL)
    {
        printf("Error loading image %s\n", argv[2]);
        exit(1);
    }
    Image big = ImageLoad(argv[3]);
    if (big == NULL)
    {
        printf("Error loading image %s\n", argv[3]);
        exit(1);
    }

    Image smaller = ImageLoad(argv[4]);
    if (smaller == NULL)
    {
        printf("Error loading image %s\n", argv[4]);
        exit(1);
    }

    ImagePaste(big, ImageWidth(big) - ImageWidth(smaller), ImageHeight(big) - ImageHeight(smaller), smaller);
    ImagePaste(medium, ImageWidth(medium) - ImageWidth(smaller), ImageHeight(medium) - ImageHeight(smaller), smaller);
    ImagePaste(small, ImageWidth(small) - ImageWidth(smaller), ImageHeight(small) - ImageHeight(smaller), smaller);

    int px, py;

    
    // Test if the smaller image is in the small image
    InstrReset();
    printf("Small image: \n");
    if (ImageLocateSubImage(small, &px, &py, smaller))
    {
        printf("Image found at (%d, %d)\n", px, py);
    }
    else
    {
        printf("Image not found\n");
    }
    InstrPrint();

    // Test if the smaller image is in the medium image
    InstrReset();
    printf("Medium image: \n");
    if (ImageLocateSubImage(medium, &px, &py, smaller))
    {
        printf("Image found at (%d, %d)\n", px, py);
    }
    else
    {
        printf("Image not found\n");
    }

    InstrPrint();

    // Test if the smaller image is in the big image
    InstrReset();
    printf("Big image: \n");
    if (ImageLocateSubImage(big, &px, &py, smaller))
    {
        printf("Image found at (%d, %d)\n", px, py);
    }
    else
    {
        printf("Image not found\n");
    }

    InstrPrint();
    
    printf("---------------------------------------------------------------\n");

    ImageDestroy(&small);
    ImageDestroy(&medium);
    ImageDestroy(&big);
    ImageDestroy(&smaller);
}

int main(int argc, char *argv[])
{
    printf("-------------------SubImage Size (222x217)---------------------\n");
    LocateImageBestCase(argc, argv);
    LocateImageAverageCase(argc, argv);
    LocateImageWorstCase(argc, argv);

    printf("--------------------The Worst Case (256x256)-------------------\n");
    Image testBlack = ImageCreate(256, 256, 255);
    ImageSetPixel(testBlack, 255, 255, 255);
    Image subTestBlackSmall = ImageCreate(50, 50, 255);
    ImageSetPixel(subTestBlackSmall, 49, 49, 255);
    Image subTestBlackOne = ImageCreate(1,1, 255);
    ImageSetPixel(subTestBlackOne, 0, 0, 255);
    Image subTestBlackMedium = ImageCreate(128, 128, 255);
    ImageSetPixel(subTestBlackMedium, 127, 127, 255);
    Image subTestBlackMediumPlus = ImageCreate(206, 206, 255);
    ImageSetPixel(subTestBlackMediumPlus, 205, 205, 255);
    
    int px, py;

    InstrReset();
    printf("Image (1x1): \n");
    ImageLocateSubImage(testBlack, &px, &py, subTestBlackOne);
    InstrPrint();

    InstrReset();
    printf("Image (50x50): \n");
    ImageLocateSubImage(testBlack, &px, &py, subTestBlackSmall);
    InstrPrint();

    InstrReset();
    printf("Image (128x128): \n");
    ImageLocateSubImage(testBlack, &px, &py, subTestBlackMedium);
    InstrPrint();

    InstrReset();
    printf("Image (206x206): \n");
    ImageLocateSubImage(testBlack, &px, &py, subTestBlackMediumPlus);
    InstrPrint();

    InstrReset();
    printf("Image (256x256): \n");
    ImageLocateSubImage(testBlack, &px, &py, testBlack);
    InstrPrint();

    printf("---------------------------------------------------------------\n");

    ImageDestroy(&testBlack);
    ImageDestroy(&subTestBlackSmall);
    ImageDestroy(&subTestBlackMedium);
    return 0;
}