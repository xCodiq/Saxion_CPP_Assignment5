//
// Created by elmar on 07/04/2022.
//

#ifndef CPPASSIGNMENT5_TRACKER_H
#define CPPASSIGNMENT5_TRACKER_H

#include <cstdio>

class Tracker {
public:
    Tracker();

    // increments `m_instance_count`
    void add_instance();

    // decrements `m_instance_count`
    void remove_instance();

    // adds memory to `m_memory_count`
    void add_memory(std::size_t memory);

    // subtracts memory
    void remove_memory(std::size_t memory);

    [[nodiscard]] std::size_t memory() const;

    [[nodiscard]] std::size_t instances() const;

private:
    std::size_t m_instance_count;
    std::size_t m_memory_count;
};


#endif //CPPASSIGNMENT5_TRACKER_H
