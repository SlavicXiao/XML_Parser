#include"Node.hpp"

Node::Node(std::string tag, std::string content)
{
    this->tag = tag;
    this->content = content;
}

std::string Node::GetText()
{
    return content;
}