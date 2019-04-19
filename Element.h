#ifndef __ELEMENT_H_
#define __ELEMENT_H_

#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include <string>
#include "assert.h"

using namespace std;

template <class DataType>
class List;

template <class DataType>
class Element
{   
    private:

        DataType info;
        Element* left_pointer;
        Element* right_pointer;

    public:

        void Set_left_pointer (Element* _left_pointer);
        void Set_right_pointer(Element* _right_pointer);

        Element(DataType input_info, Element* _left_pointer, Element* _right_pointer);
        ~Element();

        void Current_Element_print();

        // just for debug
        DataType Get_info(); 
        Element* Get_left_pointer();
        Element* Get_right_pointer();

    friend List<DataType>;

};

#endif __ELEMENT_H_