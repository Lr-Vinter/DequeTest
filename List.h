//#ifndef __LIST_H_
//#define __LIST_H_

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

//#endif __LIST_H_