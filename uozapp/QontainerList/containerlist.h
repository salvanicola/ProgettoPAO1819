#ifndef CONTAINERLIST_H
#define CONTAINERLIST_H

#include <stdexcept>
//#include "deepptr.h"

template<class T>
class ContainerList
{
    friend class const_iterator;
    friend class iterator;
private:
    class nodo{
    public:
        T info;
        nodo* next;
        nodo* prev;
        nodo();
        nodo(const T&,nodo* =nullptr, nodo* =nullptr);
        ~nodo();
    };
    nodo* first;
    nodo* last;
    static nodo* copy(nodo*);
    static void destroy(nodo*);
public:
    class const_iterator{
        friend class ContainerList;
    private:
        const nodo* p;
    public:
        const_iterator(const nodo* =nullptr);
        bool operator==(const const_iterator&)const;
        bool operator!=(const const_iterator&)const;
        const_iterator& operator++(); //prefisso
        const_iterator operator++(int); //postfisso
        const_iterator& operator--(); //prefisso
        const_iterator operator--(int); //postfisso
        const_iterator operator+(int);
    };
    class iterator{
        friend class ContainerList;
    private:
        nodo* p;
    public:
        iterator(nodo* =nullptr);
        //iterator(const const_iterator& );
        bool operator==(const iterator&);
        bool operator!=(const iterator&);
        iterator& operator++(); //prefisso
        iterator operator++(int); //postfisso
        iterator& operator--(); //prefisso
        iterator operator--(int); //postfisso
        iterator operator+(int);
        nodo* operator*();
    };
    ContainerList();
    ContainerList(const ContainerList&);
    ~ContainerList();
    bool vuota()const;
    void push_back(const T&);
    void pop_back();
    const_iterator search(const T&)const;
    iterator search(const T&);
    iterator remove(const T& );
    const_iterator begin()const;
    iterator begin();
    const_iterator end()const;
    iterator end();
    const_iterator past_the_end()const;
    const T& operator[](const const_iterator&)const;
    T& operator[](const iterator&);
    int size()const;
};
//+++++++++NODO+++++++++++
template <class T>
ContainerList<T>::nodo::nodo(): info(), next(nullptr), prev(nullptr){

}

template<class T>
ContainerList<T>::nodo::nodo(const T& el, nodo* n, nodo* p): info(el), next(n), prev(p){

}

template <class T>
ContainerList<T>::nodo::~nodo(){
    if (next) delete next;
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
    return (p!=(it.p));
}


template <class T>
typename ContainerList<T>::const_iterator& ContainerList<T>::const_iterator::operator++(){
    if (p) p=p->next;
    else {
        p=nullptr;
    }
    return *this;
}

template<class T>
typename ContainerList<T>::const_iterator ContainerList<T>::const_iterator::operator++(int){
    if(p) return p=p->next;
    else {
        throw std::out_of_range("out of bound");
        return nullptr;
    }
}

template <class T>
typename ContainerList<T>::const_iterator& ContainerList<T>::const_iterator::operator--(){
    if (p) p=p->prev;
    return *this;
}

template<class T>
typename ContainerList<T>::const_iterator ContainerList<T>::const_iterator::operator--(int){
    if(p) return p->prev;
    else {
        throw std::out_of_range("out of bound");
        return nullptr;
    }
}

template<class T>
typename ContainerList<T>::const_iterator ContainerList<T>::const_iterator::operator+(int n){
    for(int i=0; i<n; i++){
        if (p) p=p->next;
    }
    return *this;
}

//+++++++++iterator+++++++++++

template<class T>
ContainerList<T>::iterator::iterator(nodo* punt): p(punt){}

/*template<class T>
ContainerList<T>::iterator::iterator(const const_iterator& punt): p(punt){}*/

template<class T>
bool ContainerList<T>::iterator::operator==(const iterator& it){
    return p==it.p;
}
template <class T>
bool ContainerList<T>::iterator::operator!=(const iterator& it){
    return (p!=(it.p));
}


template <class T>
typename ContainerList<T>::iterator& ContainerList<T>::iterator::operator++(){
    if (p) p=p->next;
    else {
        p=nullptr;
    }
    return *this;
}

template<class T>
typename ContainerList<T>::iterator ContainerList<T>::iterator::operator++(int){
    if(p) return p=p->next;
    else {
        throw std::out_of_range("out of bound");
        return nullptr;
    }
}

