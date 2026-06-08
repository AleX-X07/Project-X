#pragma once

class Reader {
public:
    virtual ~Reader();
    virtual void read() = 0;
};
