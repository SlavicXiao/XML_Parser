#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"Node.hpp"
#include<stack>
#include<unordered_map>

class XML
{
    private:
    //std::vector<Node> nodes;
    std::unordered_map<std::string, std::vector<Node>> nodes;

    public:
        XML(std::string path);
        void Load(std::string path, int posPtr);

        std::vector<Node> GetNodesByName(std::string name);
        XML GetChildByName(std::string name);
        void PrintChildren(Node node);
};

