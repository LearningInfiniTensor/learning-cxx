add_rules("mode.debug", "mode.release")
set_encodings("utf-8")

target("exercise00")
    set_kind("binary")
    add_files("exercises/00_hello_world/main.cpp")

target("exercise01")
    set_kind("binary")
    add_files("exercises/01_variable&add/main.cpp")

target("exercise02")
    set_kind("binary")
    add_files("exercises/02_function/main.cpp")

target("exercise03")
    set_kind("binary")
    add_files("exercises/03_argument&parameter/main.cpp")

target("exercise04")
    set_kind("binary")
    add_files("exercises/04_static/main.cpp")

target("exercise05")
    set_kind("binary")
    add_files("exercises/05_constexpr/main.cpp")

target("exercise06")
    set_kind("binary")
    add_files("exercises/06_loop/main.cpp")

target("exercise07")
    set_kind("binary")
    add_files("exercises/07_struct/main.cpp")

target("exercise08")
    set_kind("binary")
    add_files("exercises/08_class/main.cpp")
