#ifdef _SILENCE_CLANG_COROUTINE_MESSAGE
extern "C" size_t _coro_resume(void* addr) { __builtin_coro_resume(addr); return 0; }
extern "C" void _coro_destroy(void* addr)  { __builtin_coro_destroy(addr); }
extern "C" size_t _coro_done(void* addr)   { return __builtin_coro_done(addr) ? 1 : 0; }
#endif