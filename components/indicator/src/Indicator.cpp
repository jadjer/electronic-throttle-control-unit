// Copyright 2022 Pavel Suprunov
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "indicator/Indicator.hpp"

#include "driver/gpio.h"

namespace indicator
{

constexpr uint8_t lowLevel = 0;
constexpr uint8_t highLevel = 1;

Indicator::Indicator(int pinNum) : m_enableFlag(true), m_pinNum(pinNum), m_taskValue(0)
{

    gpio_config_t buttonConfig = {
        .pin_bit_mask = (1ull << m_pinNum),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_ENABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&buttonConfig);
}

Indicator::~Indicator()
{
    m_enableFlag = false;
    if (m_thread.joinable())
    {
        m_thread.join();
    }
}

void Indicator::enable()
{
    m_enableFlag = false;
    if (m_thread.joinable())
    {
        m_thread.join();
    }

    gpio_set_level(static_cast<gpio_num_t>(m_pinNum), highLevel);
}

void Indicator::disable()
{
    m_enableFlag = false;
    if (m_thread.joinable())
    {
        m_thread.join();
    }

    gpio_set_level(static_cast<gpio_num_t>(m_pinNum), lowLevel);
}

void Indicator::blink(int value)
{
    m_taskValue = value;

    if (m_enableFlag)
    {
        return;
    }

    m_enableFlag = true;
    m_thread = std::thread(&Indicator::blinkTask, this);
}

void Indicator::process() {}

} // namespace indicator
