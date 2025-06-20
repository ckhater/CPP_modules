#include"Intern.hpp"

int main(){
    Intern frr;
    AForm *form1;
    AForm *form2;
    AForm *form3;

    form1 = frr.makeForm("robotomy request","bender");
    form2 = frr.makeForm("presidential request","bender");
    form3 = frr.makeForm("shrubbery creation","bender");
    delete form1;
    delete form2;
    delete form3;
    return 0;
}
