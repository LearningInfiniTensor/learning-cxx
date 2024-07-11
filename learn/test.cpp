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
    static const auto exercises = fs::absolute(fs::path(XMAKE) / "exercises");
    auto command = std::string("xmake ") + cmd + " -P " + exercises.string() + ' ' + proj;
    if (log) {
        command += " >> ";
        command += log;
        command += " 2>&1";
    }
    return std::system(command.c_str());
}

static bool test_exercise(std::ostream &os, int n, const char *log) {
    char str[] = "exerciseXX";
    std::sprintf(str, "exercise%02d", n);

    os << "\x1b[34m" << str << " testing" << "\x1b[0m" << std::endl
       << "==================" << std::endl
       << std::endl;
    auto pass = process_run("", str, log) == EXIT_SUCCESS && process_run("run", str, log) == EXIT_SUCCESS;
    os << "=================" << std::endl
       << "\x1b[" << (pass ? 32 : 31) << 'm' << str << (pass ? " passed" : " failed") << "\x1b[0m" << std::endl;
    return pass;
}

bool test_exercise(int n, const char *log) {
    if (log) {
        const auto log_ = fs::absolute(fs::path(XMAKE) / "log" / log);
        const auto log__ = log_.string();
        auto file = std::fstream(log_, std::ios::out | std::ios::app);
        return test_exercise(file, n, log__.c_str());
    } else {
        return test_exercise(std::cout, n, nullptr);
    }
}
