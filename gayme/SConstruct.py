#!/usr/bin/env python
import os
import sys

# Uses godot-cpp's SConstruct to setup the environment
env = SConscript("godot-cpp/SConstruct")

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
# Gets your source file and appends it to the environment
env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")

# Create theDLL / shared library
if env["platform"] == "macos":
    library = env.SharedLibrary(
        "demoproject/bin/HelloWorld.{}.{}.framework/helloWorld.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "demoproject/bin/HelloWorld{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

#Builds out library

Default(library)