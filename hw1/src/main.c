#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "transport.h"
#include "container.h"

int main(int argc, char** argv)
{
    bool randomize = !strcmp(argv[1], "-r") || !strcmp(argv[1], "--randomize");
    if (argc != (randomize ? 4 : 3))
    {
        printf("Invalid arguments.\nUsage: program.exe [-r|--randomize] inputFile outputFile\n");
        exit(1);
    }

    const char* inputFileName = randomize ? argv[2] : argv[1];
    const char* outputFileName = randomize ? argv[3] : argv[2];

    return 0;
}
