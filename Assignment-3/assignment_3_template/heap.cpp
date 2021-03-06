#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "heap.h"
using std::cout;
using std::cin;

template<class T> T &AList<T>::operator[](int index)
{
    return reprarray[index - 1];
}

template<class T> int AList<T>::getlength(void)
{
    return numitems;
}

template<class T> void AList<T>::setitem(int index, T value)
{
    if ((index > 0) && (index <= numitems))
    {
        reprarray[index - 1] = value;
        return;
    }
    else
        cout << "Index error: index out of range\n";
}

template<class T> T AList<T>::getitem(int index)
{
    if ((index > 0) && (index <= numitems))
    {
        return reprarray[index - 1];
    }
    else
    {
        cout << "Index error: index out of range\n";
        exit(EXIT_FAILURE);
    }
}

template<class T> void AList<T>::append(T value)
{
    if (numitems == maxsize)
        allocate();
    reprarray[numitems] = value;
    ++numitems;
    return;
}

template<class T> void AList<T>::insert(int index, T value)
{
    if (numitems == maxsize)
        allocate();
    if (index < numitems)
    {
        for (int j = numitems - 1; j >= index; --j)
        {
            reprarray[j+1] = reprarray[j];
        }
        reprarray[index] = value;
        ++numitems;
        return;
    }
    else
    {
        append(value);
        return;
    }
}

