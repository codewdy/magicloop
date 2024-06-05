#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")
test = SConscript("test/SConstruct")

def RGlob(root_path, pattern):
    result_nodes = []
    paths = [root_path]
    while paths:
        path = paths.pop()
        all_nodes = Glob(f'{path}/*')
        paths.extend(entry for entry in all_nodes
                     if entry.isdir() or (entry.srcnode() and entry.srcnode().isdir()))
        result_nodes.extend(Glob(f'{path}/{pattern}'))
    return sorted(result_nodes)

env.Append(CPPPATH=["src/"])
env.Append(CXXFLAGS=["-std=c++20"])
sources = RGlob("src", "*.cpp")

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "magicloop/bin/libmagicloop.{}.{}.framework/libgdexample.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "magicloop/bin/libmagicloop{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
