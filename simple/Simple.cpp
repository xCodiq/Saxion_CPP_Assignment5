//
// Created by elmar on 07/04/2022.
//

#include "Simple.h"

Simple::Simple(double n) : m_number{n} {
    s_tracker.add_instance();
    s_tracker.add_memory(sizeof(Simple));
}

Simple::Simple() : Simple{0} {}

Simple::~Simple() {
    s_tracker.remove_instance();
    s_tracker.remove_memory(sizeof(*this));
}

const Tracker &Simple::tracker() {
    return s_tracker;
}

double Simple::number() const {
    return m_number;
}
