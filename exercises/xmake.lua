add_rules("mode.debug", "mode.release")
set_encodings("utf-8")

target("exercise00")
    set_kind("binary")
    add_files("00_hello_world/main.cpp")

target("exercise01")
    set_kind("binary")
    add_files("01_variable&add/main.cpp")

target("exercise02")
    set_kind("binary")
    add_files("02_function/main.cpp")

target("exercise03")
    set_kind("binary")
    add_files("03_argument&parameter/main.cpp")

target("exercise04")
    set_kind("binary")
    add_files("04_static/main.cpp")

target("exercise05")
    set_kind("binary")
    add_files("05_constexpr/main.cpp")

target("exercise06")
    set_kind("binary")
    add_files("06_loop/main.cpp")

target("exercise07")
    set_kind("binary")
    add_files("07_enum&union/main.cpp")

target("exercise08")
    set_kind("binary")
    add_files("08_trivial/main.cpp")

target("exercise09")
    set_kind("binary")
    add_files("09_method/main.cpp")

target("exercise10")
    set_kind("binary")
    add_files("10_method_const/main.cpp")

target("exercise11")
    set_kind("binary")
    add_files("11_class/main.cpp")

target("exercise12")
    set_kind("binary")
    add_files("12_class_deconstruct/main.cpp")

target("exercise13")
    set_kind("binary")
    add_files("13_class_clone/main.cpp")

target("exercise14")
    set_kind("binary")
    add_files("14_class_move/main.cpp")
