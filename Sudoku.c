#include "main.h"

int fillNums(SquMap ** map){
    SquMap * new_map;
    for(int x=0; x<9; x++){
        for(int y=0; y<9; y++){
            SqMDataType val;
            getNodeValue(*map, x, y, &val);
            if(val != 0) continue;
            for(int n=1; n<=9; n++){
                if(checkNum(*map, x, y, n)){
                    new_map = copySquMap(*map);
                    setNodeValue(new_map, x, y, n);
                    // printf("====================\n");
                    // printSquMap(new_map);
                    if(fillNums(&new_map)){
                        destroySquMap(*map);
                        *map = new_map;
                        return 1;
                    }
                }
            }
            destroySquMap(*map);
            return 0;
        }
    }
    return 1;
}

int checkNum(SquMap *map, int x, int y, int num){
    // 检查行是否正确
    for(int ix=0; ix<map->width; ix++){
        if(ix == x) continue;
        SqMDataType val;
        getNodeValue(map, ix, y, &val);
        if(val == num) return 0;
    }

    // 检查列是否正确
    for(int iy=0; iy<map->width; iy++){
        if(iy == y) continue;
        SqMDataType val;
        getNodeValue(map, x, iy, &val);
        if(val == num) return 0;
    }

    // 检查九宫格是否正确
    int golx = x / 3;
    int goly = y / 3;
    for(int ix=golx*3; ix<golx*3+3; ix++){
        for(int iy=goly*3; iy<goly*3+3; iy++){
            if(ix == x && iy == y) continue;
            SqMDataType val;
            getNodeValue(map, ix, iy, &val);
            if(val == num) return 0;
        }
    }

    return 1;    
}