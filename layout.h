#ifndef sonar_SFX_layout_h
#define sonar_SFX_layout_h
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
#include "object.h"

__namespace_sonar
__namespace_sfx

/* layout
*/
class layout: public object
{
  widget*     m_head;

  protected:
  virtual bool  on_object_insert(object*) noexcept = 0;
  virtual bool  on_object_remove(object*) noexcept = 0;

  public:
          layout(widget*) noexcept;
          layout(widget*, const layout*) noexcept;
  virtual ~layout();
          bool    insert(widget*) noexcept;
  virtual bool    has_widget(const widget*) const noexcept;
  virtual widget* get_widget(int) const noexcept;
  virtual widget* find_widget(const widget*) const noexcept;
  virtual widget* find_widget(const char*) const noexcept;
          bool    remove(widget*) noexcept;
          int           count() const noexcept;
          layout* hook()   noexcept;
          layout* unhook() noexcept;
};

__endspace_sfx
__endspace_sonar
#endif
