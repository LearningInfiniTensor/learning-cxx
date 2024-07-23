#include "test.h"
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
    auto command = std::string("xmake ") + cmd + " -P \"" + exercises.string() + "\" " + proj;
    if (log) {
        command += " >> ";
        command += log;
        command += " 2>&1";
    }
    return std::system(command.c_str());
}

static bool test_exercise(int n, const char *log) {
    std::ofstream file;
    if (log) {
        file.open(log, std::ios::out | std::ios::app);
    }
    std::ostream &os = log ? file : std::cout;

    char str[] = "exerciseXX";
    std::sprintf(str, "exercise%02d", n);

    os << "\x1b[34m" << str << " testing" << "\x1b[0m" << std::endl
       << "==================" << std::endl;
    auto pass = process_run("", str, log) == EXIT_SUCCESS && process_run("run", str, log) == EXIT_SUCCESS;
    os << "=================" << std::endl
       << "\x1b[" << (pass ? 32 : 31) << 'm' << str << (pass ? " passed" : " failed") << "\x1b[0m" << std::endl
       << std::endl;
    return pass;
}

Log &Log::operator<<(unsigned int n) {
    namespace fs = std::filesystem;
    bool pass;
    if (std::holds_alternative<Console>(this->dst)) {
        pass = test_exercise(n, nullptr);
    } else if (std::holds_alternative<Null>(this->dst)) {
#if defined(_WIN32)
        constexpr auto null = "nul";
#elif defined(__linux__) || defined(__unix__) || defined(__MACOSX__) || defined(__APPLE__)
        constexpr auto null = "/dev/null";
#else
#error "Unsupported platform"
#endif
        pass = test_exercise(n, null);
    } else {
        const auto path = fs::absolute(fs::path(XMAKE) / "log" / std::get<fs::path>(this->dst));
        const auto path_string = path.string();
        pass = test_exercise(n, path_string.c_str());
    }
    {
        std::lock_guard lock(this->mutex);
        this->result.push_back(pass);
    }
    return *this;
}
