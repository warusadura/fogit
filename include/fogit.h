/*
 * Copyright (C) 2022 Dhanuka Warusadura
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sqlite3.h>

#define CATGORY_1 "tech"
#define CATGORY_2 "programming"
#define CATGORY_3 "security"
#define CATGORY_4 "other"

int run(int argc, char *argv[]);
int init_directory(void);
int init_database(void);
int add_post(char *url, char *category);
int remove_post();
int get_list(char *category);
int check_stack_duplicates();
int encrypt();
int decrypt();
