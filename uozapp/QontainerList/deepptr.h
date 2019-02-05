#ifndef DEEPPTR_H
#define DEEPPTR_H

//+++++può essere istanziato solo su tipi che contengono il campo ref che serve a contare il numero di riferimenti a quell'oggetto+++++

template <class T>
class DeepPtr
{
private:
    T* punt;
public:
    DeepPtr(T* p=nullptr);
    DeepPtr(const DeepPtr& );
    ~DeepPtr();
    DeepPtr<T>&  operator=(const DeepPtr&);
    T& operator*()const;
    T* operator->()const;
    bool operator==(const DeepPtr&)const;
    bool operator!=(const DeepPtr&)const;
    void copy();
};

template <class T>
DeepPtr<T>::DeepPtr(T* p): punt(p){
    if(p){
        ++p->ref;
    }
}

template <class T>
DeepPtr<T>::DeepPtr(const DeepPtr& sp): punt(sp.punt){
    ++punt->ref;
}

template<class T>
DeepPtr<T>::~DeepPtr(){
    if(punt)
    if(punt->ref==0){
         delete punt;
     }
}

template <class T>
DeepPtr<T>& DeepPtr<T>::operator=(const DeepPtr& sp){
    if(this != &sp){
        T* p=punt;
        punt=sp.punt;
        punt->ref++;
        if(p){//se l'oggetto di invocazione puntava già ad altro prima
            p->ref--;
            if(p->ref==0) delete p;
        }
    }
    return *this;
}

template<class T>
T& DeepPtr<T>::operator*()const{
    return *punt;
}

template<class T>
T* DeepPtr<T>::operator->()const{
    return punt;
}

template <class T>
bool DeepPtr<T>::operator==(const DeepPtr& sp)const{
    return punt==sp.punt;
}

template <class T>
bool DeepPtr<T>::operator!=(const DeepPtr& sp)const{
    return punt!=sp.punt;
}

template<class T>
void DeepPtr<T>::copy(){
    T* temp=punt;
    delete punt;
    punt=new T(*temp);//viene invocato il costruttore di copia della struttura dati.
}
#endif // DEEPPTR_H
