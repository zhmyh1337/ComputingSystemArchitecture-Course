#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "transport.h"
#include "container.h"

static Container container;

int main(int argc, char** argv)
{
    bool randomize = argc > 1 && (!strcmp(argv[1], "-r") || !strcmp(argv[1], "--randomize"));
    if (argc != (randomize ? 4 : 3))
    {
        printf("Invalid arguments.\nUsage: program.exe [-r|--randomize] inputFile outputFile\n");
        exit(1);
    }

    const char* inputFileName = randomize ? argv[2] : argv[1];
    const char* outputFileName = randomize ? argv[3] : argv[2];

    FILE* inputFile = fopen(inputFileName, "rt");
    ContainerInit(&container);
    if (randomize)
    {
        ContainerInRnd(&container, inputFile);
    }
    else
    {
        ContainerIn(&container, inputFile);
    }
    fclose(inputFile);

    FILE* outputFile = fopen(outputFileName, "wt");
    printf("Before sort:\n");
    fprintf(outputFile, "Before sort:\n");
    ContainerOut(&container, stdout);
    ContainerOut(&container, outputFile);
    ContainerSort(&container);
    printf("\nAfter sort:\n");
    fprintf(outputFile, "\nAfter sort:\n");
    ContainerOut(&container, stdout);
    ContainerOut(&container, outputFile);
    fclose(outputFile);

    return 0;
}