template<class T> void AList<T>::allocate(void)
{
    int newsize = 2 * maxsize;
    T *newarray = new T[newsize];
    for (int i = 0; i < numitems; ++i)
    {
        newarray[i] = reprarray[i];
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    return;
}

template<class T> void AList<T>::remove(int index)
{
    if ((numitems == maxsize / 4) && (maxsize > minsize))
        deallocate();
    if (index < numitems)
    {
        for (int j = index; j < numitems; ++j)
        {
            reprarray[j-1] = reprarray[j];
        }
        --numitems;
        return;
    }
    else
        cout << "Index error: list index out of range\n";
}

template<class T> void AList<T>::deallocate(void)
{
    int newsize = maxsize / 2;
    T *newarray = new T[newsize];
    for (int i = 0; i < numitems; ++i)
    {
        newarray[i] = reprarray[i];
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    return;
}

template<class T> void AList<T>::concat(AList<T> &list)
{
    int length = list.getlength();
    for (int i = 1; i <= length; ++i)
    {
        append(list[i]);
    }
    return;
}

template<class T> bool AList<T>::member(T value)
{
    bool result = false;
    for (int i = 0; i < numitems; ++i)
    {
        if (reprarray[i] == value)
        {
            result = true;
            break;
        }
    }
    return result;
}

template<class T> bool AList<T>::equal(AList<T> &list)
{
    bool result = true;
    if (numitems == list.getlength())
    {
        for (int i = 0; i < numitems; ++i)
        {
            if (reprarray[i] == list[i + 1])
                continue;
            else
            {
                result = false;
                break;
            }
        }
    }
    else
        result = false;
    return result;
}

template<class T> bool AList<T>::sublist(AList<T> &list)
{
    int length = list.getlength();
    bool result = true;
    for (int i = 1, j = 0; (i <= length) && (j < numitems); ++i, ++j)
    {
        if (list[i] == reprarray[j])
        {
            if ((j == numitems - 1) && (i < length))
            {
                result = false;
                break;
            }
        }
        else
            if (j == numitems - 1)
            {
                result = false;
                break;
            }
            else
                ++j;
    }
    return result;
}

//build the max heap using elements in the input array.
template<class T> void MaxHeap<T>::build_heap(AList<T> &array){
    //put your code below
    int length = array.getlength();
    if (0 == length){
        return;
    }
    for (int i = 1; i <= length; i++){
        this->append(array[i]);// difference between array[i] and array.getitem
    }
    for (int i = length/2; 0 < i; i--){
        this->sift_down(i, length); // call sift_down to build max-heap
    }
}

//sift down the element with index i within the first num_elements elements.
template<class T> void MaxHeap<T>::sift_down(int i, int num_elements){
    //put your code below
    int biggest = i; // note that the index starts from 1, not 0
    int l = 2 * i;
    int r = 2 * i + 1;
    if ((l <= num_elements) && (this->getitem(i) < this->getitem(l))){
        biggest = l;
        this->swap(i, biggest); // swap the elements, not the indices
        this->sift_down(biggest, num_elements); // recursively call sift_down to make sure the exchange does not violate max-heap property
    }
    if ((r <= num_elements) && (this->getitem(i) < this->getitem(r))){
        biggest = r;
        this->swap(i, biggest);
        this->sift_down(biggest, num_elements);
    }
}

//sort the input array using max heap.
template<class T> void MaxHeap<T>::heap_sort(AList<T> &array){
    //put your code below
    int length = array.getlength();
    if (0 == length){
        return;
    }
    this->build_heap(array);
    for (int i = length; 0 < i; i--){
        this->swap(1, i); // swap the root node with the last node, and we do not consider the original root node anymore
        this->sift_down(1, i - 1); // rebuild max-heap
    }
}

//swap elements with indices i and j.
template<class T> void MaxHeap<T>::swap(int i, int j){
    //put your code below    
    T temp = this->getitem(i); // a simple swap, nothing complicated
    this->setitem(i, this->getitem(j));
    this->setitem(j, temp);
}

//return the root element. 
template<class T> T MaxHeap<T>::max(){
    //put your code below
    return this->getitem(1); // return the root element
}

//print all elements in the heap in sequential order.
template<class T> void MaxHeap<T>::print_elements(){

    int n = this->getlength();
    for (int i=1; i<=n; i++){
        cout << this->getitem(i) << "\n";
    }

}

int main(){
    cout << "\npart1 test\n";
    //please feel free to add more test cases
    int input_list[10] = {5, 3, 9, 46, 15, 22, 91, 8, 29, 77};
    AList<int> input_array;
    for (int i=0; i<10; i++){
        input_array.append(input_list[i]);
    }
    MaxHeap<int> max_heap;
    max_heap.build_heap(input_array);
    cout<< max_heap.max() << "\n\n";
    max_heap.print_elements();

    cout << "\npart2 test\n";
    //please feel free to add more test cases
    int input_list_2[15] = {55, 32, 9, 46, 15, 22, 91, 18, 29, 77, 32, 16, 791, 45, 32};
    AList<int> input_array_2;
    for (int i=0; i<15; i++){
        input_array_2.append(input_list_2[i]);
    }
    MaxHeap<int> max_heap_2;
    max_heap_2.heap_sort(input_array_2);
    max_heap_2.print_elements();

    // test type double, and there is negative number
    cout << "\npart3 test: test type double, and there are negative numbers\n";
    double input_list_0[6] = {5.1, 3.8, -9.0, 46.1, -22, 91};
    AList<double> input_array_0;
    for (int i=0; i<6; i++){
        input_array_0.append(input_list_0[i]);
    }
    MaxHeap<double> max_heap_0;
    max_heap_0.heap_sort(input_array_0);
    max_heap_0.print_elements();
    
    //test case for build max_heap for type double, including negative number
    cout << "\npart4 test: test case for build max_heap for type double, including negative number\n";
    double input_list_3[20] = {55.4, 2, 3, 4, -15, 22, 9.1, 18, 9, 74.7, 37.2, 1.6, 79.1, 4.5, 3.2, 10.2, 4.1, 5.1, 6, 7};
    AList<double> input_array_3;
    for (int i=0; i<20; i++){
        input_array_3.append(input_list_3[i]);
    }
    MaxHeap<double> max_heap_3;
    max_heap_3.build_heap(input_array_3);
    cout<< max_heap_3.max() << "\n\n";
    max_heap_3.print_elements();
    
    //test case for empty array
    cout << "\npart5 test: test case for empty array\n";
    double input_list_4[0] = {};
    AList<double> input_array_4;
    MaxHeap<double> max_heap_4;
    max_heap_4.build_heap(input_array_4);
    max_heap_4.print_elements();
    
    // test type float, and there are negative numbers 
    cout << "\npart6 test: test case for float type, and there are negative numbers\n";
    float input_list_5[6] = {51.5, 3.82, -9.0, -46.1, -2.2, 9.1};
    AList<float> input_array_5;
    for (int i=0; i<6; i++){
        input_array_5.append(input_list_5[i]);
    }
    MaxHeap<float> max_heap_5;
    max_heap_5.heap_sort(input_array_5);
    cout<< max_heap_5.max() << "\n\n";
    max_heap_5.print_elements();


    return 0;
}
