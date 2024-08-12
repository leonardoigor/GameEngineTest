#include "Models/CreateWindowData.hpp"

CreateWindowData::CreateWindowData()
{
}

CreateWindowData::~CreateWindowData()
{
}

std::string CreateWindowData::ProjectPathFull()
{
    return projectPath + "/" + projectName;
}
