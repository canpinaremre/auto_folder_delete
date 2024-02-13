#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <thread>
#include <filesystem>

void parseConfig(const std::string& filename, std::string& date, std::string& time, std::string& path) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        if (line.find("Date:") != std::string::npos)
            date = line.substr(line.find(":") + 2);
        else if (line.find("Time:") != std::string::npos)
            time = line.substr(line.find(":") + 2);
        else if (line.find("Path:") != std::string::npos)
            path = line.substr(line.find(":") + 2);
    }
}

void writeInputFile(const std::tm& tm, const std::string& path, const std::string& errorMessage = "") {
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M", &tm);
    std::ofstream file("input.txt");
    file << (errorMessage.empty() ? "Folder " + path + " will be deleted at " + buffer : errorMessage) << std::endl;
}

int main() {
    std::string date, time, path;
    parseConfig("folder_config.txt", date, time, path);

    // Check if date and path are empty
    if (date.empty()) {
        writeInputFile({}, path, "Not valid date");
        return 1;
    }
    if (path.empty()) {
        writeInputFile({}, path, "Not valid path");
        return 1;
    }

    // Validate path existence
    if (!std::filesystem::exists(path)) {
        writeInputFile({}, path, "Not valid path");
        return 1;
    }

    std::tm tm = {};
    std::istringstream ss_date(date + " " + time);
    ss_date >> std::get_time(&tm, "%d.%m.%Y %H:%M");

    // Check if date is valid
    if (ss_date.fail()) {
        writeInputFile({}, path, "Not valid date");
        return 1;
    }

    writeInputFile(tm, path);

    std::chrono::system_clock::time_point now, target;
    target = std::chrono::system_clock::from_time_t(std::mktime(&tm));

    while (true) {
        now = std::chrono::system_clock::now();
        if (now >= target) {
            std::filesystem::remove_all(path);
            break;
        }
        std::this_thread::sleep_for(std::chrono::minutes(5));
    }

    return 0;
}
