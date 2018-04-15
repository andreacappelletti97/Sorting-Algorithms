//
//  HeapSort - Array implementation - C++
//
//  Created by Andrea Cappelletti on 15/04/2018.
//
//  Explanation: https://www.cmprogrammers.com/post.php?id=55

#include <iostream>

#define size 5

void heapify(int array[], int n_size, int index)
{
    //Set the largest as the index
    int largest = index;
    //Left element in the array of max-heap
    int left = (2*index) + 1;
    //Right element in the array of max-heap
    int right = (2*index) + 2;
    
    //Check if the left children element is greater than its parent
    if (left < n_size && array[left] > array[largest])
        largest = left;
    
    //Check if the right children element is greater than its parent
    if (right < n_size && array[right] > array[largest])
        largest = right;
    
    //If the largest is not the parent
    if (largest != index)
    {
        //Swap it with the largest one
        std::swap(array[index], array[largest]);
        //Recursively check the subtrees
        heapify(array, n_size, largest);
    }
}

//heapSort function
void heapSort(int arr[], int n)
{
    //Let's build the max-heap from the input array
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    //Now we are sure that the first element is the max
    n--;                            //While cicle from the last element
    do{
        std::swap(arr[0], arr[n]);  //Let's swap the first element
        heapify(arr, n--, 0);       //Recall the heapify function to rebuild the max-heap
        
    } while(n > 0);
}

//This function allow us to print the array so we can check if the merge was successfull
void print(int array[]){
    for(int i = 0; i< size; i++){
        std:: cout <<array[i]<<" ";
        
    }
    std::cout<<std::endl;
}

int main() {
    
    //Let's fill our array of size defined in the beginning of the file
    int array[size]={1,4,3,8,0};
    std::cout<<"Array before heapSort"<<std::endl;
    print(array);
    heapSort(array, size);
    std::cout<<"Array after heapSort"<<std::endl;
    print(array);
}
