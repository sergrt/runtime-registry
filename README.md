# runtime-registry
Runtime dependencies registry

## Description
This project is an approach of maintaining runtime dependencies for Windows. It's lightweight, simple, extensible and extremely easy to use.
## Scenarios
- An application may require several functions from several dlls, and, depending on what set of functions is available, perform one way or another.
- Application can be compiled with the Vista+ toolchain, and then run with the XP environment (I know how it sounds, but I have worked at such environment several times). This causes runtime errors because XP's system dll files do not contain functions that were available at compile time, and the application simply won't start. This runtime registry can introduce a level of abstraction to check for necessary functions at runtime.
## Features
Goals in mind while designing this software:
  - Add and maintain dependencies as easy as possible: one-line function definition, in one place
  - Allow functions registry to operate at any level of abstraction: application, component, class.
  - Allow to check for any number of dependencies at runtime with delayed initialization

Examples are available at main.cpp
