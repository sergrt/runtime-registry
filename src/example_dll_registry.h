#pragma once

#include "named_type.h"
#include "registry_helpers.h"

#include <string>
#include <utility>

struct ExampleDllRegistry {
    // Specify file, containing functions of this registry
    static constexpr const char* fileName = "example_dll.dll";

    // There are several ways to define the registry, with explicit signature
    // or without it depending on what information is available at compilte time
    // DEFINE_REGISTRY_FUNC(Add, int(__stdcall*)(int, int));
    // #include "some_dll_header.h"
    // DEFINE_REGISTRY_FUNC(Add, decltype(&::Add));
    // DEFINE_REGISTRY_FUNC_IMPLICIT(Add);

    // Some test functions
    DEFINE_REGISTRY_FUNC(Add, int(__stdcall*)(int, int));
    DEFINE_REGISTRY_FUNC(Mult, int(__stdcall*)(int, int));
    DEFINE_REGISTRY_FUNC(Sqrt, int(__stdcall*)(int));
    DEFINE_REGISTRY_FUNC(Print, void(__stdcall*)(const char*));

    // Non-existing function
    DEFINE_REGISTRY_FUNC(Div, int(__stdcall*)(int, int));
};
