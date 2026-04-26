#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"Node.hpp"

class XML
{
    private:
    std::vector<Node> nodes;

    public:
        XML(std::string path);
        void Load(std::string path, int posPtr);

        std::vector<Node> GetNodesByName(std::string name);
        //std::vector<std::string> GetAttributesByName(std::string name);
        XML GetChildByName(std::string name);
};











