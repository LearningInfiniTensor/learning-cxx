add_rules("mode.debug", "mode.release")
set_encodings("utf-8")

target("learn")
    set_kind("binary")

    add_defines(string.format("__XMAKE__=\"%s\"", os.scriptdir():gsub("\\", "/")))

    set_languages("cxx17")
    add_files("learn/main.cpp")
