#include <iostream>
#include <string>
#include <set>


class MedicalProvider{
private:
    std::string title;
    std::string name;
    double visitFee;
    std::set<std::string> procedures;
public:
    MedicalProvider(){}
    MedicalProvider(std::string t, std::string n, double vf){
        title =t;
        name = n;
        visitFee=vf;
    }
    double getFee(){return visitFee;}
    virtual bool doSurgery(){return false;}
    void addProcedure(std::string p){ procedures.insert(p);}
    bool doProcedure(std::string p){ return procedures.find(p) != procedures.end();}

    std::string getname(){return name;}
};


class Doctor: public MedicalProvider{
public:
    Doctor();
    
    Doctor(std::string n, std::string s);

    bool doSurgery();

private:
    std::string specialty;
};

class Nurse: public MedicalProvider{
public:
    Nurse();

    Nurse(std::string n, std::string g);

    std::string getGrade();

    bool doSurgery();
private:
    std::string grade;
};




