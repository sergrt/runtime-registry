#pragma once

#define DEFINE_REGISTRY_FUNC(Name, Signature) \
    using Name##Func = NamedType<Signature, struct Name##Func##Parameter>; \
    Name##Func Name{#Name}; \
    void GetFunction(Name##Func** function) \
    { \
        *function = &Name; \
    }

// There are some cases when function definition is available at compile time
// So there's no need to specify signature, and registry definition is shorter
#define DEFINE_REGISTRY_FUNC_IMPLICIT(Name) \
    using Name##Func = NamedType<decltype(&::Name), struct Name##Func##Parameter>; \
    Name##Func Name{#Name}; \
    void GetFunction(Name##Func** functionInfo) \
    { \
        *functionInfo = &Name; \
    }
