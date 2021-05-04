#ifndef PRIVATE_HOUSE_H
#define PRIVATE_HOUSE_H
#include <iostream>
#include "house.h"


class Private_house: public House
{
public:
    Private_house()
    {
        name = "House_"+ std::to_string(rand()%30);
        land_holder = "Goverment";
        size = "50x40x15_m";
        cost = 1000000;
        householder = "Ivanov";
    }

    ~Private_house()
    {
    }
    Private_house(std::string new_name,std::string new_land_holder,
                  std::string new_size, double new_cost,
                  std::string new_householder = "Ivanov")
    {
        if (!new_name.empty())
            name = new_name;
        else
            name = "House_"+ std::to_string(rand()%30);
        if (!new_land_holder.empty())
            land_holder = new_land_holder;
        else
            land_holder = "Goverment";
        if (!new_size.empty())
            size = new_size;
        else
            size = "50x40x15_m";
        if (new_cost > 0)
            cost = new_cost;
        else
            cost = 1000000;
        if (!new_householder.empty())
            householder = new_householder;
        else
            householder = "Ivanov";
    }
    std::string get_type() override
    {
        return "Private";
    }
    std::string get_house_holder() const
    {
        return householder;
    }
    void change_holder(const std::string new_holder)
    {
        if (!new_holder.empty())
            householder = new_holder;
    }
private:
    std::string householder;
};

#endif // PRIVATE_HOUSE_H
