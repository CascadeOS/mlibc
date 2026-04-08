#pragma once

#include <mlibc/sysdep-signatures.hpp>

namespace mlibc {

struct CascadeSysdepTags : LibcPanic,
                           LibcLog,
                           Isatty,
                           Write,
                           TcbSet,
                           AnonAllocate,
                           AnonFree,
                           Seek,
                           Exit,
                           ThreadExit,
                           Close,
                           FutexWake,
                           FutexWait,
                           Read,
                           Open,
                           VmMap,
                           VmUnmap,
                           ClockGet,
                           Dup2 {};

template <typename Tag>
using Sysdeps = SysdepOf<CascadeSysdepTags, Tag>;

} // namespace mlibc
