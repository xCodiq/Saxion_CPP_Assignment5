//
// Created by elmar on 07/04/2022.
//

#include "Tracker.h"

Tracker::Tracker() {

}

void Tracker::add_instance() {
    this->m_instance_count++;
}

void Tracker::remove_instance() {
    this->m_instance_count--;
}

void Tracker::add_memory(std::size_t memory) {
    this->m_memory_count += memory;
}

void Tracker::remove_memory(std::size_t memory) {
    this->m_memory_count -= memory;
}

std::size_t Tracker::memory() const {
    return this->m_memory_count;
}

std::size_t Tracker::instances() const {
    return this->m_instance_count;
}
