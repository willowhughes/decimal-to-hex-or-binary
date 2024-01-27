#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>

#define MAX 100

void hex(char*, char*);
void bin(char*, char*);
void reverse(char*);
void USAGE(void);

int main(int argc, char* argv[]) {
    int option = 0;
    char final[MAX];
    opterr = 0;
    if (argc < 3) {
        USAGE();
        return 1;
    }
    if (strcmp(argv[1], "-b") && strcmp(argv[1], "-x")) {
        USAGE();
        return 1;
    }
    if (strcmp(argv[2], "-p") == 0) {
        USAGE();
        return 1;
    }
    while ((option = getopt(argc, argv, "b:x:")) != -1) {
        switch (option) {
            case 'b':
                for (int i = 2; i < argc; i++) {
                    memset(final, 0, sizeof(final));
                    bin(argv[i], final);
                    printf("%s=%s\n", argv[i], final);
                }
                break;
            case 'x':
                for (int i = 2; i < argc; i++) {
                    memset(final, 0, sizeof(final));
                    hex(argv[i], final);
                    printf("%s=0x%s\n", argv[i], final);
                }
                break;
            default:
                USAGE();
                return 1;
        }
    }
    return 0;
}

void hex(char* input, char* final) {
    int value = atoi(input);
    int count = 0;
    int hex_count = 0;
    int remainder = 0;
    if (value == 0) {
        final[0] = '0';
    }
    while (value != 0) {
        remainder = value % 16;
        if (hex_count % 2 == 0 && hex_count != 0) {
            final[count] = ' ';
            count++;
        }
        if (remainder < 10) {
            final[count] = (remainder) + '0';
        } else {
            final[count] = ((remainder) - 10) + 'a';
        }
        hex_count++;
        count++;
        value = value / 16;
    }
    reverse(final);
}

void bin(char* input, char* final) {
    int value = atoi(input);
    int count = 0;
    int bin_count = 0;
    if (value == 0) {
        final[0] = '0';
    }
    while (value != 0) {
        if (bin_count % 4 == 0 && bin_count != 0) {
            final[count] = ' ';
            count++;
        }
        final[count] = (value % 2) + '0';
        bin_count++;
        count++;
        value = value / 2;
    }
    reverse(final);
}

void reverse(char* final) {
    int final_length = strlen(final);
    char t[MAX];
    for (int i = 0; i < final_length; i++) {
        t[i] = final[final_length - i - 1];
    }
    t[final_length] = '\0';
    memcpy(final, t, strlen(t));
}

void USAGE() {
    printf("Usage: ./convert [-x|-b] num1 [num2 ...]\n");
}
