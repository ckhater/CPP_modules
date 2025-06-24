#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include<iostream>
#include<stdint.h>

typedef struct t_data{
   std::string  name;
   int          i;
   void         *p;
   bool         ft; 
}Data;


class Serializer{
    private:
        Serializer(void);
        ~Serializer(void);
        Serializer(Serializer const &sr);
        Serializer &operator=(Serializer const &sr);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif