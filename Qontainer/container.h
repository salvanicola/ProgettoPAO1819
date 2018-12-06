#ifndef CONTAINER_H
#define CONTAINER_H

template <class T>
class container
{
private:
    T* p;//handler dell'array dinamico
    int size;//effettiva ampiezza dell'array in memoria
    int filling;//numero di elementi nel container
    T* copyarr(const int& )const; //crea una copia dellárray interno con nuove dimensioni
public:
    container(T* =nullptr);//
    ~container();//
    container(const container&);
    bool isempty()const;//ritorna se il contenitore è vuoto
    void add(const T&);//
    void addinpos(const T&, int i);
    void search(const T&)const;
    void remove(const T&);
    T operator[](const int&);
};

#endif // CONTAINER_H
