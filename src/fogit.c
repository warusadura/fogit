/*
 * Copyright (C) 2022 Dhanuka Warusadura
 */

#include "../include/fogit.h"

int run(int argc, char *argv[]) {
    int ret = 0;
    char *input = NULL;
    char *quit = ":q";

    printf("FogIt version 0.1\n");
    printf("Press :q to exit\n");

    while (1) {
        input = readline("fogit> ");
        if (! strcmp("\0", input)) {
            printf("fogit> Please enter a valid input\n");
            free(input);
            continue;
        }

        add_history(input); /* to check duplicate items */

        if (! strcmp(quit, input)) {
            free(input);
            break;
        }
        printf("fogit> Added to your local library %s\n", input);
        free(input);
    }

    return ret;
}

int add_post(char *url, char *category) {
    int ret = 1;

    printf("%s\n", sqlite3_libversion());

    return ret;
}
