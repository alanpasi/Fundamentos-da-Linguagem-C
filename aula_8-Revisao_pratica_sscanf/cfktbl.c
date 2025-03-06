#include <stdio.h>
#include <stdlib.h>

/* Protótipos das funções */
float ctf_conv(float);
float ctk_conv(float);
float ftc_conv(float);
void cfk_table(int, int, int);
void fck_table(int, int, int);
void usage(char *);

/* Funções */
void usage(char *program) {
    puts("Parameters missing!\n\nUsage:");
    printf("%s c|f <min> <max> <step>\n", program);
    exit(1);
}

float ctf_conv(float celsius) {
    return (celsius * 1.8) + 32;
}

float ctk_conv(float celsius) {
    return celsius + 237.15;
}

float ftc_conv(float fahrenheit) {
    return (fahrenheit -32) / 1.8;
}

void cfk_table(int min, int max, int step) {
    printf("\n(°C)  (°F)  (K)\n");
    while (min <= max) {
        printf("%4d %6.2f %6.2f\n", min, ctf_conv(min),ctk_conv(min));
        min += step;
    }
    puts("");
}

void fck_table(int min, int max, int step) {
    float c;
    printf("\n(°F)  (°C)  (K)\n");
    while (min <= max) {
        c = ftc_conv(min);
        printf("%4d %6.2f %6.2f\n", min, c, ctk_conv(c));
        min += step;
    }
    puts("");
}

int main(int argc, char *argv[]) {

    int min, max, step;

    if (argc < 5)
        usage(argv[0]);

    /* sscanf(string, formato, &var) */
    sscanf(argv[2], "%d", &min);
    sscanf(argv[3], "%d", &max);
    sscanf(argv[4], "%d", &step);

    if (*argv[1] == 'c')
        cfk_table(min, max, step);

    if (*argv[1] == 'f')
        fck_table(min, max, step);

    return 0;
}
