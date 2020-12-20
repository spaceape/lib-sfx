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
#include "widget.h"

__namespace_sonar
__namespace_sfx

      widget::widget() noexcept:
      object(),
      m_head(nullptr),
      m_next(nullptr),
      m_layout(nullptr),
      m_hook(nullptr),
      m_px0(0),
      m_py0(0),
      m_px1(0),
      m_py1(0)
{
}

      widget::widget(widget* widget, std::uint8_t attributes, std::uint8_t flags) noexcept:
      object(attributes, flags),
      m_head(nullptr),
      m_next(nullptr),
      m_layout(nullptr),
      m_hook(nullptr),
      m_px0(0),
      m_py0(0),
      m_px1(0),
      m_py1(0)
{
      set_parent(widget);
}

      widget::widget(const widget& copy) noexcept:
      object(copy),
      m_head(copy.m_head),
      m_next(copy.m_next),
      m_layout(copy.m_layout),
      m_hook(copy.m_hook),
      m_px0(copy.m_px0),
      m_py0(copy.m_py0),
      m_px1(copy.m_px1),
      m_py1(copy.m_py1)
{
}

      widget::widget(widget&& copy) noexcept:
      object(std::move(copy)),
      m_head(copy.m_head),
      m_next(copy.m_next),
      m_layout(copy.m_layout),
      m_hook(copy.m_hook),
      m_px0(copy.m_px0),
      m_py0(copy.m_py0),
      m_px1(copy.m_py1),
      m_py1(copy.m_py1)
{
      copy.m_head = nullptr;
      copy.m_next = nullptr;
      copy.m_layout = nullptr;
      copy.m_hook = nullptr;
}

      widget::~widget()
{
}

/* set_contents_dirty()
   notify upstream widgets (and finally the rendering engine) that the contents of the widget
   have changed;
   called when the widget needs to be repainted
*/
void  widget::set_contents_dirty(widget* object) noexcept
{
      if(m_head) {
          m_head->set_contents_dirty(object);
      }
}

/* set_geometry_dirty()
   notify upstream widgets (and finally the rendering engine) that the geometry of the widget
   has changed;
   called when the widget is moved or resized;
*/
void  widget::set_geometry_dirty(widget* object, unsigned int flags) noexcept
{
      if(m_head) {
          m_head->set_geometry_dirty(object, flags);
      }
}

/* set_hierarchy_dirty()
   notify upstream widgets (and finally the rendering engine) that the hierarchy of the widget
   has changed;
   called when a widget has been added or removed from the child list
*/
void  widget::set_hierarchy_dirty(widget* object, unsigned int flags) noexcept
{
      if(m_head) {
          m_head->set_hierarchy_dirty(object, flags);
      }
}

widget* widget::set_parent(widget* parent) noexcept
{
      if(m_root != parent) {
          if(m_root != nullptr) {
              m_root->remove(this);
          }
          if(m_root == nullptr) {
              if(parent != nullptr) {
                  parent->insert(this);
              }
          }
      }
      return m_root;
}

void* widget::get_hook() noexcept
{
      return m_hook;
}

void  widget::set_hook(void* hook) noexcept
{
      m_hook = hook;
}

std::int16_t widget::get_px() const noexcept
{
      return m_px0;
}

std::int16_t widget::get_px0() const noexcept
{
      return m_px0;
}

std::int16_t widget::get_py() const noexcept
{
      return m_py0;
}

std::int16_t widget::get_py0() const noexcept
{
      return m_py0;
}

std::int16_t widget::get_cx() const noexcept
{
      return get_px() + get_sx() / 2;
}

std::uint16_t widget::get_sx() const noexcept
{
      return m_px1 - m_px0;
}

std::int16_t widget::get_px1() const noexcept
{
      return m_px1;
}

std::int16_t widget::get_cy() const noexcept
{
      return get_py() + get_sy() / 2;
}

std::uint16_t widget::get_sy() const noexcept
{
      return m_py1 - m_py0;
}

std::int16_t widget::get_py1() const noexcept
{
      return m_py1;
}

/* has_widget()
   find if given widget exists amongst the children of this widget; don't search, just
   verify the parent
*/
bool  widget::has_widget(const widget* widget) const noexcept
{
      if(widget) {
          return widget->has_parent(this);
      }
      return false;
}

/* find_widget()
   get the child widget at given index
*/
widget* widget::get_widget(int index) const noexcept
{
      int     l_index  = index;
      widget* l_widget = m_head;
      if(l_widget) {
          while(l_index) {
              if(l_widget) {
                  l_widget = l_widget->m_next;
                  l_index--;
              } else
                  break;
          }
      }
      return l_widget;
}

