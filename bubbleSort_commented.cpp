//
// Created by Pirmin on 29.05.2022.
//

//Helper function to swap two elements
void swap(Ware *element_a[], Ware *element_b[]){
    auto temp = *element_a;
    *element_a = *element_b;
    *element_b = temp;
}

//Bubblesort algorithm
//https://sakai.mci4me.at/portal/site/Course-ID-SLVA-38280/tool/eb7df1f1-a702-40b7-b9b0-805acbb500f3?panel=Main
void bubbleSort(Ware *waren[], int array_size) {
    bool swapped;
    //Loop in loop = O(n^2)
    do {
        swapped = false;
        //Running through the array bubbling elements until no more swaps(swapped == false) happening
        for(int i=0; i<array_size-1;i++){

            //Element bubbling towards the end of the array, until a bigger element is in front or end of array reached
            if(waren[i]->getGewicht() > waren[i+1]->getGewicht()){
                swap(&waren[i], &waren[i+1]);
                swapped = true;
            }
        }
    } while (swapped == true);

}