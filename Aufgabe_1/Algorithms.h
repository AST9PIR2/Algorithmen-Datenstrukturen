//
// Created by Pirmin on 27.05.2022.
//

#ifndef AUFGABE_1_ALGORITHMS_H
#define AUFGABE_1_ALGORITHMS_H

#include "Ware.h"
#include "Sortiment.h"


void insertionSortBaseEinkauf(Ware *waren[], int array_size);

void insertionSortBaseVerkauf(Ware *waren[], int array_size);

void bubbleSort(Ware *waren[], int array_size);

void merge(Ware *waren[], int start, int middle, int end);

void mergeSort(Ware *waren[], int start, int end);

void quickSort(Ware *waren[], int start, int end);

#endif //AUFGABE_1_ALGORITHMS_H
