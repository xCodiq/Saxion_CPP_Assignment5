//
// Created by elmar on 07/04/2022.
//

#include "DynamicArray.h"

DynamicArray::DynamicArray(std::size_t capacity) :
        m_capacity{capacity ? capacity : DEFAULT_CAP},
        m_size{0},
        m_data{new double[m_capacity]} {
    // Elmar
    s_tracker.add_instance();
    s_tracker.add_memory(capacity);
}

DynamicArray::DynamicArray() : DynamicArray{DEFAULT_CAP} {

}

DynamicArray::~DynamicArray() {
    s_tracker.remove_instance();
    s_tracker.remove_memory(sizeof(double) * m_capacity);
}

const Tracker &DynamicArray::tracker() {
    return s_tracker;
}


double *DynamicArray::get() {
    return m_data.get();
}

const double *DynamicArray::get() const {
    return m_data.get();
}

double &DynamicArray::at(std::size_t index) {
    return m_data[index];
}

const double &DynamicArray::at(std::size_t index) const {
    return m_data[index];
}

std::size_t DynamicArray::size() const {
    return m_size;
}

std::size_t DynamicArray::capacity() const {
    return m_capacity;
}

void DynamicArray::push_n(std::size_t count, double val) {
    reserve(m_size + count);
    std::fill_n(&m_data[m_size], count, val);
    m_size += count;
}

void DynamicArray::push_back(double val) {
    reserve(size() + 1);
    m_data[m_size++] = val;
}

double DynamicArray::pop_back() {
    return m_data[--m_size];
}

double DynamicArray::remove(std::size_t index) {
    auto result{m_data[index]};
    std::move(&m_data[index + 1], &m_data[m_size], &m_data[index]);
    m_size--;
    return result;
}

//DynamicArray DynamicArray::deep_copy() const {
//    DynamicArray copy{m_capacity};
//    std::copy(&m_data[0], &m_data[m_size], &copy.m_data[0]);
//    copy.m_size = m_size;
//    return copy;
//}

void DynamicArray::insert(std::size_t index, double val) {
    reserve(size() + 1);
    std::move(&m_data[index], &m_data[m_size], &m_data[index + 1]);
    m_data[index] = val;
    m_size++;
}

void DynamicArray::reserve(std::size_t min_capacity) {
    auto new_capacity = m_capacity;
    while (new_capacity < min_capacity) {
        new_capacity *= GROWTH_FAC;
    }
    if (new_capacity != m_capacity) {
        auto new_data = std::make_unique<double[]>(new_capacity);
        std::copy(&m_data[0], &m_data[m_size], &new_data[0]);
        m_data.reset(new_data.release());
        m_capacity = new_capacity;

        // Elmar
        s_tracker.add_memory(new_capacity);
    }

}
