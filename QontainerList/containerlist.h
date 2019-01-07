#ifndef CONTAINERLIST_H
#define CONTAINERLIST_H

template<class T>
class ContainerList
{
    friend class iterator;
private:
    class nodo{
    public:
        T info;
        nodo* next;
        nodo();
        nodo(const T&, nodo*);
    };
    nodo* first;
    nodo* last;
public:
    class iterator{
    private:
        ContainerList::nodo* p;
        bool operator==(const iterator&);
        bool operator!=(const iterator&);
        iterator& operator++(); //prefisso
        iterator operator++(int); //postfisso
    };
    ContainerList();
    ContainerList(const T&);
    ContainerList(const ContainerList&);
    bool vuota()const;
    void push_back(const T&);
    void pop_back();
    iterator search(const T)const;
    iterator begin()const;
    iterator end()const;
    T& operator[](const iterator&)const;
    T* extract(const iterator&);
};
//+++++++++NODO+++++++++++
template <class T>
ContainerList<T>::nodo::nodo(): info(0), next(nullptr){}

template<class T>
ContainerList<T>::nodo::nodo(const T& el, nodo* p): info(el), next(p){}

//+++++++++ITERATOR+++++++++++

#endif // CONTAINERLIST_H
