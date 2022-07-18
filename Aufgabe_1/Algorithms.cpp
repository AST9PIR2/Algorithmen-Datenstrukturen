//
// Created by Pirmin on 27.05.2022.
//

#include "Algorithms.h"

//InsertionSort, BubbleSort and

//Helper function to swap two elements
void swap(Ware *element_a[], Ware *element_b[]){
    auto temp = *element_a;
    *element_a = *element_b;
    *element_b = temp;
}

//Insertions algorithm
//https://sakai.mci4me.at/portal/site/Course-ID-SLVA-38280/tool/eb7df1f1-a702-40b7-b9b0-805acbb500f3?panel=Main
void insertionSortBaseEinkauf(Ware *waren[], int array_size) {
    int i = 0;

    //Running in loop until end of array
    while(i<array_size){
        int j = i;

        //While element j smaller than element j-1, swap elements and count backwards
        while(j > 0 && waren[j-1]->getEinkaufspreis() > waren[j]->getEinkaufspreis()){
            swap(&waren[j], &waren[j-1]);
            j--;
        }
        i++;
    }
}

//Insertions algorithm(redundant...)
//https://sakai.mci4me.at/portal/site/Course-ID-SLVA-38280/tool/eb7df1f1-a702-40b7-b9b0-805acbb500f3?panel=Main
void insertionSortBaseVerkauf(Ware *waren[], int array_size) {
    int i = 0;

    //Running in loop until end of array
    while(i<array_size){
        int j = i;

        //While element j smaller than element j-1, swap elements and count backwards
        while(j > 0 && waren[j-1]->getVerkaufspreis() > waren[j]->getVerkaufspreis()){
            swap(&waren[j], &waren[j-1]);
            j--;
        }
        i++;
    }
}

//Bubblesort algorithm
//https://sakai.mci4me.at/portal/site/Course-ID-SLVA-38280/tool/eb7df1f1-a702-40b7-b9b0-805acbb500f3?panel=Main
void bubbleSort(Ware *waren[], int array_size) {
    bool swapped;
    do {
        swapped = false;
        for(int i=0; i<array_size-1;i++){

            //Element bubbling towards the end of the array, until a bigger element is in front or end of array reached
            if(waren[i]->getGewicht() > waren[i+1]->getGewicht()){
                swap(&waren[i], &waren[i+1]);
                swapped = true;
            }
        }
    } while (swapped == true);

}

//Helper function for mergesort, merging back the splittet arrays
void merge(Ware *waren[], int start, int middle, int end) {
    auto n1 = middle - start + 1;
    auto n2 = end - middle;

    //Declaring new arrays; left and right
    Ware * leftArray[n1];
    Ware * rightArray[n2];

    //Assigning values from hand over array to the splittet arrays
    for(int i= 0; i < n1; i++) {
        leftArray[i] = waren[start + i];
    }
    for(int j = 0; j < n2; j++) {
        rightArray[j] = waren[middle + j + 1];
    }

    auto l = 0;
    auto r = 0;
    auto m = start;

    //Loop running as long both iterators stay in their arrays(left/right)
    while(l < n1 && r < n2){

        //Assigning the smaller number value to from start to end of array (m)
        if(leftArray[l]->getBezeichnung() <= rightArray[r]->getBezeichnung()) {
            waren[m] = leftArray[l];
            l++;
        } else {
            waren[m] = rightArray[r];
            r++;
        }
        m++;
    }

    //Filling up array in case left and right array are not the same size
    while(l < n1){
        waren[m] = leftArray[l];
        l++;
        m++;
    }

    while(r < n2){
        waren[m] = rightArray[r];
        r++;
        m++;
    }
}

//Mergesort algorithm
//https://sakai.mci4me.at/portal/site/Course-ID-SLVA-38280/tool/eb7df1f1-a702-40b7-b9b0-805acbb500f3?panel=Main
void mergeSort(Ware *waren[], int start, int end) {
    //Check if array has more than 1 element,  the recursive calls will break down the array in single pieces
    if(start < end) {
        //Searching for middle of array(new part array)
        int middle = start + (end - start) / 2;
        //Recursive call "left side of part array"
        mergeSort(waren, start, middle);
        //Recursive call "right side of part array"
        mergeSort(waren, middle+1, end);
        //After breaking der array in its single pieces merging them together in order
        merge(waren, start, middle, end);
    }
}

//Helper function for quicksort, for partitioning
////https://www.geeksforgeeks.org/cpp-program-for-quicksort/
int partition(Ware *waren[], int start, int end){

    // Setting pivot to start position
    auto pivot = waren[start]->getSeriennummer();

    // Searching for better pivot position
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (waren[i]->getSeriennummer() <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(&waren[pivotIndex], &waren[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (waren[i]->getSeriennummer() <= pivot) {
            i++;
        }
        while (waren[j]->getSeriennummer() > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(&waren[i++], &waren[j--]);
        }
    }

    return pivotIndex;
}


//Quicksort algorithm
//https://www.softwaretestinghelp.com/quick-sort/#:~:text=Quicksort%20is%20a%20widely%20used,the%20right%20of%20the%20list.
void quickSort(Ware *waren[], int start, int end){
    if (start < end){

        //partition the array
        int pivot = partition(waren, start, end);

        //Recursive call "left side of part array"
        quickSort(waren, start, pivot - 1);

        //Recursive call "right side of part array"
        quickSort(waren, pivot + 1, end);
    }
}