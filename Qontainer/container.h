#ifndef CONTAINER_H
#define CONTAINER_H

//exception
#include <exception>
#include <stdexcept>

class noequalstype{};
class noelementfound{};
class emptyvector{};
//exception

//test
#include <iostream>
//test

template <class T>
class container
{
private:
    T* p;//handler dell'array dinamico
    int size;//effettiva ampiezza dell'array in memoria
    int filling;//numero di elementi nel container
    T* copyarr(const int& )const; //crea una copia dell'array interno con nuove dimensioni
    static T* copia(T* );
public:
    //test
    void stmp(){std::cout << p[0] << p[1] << p[2] << p[3];}
    //test
    container(int =10);//
    ~container();//
    container(const container&)throw (emptyvector);
    bool isempty()const;//ritorna se il contenitore è vuoto
    void add(const T&);//
    T& addinpos(const T&, const int& )throw(std::out_of_range);//
    void sort();//MergeSort
    int search(const T&)const throw(noequalstype, noelementfound);//T deve possedere il confronto ==
    int remove(const T&)throw(noequalstype, noelementfound);//remove the first element found with this value, return the pos
    T removeinpos(const int&)throw(std::out_of_range);//remove the element in pos i and shift all the element
    T& operator[](const int&)const throw(std::out_of_range);//
    T& at(const int&)const throw(std::out_of_range);//
};

//RICORDATI DI SISTEMARE SEMPRE SIZE E FILLING!!


template <class T>
container<T>::container(int s): p(new T[s] ()), size(s), filling(0)
{
    //inizializzo l'array con ampiezza 10 se non specificato
}

template <class T>
container<T>::~container(){
    delete p;
}

template <class T>
container<T>::container(const container & c)throw (emptyvector){
    if(c.p==NULL)throw emptyvector();
    else{

    }
}

template <class T>
bool container<T>::isempty()const{
    if(p==NULL)return true;
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

template <class T>
void Merge(T* A, int p, int q, int r){
    int n1=q-p+1;
    int n2=r-q;
    T L[n1];
    T R[n2];
    for(int i=0; i<n1; ++i) L[i]=A[p+i];
    for(int i=0; i<n2; ++i) R[i]=A[q+i+1];
    int i=0;
    int j=0;
    int k=p;
    while(i<n1 && j<n2){
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[], if there are any
    while (i < n1){
        A[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[], if there are any
    while (j < n2){
        A[k] = R[j];
        j++;
        k++;
    }
}

template <class T>
void sortrec(T* A, int p, int r){
    if(p<r){
        int q=(p+r)/2;
        sortrec(A,p,q);
        sortrec(A,q+1,r);
        Merge(A, p, q, r);
    }
}

template <class T>
void container<T>::sort(){
    sortrec(p, 0, filling-1);
}

template <class T>
int container<T>::search(const T& obj)const throw(noequalstype, noelementfound){
    for(int i=0; i<filling; ++i){
        try{
            if(p[i]==obj) return i;
        }
        catch(...){
            throw noequalstype();
        }
    }
    throw noelementfound();
}

template <class T>
T& container<T>::operator[](const int& i)const throw(std::out_of_range){
    if(i>=filling) throw std::out_of_range("position outside the bounds");//utilizza out_of_range::what() per visualizzare il messaggio
    else return p[i];
}

template <class T>
T& container<T>::at(const int& i)const throw(std::out_of_range){
    return (*this)[i];//utilizza operator[] quindi può lanciare eccezioni
}

template <class T>
T& container<T>::addinpos(const T& el, const int& i)throw(std::out_of_range){
    //caso non ci sia posto
    if(size<i){
        throw(std::out_of_range("position out of bound, please increase size of array if you want force this insert"));
    }
    else{//caso semplice
        T& sob=p[i];
        p[i]=el;
        return sob;
    }
}

template<class T>
T container<T>::removeinpos(const int& i)throw(std::out_of_range){
    if(i>=filling) throw(std::out_of_range("can't remove if there's no element"));
    else{
        T aux=p[i];
        for(int j=i; j<filling; ++j){
            p[j]=p[j+1];
        }
        filling--;
        return aux;
    }
}

template <class T>
int container<T>::remove(const T& el)throw(noequalstype, noelementfound){
    int i=search(el);
    removeinpos(i);
    return i;
}

#endif // CONTAINER_H
