//
// Created by Pirmin on 29.05.2022.
//

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
    //Loop in loop O(n^2)
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