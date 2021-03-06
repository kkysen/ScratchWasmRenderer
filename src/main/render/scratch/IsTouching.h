//
// Created by Khyber on 5/2/2019.
//

#pragma once

#include "types.h"

namespace render::scratch {
    
    template <class Impl>
    class IsTouching {

    private:
        
        const Impl& impl;

    public:
        
        explicit constexpr IsTouching(const Impl& impl) noexcept : impl(impl) {}
    
        constexpr bool nearest(const Vec2& v) noexcept {
            return impl.isTouchingNearest(v);
        }
    
        constexpr bool linear(const Vec2& v) noexcept {
            return impl.isTouchingLinear(v);
        }
        
        constexpr bool operator()(const Vec2& v, bool useNearest) noexcept {
            return useNearest ? nearest(v) : linear(v);
        }
    
    };
    
}
