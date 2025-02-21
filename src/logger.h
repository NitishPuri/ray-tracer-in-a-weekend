#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <iomanip>

class Logger
{
public:
    Logger(const std::string &log_file_path) : log_file_path(log_file_path)
    {
        log_file.open(log_file_path, std::ios_base::app); // Open in append mode
        if (!log_file.is_open())
        {
            std::cerr << "Unable to open log file: " << log_file_path << std::endl;
        }
    }

    ~Logger()
    {
        if (log_file.is_open())
        {
            log_file.close();
        }
    }

    template <typename... Args>
    void log(Args... args)
    {
        std::ostringstream oss;
        oss << get_current_timestamp() << ": ";
        (oss << ... << args); // Fold expression to handle variadic arguments

        std::string timestamped_message = oss.str();
        // Log to console
        std::cout << timestamped_message << std::endl;

        // Log to file
        if (log_file.is_open())
        {
            log_file << timestamped_message << std::endl;
        }
    }

private:
    std::string log_file_path;
    std::ofstream log_file;

    std::string get_current_timestamp()
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

        std::ostringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d-%H-%M-%S") << '-' << std::setfill('0') << std::setw(3) << ms.count();
        return ss.str();
    }
};

#endif // LOGGER_H