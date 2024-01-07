#include "main.h"

int main(){
    SquMap * map = createSquMap(9);
    initSquMap(map);
    inputLines(map);
    fillNums(&map);
    printSquMap(map);
    return 0;
}