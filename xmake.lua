add_rules("mode.debug", "mode.release")

target("00_hello_world")
    set_kind("binary")
    add_files("exercises/00_hello_world/main.cpp")
