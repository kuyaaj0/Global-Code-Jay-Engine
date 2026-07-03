#include "NoteSkinLoader.hpp"

#include "../../External/json.hpp"

#include <fstream>

using json = nlohmann::json;

NoteSkinLoader::NoteSkinLoader()
{

}

bool NoteSkinLoader::Load(
const std::string& jsonFile,
NoteSkinData& data)
{
    std::ifstream file(jsonFile);

    if(!file.is_open())
        return false;

    json root;

    file >> root;

    file.close();

    data.texture = root["texture"];
    data.atlas = root["atlas"];

    data.left = root["left"];
    data.down = root["down"];
    data.up = root["up"];
    data.right = root["right"];

    data.leftPress = root["leftPress"];
    data.downPress = root["downPress"];
    data.upPress = root["upPress"];
    data.rightPress = root["rightPress"];

    data.leftConfirm = root["leftConfirm"];
    data.downConfirm = root["downConfirm"];
    data.upConfirm = root["upConfirm"];
    data.rightConfirm = root["rightConfirm"];

    data.holdLeft = root["holdLeft"];
    data.holdDown = root["holdDown"];
    data.holdUp = root["holdUp"];
    data.holdRight = root["holdRight"];

    data.holdEndLeft = root["holdEndLeft"];
    data.holdEndDown = root["holdEndDown"];
    data.holdEndUp = root["holdEndUp"];
    data.holdEndRight = root["holdEndRight"];

    return true;
}
