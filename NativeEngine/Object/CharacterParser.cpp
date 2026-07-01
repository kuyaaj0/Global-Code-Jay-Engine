#include "CharacterParser.hpp"

CharacterParser::CharacterParser()
{

}

bool CharacterParser::Parse(
const std::string& folder,
CharacterData& data)
{
    // JSON parsing will be added later.

    data.cameraOffset =
        Vector3(
            0.0f,
            150.0f,
            0.0f
        );

    return true;
}
