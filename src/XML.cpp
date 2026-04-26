#include"XML.hpp"

XML::XML(std::string path)
{
    Load(path, 0);
}

void XML::Load(std::string path, int posPtr)
{
    std::fstream file(path);
    std::string fileContents = "";

    std::string line;
    
    while(std::getline(file, line))
    {
        fileContents += line + "\n";
    }

    for(int i = posPtr; i < fileContents.size(); i++) // Read the file character by character
    {
        std::string tag = "";
        std::string closingTag = "";
        std::string content = "";

        if(fileContents[i] == '<' && fileContents[i + 1] != '/') //Get the Tag name
        {
            i++;
            while(fileContents[i] != '>') 
            {
                tag += fileContents[i];
                i++;
            }
            i++;
            
            std::cout << tag << "\n";
            
            /*while(fileContents[i] != '<' && fileContents[i + 1] != '/' )
            {
                content += fileContents[i];
                i++;
            }

            //std::cout << content << "\n";
            std::cout << tag << " " << content << "\n"; */
        }

        else if(fileContents[i] == '<' && fileContents[i + 1] == '/') // Get the closing Tag
        {
            i++;
            while(fileContents[i] != '>') 
            {
                closingTag += fileContents[i];
                i++;
            }
            std::cout << closingTag<< "\n";
        }
    }
    
    //std::cout << fileContents + "\n";
    //std::cout << nodes[0].GetText() << " ";

    file.close();
}