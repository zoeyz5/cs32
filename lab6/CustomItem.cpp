#include "CustomItem.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

CustomItem::CustomItem(std::string size):IceCreamItem(size)
{
	if(size == "small"){
		price = 3.00;
	}
	if(size == "medium"){
		price = 5.00;
	}
	if(size == "large"){
		price = 6.50;
	}
}

CustomItem::~CustomItem(){
}

void CustomItem::addTopping(std::string topping){
	for(size_t i = 0; i<toppings.size(); i++){
		if(toppings[i].first == topping){
			toppings[i].second ++;
            price += 0.4;
            return;
		}
	}
    std::pair<std::string, int> entry;
    entry.first = topping;
    entry.second = 1;
    toppings.push_back(entry);
    price+= 0.4;
}

double CustomItem::getPrice(){
    return price;
}

std::string CustomItem::composeItem(){
    std::pair<std::string,int> temp;
    for(size_t i = 0; i<toppings.size(); i++){
        for(size_t j=i+1; j<toppings.size(); j++){
            if (toppings[i].first>toppings[j].first){
                temp = toppings[i];
                toppings[i] = toppings[j];
                toppings[j] = temp;
            }
        }
    }
	std::string output = "";
	output = "Custom Size: "+ size + "\nToppings:\n";
	for(size_t i = 0; i < toppings.size(); i++){
		output+= toppings[i].first+": "+std::to_string(toppings[i].second)+" oz\n";
	}
    stringstream stream;
    stream << fixed << setprecision(2) << price;
    output += "Price: $" + stream.str() + "\n";
	return output;

}
