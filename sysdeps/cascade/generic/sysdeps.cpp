#include <mlibc/all-sysdeps.hpp>

#include <cascade/debug.h>
#include <cascade/thread.h>
#include <string.h>

#define STUB()                                                                                     \
	({                                                                                             \
		__ensure(!"STUB function was called");                                                     \
		__builtin_unreachable();                                                                   \
	})

namespace mlibc {

[[noreturn]] void Sysdeps<LibcPanic>::operator()() {
	sysdep<LibcLog>("!!! mlibc panic !!!");
	sysdep<Exit>(42);
	__builtin_trap();
}

void Sysdeps<LibcLog>::operator()(const char *message) {
	auto len = strlen(message);
	cascade_debug_print(len, (const uint8_t*)message);
}

// In contrast to the isatty() library function, the sysdep function uses return value
// zero (and not one) to indicate that the file is a terminal.
int Sysdeps<Isatty>::operator()(int fd) { STUB(); }

int Sysdeps<Write>::operator()(int fd, void const *buf, size_t size, ssize_t *bytes_written) {
	STUB();
}

int Sysdeps<TcbSet>::operator()(void *pointer) { STUB(); }

int Sysdeps<AnonAllocate>::operator()(size_t size, void **pointer) { STUB(); }

int Sysdeps<AnonFree>::operator()(void *pointer, size_t size) { STUB(); }

int Sysdeps<Seek>::operator()(int fd, off_t offset, int whence, off_t *new_offset) { STUB(); }

[[noreturn]] void Sysdeps<Exit>::operator()(int status) {
	(void)status; // TODO: implement process exit instead of just thread exit
	sysdep<ThreadExit>();
}

[[noreturn]] void Sysdeps<ThreadExit>::operator()() { cascade_thread_exit_current(); }

int Sysdeps<Close>::operator()(int fd) { STUB(); }

int Sysdeps<FutexWake>::operator()(int *pointer, bool all) { STUB(); }

int Sysdeps<FutexWait>::operator()(int *pointer, int expected, const struct timespec *time) {
	STUB();
}

int Sysdeps<Read>::operator()(int fd, void *buf, size_t count, ssize_t *bytes_read) { STUB(); }

int Sysdeps<Open>::operator()(const char *pathname, int flags, mode_t mode, int *fd) { STUB(); }

int Sysdeps<VmMap>::operator()(
    void *hint, size_t size, int prot, int flags, int fd, off_t offset, void **window
) {
	STUB();
}

int Sysdeps<VmUnmap>::operator()(void *pointer, size_t size) { STUB(); }

int Sysdeps<ClockGet>::operator()(int clock, time_t *secs, long *nanos) { STUB(); }

int Sysdeps<Dup2>::operator()(int fd, int flags, int newfd) { STUB(); }

} // namespace mlibc
