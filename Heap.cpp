#include "Heap.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

Heap::Heap (int* array, int size) {
    this->array = array;
    this->heap_size= size;
    this->heap_capability = size;
}

Heap::~Heap(){

}

int Heap::get_key (int index) {
    return this->array[index];
}

int Heap::get_parent_index(int index){ 
    int parent_index = (double)(index-1) / 2;
    return floor(parent_index);
}

int Heap::get_right_child_index (int index) {
    return (2*index) + 2;
}

int Heap::get_left_child_index (int index){
    return (2*index) + 1;
}

int Heap::get_parent_key (int index) { 
    int parent_index = this->get_parent_index(index);
    int parent_key = this->array[parent_index];
    return parent_key;
}

int Heap::get_left_child_key(int index){
    int left_child_index = this->get_left_child_index(index);
    int left_child_key = this->array[left_child_index];
    return left_child_key;
}

int Heap::get_right_child_key(int index){
    int right_child_index = this->get_right_child_index(index);
    int right_child_key = this->array[right_child_index];
    return right_child_key;
}

void Heap::set_parent_key(int index, int new_key){
    int parent_index = this->get_parent_index(index);
    this->array[parent_index] = new_key;
}

void Heap::set_right_child_key(int index, int new_key){
    int right_child_index = this->get_right_child_index(index);
    this->array[right_child_index] = new_key;
}

void Heap::set_left_child_key(int index, int new_key){
    int left_child_index = this->get_left_child_index(index);
    this->array[left_child_index] =  new_key;
}

bool Heap::is_leaf(int index){
    int left_child_index = this->get_left_child_index(index);
    int right_child_index = this->get_right_child_index(index);
    if(!(left_child_index >= 0 && left_child_index < this->get_size()) && 
            !(right_child_index >= 0 && right_child_index < this->get_size())){
       return true; 
    }
    return false; 
}

int* Heap::get_array(){
    return this->array;
}

int Heap::get_size(){
    return this->heap_size;
}

int Heap::get_capability(){
    return this->heap_capability;
}

void Heap::set_key(int index, int new_key){ 
    this->array[index] = new_key;
}

void Heap::max_heapify(int error_node) {
    int left_child_key = this->get_left_child_key(error_node);
    int right_child_key = this->get_right_child_key(error_node);
    int left_child_index = this->get_left_child_index(error_node);
    int right_child_index = this->get_right_child_index(error_node);
    int largest_index;
    if(left_child_index < this->get_size() && left_child_key > this->get_key(error_node)){
        largest_index = left_child_index;
    } 
    else largest_index = error_node;
    if(right_child_index < this->get_size() && right_child_key > this->get_key(largest_index)){
        largest_index = right_child_index;
    }
    if(largest_index != error_node){
        int temp = this->get_key(largest_index);
        this->set_key(largest_index, this->get_key(error_node));
        this->set_key(error_node, temp);
        this->max_heapify(largest_index);
    }
} 

void Heap::build_max_heap(){
     int last_node_has_child_index;
     if(this->get_size() % 2 == 0){
         last_node_has_child_index = this->get_size() / 2;
     }
     else last_node_has_child_index = (this->get_size() / 2) - 1;
     for(int i = last_node_has_child_index; i >= 0; i--){ 
         this->max_heapify(i);
     }
}

void Heap::decrement_heap_size(){
    this->heap_size -= 1;
}

int Heap::extract_max(){ 
    this->build_max_heap();
    int max = this->get_key(0);
    this->set_key(0, this->get_key(this->get_size() - 1));
    this->set_key(this->get_size() - 1, max);
    this->decrement_heap_size();
    this->max_heapify(0);
    return max;
}

void Heap::heap_sort(){
    this->build_max_heap();
    for(int i = this->get_size() - 1; i > 0; i--){
        int current_max = this->get_key(0);
        this->set_key(0, this->get_key(this->get_size() - 1));
        this->set_key(this->get_size() - 1, current_max);
        this->decrement_heap_size();
        this->max_heapify(0); 
    }
}

int main(){
    int array[] = {1,3,4,5,2,5,6,7,3,5,1,8,9,5,3};
    int size = 15;
    Heap* new_heap = new Heap(array, size);
    new_heap->build_max_heap();
    std::cout<<new_heap->extract_max();
    return 0;
}
