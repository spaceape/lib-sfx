#ifndef sonar_SFX_dc_h
#define sonar_SFX_dc_h
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
#include "metrics.h"
#include "raster.h"
#include "vector.h"

__namespace_sonar
__namespace_sfx

/* dc
 * device context
*/
class dc
{
  protected:
  static  std::uint16_t  s_charset_sx;
  static  std::uint16_t  s_charset_sy;
  static  std::uint8_t*  s_charset_ptr;
  static  std::uint32_t* s_palette;
  static  dc*  s_dc;

  protected:
  virtual bool  sdc_make_cbo(char*&, std::uint8_t, std::uint16_t, std::uint16_t, std::size_t&) noexcept;
  virtual bool  sdc_free_cbo(char*&, std::uint8_t, std::uint16_t, std::uint16_t, std::size_t&) noexcept;
  virtual bool  sdc_make_rbo(void*&, std::uint8_t, std::uint16_t, std::uint16_t, std::size_t&) noexcept;
  virtual bool  sdc_free_rbo(void*&, std::uint8_t, std::uint16_t, std::uint16_t, std::size_t&) noexcept;

  public:
          dc() noexcept;
          dc(const dc&) noexcept;
          dc(dc&&) noexcept;
  virtual ~dc();

  virtual void update() noexcept;

  virtual void update(const box2d_t&) noexcept;

  inline  void update(std::int16_t px, std::int16_t py, std::int16_t sx, std::int16_t sy) noexcept {
          update(box2d_t(px, py, sx, sy));
  }

          dc& operator=(const dc& rhs) noexcept;
          dc& operator=(dc&& rhs) noexcept;
};

__endspace_sfx
__endspace_sonar
#endif
