#pragma once

#include "Interface/IGpioContentReader.hpp"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "driver/gpio.h"

#include <chrono>


using GpioConfig = gpio_config_t;
using GpioPin = gpio_num_t;
using Milliseconds = std::chrono::milliseconds;

class GpioContentReader : public IGpioContentReader
{
public:
    GpioContentReader(GpioConfig gpioConfig, GpioPin gpioPin, Milliseconds const& delay);

    void Execute() override;

private:
    GpioConfig const m_gpioConfig;
    GpioPin const m_gpioPin;
    Milliseconds const& m_delay;
};
