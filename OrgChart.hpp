#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Iterator.hpp"
using namespace std;

namespace ariel
{
    class Iterator;
    struct Node
    {
        string name;
        vector<Node*> sones;
    };
    
    class OrgChart
    {
    
    private:
        Node root;
    public:
        OrgChart(/* args */);
        OrgChart &add_root(string name);
        OrgChart &add_sub(string father, string son);
        friend ostream &operator<<(ostream &out, const OrgChart &root);
        Iterator begin_level_order();
        Iterator end_level_order();
        Iterator begin_reverse_order();
        Iterator end_reverse_order();
        Iterator begin_preorder();
        Iterator end_preorder();

        ~OrgChart();
    };
}

// OrgChart::OrgChart(/* args */)
// {
// }

// OrgChart::~OrgChart()
// {
// }
