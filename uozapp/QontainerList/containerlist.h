#ifndef CONTAINERLIST_H
#define CONTAINERLIST_H

#include <stdexcept>
//#include "deepptr.h"

template<class T>
class ContainerList
{
    friend class const_iterator;
private:
    class nodo{
    public:
        T info;
        nodo* next;
        nodo* prev;
        nodo();
        nodo(const T&,nodo* =nullptr, nodo* =nullptr);
    };
    nodo* first;
    nodo* last;
public:
    class const_iterator{
        friend class ContainerList;
    private:
        nodo* p;
    public:
        const_iterator(const nodo* =0);
        bool operator==(const const_iterator&)const;
        bool operator!=(const const_iterator&)const;
        const_iterator& operator++(); //prefisso
        const_iterator operator++(int); //postfisso
        const_iterator& operator--(); //prefisso
        const_iterator operator--(int); //postfisso
    };
    ContainerList();
    ContainerList(const ContainerList&);
    bool vuota()const;
    void push_back(const T&);
    void pop_back();
    const_iterator search(const T&)const;
    const_iterator begin()const;
    const_iterator end()const;
    const_iterator past_the_end()const;
    T& operator[](const const_iterator&)const;
};
//+++++++++NODO+++++++++++
template <class T>
ContainerList<T>::nodo::nodo(): info(0), next(nullptr), prev(nullptr){

}

template<class T>
ContainerList<T>::nodo::nodo(const T& el, nodo* n, nodo* p): info(el), next(n), prev(p){

}

//+++++++++const_iterator+++++++++++
template<class T>
ContainerList<T>::const_iterator::const_iterator(const nodo* punt): p(punt){}

template<class T>
bool ContainerList<T>::const_iterator::operator==(const const_iterator& it)const{
    return p==it.p;
}
template <class T>
bool ContainerList<T>::const_iterator::operator!=(const const_iterator& it)const{
    return p=!it.p;
}

template <class T>
typename ContainerList<T>::const_iterator& ContainerList<T>::const_iterator::operator++(){
    if (p) p=p->next;
    return *this;
}

template<class T>
typename ContainerList<T>::const_iterator ContainerList<T>::const_iterator::operator++(int){
    if(p) return p->next;
    else throw std::out_of_range("out of bound");
}

template <class T>
typename ContainerList<T>::const_iterator& ContainerList<T>::const_iterator::operator--(){
    if (p) p=p->prev;
    return *this;
}

template<class T>
typename ContainerList<T>::const_iterator ContainerList<T>::const_iterator::operator--(int){
    if(p) return p->prev;
    else throw std::out_of_range("out of bound");
}

//+++++++++CONTAINER+++++++++++
template <class T>
ContainerList<T>::ContainerList(): first(nullptr), last(nullptr){}

template<class T>
void ContainerList<T>::push_back(const T& el){
    if(first==nullptr){
        first=new nodo(el);
        last=first;
    }
    else{
        last->next=new nodo(el, nullptr, last);
        last=last->next;
    }
}

template<class T>
void ContainerList<T>::pop_back(){
    if(first==nullptr){
        std::out_of_range("nothing to delete");
    }
    else{
        last=last->prev;
        delete last->next;
    }
}

template <class T>
typename ContainerList<T>::const_iterator ContainerList<T>::begin()const{
    return first;//convertitore implicito
}

template <class T>
typename ContainerList<T>::const_iterator ContainerList<T>::end()const{
    return nullptr;
}

template<class T>
typename ContainerList<T>::const_iterator ContainerList<T>::past_the_end()const{
    return new const_iterator(last);
}

template <class T>
T& ContainerList<T>::operator[](const ContainerList<T>::const_iterator& it)const{
    if(it!=nullptr) return it.p->info;
    else std::out_of_range("not in memory");
}

template <class T>
typename ContainerList<T>::const_iterator ContainerList<T>::search(const T& el)const{
    auto it=begin();
    for(; it!=end() && it->info==el ; ++it){

    }
    if(it==nullptr) std::out_of_range("no element found");
    else return it;
}
#endif // CONTAINERLIST_H
