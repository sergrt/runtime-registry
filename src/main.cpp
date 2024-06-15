#include "example_dll_registry.h"
#include "runtime.h"

#include <cassert>
#include <iostream>

int main() {
     Runtime<ExampleDllRegistry> exampleDllRuntime;

    // Valid dependencies
    if (exampleDllRuntime.AddDependencies<
        ExampleDllRegistry::AddFunc,
        ExampleDllRegistry::MultFunc,
        ExampleDllRegistry::SqrtFunc,
        ExampleDllRegistry::PrintFunc
    >()) {
        auto add_result = exampleDllRuntime->Add(1, 2);
        auto mult_result = exampleDllRuntime->Mult(3, 4);
        auto sqrt_result = exampleDllRuntime->Sqrt(9);

        const std::string message = std::string("Operation results:") + "\n"
            + "    " + "add_result = " + std::to_string(add_result) + "\n"
            + "    " + "mult_result = " + std::to_string(mult_result) + "\n"
            + "    " + "sqrt_result = " + std::to_string(sqrt_result) + "\n";
        exampleDllRuntime->Print(message.c_str());
    } else {
        throw std::runtime_error("Could not find dependencies");
    }

    if (exampleDllRuntime.AddDependency<ExampleDllRegistry::DivFunc>()) {
        assert(false);
    } else {
        std::cout << "Dependency not found" << std::endl;
    }

    return EXIT_SUCCESS;
}