/* find_widget()
   get the child widget with given name: not supported - return nullptr
*/
widget* widget::get_widget(const char* name) const noexcept
{
      return nullptr;
}

/* insert()
   insert an item into the child list, setting its parent member to <this>; item is inserted
   at the head of the child list (const time)
*/
widget* widget::insert(widget* object) noexcept
{
      if(object) {
          if(is_composable()) {
              if(object->has_parent(nullptr)) {
                  object->m_root = this;
                  object->m_next = m_head;
                  m_head = object;
                  set_hierarchy_dirty(this, opt_notify_insert);
                  return this;
              }
          }
      }
      return nullptr;
}

/* remove()
   remove an item from the child list, effectively setting its parent and m_next members to
   nullptr; since child widgets are kept in a linked list, this is actually a linear time
   search.
*/
widget* widget::remove(widget* object) noexcept
{
      if(object) {
          if(is_composable()) {
              if(object->has_parent(this)) {
                  widget* l_prev = nullptr;
                  widget* l_iter = m_head;
                  while(l_iter) {
                      if(l_iter == object) {
                          if(l_prev != nullptr) {
                              l_prev->m_next = l_iter->m_next;
                          }
                          l_iter->m_next = nullptr;
                          l_iter->m_root = nullptr;
                          set_hierarchy_dirty(this, opt_notify_remove);
                          return nullptr;
                      }
                      l_prev = l_iter;
                      l_iter = l_prev->m_next;
                  }
              }
          }
      }
      return this;
}

widget* widget::get_sibling(int index) noexcept
{
      int     l_index  = index;
      widget* l_widget = m_next;
      while(l_index) {
          if(l_widget) {
              l_widget = l_widget->m_next;
              l_index--;
          } else
              break;
      }
      return l_widget;
}

box2d_t widget::get_geometry() const noexcept
{
      return box2d_t(m_px0, m_py0, m_px1, m_py1);
}

void  widget::get_local_offset(std::int16_t& dx, std::int16_t& dy) const noexcept
{
      dx -= get_px();
      dy -= get_py();
      if(m_root) {
          m_root->get_local_offset(dx, dy);
      }
}

void  widget::get_global_offset(std::int16_t& dx, std::int16_t& dy) const noexcept
{
      dx += get_px();
      dy += get_py();
      if(m_root) {
          m_root->get_global_offset(dx, dy);
      }
}

void  widget::set_geometry(std::int16_t px0, std::int16_t py0, std::int16_t px1, std::int16_t py1) noexcept
{
      int  l_geometry_flags = opt_notify_none;
      if(m_px0 != px0) {
          m_px0 = px0;
          l_geometry_flags |= opt_notify_move;
      }
      if(m_py0 != py0) {
          m_py0 = py0;
          l_geometry_flags |= opt_notify_move;
      }
      if(m_px1 != px1) {
          m_px1 = px1;
          l_geometry_flags |= opt_notify_resize;
      }
      if(m_py1 != py1) {
          m_py1 = py1;
          l_geometry_flags |= opt_notify_resize;
      }
      if(l_geometry_flags != opt_notify_none) {
          set_geometry_dirty(this, l_geometry_flags);
      }
}

bool  widget::sync(float) noexcept
{
      return false;
}

widget& widget::operator=(const widget& rhs) noexcept
{
      object::operator=(rhs);
      m_head = rhs.m_head;
      m_next = rhs.m_next;
      m_layout = rhs.m_layout;
      m_hook = rhs.m_hook;

      //update child ownership
      m_px0 = rhs.m_px0;
      m_py0 = rhs.m_py0;
      m_px1 = rhs.m_px1;
      m_py1 = rhs.m_py1;
      return *this;
}

widget& widget::operator=(widget&& rhs) noexcept
{
      object::operator=(std::move(rhs));
      m_head = rhs.m_head;
      m_next = rhs.m_next;
      m_layout = rhs.m_layout;
      m_hook = rhs.m_hook;

      //update child ownership
      m_px0 = rhs.m_px0;
      m_py0 = rhs.m_py0;
      m_px1 = rhs.m_px1;
      m_py1 = rhs.m_py1;
      rhs.m_head = nullptr;
      rhs.m_next = nullptr;
      rhs.m_layout = nullptr;
      rhs.m_hook = nullptr;
      rhs.m_px0 = 0;
      rhs.m_py0 = 0;
      rhs.m_px1 = 0;
      rhs.m_py1 = 0;
      return *this;
}

__endspace_sfx
__endspace_sonar
