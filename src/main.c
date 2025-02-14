#include "map.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("Welcome to my dungeon crawler!\n");

    map_t *map = generate_map(50, 50);
    if(map == NULL) {
        return 1;
    }

    print_map(map);

    bool is_running = false;
    while(is_running) {

    }

    destroy_map(map);
    return 0;
}
