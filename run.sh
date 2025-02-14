#!/bin/bash

clang src/main.c src/map.c src/tile.c src/player.c -o bin/dungeon

bin/dungeon
