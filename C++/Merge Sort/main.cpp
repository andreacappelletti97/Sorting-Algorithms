//
//  MergeSort - Array Implementation - C++
//
//  Created by Andrea Cappelletti on 10/04/2018.
//
//  Explanation: https://www.cmprogrammers.com/post.php?id=51

#include <iostream>

//Define the constant size of the array
#define size 5

//Function Merge that combine the processed array
void merge(int array[], int& first, int& middle, int& last){
   
    int length = last-first+1;                          //Calculate the length of the support array tmp
    
    int* tmp = new int[length];                         //Inizialize tmp
    
    int startLeft = first;                              //Save the initial index of the left side array
    
    int startRight = middle+1;                          //Save the initial index of the right side array
    
    
    for(int i = 0; i<length; ++i){                      //Let's fill the ordered array tmp with a for cicle
         if(startLeft>middle){                          //We have finished to fill the right side of the array
             tmp[i] = array[startRight++];
        }
        else if(startRight>last){
            tmp[i] = array[startLeft++];                //We have finished to fill the left side of the array
        }
        else if(array[startLeft]<=array[startRight]){   //Each time we are going to add the minimum element
            tmp[i] = array[startLeft++];                //The left element is the least
        }
        else{
            tmp[i] = array[startRight++];               //The right element is the least
        }
    }
    
  
    
    //Let's save the ordered array and delete tmp
    for (int m=0; m< length; ++m){
        array[first++] =tmp[m];
        
    }
    delete [] tmp;
    
}

//This is the recursive function
void mergeSort(int array[], int first, int last){
    
    if(first>=last)                                    //Base case
        
        return;
    
    
    int middle = first + (last-first)/2;               //Calculate the middle of the array (avoiding the overflow)
   
    
    mergeSort(array, first, middle);                   //Let's call the function recursively
    
    mergeSort(array, middle+1, last);
    
    merge(array, first, middle, last);                 //And then...merge!
    
    
}

//This function allows us to print the array so we can check if the merge was successful
void print(int array[]){
    for(int i = 0; i< size; i++){
        std:: cout <<array[i]<<" ";
        
    }
    std::cout<<std::endl;
}

//Main
int main(){
    int array[size]={4,6,3,2,1};                       //Let's fill our array of size defined in the beginning of the file
    std::cout<<"Array before mergeSort"<<std::endl;
    print(array);
    mergeSort(array, 0, size-1);
    std::cout<<"Array after mergeSort"<<std::endl;
    print(array);
}
