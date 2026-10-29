class Dwelling{
private:
    std::size_t bedrooms;
    std::size_t bathrooms;
public:
    Dwelling()
    {
    bedrooms=0;
    bathrooms=0;
    }
    Dwelling(std::size_t bed, std::size_t bath)
    {
    bedrooms=bed;
    bathrooms=bath;
    }
    virtual double value() const // the value function should be virtual because house also have value function and we want the function of house have it own value
    {
    return 200+50*bedrooms+20*bathrooms;
    //estimated value in thousands
    }

    bool operator<(const Dwelling& d2) const{ // pass in pointer, so it will work with child varibale (house)
        return (value()<d2.value()) ? true:false;
    }
};

class House: public Dwelling{ // inheritance from dwelling
private:
    std::size_t size_of_yards;
public:
    House() : Dwelling(), size_of_yards(0){} // call parent constructor, and initialize it value

    House(std::size_t bed, std::size_t bath, std::size_t yards) : Dwelling(bed,bath), size_of_yards(yards){}

    double value() const override{
        double v1 = Dwelling::value(); // dewelling version of value
        double v2 = 0.1*size_of_yards;

        return v1+v2;
    }

};
