import sys
from container import *

def main():
    quiet = False
    randomize = False
    arg_index = 1
    while arg_index < len(sys.argv):
        if sys.argv[arg_index] == '-q' or sys.argv[arg_index] == '--quiet':
            quiet = True
        elif sys.argv[arg_index] == '-r' or sys.argv[arg_index] == '--randomize':
            randomize = True
        else:
            break
        arg_index += 1

    if arg_index != len(sys.argv) - 2:
        print('Invalid arguments.\nUsage: program.exe [-q|--quiet] [-r|--randomize] inputFile outputFile\n')
        exit(1)

    try:
        with open(sys.argv[arg_index], 'rt') as f:
            container = Container()
            if randomize:
                container.inp_rnd(f)
            else:
                container.inp(f)

        with open(sys.argv[arg_index + 1], 'wt') as f:
            if not quiet:
                print('Before sort:')
                print(*container.out(), sep='\n')
            f.write('Before sort:\n')
            f.write('\n'.join(container.out()) + '\n')

            container.sort()

            if not quiet:
                print('\nAfter sort:')
                print(*container.out(), sep='\n')
            f.write('\nAfter sort:\n')
            f.write('\n'.join(container.out()) + '\n')

    except IOError:
        print(f'Failed to open file: {sys.argv[arg_index]}\n')
        exit(1)

if __name__ == '__main__':
    main()
