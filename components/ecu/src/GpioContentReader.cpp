#include "ECU/GpioContentReader.h"


GpioContentReader::GpioContentReader(GpioConfig gpioConfig, GpioPin gpioPin, Milliseconds const& delay) :
    m_gpioConfig(gpioConfig), m_gpioPin(gpioPin), m_delay(delay)
{
}

void GpioContentReader::Execute()
{
    gpio_config(&m_gpioConfig);

    while (1) {
        int const gpio_state = gpio_get_level(m_gpioPin);

        printf("GPIO Pin %d is currently %s\n", m_gpioPin, gpio_state ? "HIGH" : "LOW");

        vTaskDelay(pdMS_TO_TICKS(m_delay.count()));
    }
}
