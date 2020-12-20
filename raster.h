#ifndef sonar_SFX_raster_h
#define sonar_SFX_raster_h
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
#include <sfx.h>

__namespace_sonar
__namespace_sfx

/* buffer format flags
*/
constexpr std::uint8_t fmt_undef = 0;

constexpr std::uint8_t fmt_tile = 16;
constexpr std::uint8_t mode_colour_1bit = fmt_tile | 0;
constexpr std::uint8_t mode_colour_4bit = fmt_tile | 2;
constexpr std::uint8_t mode_colour_8bit = fmt_tile | 3;

constexpr std::uint8_t fmt_indexed = 32;
constexpr std::uint8_t mode_x8 = fmt_indexed;

constexpr std::uint8_t fmt_argb = 64;
constexpr std::uint8_t mode_argb_1111 = fmt_argb | 0 | 1;
constexpr std::uint8_t mode_argb_2222 = fmt_argb | 0 | 0;
constexpr std::uint8_t mode_argb_4444 = fmt_argb | 2 | 1;
constexpr std::uint8_t mode_argb_8888 = fmt_argb | 2 | 0;

// primary format attribute: set for the primary surface
constexpr std::uint8_t attr_primary = 128;

/* 8 bit ARGB
*/
union pixel8_t
{
  std::uint8_t value;

  struct {
    std::uint8_t b:2;
    std::uint8_t g:2;
    std::uint8_t r:2;
    std::uint8_t a:2;
  } argb;
};

/* 16 bit ARGB
*/
union pixel16_t
{
  std::uint16_t value;

  struct {
    std::uint8_t b:4;
    std::uint8_t g:4;
    std::uint8_t r:4;
    std::uint8_t a:4;
  } argb;
};

/* 32 bit ARGB
*/
union pixel32_t
{
  std::uint32_t value;

  struct {
    std::uint8_t b;
    std::uint8_t g;
    std::uint8_t r;
    std::uint8_t a;
  } argb;

  public:
  inline  pixel32_t() noexcept:
          value(0) {
  }

  inline  pixel32_t(std::uint32_t colour) noexcept:
          value(colour) {
  }

  inline  pixel32_t(std::uint8_t a, std::uint8_t r, std::uint8_t g, std::uint8_t b) noexcept {
          argb.a = a;
          argb.r = r;
          argb.g = g;
          argb.b = b;
  }

  inline  pixel32_t(const pixel32_t& copy) noexcept:
          value(copy.value) {
  }

  inline  pixel32_t(pixel32_t&& copy) noexcept:
          value(copy.value) {
  }

  inline  pixel32_t& operator=(std::uint32_t rhs) noexcept {
          value = rhs;
          return *this;
  }

  inline  pixel32_t& operator=(const pixel32_t& rhs) noexcept {
          value = rhs.value;
          return *this;
  }

  inline  pixel32_t& operator=(pixel32_t&& rhs) noexcept {
          value = rhs.value;
          return *this;
  }
};

/* get_surface_bytes()
   find out how many bytes a buffer of the given format would occupy for the given number of
   pixels
*/
constexpr std::uint32_t get_surface_bytes(std::uint8_t format, std::uint32_t px) noexcept
{
        if(format & fmt_tile) {
            return  px >> (3 - (format & 7));
        } else
        if(format & fmt_indexed) {
            return  px >> (format & 3);
        } else
        if(format & fmt_argb) {
            return  px << (format & 2) >> (format & 1);
        } else
            return 0;
}

/* get_surface_bytes()
   find out how many bytes a buffer of the given format would occupy for the given size in
   pixels
*/
constexpr std::uint32_t get_surface_bytes(std::uint8_t format, std::uint16_t sx, std::uint16_t sy) noexcept
{
        return get_surface_bytes(format, sx * sy);
}

__endspace_sfx
__endspace_sonar
#endif
