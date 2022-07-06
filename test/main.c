/*
 * Copyright (C) 2022 Dhanuka Warusadura
 */

#include <glib.h>

#include "../include/fogit.h"

void test_add_post(void) {
    char *url = "";
    char *category = "";

    g_assert_false(add_post(url, category));
}

int main(int argc, char *argv[]) {
    g_test_init(&argc, &argv, NULL);
    g_test_add_func("/test_add_post", test_add_post);

    return g_test_run();
}
