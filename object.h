#ifndef sonar_SFX_object_h
#define sonar_SFX_object_h
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
#include "dc.h"
#include "metrics.h"
#include "graphics.h"

__namespace_sonar
__namespace_sfx

class object: public dc
{
  protected:
  widget*       m_root;

  protected:
  /* attributes
     values that describe permanent (or close to) features
  */
  static constexpr std::uint8_t  a_none = 0;
  static constexpr std::uint8_t  a_active = 1;        // widget is interactive: can display graphics and respond to input
  static constexpr std::uint8_t  a_text = 2;          // object is drawn from a text buffer
  static constexpr std::uint8_t  a_raster = 4;        // object is drawn using pixel buffer
  static constexpr std::uint8_t  a_vector = 8;        // object is drawn using vector graphics
  static constexpr std::uint8_t  a_user_min = 16;
  static constexpr std::uint8_t  a_user_max = 64;
  static constexpr std::uint8_t  a_composable = 128;  // object can have sub-objects
  static constexpr std::uint8_t  a_any = 255;

  std::uint8_t  m_attributes;

  /* flags
     values that describe the state of the object
  */
  static constexpr std::uint8_t  f_none = 0;
  static constexpr std::uint8_t  f_visible = 1;       // object is visiblele
  static constexpr std::uint8_t  f_ready = 4;         // scene is ready
  static constexpr std::uint8_t  f_valid = 8;         // object is valid
  static constexpr std::uint8_t  f_user_min = 16;
  static constexpr std::uint8_t  f_user_max = 128;
  static constexpr std::uint8_t  f_public = 255;
  static constexpr std::uint8_t  f_any = 255;

  std::uint8_t  m_flags;

  static constexpr std::uint32_t h_undef = 0x00ffffff;
  
  std::uint32_t m_hash:24;
  
  public:
          object(std::uint8_t = a_composable, std::uint8_t = f_visible) noexcept;
          object(const object&) noexcept;
          object(object&&) noexcept;
          ~object();
  
          bool  has_name() const noexcept;
          bool  has_name(const char*) const noexcept;
          const char*   get_name() const noexcept;

          bool    has_parent() const noexcept;
          bool    has_parent(const widget*) const noexcept;
          widget* get_parent() noexcept;
          widget* set_parent(widget*) noexcept;

          bool          has_attributes(std::uint8_t) const noexcept;
          std::uint8_t  get_attributes(std::uint8_t = a_any) const noexcept;
          bool          has_flags(std::uint8_t) const noexcept;
          std::uint8_t  get_flags(std::uint8_t = f_any) const noexcept;
          std::uint8_t  set_flags(std::uint8_t) noexcept;
          std::uint8_t  clear_flags(std::uint8_t) noexcept;
          std::uint32_t get_hash() const noexcept;
          void          set_hash(std::uint32_t) noexcept;

          bool  is_visible() const noexcept;
          bool  is_composable() const noexcept;
  
          object& operator=(const object&) noexcept;
          object& operator=(object&&) noexcept;
};

__endspace_sfx
__endspace_sonar
#endif
