/*
 * Copyright (C) 2022 Dhanuka Warusadura
 */

#include <glib.h>

#include "../include/fogit.h"

void test_init(void) {
    g_assert_false(init_directory());
}

void test_init_database(void) {
    g_assert_false(init_database());
}

void test_add_post(void) {
    char *url = "";
    char *category = "";

    g_assert_false(add_post(url, category));
}

int main(int argc, char *argv[]) {
    g_test_init(&argc, &argv, NULL);

    g_test_add_func("/test_init", test_init);
    g_test_add_func("/test_init_database", test_init_database);
    g_test_add_func("/test_add_post", test_add_post);

    return g_test_run();
}
