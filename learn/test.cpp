#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>

#ifndef __XMAKE__
#define __XMAKE__ "XMAKE is not defined"
#endif

namespace fs = std::filesystem;
constexpr static auto XMAKE = __XMAKE__;

static int process_run(const char *cmd, const char *proj, const char *log) {
    static auto exercises = fs::absolute(fs::path(XMAKE) / "exercises");
    auto command = std::string("xmake ") + cmd + " -P " + exercises.string() + ' ' + proj;
    if (log) {
        command += " >> ";
        command += log;
        command += " 2>&1";
    }
    return std::system(command.c_str());
}

bool test_exercise(int n, const char *log) {
    char str[] = "exerciseXX";
    std::sprintf(str, "exercise%02d", n);

    if (log) {
        static auto log_ = fs::absolute(fs::path(XMAKE) / "log" / log);
        std::fstream(log_, std::ios::out | std::ios::app)
            << "Testing " << str << std::endl
            << std::endl;
        auto log__ = log_.string();
        auto log___ = log__.c_str();
        return process_run("", str, log___) == EXIT_SUCCESS && process_run("run", str, log___) == EXIT_SUCCESS;
    }

    std::cout << "Testing " << str << std::endl
              << std::endl;
    return process_run("", str, nullptr) == EXIT_SUCCESS && process_run("run", str, nullptr) == EXIT_SUCCESS;
}
