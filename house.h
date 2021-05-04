#ifndef HOUSE_H
#define HOUSE_H
#include <string>


class House
{
public:

    virtual ~House()
    {
    }

    std::string get_name() const
    {
        return name;
    }
    std::string get_land_holder() const
    {
        return land_holder;
    }
    std:: string get_size() const
    {
        return size;
    }
    double get_cost() const
    {
        return cost;
    }
    void change_name(std::string new_name)
    {
        if (!new_name.empty())
            name = new_name;
    }
    void change_size(std::string new_size)
    {
        if (!new_size.empty())
            size = new_size;
    }
    void change_land_holder(std::string new_land_holder)
    {
        if (!new_land_holder.empty())
            size = new_land_holder;
    }
    void change_cost(double new_cost)
    {
        if (new_cost > 0)
            cost = new_cost;
    }
    virtual  std::string get_type() = 0;
protected:
    std::string name;
    std::string land_holder;
    std::string size;
    double cost;

};

#endif // HOUSE_H
