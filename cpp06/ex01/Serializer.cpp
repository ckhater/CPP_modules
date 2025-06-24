#include "Serializer.hpp"

Serializer::~Serializer(void){}

Serializer &Serializer::operator=(Serializer const &sr)
{
    (void)sr;
    return *this;
}

uintptr_t   Serializer::serialize(Data *ptr)
{
    uintptr_t raw;

    raw = reinterpret_cast<uintptr_t>(ptr);
    return raw;
}

Data *Serializer::deserialize(uintptr_t raw){
    Data *d;

    d = reinterpret_cast<Data *>(raw);
    return d;
}