#include "OrgChart.hpp"
using namespace std;

namespace ariel
{
    OrgChart::OrgChart(/* args */)
    {
    }

    OrgChart::~OrgChart()
    {
    }
    OrgChart &OrgChart::add_root(string name)
    {
        this->root.name = name;
        return *this;
    }
    OrgChart &OrgChart::add_sub(string father, string son)
    {
        find_sub(this->root, father, son);
        return *this;
    }
    bool OrgChart::find_sub(Node &node, string father, string son)
    {
        int b = node.name.compare(father);
        if (!b)
        {
            Node temp;
            temp.name = son;
            node.sones.push_back(temp);
            return true;
        }
        else
        {
            for (size_t i = 0; i < node.sones.size(); i++)
            {
                if (find_sub(node.sones[i], father, son))
                {
                    return true;
                }
            }
        }
        return false;
    }

    void OrgChart::fill_q_for_level_order(Node &node)
    {
        for (size_t i = 0; i < node.sones.size(); i++)
        {
            this->q_level_order.push_back(node.sones.at(i).name);
        }
        for (size_t i = 0; i < node.sones.size(); i++)
        {
            fill_q_for_level_order(node.sones[i]);
        }
    }
    void OrgChart::fill_q_for_reverse_order(Node &node)
    {
        for (int i = node.sones.size() - 1; i >= 0; i--)
        {
            this->q_reverse_order.push_front(node.sones.at((size_t)i).name);
        }

        for (int i = node.sones.size() - 1; i >= 0; i--)
        {
            fill_q_for_reverse_order(node.sones[(size_t)i]);
        }
    }

    deque<string>::iterator OrgChart::begin_level_order()
    {
        this->q_level_order.clear();
        this->q_level_order.push_front(this->root.name);
        fill_q_for_level_order(root);
        return q_level_order.begin();
    }
    deque<string>::iterator OrgChart::end_level_order()
    {
        return q_level_order.end();
    }
    deque<string>::iterator OrgChart::begin_reverse_order()
    {
        this->q_reverse_order.clear();
        this->q_reverse_order.shrink_to_fit();
        this->q_reverse_order.push_front(this->root.name);
        fill_q_for_reverse_order(root);
        return q_reverse_order.begin();
    }
    deque<string>::iterator OrgChart::reverse_order()
    {
        return q_reverse_order.end();
    }

}