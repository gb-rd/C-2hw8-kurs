#include <stdio.h>
#include <string.h>
#include "help.h"

int printAbscs = 0;
int printIters = 0;
int printAreas = 0;

int stepcount1, stepcount2, stepcount3;

float eps = 0.001;    //default setting for accuracy

void printHelp(char *argv[]) {
    fprintf(stderr, "Usage: %s [-absh] [Accuracy]\n", argv[0]);
    fprintf(stderr, "\n");
    fprintf(stderr, "    Options:\n");
    fprintf(stderr, "      -a            print root's abscissa\n");
    fprintf(stderr, "      -b            print root's iterations\n");
    fprintf(stderr, "      -s            print calculated Areas\n");
    fprintf(stderr, "      -h, --help    print this help\n\n");
    fprintf(stderr, "    Accuracy:\n");
    fprintf(stderr, "       1            0.1\n");
    fprintf(stderr, "       2            0.01\n");
    fprintf(stderr, "       3            0.001\n");
    fprintf(stderr, "       4            0.0001\n\n");
}

int parseArgs(int argc, char *argv[]) {

    size_t opt;
    for (opt = 1; opt < argc; opt++) {

    if ((argv[opt][0]=='-') && (argv[opt][1]!='-')) {
        for (int i=1; (i<strlen(argv[opt]) || (strlen(argv[opt])>5)); i++) {
            switch (argv[opt][i]) {

                case 'a':
	                printAbscs = 1;
			break;
                case 'b':
		        printIters = 1;
			break;
                case 's':
			printAreas = 1;
			break;
                default:
			printHelp(&argv[0]);
                   	return -1;
            }
        }            //TODO: check for doubles
    }
    else if ((argv[opt][0]=='-') && (argv[opt][1]=='-')) {
	if ((argv[opt][2]=='h') && (argv[opt][3]=='e') &&
	    (argv[opt][4]=='l') && (argv[opt][2]=='p')) {
                printHelp(&argv[0]);
                return -1;
	}
	else {
            printHelp(&argv[0]);
            return -1;
	}              //TODO: rest options
    }
    else if ((argv[opt][0]>='0') && (argv[opt][0]<='9') && (strlen(argv[opt])==1)) {
        switch (argv[opt][0]) {
            case '1': 
                    eps = 0.1;
                    break;
            case '2':
	            eps = 0.01;
		        break;
            case '3':
	            eps = 0.001;
	            break;
            case '4':
                    eps = 0.0001;
                    break;
            default:
                    printHelp(&argv[0]);
                    return -1;
        }
    }
    else {
        printHelp(&argv[0]);
        return -1;
    }
    }

    argv += opt;

    return 0;
}


void printResults(float root1, float root2, float root3,
		  float area1, float area2, float area3, float areaFull) {

    printf("Accuracy set %g  (use key -h or --help to see options)\n\n", eps);

    if (printIters) {
        printf("Roots search speed:\n");
        printf("    Found root 1 for %d steps\n"  , stepcount1);
        printf("    Found root 2 for %d steps\n"  , stepcount2);
        printf("    Found root 3 for %d steps\n\n", stepcount3);
    }
    if (printAbscs) {
        printf("Roots of pairs of functions from left to right:\n");
	printf("    Abscissa 1 value = %f\n"  , root1);
	printf("    Abscissa 2 value = %f\n"  , root2);
        printf("    Abscissa 3 value = %f\n\n", root3);
    }
    if (printAreas) {
        printf("All shapes have been shifted behind the axis:\n");
        printf("    Area 1 value = %f\n"  , area1);
        printf("    Area 2 value = %f\n"  , area2);
        printf("    Area 3 value = %f\n\n", area3);
    }

    printf("Figure area = %f\n", areaFull);
}
