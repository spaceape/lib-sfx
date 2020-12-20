/**
    Copyright (c) 2020, wicked systems

    Redistribution and use in source and binary forms, with or without modification, are
    permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright notice, this list of
    conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, this list
    of conditions and the following disclaimer in the documentation and/or other materials
    provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
    MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
    THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
    OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
    TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/
#include "dc.h"

__namespace_sonar
__namespace_sfx

      std::uint16_t  dc::s_charset_sx;
      std::uint16_t  dc::s_charset_sy;
      std::uint8_t*  dc::s_charset_ptr;
      std::uint32_t* dc::s_palette;
      dc*            dc::s_dc;

      dc::dc() noexcept
{
}

      dc::dc(const dc&) noexcept
{
}

      dc::dc(dc&&) noexcept
{
}

      dc::~dc()
{
}

bool  dc::sdc_make_cbo(char*& data, std::uint8_t format, std::uint16_t sx, std::uint16_t sy, std::size_t& size) noexcept
{
      return s_dc->sdc_make_cbo(data, format, sx, sy, size);
}

bool  dc::sdc_free_cbo(char*& data, std::uint8_t format, std::uint16_t sx, std::uint16_t sy, std::size_t& size) noexcept
{
      return s_dc->sdc_free_cbo(data, format, sx, sy, size);
}

bool  dc::sdc_make_rbo(void*& data, std::uint8_t format, std::uint16_t sx, std::uint16_t sy, std::size_t& size) noexcept
{
      return s_dc->sdc_make_rbo(data, format, sx, sy, size);
}

bool  dc::sdc_free_rbo(void*& data, std::uint8_t format, std::uint16_t sx, std::uint16_t sy, std::size_t& size) noexcept
{
      return s_dc->sdc_free_rbo(data, format, sx, sy, size);
}

void  dc::update() noexcept
{
      s_dc->update();
}

void  dc::update(const box2d_t& geometry) noexcept
{
      s_dc->update(geometry);
}

dc&   dc::operator=(const dc& rhs) noexcept
{
      return *this;
}

dc&   dc::operator=(dc&& rhs) noexcept
{
      return *this;
}

__endspace_sfx
__endspace_sonar

