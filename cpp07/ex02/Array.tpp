#include"Array.hpp"

template<class T> Array<T>::~Array(void){
   delete[] array;
}

template<class T> Array<T>::Array(void){
    lenght = 0;
    array = NULL;
}

template<class T> Array<T>::Array(unsigned int n){
    lenght = n;
    array = new T[lenght]();
}

template<class T>Array<T>::Array(Array<T> const &arr){
    unsigned int i = 0;

    this->lenght = arr.size();
    this->array = new T[lenght]();
    while(i < this->lenght){
        this->array[i] = arr.array[i];
        i++;
    }
}

template<class T>Array<T> &Array<T>::operator=(Array<T> const &arr){
    unsigned int i = 0;
    if (this == &arr) {
       return *this;
    }
    else{
        delete[] array;
        this->lenght = arr.size();
        this->array = new T[lenght]();
        while(i < this->lenght){
            this->array[i] = arr.array[i];
            i++;
        }
        return *this;
    }
}

template<class T>T &Array<T>::operator[](int n)const{
    unsigned int l;

    l = n;
    if(n < 0 || l >= this->lenght)
        throw std::out_of_range("Index is out of range");
    else
        return this->array[n];
}

// template<class T>const T  &Array<T>::operator[](int n)const{
//     unsigned int l;

//     l = n;
    // if(n < 0 || n > INT_MAX)
//         throw std::out_of_range("Index is out of range");
//     else if ( l >= this->lenght)
//         throw std::out_of_range("Index is out of range");
//     else
//         return this->array[n];
// }

template<class T>unsigned int Array<T>::size(void)const{
    return (this->lenght);
}
