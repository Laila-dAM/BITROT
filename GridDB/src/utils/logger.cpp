#include "logger.h"
#include "constants.h"
#include <iostream>
#include <ctime>

Logger::Logger()
{
    file.open(Constants::LOG_FILE_NAME, std::ios::app);
}

Logger::~Logger()
{
    if (file.is_open())
        file.close();
}

Logger& Logger::instance()
{
    static Logger logger;
    return logger;
}

std::string Logger::levelToString(LogLevel level)
{
    switch (level)
    {
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::WARNING:
            return "WARNING";
        case LogLevel::ERROR:
            return "ERROR";
    }
    return "UNKNOWN";
}

void Logger::log(LogLevel level, const std::string& message)
{
    std::lock_guard<std::mutex> lock(mutex);

    std::time_t now = std::time(nullptr);
    std::tm* tm = std::localtime(&now);

    char buffer[64];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm);

    std::string line = std::string(buffer) + " [" + levelToString(level) + "] " + message;

    std::cout << line << std::endl;

    if (file.is_open())
        file << line << std::endl;
}

void Logger::info(const std::string& message)
{
    log(LogLevel::INFO, message);
}

void Logger::warning(const std::string& message)
{
    log(LogLevel::WARNING, message);
}

void Logger::error(const std::string& message)
{
    log(LogLevel::ERROR, message);
}