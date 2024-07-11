add_rules("mode.debug", "mode.release")
set_encodings("utf-8")
set_warnings("all", "error")
set_kind("binary")
set_languages("cxx17")

target("exercise00")
    add_files("00_hello_world/main.cpp")

target("exercise01")
    add_files("01_variable&add/main.cpp")

target("exercise02")
    add_files("02_function/main.cpp")

target("exercise03")
    add_files("03_argument&parameter/main.cpp")

target("exercise04")
    add_files("04_static/main.cpp")

target("exercise05")
    add_files("05_constexpr/main.cpp")

target("exercise06")
    add_files("06_loop/main.cpp")

target("exercise07")
    add_files("07_enum&union/main.cpp")

target("exercise08")
    add_files("08_trivial/main.cpp")

target("exercise09")
    add_files("09_method/main.cpp")

target("exercise10")
    add_files("10_method_const/main.cpp")

target("exercise11")
    add_files("11_class/main.cpp")

target("exercise12")
    add_files("12_class_destruct/main.cpp")

target("exercise13")
    add_files("13_class_clone/main.cpp")

target("exercise14")
    add_files("14_class_move/main.cpp")

target("exercise15")
    add_files("15_class_derive/main.cpp")

target("exercise16")
    add_files("16_class_virtual/main.cpp")

target("exercise17")
    add_files("17_class_virtual_destruct/main.cpp")

-- TODO: template; array; vector; deque; map; transform; accumulate; fs; thread; mutex;
