//
// Created by elmar on 07/04/2022.
//

#ifndef CPPASSIGNMENT5_DYNAMICARRAY_H
#define CPPASSIGNMENT5_DYNAMICARRAY_H

#include <cstdio>
#include <memory>
#include <algorithm>
#include "../tracker/Tracker.h"

class DynamicArray {
public:
    DynamicArray(std::size_t capacity);

    DynamicArray();

    ~DynamicArray();

    static const Tracker &tracker();

    double *get();

    const double *get() const;

    double &at(std::size_t index);

    const double &at(std::size_t index) const;

    std::size_t size() const;

    std::size_t capacity() const;

    void push_n(std::size_t count, double val);

    void push_back(double val);

    double pop_back();

    void insert(std::size_t index, double val);

    double remove(std::size_t index);

//    DynamicArray deep_copy() const;

private:
    const static std::size_t GROWTH_FAC{2};
    const static std::size_t DEFAULT_CAP{16};

    static inline Tracker s_tracker{};

    std::size_t m_capacity;
    std::size_t m_size;

    std::unique_ptr<double[]> m_data;

    void reserve(std::size_t min_capacity);
};


#endif //CPPASSIGNMENT5_DYNAMICARRAY_H
