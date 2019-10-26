//
// Created by maruba on 21/10/19.
//
/*
#ifndef AEDA_PROJ1_ALGORITHMS_H
#define AEDA_PROJ1_ALGORITHMS_H
#include <vector>
#include <iostream>
using namespace std;

template<class T>
int partition(vector<T>& v, int left, int right){
    T pivot = v[right];                     //last element is the pivot
    int i = left-1;
    for (int j = left; j < right; j++){

        if (v[j] <= pivot){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[right]);
    return i+1;
}

template<class T>
void quickSort(vector<T>& v, int left, int right) {
    if (left<right) {
        int pivot = partition(v, left, right);
        quickSort(v, left, pivot - 1);
        quickSort(v, pivot + 1, right);
    }
}


template<class T>

#endif //AEDA_PROJ1_ALGORITHMS_H
*/