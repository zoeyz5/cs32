//PreMadeItem.cpp
#include<iostream>
#include"PreMadeItem.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

PreMadeItem::PreMadeItem(std::string name, std::string size):IceCreamItem(size){
    this->name = name;
    if(size == "small"){
        IceCreamItem::price = 4.00;
    }else if(size == "medium"){
        IceCreamItem::price = 6.00;
    }else if(size == "large"){
        IceCreamItem::price = 7.50;
    }
}

std::string PreMadeItem::composeItem(){
    std::string prestr;
    prestr = "Pre-made Size: "+PreMadeItem::size+"\n";
    prestr += "Pre-made Item: "+PreMadeItem::name+"\n";
    stringstream stream;
    stream << fixed << setprecision(2) << price;
    prestr += "Price: $"+stream.str()+"\n";
    return prestr;
}
