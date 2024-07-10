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
    add_files("07_struct/main.cpp")

target("exercise08")
    set_kind("binary")
    add_files("08_class/main.cpp")

target("exercise09")
    set_kind("binary")
    add_files("09_class_method_const/main.cpp")

target("exercise10")
    set_kind("binary")
    add_files("10_class_drop/main.cpp")

target("exercise11")
    set_kind("binary")
    add_files("11_class_clone/main.cpp")

target("exercise12")
    set_kind("binary")
    add_files("12_class_move/main.cpp")

target("exercise13")
    set_kind("binary")
    add_files("13_std_array/main.cpp")

target("exercise14")
    set_kind("binary")
    add_files("14_std_vector/main.cpp")

target("exercise15")
    set_kind("binary")
    add_files("15_std_deque/main.cpp")

target("exercise16")
    set_kind("binary")
    add_files("16_std_map/main.cpp")

target("exercise17")
    set_kind("binary")
    add_files("17_std_accumulate/main.cpp")

target("exercise18")
    set_kind("binary")
    add_files("18_std_transform/main.cpp")

target("exercise19")
    set_kind("binary")
    add_files("19_std_fs/main.cpp")

target("exercise20")
    set_kind("binary")
    add_files("20_std_thread/main.cpp")

target("exercise21")
    set_kind("binary")
    add_files("21_std_mutex/main.cpp")

target("exercise22")
    set_kind("binary")
    add_files("22_template/main.cpp")
