//
//  main.cpp
//  MergeSort
//
//  Created by Andrea Cappelletti on 10/04/2018.
//  Copyright © 2018 Andrea Cappelletti. All rights reserved.
//

// Example program
#include <iostream>
#include <string>
#include <vector>

#define size 3

struct Coord{
    int x;
    int y;
};

void print(int array[][size]){
    for(int i=0; i<size; i++){
        for(int m=0; m<size; m++){
            std::cout<<array[i][m];
            }
        std::cout<<std::endl;
        
    }
}
Coord findCoord(int array[][size]){
    Coord current;
    for(int c=0; c<size; c++){
        for(int r=0; r<size; r++){
            if(array[r][c]==1){
                current.x=c;
                current.y=r;
            }
        }
    }
    return current;
}

bool checkCoord(int x, int y){
    if((x>=0 || x<size) && (y>=0 || y<size)){
        return true;
    }
    return false;
}

bool percorso(int array[][size], int x_player, int y_player, int x, int y){
    
    
    return true;
}

int main()
{
    
    int griglia[size][size] = {
        {2,1,1},
        {0,0,1},
        {3,1,1}
    };
    
    print(griglia);
    //std::cout<<findCoord(griglia).x<<findCoord(griglia).y;
    if(percorso(griglia,0,0,0,2)){
        std::cout<<"Percorso trovato"<<std::endl;
    }
    
}


