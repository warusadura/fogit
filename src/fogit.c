/*
 * Copyright (C) 2022 Dhanuka Warusadura
 */

#include "../include/fogit.h"

/* directory init */
int init_directory(void) {
    int ret = 0;
    errno = 0;

    ret = mkdir(".conf", 0777);
    if (errno == EEXIST)
        return 0;
    else if (ret == -1) {
        fprintf(stderr, "Failed to create .config directory\n");
        return 1;
    }
    return ret;
}

/* database init */
int init_database(void) {
    int ret = 0;
    sqlite3 *database = NULL;
    char *query = NULL;
    char *error = NULL;

    /* check if the database file already exists */
    ret = access(".conf/fogit.db", F_OK);
    if (! ret)
        return ret;

    ret = sqlite3_open(".conf/fogit.db", &database);
    if (ret != SQLITE_OK) {
        fprintf(stderr, "Failed to open the database\n");
        sqlite3_close(database);

        return 1;
    }

    query = "CREATE TABLE bookmarks(id INTEGER PRIMARY KEY"
            " AUTOINCREMENT, category TEXT, title TEXT, url TEXT);";

    ret = sqlite3_exec(database, query, 0, 0, &error);
    if (ret != SQLITE_OK) {
        fprintf(stderr, "Failed to insert data in to the database: %s\n",
                error);
        sqlite3_free(error);
        sqlite3_close(database);

        return 1;
    }
    sqlite3_close(database);

    return ret;
}

/* add item */
int add_post(char *url, char *category) {
    int ret = 0;
    sqlite3 *database = NULL;
    char *query = NULL;
    char *error = NULL;

    ret = sqlite3_open(".conf/fogit.db", &database);
    if (ret != SQLITE_OK) {
        fprintf(stderr, "Failed to open the database\n");
        sqlite3_close(database);

        return 1;
    }
    query = "INSERT INTO bookmarks (category, title, url) "
            "VALUES('other', 'temp', 'https://zetcode.com/db/sqlitec/');";

    ret = sqlite3_exec(database, query, 0, 0, &error);
    if (ret != SQLITE_OK) {
        fprintf(stderr, "Failed to insert data in to the database: %s\n",
                error);
        sqlite3_free(error);
        sqlite3_close(database);

        return 1;
    }
    sqlite3_close(database);

    return ret;
}

/* fogit runner */
int run(int argc, char *argv[]) {
    int ret = 0;
    char *input = NULL;
    char *quit = ":q";

    printf("FogIt version 0.1\n");
    printf("Press :q to exit\n");

    /* initialize directory and database if required */
    ret = init_directory();
    ret = init_database();

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
