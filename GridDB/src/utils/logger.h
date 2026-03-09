#pragma once
#include <string>
#include <fstream>
#include <mutex>

enum class LogLevel
{
    INFO,
    WARNING,
    ERROR
};

class Logger
{
private:
    std::ofstream file;
    std::mutex mutex;

    Logger();
    ~Logger();

    std::string levelToString(LogLevel level);

public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& instance();

    void log(LogLevel level, const std::string& message);

    void info(const std::string& message);
    void warning(const std::string& message);
    void error(const std::string& message);
};