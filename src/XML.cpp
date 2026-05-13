#include"XML.hpp"

struct Pair
{
    int index;
    std::string tag;
};

XML::XML(std::string path)
{
    Load(path, 0);
}

void XML::Load(std::string path, int posPtr)
{
    std::fstream file(path);
    std::string fileContents = "";

    std::string line;

    std::stack<Pair> lookingForPair;

    while(std::getline(file, line))
    {
        fileContents += line + "\n";
    }

    for(int i = posPtr; i < fileContents.size(); i++) // Read the file character by character
    {
        std::string tag = "";
        std::string closingTag = "";
        std::string content = "";

        int contentStartIndex;
        int contentEndIndex;

        if(fileContents[i] == '<' && fileContents[i + 1] != '/') //Get the Tag name
        {
            i++;
            while(fileContents[i] != '>') 
            {
                tag += fileContents[i];
                i++;
            }
            i++;
            
            contentStartIndex = i;   
    
            Pair p = {contentStartIndex, tag};
            lookingForPair.push(p);

            std::cout << "Opening tag: " << tag << "\n";
            //std::cout << "Pushed tag: " << lookingForPair.top().tag << "\n";   
        }

        else if(fileContents[i] == '<' && fileContents[i + 1] == '/') // Get the closing Tag
        {
            contentEndIndex = i;
            i+=2;
            while(fileContents[i] != '>') 
            {
                closingTag += fileContents[i];
                i++;
            }

            if(lookingForPair.top().tag == closingTag)
            {
                for(int c = lookingForPair.top().index; c < contentEndIndex; c++)
                {
                    content += fileContents[c];
                }

                lookingForPair.pop();

                std::cout << "Content: " << content << "\n";
            }

            std::cout << "Closing tag: " << closingTag<< "\n";   
        }
    }
    
    //std::cout << fileContents + "\n";
    //std::cout << nodes[0].GetText() << " ";

    file.close();
}