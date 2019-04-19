#include "Element.h"

template <class DataType>
Element<DataType>::Element(DataType input_info, Element* _left_pointer, Element* _right_pointer)
{
    info = input_info;
    Set_left_pointer (_left_pointer);
    Set_right_pointer(_right_pointer);
    cout << "Constructor for Element finish" << endl;
}

template <class DataType>
Element<DataType>::~Element() { }

template <class DataType>
void Element<DataType>::Set_left_pointer(Element* _left_pointer)
{
    left_pointer = _left_pointer;
}

template <class DataType>
void Element<DataType>::Set_right_pointer(Element* _right_pointer)
{
    right_pointer = _right_pointer;
}


template <class DataType>
void Element<DataType>::Current_Element_print()
{
    cout << "This is info :" << info << endl;
    cout << "This is right ptr" << right_pointer << endl;
    cout << "This is left  ptr" <<  left_pointer << endl;
    cout << "-----------------" << endl;
}

template <class DataType> 
DataType Element<DataType>::Get_info()
{
    return info;
}

template <class DataType>
Element<DataType>* Element<DataType>::Get_left_pointer()
{
    return left_pointer;
}

template <class DataType>
Element<DataType>* Element<DataType>::Get_right_pointer()
{
    return right_pointer;
}