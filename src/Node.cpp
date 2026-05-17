#include"Node.hpp"


Node::Node(std::string tag)
{
    this->tag = tag;
}

Node::Node(std::string tag, std::vector<Node*> children)
{
    this->tag = tag;
    this->children = children;
}

Node::Node(std::string tag, std::string content)
{
    this->tag = tag;
    this->content = content;
}

std::string Node::GetText()
{
    return content;
}

std::string Node::GetTagName()
{
    return tag;
}

std::string Node::AddChild(Node* node)
{
    children.push_back(node);
    return "abc";
}
