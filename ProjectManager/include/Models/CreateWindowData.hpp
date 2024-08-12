#pragma once
#include "iostream"

class CreateWindowData
{
private:
    /* data */
public:
    CreateWindowData(/* args */);
    ~CreateWindowData();

    std::string projectName;
    std::string projectPath;
    std::string ProjectPathFull();
};
