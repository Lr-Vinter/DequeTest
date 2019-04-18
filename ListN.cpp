#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include <string>
#include "assert.h"

using namespace std;

// добавление в конец списка
// добавление в начало списка
// добавление в список по указанному индексу
// удаление последнего элемента
// удаление первого элемента
// удаление элемента по указанному индексу 
//----------------------------------------------------------

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

//----------------------------------------------------------

template <class DataType>
class List 
{    
    private:

        Element<DataType>* Header;
        int Size;

    public:

        void Push_back(DataType data);
        void Push_front(DataType data);
        void Element_add(int key, DataType data, bool side);

        void Delete_first();
        void Delete_last();
        void Delete_by_key(int key);

        List();
        ~List();

        void Print_list();
};


template <class DataType>
List<DataType>::List ()
{
    Header = nullptr;
    cout << "Constructor for List finish" << endl;
}

template <class DataType> List<DataType>::~List () { }

// Добавление в начало

template <class DataType>
void List<DataType>::Push_back(DataType data)
{
    if(Header == nullptr)
    {
        Header = new Element<DataType>(data, nullptr, nullptr);
    }
    else
    {
        Element<DataType>* Created = new Element<DataType>(data, nullptr, Header);
        Header->Set_left_pointer(Created);
        Header = Created;
    }
    Size++;
}

// Добавление в конец
template <class DataType>
void List<DataType>::Push_front(DataType data)
{
    if(Header == nullptr)
    {
        Header = new Element<DataType>(data, nullptr, nullptr);
    }
    else
    {
        Element<DataType>* TempElement = Header;
        while(1)
        {
            if(TempElement->right_pointer == nullptr)
                break;
            TempElement = TempElement->right_pointer;
        }
        Element<DataType>* Created = new Element<DataType>(data, TempElement, nullptr);
        TempElement->Set_right_pointer(Created);
    }
    Size++;
}

// Добавление в проивзольное место

enum { LEFT, RIGHT };

template <class DataType>
void List<DataType>::Element_add(int key, DataType data, bool side)
{
    Element<DataType>* Created = new Element<DataType>(data, nullptr, nullptr);
    Element<DataType>* TempElement = Header;

    for(int i = 0; i < key - 1; i++)
    {
        assert(TempElement->Get_right_pointer() != nullptr);
        TempElement = TempElement->right_pointer;
    }
    
    switch (side)
    {
        case LEFT:
            if(TempElement->left_pointer == nullptr)
                Push_back(data);
            else
            {
                TempElement->left_pointer->Set_right_pointer(Created);
                Created->Set_left_pointer(TempElement->left_pointer);

                Created->Set_right_pointer(TempElement);
                TempElement->Set_left_pointer(Created);
            }
            break;

        case RIGHT:
            if(TempElement->right_pointer == nullptr)
                Push_front(data);
            else
            {
                TempElement->right_pointer->Set_left_pointer(Created);
                Created->Set_right_pointer(TempElement->right_pointer);

                Created->Set_left_pointer(TempElement);
                TempElement->Set_right_pointer(Created);
            }
            break;
        default:
            assert(0);
            break;
    }
}

// Печать списка
template <class DataType>
void List<DataType>::Print_list() // работает только если лист не пустой (очевидно)
{
    Element<DataType>* Current_element = Header;
    Element<DataType>* Last_element;
    while(1)
    {
        cout << "This is currrent element data " << Current_element->Get_info() << endl;
        if(Current_element->right_pointer == nullptr)
            {
                Last_element = Current_element;
                break;
            }
        Current_element = Current_element->right_pointer;
    }
    cout << "End of list printing" << endl;
    while(1)
    {
        cout << "This is current element data " << Last_element->Get_info() << endl;
        if(Last_element->left_pointer == nullptr)
            break;
        Last_element = Last_element->left_pointer;
    }
}

// удаление первого элемента

template <class DataType>
void List<DataType>::Delete_first()
{
    Header = Header->right_pointer;
    delete Header->left_pointer;
    Header->Set_left_pointer(nullptr);
    Size--;
}

// удаление последнего элемента

template <class DataType>
void List<DataType>::Delete_last()
{
    Element<DataType>* TempElement = Header;
    while(1)
    {
        if(TempElement->right_pointer == nullptr)
            break;
        TempElement = TempElement->right_pointer;
    }
    TempElement->left_pointer->Set_right_pointer(nullptr);
    delete TempElement;
    Size--;
}

// удаление по ключу

template <class DataType>
void List<DataType>::Delete_by_key(int key)
{
    Element<DataType>* TempElement = Header;
    for(int i = 0; i < key - 1; i++)
    {
        assert(TempElement->Get_right_pointer() != nullptr);
        TempElement = TempElement->right_pointer;
    }
    
    if(TempElement->left_pointer == nullptr)
        Delete_first();
    if(TempElement->right_pointer == nullptr)
        Delete_last();

    TempElement->left_pointer->Set_right_pointer(TempElement->right_pointer);
    TempElement->right_pointer->Set_left_pointer(TempElement->left_pointer);

    delete TempElement;
    Size--;
}

int main ()
{
    List <int> mylist;

    mylist.Push_back(3);
    mylist.Push_back(5);
    mylist.Push_back(11);
    mylist.Push_front(9);
    mylist.Push_back(12);
    mylist.Element_add(2, 999, 1);
    mylist.Element_add(2, 888, 0);
    mylist.Element_add(1, 555, 0);
    mylist.Element_add(8, 666, 1);
    
    mylist.Delete_by_key(1);
    mylist.Print_list();
    
    cout << "end==============================";

    /*
    List <string> CharList;

    CharList.Push_back("c");
    CharList.Push_back("mudak");

    CharList.Print_list();
    */

    return 0;      
}

//-----------------------------------
