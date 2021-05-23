#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include <string>
#include <vector>
#include <iostream>
#include "IceCreamItem.h"

class CustomItem : public IceCreamItem
{
public:
	CustomItem(std::string size);
	virtual ~CustomItem();
	void addTopping(std::string topping);
	virtual double getPrice();
	std::string composeItem();

protected:
    std::vector<std::pair<std::string,int> > toppings;
};

#endif
