#pragma once

#include <memory>


class IGpioContentReader
{
public:
    virtual void Execute() = 0;
};

using IGpioContentReaderPtr = std::unique_ptr<IGpioContentReader>;
