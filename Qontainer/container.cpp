#include "container.h"

//RICORDATI DI SISTEMARE SEMPRE SIZE E FILLING!!

template <class T>
container<T>::container(T* first)
{
    //inizializzo l'array con ampiezza 10
    p=new T[10];
    size=10;
    if(first) {
        p[0]=*first;
        filling=1;
    }
    else filling=0;
}

template <class T>
container<T>::~container(){
    delete p;
}

template <class T>
bool container<T>::isempty()const{
    if(p==nullptr)return true;
    else return false;
}

template <class T>
T* container<T>::copyarr(const int& dim)const{
    T* q=new T[dim];
    for(int i=0; i<filling; ++i){
        q[i]=p[i];
    }
    return q;
}
template <class T>
void container<T>::add(const T& el){
    //if else if... perchè casi esclusivi
    //caso vuoto
    if(isempty()){
        p=new T[10];
        size=10;
        p[0]=el;
        filling=1;
    }
    else
    {
        //caso non ci sia posto
        if(size <= filling+1){
        T* q=copyarr(size*2);
        delete p;
        p=q;
        size=size*2;
        }
        //caso semplice
        p[filling]=el;
        filling++;
    }
}
