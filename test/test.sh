#!/bin/sh

valgrind --leak-check=full --show-leak-kinds=all ./cub3D map.cu
valgrind --leak-check=full --show-leak-kinds=all ./cub3D map.cuba
valgrind --leak-check=full --show-leak-kinds=all ./cub3D map.cubcub
valgrind --leak-check=full --show-leak-kinds=all ./cub3D map1.cub
valgrind --leak-check=full --show-leak-kinds=all ./cub3D map2.cub
valgrind --leak-check=full --show-leak-kinds=all ./cub3D map3.cub
valgrind --leak-check=full --show-leak-kinds=all ./cub3D map4.cub
valgrind --leak-check=full --show-leak-kinds=all ./cub3D map5.cub
valgrind --leak-check=full --show-leak-kinds=all ./cub3D map6.cub
valgrind --leak-check=full --show-leak-kinds=all ./cub3D map7.cub
valgrind --leak-check=full --show-leak-kinds=all ./cub3D map8.cub
valgrind --leak-check=full --show-leak-kinds=all ./cub3D map9.cub
valgrind --leak-check=full --show-leak-kinds=all ./cub3D map10.cub
valgrind --leak-check=full --show-leak-kinds=all ./cub3D map11.cub
valgrind --leak-check=full --show-leak-kinds=all ./cub3D map12.cub
valgrind --leak-check=full --show-leak-kinds=all ./cub3D map13.cub
