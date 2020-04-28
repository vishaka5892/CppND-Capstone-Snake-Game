#ifndef PLATFORM_H
#define PLATFORM_H

#include "SDL.h"
#include <iostream>
#include <string>


class Platform 
{
public:
	Platform() : platform(std::string())
    {
    	platform = getPlatform();
    }
    
    /*
     User's system platfrom is set to the private variable platform.
     The platform used is returned as a string.
     */
    std::string getPlatform();
    void displayPlatform();

private:
    std::string platform;
};

std::string Platform::getPlatform()
{
    const char* sysPlatf = SDL_GetPlatform();
    std::string pl(sysPlatf);
    platform = pl;
    return platform;
};

void Platform::displayPlatform()
{
    if (platform != " ")
        std::cout << "System platform detected: " << platform << std::endl;
    else
        std::cout << "Error: System platform is not detected." << std::endl;
}

#endif