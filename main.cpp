#include "Element.cpp" // Вот, это, конечно, ПИЗДЕЦ, понимание того, как работает компоновщик...
// g++ -std=c++11 Element.cpp List.cpp main.cpp -o deq.out

#include "List.cpp"

int main ()
{
    List<int> mylist;
    
    mylist.Push_back(3);
    
    mylist.Push_back(5);
    mylist.Push_back(11);
    mylist.Push_front(9);
    mylist.Push_back(12);
    mylist.Element_add(2, 999, 1);
    mylist.Element_add(2, 888, 0);
    mylist.Element_add(1, 555, 0);
    mylist.Element_add(8, 666, 1);
    
    mylist.Delete_by_key(9);
    mylist.Print_list();
    
    cout << "end==============================";

    List <string> CharList;

    CharList.Push_back("c");
    CharList.Push_back("mudak");
    
    CharList.Print_list();
    
    return 0;      
}
