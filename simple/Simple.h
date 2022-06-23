//
// Created by elmar on 07/04/2022.
//

#ifndef CPPASSIGNMENT5_SIMPLE_H
#define CPPASSIGNMENT5_SIMPLE_H

#include "../tracker/Tracker.h"

class Simple {
public:
    Simple();

    explicit Simple(double n);

    // this destructor is not needed - it is there to hook a Tracker
    ~Simple();

    static const Tracker &tracker();

    [[nodiscard]] double number() const;

private:
    double m_number;

    static inline Tracker s_tracker{};
};


#endif //CPPASSIGNMENT5_SIMPLE_H
