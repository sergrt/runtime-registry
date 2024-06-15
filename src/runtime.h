#pragma once

#include <windows.h>

template <typename Registry>
class Runtime {
public:
    Runtime() {
        dllHandle_ = LoadLibraryA(Registry::fileName);

        if (!dllHandle_) {
            throw std::runtime_error("Could not load the dynamic library");
        }
    }

    ~Runtime() {
        FreeLibrary(dllHandle_);
    }

    template <typename T>
    bool AddDependency() {
        T* functionInfo = nullptr;
        registry_.GetFunction(&functionInfo);

        if (functionInfo->IsValid())  // Dependency already has been loaded
            return true;

        FARPROC func_addr = GetProcAddress(dllHandle_, functionInfo->GetName());

        if (!func_addr)  // No such function
            return false;

        functionInfo->Set((decltype(functionInfo->Get()))func_addr);
        return true;
    }

    template <typename... Args>
    bool AddDependencies() {
        bool res = false;
        ((res = AddDependency<Args>()) && ...);
        // Some strict warnings checks trigger here, there's a (more cumbersome) solution:
        // (((res = AddDependency<Args>() == true) && ...);
        return res;
    }

    // Here is an expansion of "->" is used. It works like this:
    // Runtime->someFunction() transforms into:
    // (Runtime.operator->())->someFunction()
    // operator-> returns Registry*, so it will result in (Registry*)->someFunction()
    //
    // cpp standard § 13.5.6:
    // operator-> shall be a non-static member function taking no parameters.
    // It implements the class member access syntax that uses ->.
    // postfix-expression -> template opt id-expression
    // postfix-expression -> pseudo-destructor-name
    // An expression x->m is interpreted as (x.operator->())->m for a class object x of type T
    // if T::operator->() exists and if the operator is selected as the best match function
    // by the overload resolution mechanism (13.3).
    const Registry* const operator->() const {
        return &registry_;
    }

private:
    Registry registry_{};
    HINSTANCE dllHandle_{};
};
