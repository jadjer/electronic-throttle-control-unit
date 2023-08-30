#include "Common/Exception.hpp"

namespace Common
{

Exception::Exception(std::string const& message, ErrorCode::Enum const code) : m_errorMessage(message), m_errorCode(code) {}

const char* Exception::what() const noexcept
{
    return m_errorMessage.c_str();
}

ErrorCode::Enum Exception::code() const noexcept
{
    return m_errorCode;
}

std::string const& Exception::message() const noexcept
{
    return m_errorMessage;
}

} // namespace Common