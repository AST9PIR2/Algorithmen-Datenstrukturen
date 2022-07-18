//
// Created by Pirmin on 29.05.2022.
//

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
    //Multiple loops but no loop in loop so O(n)
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
    //Check if array has more than 1 element, this in connection with the recursive calls will break down the array in single pieces
    //With the helper function O(n) and the divide phase O(log(n)) we get a total of O(n log(n))
    if(start < end) {
        //Searching for middle of array(new part array)
        int middle = start + (end - start) / 2;
        //Recursive call "left side of part array"
        //Divide phase O(log(n))
        mergeSort(waren, start, middle);
        //Recursive call "right side of part array"
        mergeSort(waren, middle+1, end);
        //After breaking der array in its single pieces merging them together in order
        merge(waren, start, middle, end);
    }
}