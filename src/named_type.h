#pragma once

#include <utility>

template <typename T, typename Parameter>
class NamedType {
public:
    NamedType(const char* name) : name_(name) {}
    T& Get() {
        return value_;
    }
    T const& Get() const {
        return value_;
    }

    void Set(T value) {
        value_ = value;
    }
    bool IsValid() const {
        return value_ != nullptr;
    }

    template <typename... Args>
    auto operator()(Args... args) const {
        return value_(args...);
        // Using std::forward requires strict types match, no implicit conversions
        // return std::forward<T>(value_)(args...);
    }

    const char* GetName() const {
        return name_;
    }

private:
    T value_{};
    const char* name_{};
};