template <class T>
typename ContainerList<T>::iterator& ContainerList<T>::iterator::operator--(){
    if (p) p=p->prev;
    return *this;
}

template<class T>
typename ContainerList<T>::iterator ContainerList<T>::iterator::operator--(int){
    if(p) return p->prev;
    else {
        throw std::out_of_range("out of bound");
        return nullptr;
    }
}

template<class T>
typename ContainerList<T>::iterator ContainerList<T>::iterator::operator+(int n){
    for(int i=0; i<n; i++){
        if (p) p=p->next;
    }
    return *this;
}

template<class T>
typename ContainerList<T>::nodo* ContainerList<T>::iterator::operator*(){
    return p;
}

//+++++++++CONTAINER+++++++++++
template <class T>
ContainerList<T>::ContainerList(): first(nullptr), last(nullptr){

}

template <class T>
ContainerList<T>::ContainerList(const ContainerList& b): first(copy(b.first)){

}

template <class T>
ContainerList<T>::~ContainerList(){
    if(first)delete first;
}

template <class T>
typename ContainerList<T>::nodo* ContainerList<T>::copy(nodo* p){
    if(!p) return nullptr;
    nodo* first= new nodo();
    first->info=p->info;
    nodo* q=first;
    while (p->next) {
        q->next = new nodo();
        p=p->next;
        q=q->next;
        q->info = p->info;
    }
    q->next=nullptr;
    return first;
}

template <class T>
void ContainerList<T>::destroy(nodo* p){
    if(p){
        destroy(p->next);
        delete p;
    }
}

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
typename ContainerList<T>::iterator ContainerList<T>::begin(){
    return first;//convertitore implicito
}


template <class T>
typename ContainerList<T>::const_iterator ContainerList<T>::end()const{
    return nullptr;
}

template <class T>
typename ContainerList<T>::iterator ContainerList<T>::end(){
    return nullptr;
}

template<class T>
typename ContainerList<T>::const_iterator ContainerList<T>::past_the_end()const{
    return new const_iterator(last);
}

template <class T>
const T& ContainerList<T>::operator[](const ContainerList<T>::const_iterator& it)const{
    if(it.p!=nullptr) return it.p->info;
    else {
        std::out_of_range("not in memory");
        return nullptr;
    }
}

template <class T>
T& ContainerList<T>::operator[](const ContainerList<T>::iterator& it){
    if(it.p!=nullptr) return it.p->info;
    else {
        std::out_of_range("not in memory");
    }
}

template <class T>
typename ContainerList<T>::const_iterator ContainerList<T>::search(const T& el)const{
    auto it=begin();
    for(; it!=end() && it->info!=el ; ++it){

    }
    if(it==nullptr) std::out_of_range("no element found");
    else return it;
}

template <class T>
typename ContainerList<T>::iterator ContainerList<T>::search(const T& el){
    auto it=begin();
    for(; it!=end() && (*it)->info!=el ; ++it){

    }
    if(it==nullptr) std::out_of_range("no element found");
    else return it;
}

template <class T>
typename ContainerList<T>::iterator ContainerList<T>::remove(const T& el){
    ContainerList<T>::iterator it=search(el);
    if(it!=nullptr){
        if((*it)->prev!=nullptr)(*it)->prev->next=(*it)->next;
        else first=(*it)->next;
        if((*it)->next!=nullptr)(*it)->next->prev=(*it)->prev;
        else last=(*it)->prev;
        ContainerList<T>::iterator aux;
        if((*it)->prev!=nullptr)aux=(*it)->prev;
        else aux=(*it)->next;
        (*it)->next=nullptr;//così non distruggo l'intera lista
        (*it)->prev=nullptr;
        delete *it;
        return aux;
    }
    else{
        std::out_of_range("no element found");
        return it;
    }
}

template <class T>
int ContainerList<T>::size()const{
    int i=0;
    for(auto it=begin(); it!=end(); ++it, ++i){}
    /*const nodo* p=first;
    int i=0;
    while(p!=nullptr){
        p=p->next;
        ++i;
    }*/
    return i;
}

template <class T>
bool ContainerList<T>::vuota()const{
    if(first==nullptr) return true;
    else return false;
}

#endif // CONTAINERLIST_H
