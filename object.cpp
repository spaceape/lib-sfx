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
#include "object.h"
#include "widget.h"

__namespace_sonar
__namespace_sfx

      object::object(std::uint8_t attributes, std::uint8_t flags) noexcept:
      m_root(nullptr),
      m_attributes(attributes),
      m_flags(flags),
      m_hash(h_undef)
{
}

      object::object(const object& copy) noexcept:
      m_root(copy.m_root),
      m_attributes(copy.m_attributes),
      m_flags(copy.m_flags),
      m_hash(copy.m_hash)
{
}

      object::object(object&& copy) noexcept:
      m_root(copy.m_root),
      m_attributes(copy.m_attributes),
      m_flags(copy.m_flags),
      m_hash(copy.m_hash)
{
      copy.m_root = nullptr;
      copy.m_attributes = a_none;
      copy.m_flags = f_none;
      copy.m_hash = h_undef;
}

      object::~object()
{
}

bool  object::has_name() const noexcept
{
      return false;
}

bool  object::has_name(const char* name) const noexcept
{
      return name == nullptr;
}

const char* object::get_name() const noexcept
{
      return nullptr;
}

bool  object::has_parent() const noexcept
{
      return m_root != nullptr;
}

bool  object::has_parent(const widget* widget) const noexcept
{
      return m_root == widget;
}

widget* object::get_parent() noexcept
{
      return m_root;
}

bool  object::has_attributes(std::uint8_t attributes) const noexcept
{
      return ((m_attributes & attributes) == attributes);
}

std::uint8_t object::get_attributes(std::uint8_t filter) const noexcept
{
      return m_attributes & filter;
}

bool  object::has_flags(std::uint8_t flags) const noexcept
{
      return ((m_flags & flags) == flags);
}

std::uint8_t object::get_flags(std::uint8_t filter) const noexcept
{
      return m_flags & filter;
}

std::uint8_t object::set_flags(std::uint8_t flags) noexcept
{
      return m_flags = flags & f_public;
}

std::uint8_t object::clear_flags(std::uint8_t flags) noexcept
{
      return m_flags &= ~flags;
}

std::uint32_t object::get_hash() const noexcept
{
      return m_hash;
}

void  object::set_hash(std::uint32_t value) noexcept
{
      m_hash = value;
}

bool  object::is_visible() const noexcept
{
      return m_flags & f_visible;
}

bool  object::is_composable() const noexcept
{
      return m_attributes & a_composable;
}

object& object::operator=(const object& rhs) noexcept
{
      m_root = rhs.m_root;
      m_attributes = rhs.m_attributes;
      m_flags = rhs.m_flags;
      m_hash = rhs.m_hash;
      return *this;
}

object& object::operator=(object&& rhs) noexcept
{
      m_root = rhs.m_root;
      m_attributes = rhs.m_attributes;
      m_flags = rhs.m_flags;
      m_hash = rhs.m_hash;
      rhs.m_root = nullptr;
      rhs.m_attributes = a_none;
      rhs.m_flags = f_none;
      rhs.m_hash = h_undef;
      return *this;
}

__endspace_sfx
__endspace_sonar
