#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
using namespace std;

namespace ariel
{
    class Iterator;
    struct Node
    {
        string name;
        vector<Node> sones;
    };

    class OrgChart
    {
    private:
        Node root;
        bool find_sub(Node &node, string father, string son);
        void fill_q_for_level_order(Node &node);
        void fill_q_for_reverse_order(Node &node);
        void fill_q_for_preorder(Node &node);
        deque<string> q_level_order;
        deque<string> q_reverse_order;
        deque<string> q_preorder;

    public:
        OrgChart();
        OrgChart &add_root(string name);
        OrgChart &add_sub(string father, string son);

        friend ostream &operator<<(ostream &out, const OrgChart &root);
        deque<string>::iterator begin_level_order();
        deque<string>::iterator end_level_order();
        deque<string>::iterator begin_reverse_order();
        deque<string>::iterator reverse_order();
        deque<string>::iterator begin_preorder();
        deque<string>::iterator end_preorder();

        ~OrgChart();
    };
    
}
