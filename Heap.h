#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

class Heap {
    private: int* array;
    private: int heap_size;
    private: int heap_capability; 

    public: Heap(int* array, int size );
    public: ~Heap(); 
    
    public: int get_size();
    public: int get_capability();
    public: int* get_array();

    public: int get_key(int index);
    public: int get_parent_key(int index);
    public: int get_parent_index(int index);
    public: int get_right_child_key(int index);
    public: int get_right_child_index(int index);
    public: int get_left_child_key(int index);
    public: int get_left_child_index(int index);

    public: void decrement_heap_size();
    public: void set_parent_key(int index, int new_key);
    public: void set_left_child_key(int index, int new_key);
    public: void set_right_child_key(int index, int new_key);
    public: void set_key(int index, int new_key);

    public: bool is_leaf(int index);

    public: void insert(int new_key);
    public: void remove(int index);

    public: int extract_max();
    public: int extract_min();

    public: void max_heapify(int error_node);
    public: void build_max_heap();
    public: void heap_sort();
};

#endif 
