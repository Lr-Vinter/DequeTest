#include "Element.h"
#include "List.h"

template <class DataType>
List<DataType>::List ()
{
    Header = nullptr;
    cout << "Constructor for List finish" << endl;
}

template <class DataType> List<DataType>::~List () { }

// Adding element in the beginning

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

// Adding element in the end 

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

// Adding element by key 

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

// Printing list + reverse printing for assertion, that left pointers are OK 

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

// Deleting first element 

template <class DataType>
void List<DataType>::Delete_first()
{
    Header = Header->right_pointer;
    delete Header->left_pointer;
    Header->Set_left_pointer(nullptr);
    Size--;
}

// Deleting last element 

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

// Deleting element by key 

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
    else if(TempElement->right_pointer == nullptr)
        Delete_last();
    else 
    {
        TempElement->left_pointer->Set_right_pointer(TempElement->right_pointer);
        TempElement->right_pointer->Set_left_pointer(TempElement->left_pointer);

        delete TempElement;
    }
    Size--;
}
