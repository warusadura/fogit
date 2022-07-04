/*
 * Copyright (C) 2022 Dhanuka Warusadura
 */

#include <glib.h>

void dummy_test(void) {
    g_test_fail();
}

int main(int argc, char *argv[]) {
    g_test_init(&argc, &argv, NULL);
    g_test_add_func("/dummy_test", dummy_test);

    return g_test_run();
}
