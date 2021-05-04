#ifndef TENEMENT_HOUSE_H
#define TENEMENT_HOUSE_H
#include "house.h"

struct Qelem_2
{
    std::string *resident = nullptr;
    Qelem_2 *next = nullptr;
};


class Tenement_house : public House
{
public:
    Tenement_house()
    {
        name = "House_"+ std::to_string(rand()%30);
        land_holder = "Goverment";
        size = "50x40x15_m";
        cost = 1000000;
        number_apart = 30;
        first = last = new Qelem_2;
        first->resident = new std::string("Mikhailov");
        //*first->resident = "Mikhailov";
        number_people = 1;
    }
    Tenement_house(std::string new_name,std::string new_land_holder,
                   std::string new_size, double new_cost, int new_numb = 30)
    {
        if (!new_name.empty())
            name = new_name;
        else
            name = "House "+ std::to_string(rand()%30);
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
        if (new_numb > 0 && new_numb < 1000)
            number_apart = new_numb;
        else
            number_apart = 30;
        if (!first)
        {
            first = new Qelem_2;
            first->resident = new std::string("Mikhailov");
        }
        //*first->resident = "Mikhailov";
        number_people += 1;
    }

    void del_f()
    {
        if (first)
        {
            Qelem_2 *s = first->next;
            if(first == last)
                last = nullptr;
            delete first;
            first = s;
        }
    }

    void del_all()
    {
        while (first)
            del_f();
    }

    ~Tenement_house()
    {
        del_all();
    }
    std::string get_type() override
    {
        return "Tenement";
    }
    void add_resident(const std::string new_man)
    {
        if(number_people < number_apart)
        {
            last->next = new Qelem_2;
            last = last->next;
            ++number_people;
            if (!new_man.empty())
            {

                last->resident = new std::string(new_man);
            }
            else
                last->resident = new std::string("Mihailov");
        }
    }
    void del_resident(const std::string name)
    {
        if (number_people > 0)
        {
            Qelem_2 *s = first, *up;
            int i = 0;
            while(i < number_people && s)
            {
                if(*s->resident == name)
                {
                    --number_people;
                    if (up)
                        up->next = s->next;

                    else
                        if(s->next)
                        first = s->next;
                    else
                        {
                            up->next = s ->next;
                            last = up;
                        }
                    delete s;
                }
                up = s;
                s = s->next;
                ++i;
            }
        }
    }
    std::string get_resident(int number)
    {
        if (number <= number_people)
        {
            Qelem_2 *s = first;
            for(int i = 0; i + 1 != number; ++i)
                s = s->next;
            return *s->resident;
        }
        else
            return "";
    }
    int get_apart()
    {
        return number_apart;
    }
private:
    int number_apart;
    int number_people;
    Qelem_2 *first, *last;
};

#endif // TENEMENT_HOUSE_H
