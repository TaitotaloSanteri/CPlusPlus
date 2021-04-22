#pragma once
#define ASETASUOMENKIELI std::setlocale(0, "fi-FI")

#ifdef _DEBUG
#define LOG(message) std::cout << message << std::endl
#else
#define LOG(message) 
#endif

#ifdef _WIN64
#define SHOWOS std::cout << "K�yt�t 64-bittist� windowsia" << std::endl
#elif _WIN32
#define SHOWOS std::cout << "K�yt�t 32-bittist� windowsia" << std::endl
#elif __APPLE__
#define SHOWOS std::cout << "K�yt�t Applen tietokonetta" << std::endl
#endif

