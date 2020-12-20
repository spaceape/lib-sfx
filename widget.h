#ifndef sonar_SFX_widget_h
#define sonar_SFX_widget_h
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
#include <gfx.h>
#include <sfx.h>
#include "dc.h"
#include "object.h"
#include "layout.h"

__namespace_sonar
__namespace_sfx

class widget: public object
{
  // first of the child widgets in widget's linked list
  widget* m_head;

  // next of the child widgets in parent's linked list
  widget* m_next;

  layout* m_layout;

  void*   m_hook;

  protected:
  std::int16_t m_px0;
  std::int16_t m_py0;
  std::int16_t m_px1;
  std::int16_t m_py1;

  protected:
  virtual void set_contents_dirty(widget*) noexcept;
  virtual void set_geometry_dirty(widget*, unsigned int) noexcept;
  virtual void set_hierarchy_dirty(widget*, unsigned int) noexcept;

  friend  class sonar::gfx::scene;

  public:
  static constexpr unsigned int opt_notify_none = 0;
  static constexpr unsigned int opt_notify_move = 1;
  static constexpr unsigned int opt_notify_resize = 2;
  static constexpr unsigned int opt_notify_insert = 1;
  static constexpr unsigned int opt_notify_remove = 2;

  public:
          widget() noexcept;
          widget(widget*, std::uint8_t = a_composable, std::uint8_t = f_visible) noexcept;
          widget(const widget&) noexcept;
          widget(widget&&) noexcept;
  virtual ~widget();
  
          widget*  set_parent(widget*) noexcept;
  
          void*    get_hook() noexcept;

  template<typename Xt>
  inline  Xt*      cast_hook() noexcept {
          return   static_cast<Xt*>(get_hook());
  }

          void     set_hook(void*) noexcept;
  
          std::int16_t  get_px() const noexcept;
          std::int16_t  get_px0() const noexcept;
          std::int16_t  get_py() const noexcept;
          std::int16_t  get_py0() const noexcept;
          std::int16_t  get_cx() const noexcept;
          std::uint16_t get_sx() const noexcept;
          std::int16_t  get_px1() const noexcept;          
          std::int16_t  get_cy() const noexcept;
          std::uint16_t get_sy() const noexcept;
          std::int16_t  get_py1() const noexcept;

          bool     has_widget(const widget*) const noexcept;
          widget*  get_widget(int) const noexcept;
          widget*  get_widget(const char*) const noexcept;
          widget*  insert(widget*) noexcept;
          widget*  remove(widget*) noexcept;
          widget*  get_sibling(int) noexcept;

          box2d_t  get_geometry() const noexcept;
          void     get_local_offset(std::int16_t&, std::int16_t&) const noexcept;
          void     get_global_offset(std::int16_t&, std::int16_t&) const noexcept;
          void     set_geometry(std::int16_t, std::int16_t, std::int16_t, std::int16_t) noexcept;

  virtual bool     sync(float) noexcept;

          widget& operator=(const widget&) noexcept;
          widget& operator=(widget&&) noexcept;
};

__endspace_sfx
__endspace_sonar
#endif
