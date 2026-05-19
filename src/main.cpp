#include<iostream>
#include"XML.hpp"

int main()
{
    XML doc = XML("../example.xml");
    
    std::vector<Node> nodes = doc.GetNodesByName("author");

    for(int i = 0; i < nodes.size(); i++)
    {
        std::cout << nodes[i].GetChildren()[0]->GetText() << "\n"; //rip
    }

    return 0;
}