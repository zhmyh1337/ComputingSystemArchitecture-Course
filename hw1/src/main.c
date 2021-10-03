#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "transport.h"
#include "container.h"

static Container container;

int main(int argc, char** argv)
{
    bool quiet = false;
    bool randomize = false;
    int argIndex;
    for (argIndex = 1; argIndex < argc; argIndex++)
    {
        if (!strcmp(argv[argIndex], "-q") || !strcmp(argv[argIndex], "--quiet"))
        {
            quiet = true;
        }
        else if (!strcmp(argv[argIndex], "-r") || !strcmp(argv[argIndex], "--randomize"))
        {
            randomize = true;
        }
        else
        {
            break;
        }
    }
    
    if (argIndex != argc - 2)
    {
        printf("Invalid arguments.\nUsage: program.exe [-q|--quiet] [-r|--randomize] inputFile outputFile\n");
        exit(1);
    }

    FILE* inputFile = fopen(argv[argIndex], "rt");
    if (!inputFile)
    {
        printf("Failed to open file: %s\n", argv[argIndex]);
        exit(1);
    }
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

    FILE* outputFile = fopen(argv[argIndex + 1], "wt");
    if (!outputFile)
    {
        printf("Failed to open file: %s\n", argv[argIndex + 1]);
        exit(1);
    }
    if (!quiet)
    {
        printf("Before sort:\n");
        ContainerOut(&container, stdout);
    }
    fprintf(outputFile, "Before sort:\n");
    ContainerOut(&container, outputFile);
    ContainerSort(&container);
    if (!quiet)
    {
        printf("\nAfter sort:\n");
        ContainerOut(&container, stdout);
    }
    fprintf(outputFile, "\nAfter sort:\n");
    ContainerOut(&container, outputFile);
    fclose(outputFile);

    return 0;
}
