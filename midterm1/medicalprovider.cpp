#include "medicalprovider.h"
#include <vector>
#include <iostream>

Doctor::Doctor() {}

Doctor::Doctor(std::string n, std::string s)
    : MedicalProvider("Doctor", n, (s == "General Practitioner") ? 100 : 150),specialty(s) {}

bool Doctor::doSurgery() { return true; }


Nurse::Nurse() {}

Nurse::Nurse(std::string n, std::string g)
    : MedicalProvider("Nurse", n, 90), grade(g) {}

std::string Nurse::getGrade() { return grade; }

bool Nurse::doSurgery() {
    return getGrade() == "Nurse Practitioner";
}

std::vector<MedicalProvider*> filterSurgery(std::vector<MedicalProvider*> list){
    std::vector<MedicalProvider*> out;
    for(auto i : list){
        if(i->doSurgery()){out.push_back(i);}
    }
    return out;
}

int main() {
    MedicalProvider* d0 = new Doctor("Todd","Family medicine");
    MedicalProvider* d1 = new Doctor("Micheal","Pulmonologists");
    MedicalProvider* d2 = new Doctor("Rick","General Practitioner");

    MedicalProvider* n0 = new Nurse("Paul","Registered Nurse");
    MedicalProvider* n1 = new Nurse("Ricky","Nurse Practitioner");

    std::vector<MedicalProvider*> l;

    l.push_back(d0);
    l.push_back(d1);
    l.push_back(d2);
    l.push_back(n0);
    l.push_back(n1);

    std::vector<MedicalProvider*> l1=filterSurgery(l);

    for(int i=0; i< l1.size();i++){
        std::cout<< l1[i]->getname() << " ";
    }
    
    std::cout<< "\n";

    for(auto p:l){delete p;}

    return 0;
}