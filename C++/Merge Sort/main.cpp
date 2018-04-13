//
//  main.cpp
//  MergeSort
//
//  Created by Andrea Cappelletti on 10/04/2018.
//  Copyright © 2018 Andrea Cappelletti. All rights reserved.
//

#include <iostream>

//Define the constant size of the array
#define size 5

void merge(int array[], int& first, int& middle, int& last){
    //Calculate the length of the support array tmp
    int length = last-first+1;
    
    int* tmp = new int[length];
    
    int startLeft = first;
    
    int startRight = middle+1;
    
    //Let's fill the ordered array tmp
    for(int i = 0; i<length; ++i){
        //If left is in overflow, let's fill right
        if(startLeft>middle){
            
            tmp[i] = array[startRight++];
            
        }
        //If right is in overflow, let's fill left
        else if(startRight>last){
            
            tmp[i] = array[startLeft++];
            
        }
        //If left and right are not empty
        //Let's compare the elements
        //If the first element of left is less than the first of right
        //Let's add it to tmp
        else if(array[startLeft]<=array[startRight]){
            
            tmp[i] = array[startLeft++];
            
        }
        
        else{
            
            tmp[i] = array[startRight++];
            
        }
        
    }
    //Now it's time to return the array ordered
    for (int m=0; m< length; ++m){
        
        array[first++] =tmp[m];
        
    }
    delete [] tmp;
    
    
}

void mergeSort(int array[], int first, int last){
    
    if(first>=last)
        
        return;
    
    
    int middle = first + (last-first)/2;
   
    
    mergeSort(array, first, middle);
    
    mergeSort(array, middle+1, last);
    
    merge(array, first, middle, last);
    
    
}

void print(int array[]){
    for(int i = 0; i< size; i++){
        
        std:: cout <<array[i]<<" ";
        
    }
    std::cout<<std::endl;
}

int main(){
    int array[size]={4,6,3,2,1};
    std::cout<<"Array before mergeSort"<<std::endl;
    print(array);
    mergeSort(array, 0, size-1);
    std::cout<<"Array after mergeSort"<<std::endl;
    print(array);
}
