#ifndef CONTAINERLIST_H
#define CONTAINERLIST_H
#include "deepptr.h"

//Debugging tool
#include <iostream>
using std::cout;
using std::endl;

template<class T>
class ContainerList
{
    friend class iterator;
private:
    class nodo{
    public:
        T info;
        DeepPtr<nodo> next;
        //nodo* prev;
        unsigned int ref;
        nodo();
        nodo(const T&, const DeepPtr<nodo>& =nullptr/*, nodo* =nullptr*/);
        nodo(const nodo&);
    };
    DeepPtr<nodo> first;//l'utilizzo della classe DeepPtr ha sul contratto l'utilizzo di un campo ref nel tipo a cui è istanziato (nodo rispetta il vincolo)
    //devo implementare un metodo di copia profonda da chiamare ogni volta che viene fatta una madifica al contenitore
public:
    class iterator{
        friend class ContainerList;
    private:
        DeepPtr<nodo> p;//dato che gli iteratori hanno come unico scopo quello di scorrere la lista e non possiedono degli oggetti, non ha senso utilizzare uno smartpointer
    public:
        iterator(const DeepPtr<nodo>& =0);
        bool operator==(const iterator&)const;
        bool operator!=(const iterator&)const;
        iterator& operator++(); //prefisso
        iterator operator++(int); //postfisso
    };
    ContainerList();
    ContainerList(const ContainerList&);
    bool vuota()const;
    void push_back(const T&);
    void pop_back();
    iterator search(const T)const;
    iterator begin()const;
    iterator end()const;
    T& operator[](const iterator&)const;
    T* extract(const iterator&);

    //debug
    void printref(){
        cout << nodo::ref << endl;
    }
};
//+++++++++NODO+++++++++++
template <class T>
ContainerList<T>::nodo::nodo(): info(0), next(nullptr) /*, prev(nullptr)*/{
    cout << "sono il costruttore di nodo" << endl;
}

template<class T>
ContainerList<T>::nodo::nodo(const T& el, const DeepPtr<nodo>& n /*, nodo* p*/): info(el), next(n) /*, prev(p)*/{
    cout << "sono il costruttore a due param di nodo" << endl;
}

template <class T>
ContainerList<T>::nodo::nodo(const nodo& n){
    cout << "sono il costruttore di copia di nodo" << endl;
    info=n.info;
    ref=1;
    if(next!=nullptr)next(DeepPtr<nodo>::copy(n.next));
}

//+++++++++ITERATOR+++++++++++
template<class T>
ContainerList<T>::iterator::iterator(const DeepPtr<nodo>& punt): p(punt){}

template<class T>
bool ContainerList<T>::iterator::operator==(const iterator& it)const{
    return p==it.p;
}
template <class T>
bool ContainerList<T>::iterator::operator!=(const iterator& it)const{
    return p=!it.p;
}

template <class T>
typename ContainerList<T>::iterator& ContainerList<T>::iterator::operator++(){
    if (p) p=p->next;
    return *this;
}

template<class T>
typename ContainerList<T>::iterator ContainerList<T>::iterator::operator++(int){
    return p->next;
}

//+++++++++CONTAINER+++++++++++
template <class T>
ContainerList<T>::ContainerList(): first(nullptr){}

template<class T>
void ContainerList<T>::push_back(const T& el){
    if(first==nullptr){
        first=new nodo(el);
    }
    else{
        iterator it=begin();
        while(it.p->next!=nullptr) it++;
        it.p->next=new nodo(el, nullptr);//qua chiama assegnazione di deeptr
    }
}

template <class T>
typename ContainerList<T>::iterator ContainerList<T>::begin()const{
    iterator aux;
    aux.p=first;//qui chiama = per il tipo nodo quindi non viene modificato il campo ref di first
    return aux;
}

template <class T>
typename ContainerList<T>::iterator ContainerList<T>::end()const{
    iterator aux;
    aux.p=nullptr;//il puntatore a null è la fine del container
    return aux;
}

template <class T>
T& ContainerList<T>::operator[](const ContainerList<T>::iterator& it)const{
    cout << it.p->ref;
    return it.p->info;
}
#endif // CONTAINERLIST_H
