#include <assert.h>
#include <errno.h>
#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image8bit.h"
#include "instrumentation.h"


void BlurTestBestCase(int argc, char* argv[]){
    if (argc != 4){
        printf("Usage: %s <small image> <medium image> <big image>\n", argv[0]);
        exit(1);
    }

    ImageInit();
    printf("------------------------Blur Best Case-------------------------\n");

    Image small = ImageLoad(argv[1]);
    if (small == NULL){
        printf("Error loading image %s\n", argv[1]);
        exit(1);
    }
    Image medium = ImageLoad(argv[2]);
    if (medium == NULL){
        printf("Error loading image %s\n", argv[2]);
        exit(1);
    }
    Image big = ImageLoad(argv[3]);
    if (big == NULL){
        printf("Error loading image %s\n", argv[3]);
        exit(1);
    }

    int dx = 0;
    int dy = 0;

    //Test the blur in the small image in window (1,1)
    InstrReset();
    printf("Blur Small Image (%dx%d): \n", ImageWidth(small), ImageHeight(small));
    ImageBlur(small, dx, dy);
    InstrPrint();

    //Test the blur in the medium image in window (1,1)
    InstrReset();
    printf("Blur Medium Image (%dx%d): \n", ImageWidth(medium), ImageHeight(medium));
    ImageBlur(medium, dx, dy);
    InstrPrint();

    //Test the blur in the big image in window (1,1)
    InstrReset();
    printf("Blur Big Image (%dx%d): \n", ImageWidth(big), ImageHeight(big));
    ImageBlur(big, dx, dy);
    InstrPrint();
    
    printf("---------------------------------------------------------------\n");

    ImageDestroy(&small);
    ImageDestroy(&medium);
    ImageDestroy(&big);
}

void BlurTestWorstCase(int argc, char* argv[]){
    if (argc != 4){
        printf("Usage: %s <small image> <medium image> <big image>\n", argv[0]);
        exit(1);
    }

    ImageInit();
    printf("------------------------Blur Worst Case------------------------\n");

    Image small = ImageLoad(argv[1]);
    if (small == NULL){
        printf("Error loading image %s\n", argv[1]);
        exit(1);
    }
    Image medium = ImageLoad(argv[2]);
    if (medium == NULL){
        printf("Error loading image %s\n", argv[2]);
        exit(1);
    }
    Image big = ImageLoad(argv[3]);
    if (big == NULL){
        printf("Error loading image %s\n", argv[3]);
        exit(1);
    }
    //Test the blur in the small image in window (1,1)
    int dx = (ImageWidth(small) - 1) / 2;
    int dy = (ImageHeight(small) - 1) / 2;
    InstrReset();
    printf("Blur Small Image (%dx%d): \n", ImageWidth(small), ImageHeight(small));
    ImageBlur(small, dx, dy);
    InstrPrint();

    //Test the blur in the medium image in window (1,1)
    dx = (ImageWidth(medium) - 1) / 2;
    dy = (ImageHeight(medium) - 1) / 2;
    InstrReset();
    printf("Blur Medium Image (%dx%d): \n", ImageWidth(medium), ImageHeight(medium));
    ImageBlur(medium, dx, dy);
    InstrPrint();

    //Test the blur in the big image in window (1,1)
    dx = (ImageWidth(big) - 1) / 2;
    dy = (ImageHeight(big) - 1) / 2;
    InstrReset();
    printf("Blur Big Image (%dx%d): \n", ImageWidth(big), ImageHeight(big));
    ImageBlur(big, dx, dy);
    InstrPrint();

    printf("---------------------------------------------------------------\n");

    ImageDestroy(&small);
    ImageDestroy(&medium);
    ImageDestroy(&big);
}

void BlurTestAverageCase(int argc, char* argv[]){
    if (argc != 4){
        printf("Usage: %s <small image> <medium image> <big image>\n", argv[0]);
        exit(1);
    }

    ImageInit();
    printf("-----------------------Blur Average Case-----------------------\n");

    Image small = ImageLoad(argv[1]);
    if (small == NULL){
        printf("Error loading image %s\n", argv[1]);
        exit(1);
    }
    Image medium = ImageLoad(argv[2]);
    if (medium == NULL){
        printf("Error loading image %s\n", argv[2]);
        exit(1);
    }
    Image big = ImageLoad(argv[3]);
    if (big == NULL){
        printf("Error loading image %s\n", argv[3]);
        exit(1);
    }
    //Test the blur in the small image in window (1,1)
    int dx = (ImageWidth(small)/2 - 1) / 2;
    int dy = (ImageHeight(small)/2 - 1) / 2;
    InstrReset();
    printf("Blur Small Image (%dx%d): \n", ImageWidth(small), ImageHeight(small));
    ImageBlur(small, dx, dy);
    InstrPrint();

    //Test the blur in the medium image in window (1,1)
    dx = (ImageWidth(medium)/2 - 1) / 2;
    dy = (ImageHeight(medium)/2 - 1) / 2;
    InstrReset();
    printf("Blur Medium Image (%dx%d): \n", ImageWidth(medium), ImageHeight(medium));
    ImageBlur(medium, dx, dy);
    InstrPrint();

    //Test the blur in the big image in window (1,1)
    dx = (ImageWidth(big)/2 - 1) / 2;
    dy = (ImageHeight(big)/2 - 1) / 2;
    InstrReset();
    printf("Blur Big Image (%dx%d): \n", ImageWidth(big), ImageHeight(big));
    ImageBlur(big, dx, dy);
    InstrPrint();

    printf("---------------------------------------------------------------\n");

    ImageDestroy(&small);
    ImageDestroy(&medium);
    ImageDestroy(&big);
}

int main(int argc, char* argv[]){
    BlurTestBestCase(argc, argv);
    BlurTestAverageCase(argc, argv);
    BlurTestWorstCase(argc, argv);
    return 0;
}