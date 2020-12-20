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
#include "layout.h"

__namespace_sonar
__namespace_sfx

      layout::layout(widget* owner) noexcept
{
}

      layout::layout(widget* owner, const layout*) noexcept
{
}

      layout::~layout()
{
}

bool  layout::insert(widget* widget) noexcept
{
      // if(object) {
      //     if(object->has_parent(m_owner)) {
      //         if(object->hook()) {
      //             if(on_object_insert(object)) {
      //                 m_list.push_back(object);
      //                 return object;
      //             }
      //             object->unhook();
      //         }
      //     }
      // }
      return false;
}

bool  layout::has_widget(const widget* widget) const noexcept
{
      return false;
}

widget* layout::get_widget(int index) const noexcept
{
      return nullptr;
}

widget* layout::find_widget(const widget* widget) const noexcept
{
      return nullptr;
}

widget* layout::find_widget(const char* name) const noexcept
{
      return nullptr;
}

bool  layout::remove(widget* widget) noexcept
{
      // if(object) {
      //     if(object->has_parent(m_owner)) {
      //         if(on_object_remove(object)) {
      //             for(auto iterator = m_list.cbegin(); iterator != m_list.cend(); iterator++) {
      //                 if(*iterator == object) {
      //                     m_list.erase(iterator);
      //                     object->unhook();
      //                     return nullptr;
      //                 }
      //             }
      //         }
      //     }
      // }
      return false;
}

int   layout::count() const noexcept
{
      return 0;
}

__endspace_sfx
__endspace_sonar
