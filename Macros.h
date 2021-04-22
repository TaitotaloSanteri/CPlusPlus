#pragma once
#define ASETASUOMENKIELI std::setlocale(0, "fi-FI")

#ifdef _DEBUG
#define LOG(message) std::cout << message << std::endl
#else
#define LOG(message) 
#endif

#ifdef _WIN64
#define SHOWOS std::cout << "Käytät 64-bittistä windowsia" << std::endl
#elif _WIN32
#define SHOWOS std::cout << "Käytät 32-bittistä windowsia" << std::endl
#elif __APPLE__
#define SHOWOS std::cout << "Käytät Applen tietokonetta" << std::endl
#endif

