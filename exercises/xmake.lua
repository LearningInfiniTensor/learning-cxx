add_rules("mode.debug", "mode.release")
set_encodings("utf-8")
set_warnings("all")
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

target("exercise18")
    add_files("18_function_template/main.cpp")

target("exercise19")
    add_files("19_runtime_datatype/main.cpp")

target("exercise20")
    add_files("20_class_template/main.cpp")

target("exercise21")
    add_files("21_template_const/main.cpp")

target("exercise22")
    add_files("22_std_array/main.cpp")

target("exercise23")
    add_files("23_std_vector/main.cpp")

target("exercise24")
    add_files("24_std_vector_bool/main.cpp")

target("exercise25")
    add_files("25_strides/main.cpp")

target("exercise26")
    add_files("26_std_string/main.cpp")

target("exercise27")
    add_files("27_std_map/main.cpp")

target("exercise28")
    add_files("28_std_transform/main.cpp")

target("exercise29")
    add_files("29_std_accumulate/main.cpp")

-- TODO: deque; forward_list; fs; thread; mutex;
