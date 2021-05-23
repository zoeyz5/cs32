// PreMadeItem.h
#ifndef PREMADEITEM_H
#define PREMADEITEM_H
#include<vector>
#include "IceCreamItem.h"
class PreMadeItem : public IceCreamItem
{
public:
    PreMadeItem(std::string name, std::string size);
    virtual ~PreMadeItem(){}
    double getPrice(){return price;}
    std::string composeItem();
protected :
std::string name;
};
#endif
