#pragma once
#include<iostream>
#include<vector>

class Node
{
    private:
        std::string tag;
        std::string content;
        std::vector<Node*> children;
        //std::unordered_map<std::string, std::string> attributes;

    public:
        Node(std::string tag, std::string content);
        std::string GetText();
};