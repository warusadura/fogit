/*
 * Copyright (C) 2022 Dhanuka Warusadura
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "../include/fogit.h"

int main(int argc, char *argv[]) {
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

        add_history(input);

        if (! strcmp(quit, input)) {
            free(input);
            break;
        }
        printf("fogit> Added to your local library %s\n", input);
        free(input);
    }

    return 0;
}
