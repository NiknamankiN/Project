#ifndef LIVING_ARRAY_H
#define LIVING_ARRAY_H
#include "house.h"
#include "fstream"
#include "tenement_house.h"
#include "private_house.h"
#include "Iterator.h"
#include <iostream>

class Living_array
{
public:
    Living_array(std::string new_city = "Moscow")
    {
        if (!new_city.empty())
            city = new_city;
        else
            city = "Moscow";
        first = last = nullptr;
        numb = 0;
    }
    void sort_by_cost(bool flag)
    {
        if (numb > 1)
        {
        Qelem *s = first->next, *u = first, *u2;
        bool f = false;
        while(!f)
        {
            s = first->next;
            u = first;
            f = true;
        while (s)
        {
            if (((u->object->get_cost() > s->object->get_cost()) && flag) ||
                    (!flag && (u->object->get_cost() < s->object->get_cost())))
            {
                if (u == first)
                {
                    first = s;
                    u->next = s->next;
                    s->next = u;
                    u = s;
                    s = s->next;
                }

                else
                {
                    u2->next = s;
                    u->next = s->next;
                    s->next = u;
                    s = u;
                    u = u2->next;
                }
                f = false;
            }
            s = s->next;
            u2 = u;
            if (numb > 2)
                u = u->next;
        }
        }
    }
        while(last->next)
            last = last->next;
    }
    Iterator begin() const
    {
        Iterator f(first);
        return f;
    }
    void build_house(Private_house &new_house)
    {
        if (last)
        {    last->next = new Qelem;
            last = last->next;
        }
        else
            first = last = new Qelem;
        last->object = dynamic_cast<House*>(&new_house);
        last->next = nullptr;
        ++numb;
    }
    void build_house(Tenement_house &new_house)
    {
        if (last)
        {
            last->next = new Qelem;
            last = last->next;
        }
        else
        {
            first = last = new Qelem;
        }
        last->object = dynamic_cast<House*>(&new_house);
        last->next = nullptr;
        ++numb;
    }
    void destroy_house(std::string name_house)
    {

        Qelem *u1 = nullptr, *s = first;
        while(name_house != s->object->get_name())
        {
            u1 = s;
            s = s->next;
        }
        if (u1)
            u1->next = s->next;

        else
            if(s->next)
            first = s->next;
        else
            {
                u1 = s ->next;
                last = u1;
            }
        delete s;
        --numb;
    }
    void write_to_file(const std::string path) const
    {
        std::ofstream in(path);
        if (in.is_open())
        {
            in<<city<<std::endl;
            Qelem *s = first;
            while(s)
            {


                    in<<" "<<s->object->get_name()<<" "<<
                        s->object->get_type()<<" "<<s->object->get_size()
                     <<" "<<s->object->get_cost()<<" "<<
                        s->object->get_land_holder()<<std::endl;
                    s = s->next;


            }
            in.close();
        }
    }
    void read_file(const std::string path)
    {
        del_all();
        numb = 0;
        std::ifstream in(path);
        if (in.is_open())
        {
            in>>city;
            first = last = nullptr;
            while(!in.eof())
            {

                    std::string na,ty,si,hol,gg;
                    double z;
                    in>>na;
                    in>>ty>>si>>z>>hol;
                    std::cout<<na<<ty<<si<<z<<hol<<gg;
                    ++numb;
                    if(last)
                    {
                        last->next = new Qelem;
                        last = last->next;
                    }
                    else
                        first = last = new Qelem;
                    if (ty == "Private")
                        last->object = dynamic_cast<House*>(new Private_house(
                                                                na, hol,si,z));
                    else
                        last->object = dynamic_cast<House*>(new
                                                            Tenement_house
                                                            (na, hol, si, z));


            }
            in.close();
            last->next = nullptr;
        }
    }
    void search_writef_by_cost(double &min_cost, double &max_cost,
                               std::string path) const
    {
        std::ofstream in(path);
        if (in.is_open())
        {
            in<<city<<std::endl;
            Qelem *s = first;
            while(s)
            {
                if (s->object->get_cost() >= min_cost &&
                        s->object->get_cost() <= max_cost)
                in<<std::endl<<s->object->get_name()<<std::endl<<
                    s->object->get_type()<<std::endl<<s->object->get_size()<<
                    std::endl<<s->object->get_cost()<<std::endl<<
                    s->object->get_land_holder()<<std::endl;
                s = s->next;
            }
            in.close();
        }
    }
    void del_f()
    {
        if (first)
        {
            Qelem *s = first->next;
            if(first == last)
                last = nullptr;
            delete first;
            --numb;
            first = s;
        }
    }
    void del_all()
    {
        while (first)
            del_f();
    }
    int get_num() const
    {
        return numb;
    }

private:
    int numb;
    Qelem *first = nullptr;
    Qelem *last = nullptr;
    std::string city;

};

#endif // LIVING_ARRAY_H
