#include"Character.hpp"

void New_Grab(t_trash **grab)
{
    *grab = new t_trash;  
    (*grab)->materia = NULL;  
    (*grab)->next = NULL;
}

Character::Character(std::string name){
    std::cout<< "Character constructor"<< std::endl;
    this->garb = NULL;
    count = 1;
    this->name = name;
    New_Grab(&garb);
    for(int i = 0;i<4;i++){
        inventory[i] = NULL;
    }
}

Character::Character(){
     std::cout<< "Character constructor"<< std::endl;
    this->garb = NULL;
    count = 1;
    this->name = "Anonyme";
    New_Grab(&garb);
    for(int i = 0;i<4;i++){
        inventory[i] = NULL;
    }
}

Character::Character(Character const &chr){
    std::cout<< "Character copy constructor"<<std::endl;
     this->name = chr.name;
    for(int i = 0; i < 4; i++){
        if(chr.inventory[i])
            inventory[i] = chr.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

Character &Character::operator=(Character const &chr){
    if(this != &chr){
        this->name = chr.name;
        for(int i = 0; i < 4; i++){
            delete inventory[i];
            if(chr.inventory[i])
                inventory[i] = chr.inventory[i]->clone();
            else
                inventory[i] = NULL;
    }
    }
    return *this;
}

void    DeleGarb(t_trash **grab)
{
    t_trash *tmp;
    tmp = *grab;
    while(grab && *grab)
    {
        tmp = *grab;
        *grab = (*grab)->next;
        if(tmp->materia)
            delete tmp->materia;
        delete tmp;
    }
}

Character::~Character(){
    DeleGarb(&garb);
    std::cout<< "Character destructor called"<< std::endl;
}

std::string const &Character::getName()const{
    return this->name;
}

void    AddGarb(AMateria *m, t_trash *grab)
{
    t_trash *tmp;

    tmp = grab;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = new t_trash;
    tmp = tmp->next;
    tmp->materia = m;
    tmp->next = NULL;
}

void    Character::equip(AMateria *m){
    if(!m)
    {
        std::cout<< "Oooops this materia doesn't exist"<< std::endl;
        return;
    }
    else if(count > 4){
        std::cout<< "the inventory of materia is full 🚨"<< std::endl;
        return;
    }
    AddGarb(m, garb);
    inventory[count - 1] = m;
    count++;
}

void    Character::unequip(int idx){
    if(idx < 0 || idx >= 4)
        std::cout<< "Ooops the inventory has only 4 slots 0️⃣-3️⃣"<< std::endl;
    else if(!inventory[idx])
        std::cout<< "This materia is empty"<< std::endl;
    else{
        std::cout<< name<< " unequipe "<< inventory[idx]->getType()<< std::endl;
        inventory[idx] = NULL;
    }
}

void    Character::use(int idx, ICharacter& target){
    if(idx < 0 || idx >= 4 || !inventory[idx])
        std::cout<< "Invalid materia"<< std::endl;
    else
        inventory[idx]->use(target);

}
