#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "OrgChart.hpp"
using namespace std;
namespace ariel{
    class OrgChart;
    class Iterator
    {
    protected:
        Node *ptr;
    public:
        Iterator(Node &root);
        Iterator begin();
        Iterator end();
        string operator*();
        Iterator operator++();
        Iterator operator++(int);
        friend bool operator== (const Iterator& a, const Iterator& b);
        friend bool operator!= (const Iterator& a, const Iterator& b);
        ~Iterator();
    };
    
    // Iteraotr::Iteraotr(/* args */)
    // {
    // }
    
    // Iteraotr::~Iteraotr()
    // {
    // }
    
}