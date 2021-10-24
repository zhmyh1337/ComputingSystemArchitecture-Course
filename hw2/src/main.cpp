#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <memory>
#include <fstream>
#include "container.h"

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
        std::cout << "Invalid arguments.\nUsage: program.exe [-q|--quiet] [-r|--randomize] inputFile outputFile\n";
        std::exit(1);
    }

    std::ifstream inputFile(argv[argIndex]);
    if (!inputFile)
    {
        std::cout << "Failed to open file: " << argv[argIndex] << std::endl;
        std::exit(1);
    }
    auto container = std::make_unique<Container>();
    if (randomize)
    {
        container->InRnd(inputFile);
    }
    else
    {
        container->In(inputFile);
    }
    inputFile.close();

    std::ofstream outputFile(argv[argIndex + 1]);
    if (!outputFile)
    {
        std::cout << "Failed to open file: " << argv[argIndex + 1] << std::endl;
        std::exit(1);
    }
    if (!quiet)
    {
        std::cout << "Before sort:" << std::endl;
        container->Out(std::cout);
    }
    outputFile << "Before sort:\n";
    container->Out(outputFile);
    container->Sort();
    if (!quiet)
    {
        std::cout << std::endl << "After sort:" << std::endl;
        container->Out(std::cout);
    }
    outputFile << std::endl << "After sort:" << std::endl;
    container->Out(outputFile);
    outputFile.close();

    return 0;
}
