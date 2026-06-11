#pragma once

#include <string>

class LuaAPI
{

public:

    bool LoadScript(

        const std::string& path

    );

    void Call(

        const std::string& function

    );

    void SetGlobal(

        const std::string& name,

        double value

    );

    double GetGlobal(

        const std::string& name

    );

};
