#include <iostream>
#include "funzioni.h"

#define type particella

using namespace std;

void Vector::append(type el){
    len++;
    type *arr2 = new type[len];
    for (int i=0; i<len-1; i++) {
        arr2[i] = arr[i];
    }
    arr2[len-1] = el;
    delete[] arr;
    this->arr = arr2;//new type[len];
    //copy(arr2,arr2 + len, this->arr);
    //delete[] arr2;
    }
    void Vector::prepend(type el){
        len++;
        type *arr2 = new type[len];
        arr2[0] = el;
        for (int i=1; i<len; i++) 
            arr2[i] = arr[i-1];
        
        //delete[] arr;
        type *arr = new type[len];
        copy(arr2,arr2 + len, this -> arr);
        //delete[] arr2;
    }
    void Vector::remove(int index){
        type *arr2 = new type[len-1];
        int count = 0;
        for (int i=0; i<len; i++) {
            if (i != index) {
            arr2[count] = arr[i];
            //cout << arr2[count] << endl;
            count++;
            }
        }
        //delete[] arr;
        len--;
        type *arr = new type[len];
        copy(arr2,arr2 + len, this -> arr);
    }
    void Vector::sort(double (*func)(type), bool inverted=false) {
        for (int i=0; i<len; i++) {
            for (int j=i; j<len; j++) {
                if ((func(arr[i]) > func(arr[j]) and !inverted) or (func(arr[i]) < func(arr[j]) and inverted)) {
                    type t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }
            }
        }
    }
    type Vector::val(int index) {
        cout << arr[index].carica;
        return this->arr[index];
    }
